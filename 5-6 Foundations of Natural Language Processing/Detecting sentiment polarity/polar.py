#-*- coding: UTF-8 -*-

import re
import math
import numpy as np

# 否定词词典，仅通过简单观测构建
noDict = {
    'no',
    'not',
    't',
    'never',
    'none',
    'less',
    'few',
    'though',
    'although',
    'should',
    'against'
}

# 导入情感分析对象，同时划分训练集与测试集
def getSnippet(file_name, start, end):
    print 'Loading snippet files...'
    count = 0
    train_sents = []
    test_sents = []
    fp = open(file_name)
    re_word = re.compile('\\W*') # 以句子为单位进行分词
    for line in fp:
        if count < start:
            continue
        sent = re_word.split(line)
        word_sent = [word for word in sent if len(word) > 0] # 过滤空字符
        train_sents.append(word_sent)
        if count > end:
            test_sents.append(word_sent)
        count += 1
    fp.close()
    print 'Done.'
    print '%d Sentences in total.' % count
    return train_sents, test_sents

# 导入情感词典
def getPolarDict(file_name):
    print 'Loading sentiment dictionary...'
    count = 0
    polar_dict = {}
    fp = open(file_name)
    re_data = re.compile('=[a-z0-9]+') # 根据词典文档特点进行信息提取
    for line in fp:
        group = re_data.findall(line)
        word = group[2].replace('=','')
        polar_dict[word] = {}
        polar_dict[word]['type'] = group[0].replace('=','')
        polar_dict[word]['len'] = group[1].replace('=','')
        polar_dict[word]['pos'] = group[3].replace('=','')
        polar_dict[word]['stem'] = group[4].replace('=','')
        polar_dict[word]['polar'] = group[5].replace('=','')
        count += 1
    #polar_dict['not'] = {'type' : 'fuck','len' : 1,'pos' : 's','polar' : 'negative' }
    print 'Done.'
    print '%d sentimental words in total.' % count
    return polar_dict

# 利用bool加权进行句子的向量化
def words2Vec(sent, polar_list, polar_dict):
    word_vec = np.zeros(len(polar_list))
    for w in sent:
        if w in polar_list:
            word_vec[polar_list.index(w)] = 1
    return word_vec

# 考虑了否定词词典的句子向量化
def words2VecWithNoDict(sent, polar_list, polar_dict, no_dict):
    len_polar_dict = len(polar_dict)
    word_vec = np.zeros(2 * len_polar_dict)
    count_no_word = 0
    for w in sent:
        if w in polar_list:
            if count_no_word % 2 == 0:
                word_vec[polar_list.index(w)] = 1
            else:
                word_vec[polar_list.index(w) + len(polar_list)] = 1
            count_no_word = 0
        if w in no_dict:
            count_no_word += 1
    return word_vec

# 训练朴素Bayes分类器
def trainBayes(train_pos_sents, train_neg_sents, polar_list, polar_dict, delta=0.5):
    print 'Training Bayes Classifier(without no_dict)...'
    n_pos = len(train_pos_sents)
    n_neg = len(train_neg_sents)
    
    p_pos = float(n_pos) / (n_pos + n_neg)
    pos_vec = np.zeros(len(polar_dict))
    neg_vec = np.zeros(len(polar_dict))
    
    for sent in train_pos_sents:
        for w in sent:
            if w in polar_dict:
                pos_vec[polar_list.index(w)] += 1
    for i in range(len(pos_vec)):
        pos_vec[i] = math.log(float(pos_vec[i] + delta) 
                              / (n_neg + delta * len(polar_dict)))
        
    for sent in train_neg_sents:
        for w in sent:
            if w in polar_dict:
                neg_vec[polar_list.index(w)] += 1
    for i in range(len(neg_vec)):
        neg_vec[i] = math.log(float(neg_vec[i] + delta) 
                              / (n_neg + delta * len(polar_dict)))
    print 'Done.'
    return pos_vec, neg_vec, p_pos

# 考虑了否定词词典，训练朴素Bayes分类器
def trainBayesWithNoDict(train_pos_sents, train_neg_sents, polar_list, polar_dict, no_dict, delta=0.5):
    print 'Training Bayes Classifier(with no_dict)...'
    n_pos = len(train_pos_sents)
    n_neg = len(train_neg_sents)
    len_polar_dict = len(polar_dict)
    
    p_pos = float(n_pos) / (n_pos + n_neg)
    pos_vec = np.zeros(2 * len_polar_dict) # 使用否定词，增加一倍的特征
    neg_vec = np.zeros(2 * len_polar_dict) # 即为每一个特征增加NOT_FEATURE
    
    count_no_word = 0
    for sent in train_pos_sents:
        for w in sent:
            if w in polar_dict:
                if count_no_word % 2 == 0:
                    pos_vec[polar_list.index(w)] += 1
                else:
                    pos_vec[polar_list.index(w) + len_polar_dict] += 1
                count_no_word = 0
            if w in no_dict:
                count_no_word += 1
    for i in range(len(pos_vec)):
        pos_vec[i] = math.log(float(pos_vec[i] + delta) 
                              / (n_pos + delta * 2 * len_polar_dict))
    count_no_word = 0
    for sent in train_neg_sents:
        for w in sent:
            if w in polar_dict:
                if count_no_word % 2 == 0:
                    neg_vec[polar_list.index(w)] += 1
                else:
                    neg_vec[polar_list.index(w) + len_polar_dict] += 1
                count_no_word = 0
            if w in no_dict:
                count_no_word += 1
    for i in range(len(neg_vec)):
        neg_vec[i] = math.log(float(neg_vec[i] + delta) 
                              / (n_neg + delta * 2 * len_polar_dict))
    print 'Done.'
    return pos_vec, neg_vec, p_pos

# Bayes分类器调用接口
def bayesClassifier(sent_vec, pos_vec, neg_vec, p_pos):
    p_class_pos = sum(sent_vec * pos_vec) + math.log(p_pos)
    p_class_neg = sum(sent_vec * neg_vec) + math.log(1 - p_pos)
    if p_class_pos > p_class_neg:
        return 'pos'
    else:
        return 'neg'

# 句子集合向量化接口
def makeVecs(test_sents, polar_list, polar_dict):
    test_vecs = []
    for sent in test_sents:
        sent_vec = words2Vec(sent, polar_list, polar_dict)
        test_vecs.append(sent_vec)
    return test_vecs

# 句子集合向量化接口，考虑了否定词，向量长度加倍
def makeVecsWithNoDict(test_sents, polar_list, polar_dict, no_dict):
    test_vecs = []
    for sent in test_sents:
        sent_vec = words2VecWithNoDict(sent, polar_list, polar_dict, no_dict)
        test_vecs.append(sent_vec)
    return test_vecs    

# 情感分类器的统一调用接口
def polarityIndentifier(test_pos_vecs, test_neg_vecs, pos_vec, neg_vec, p_pos):
    print '---'
    print 'Starting to classify...'
    total = len(test_pos_vecs) + len(test_neg_vecs)
    err = 0
    #not_err = 0
    for v in test_pos_vecs:
        p = bayesClassifier(v, pos_vec, neg_vec, p_pos)
        if p != 'pos':
            err += 1
            #if v[2200] != 0:
                #not_err += 1
    for v in test_neg_vecs:
        p = bayesClassifier(v, pos_vec, neg_vec, p_pos)
        if p != 'neg':
            err += 1
            #if v[2200] != 0:
                #not_err += 1
    #print not_err
    print 'Done.'
    print '%d Sentences classified.' % total
    print 'With precision : %f ' % (float(total - err) / total)
    print '---'
    return err, total

if __name__ == '__main__':
    
    # 获得训练集与测试集
    train_pos_sents, test_pos_sents = getSnippet('rt-polarity.pos', 0, 4000)
    train_neg_sents, test_neg_sents = getSnippet('rt-polarity.neg', 0, 4000)
    
    # 获得情感词典
    polar_dict = getPolarDict('subjclueslen1-HLTEMNLP05.tff')
    
    # 情感词典的序列化
    polar_list = [word for word in polar_dict]
    
    # 训练朴素Bayes分类器
    pos_vec, neg_vec, p_pos = trainBayes(train_pos_sents, train_neg_sents, polar_list, polar_dict)
    
    # 处理测试集，以适应分类器的接口
    test_pos_vecs = makeVecs(test_pos_sents, polar_list, polar_dict)
    test_neg_vecs = makeVecs(test_neg_sents, polar_list, polar_dict)
    
    # 调用分类器，返回分类统计结果
    err, total = polarityIndentifier(test_pos_vecs, test_neg_vecs, pos_vec, neg_vec, p_pos)
    
    # 考虑否定词词典，重新进行上述过程
    pos_vec, neg_vec, p_pos = trainBayesWithNoDict(train_pos_sents, train_neg_sents, polar_list, polar_dict, noDict)
    test_pos_vecs = makeVecsWithNoDict(test_pos_sents, polar_list, polar_dict, noDict)
    test_neg_vecs = makeVecsWithNoDict(test_neg_sents, polar_list, polar_dict, noDict)
    err, total = polarityIndentifier(test_pos_vecs, test_neg_vecs, pos_vec, neg_vec, p_pos)
    