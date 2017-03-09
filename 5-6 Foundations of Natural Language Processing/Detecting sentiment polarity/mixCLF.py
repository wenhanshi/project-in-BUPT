#-*- coding: UTF-8 -*-

# 此文档试图用以基于词典和Bayes分类器相结合的方式进行分类
# 详细内容请见设计文档

import re
import math
import numpy as np
import polar

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

# 根据强度和情感正负，量化每一个情感词的情感得分，[-2，-1，0，1，2]
def addPolarCount(polar_dict):
    for word in polar_dict:
        extent = polar_dict[word]['type']
        polar = polar_dict[word]['polar']
        if extent == 'weaksubj':
            if polar == 'positive':
                polar_dict[word]['mark'] = 1
            elif polar == 'negative':
                polar_dict[word]['mark'] = -1
            else:
                polar_dict[word]['mark'] = 0
        else:
            if polar == 'positive':
                polar_dict[word]['mark'] = 2
            elif polar == 'negative':
                polar_dict[word]['mark'] = -2
            else:
                polar_dict[word]['mark'] = 0   
    return polar_dict

# 根据情感词典，获得一个句子的情感得分
def polarMarker(sent, polar_dict):
    pol = 0
    count_no_words = 0
      
    for word in sent:
        if word in polar_dict:
            if count_no_words % 2 == 0:
                pol += polar_dict[word]['mark']
            else:
                pol -= polar_dict[word]['mark']
            count_no_words = 0
        if word in noDict:
            count_no_words += 1            
    return float(pol) / len(sent)

# 基于情感词典，以句子情感得分的正负来分类
def dictBasedClassifier(neg_sents, pos_sents, polar_dict, threshold):
    remain_pos_sents = []
    remain_neg_sents = []
    err = 0
    total = 0
    count_pos = 0
    count_neg = 0
    err_pos = 0
    err_neg = 0
    
    for sent in pos_sents:
        p = polarMarker(sent, polar_dict)
        if p >= threshold or p < -threshold:
            count_pos += 1
            total += 1
            if p < -threshold:
                err += 1
                err_pos += 1
                print p, sent
        else:
            remain_pos_sents.append(sent)
    for sent in neg_sents:
        p = polarMarker(sent, polar_dict)
        if p >= threshold or p < -threshold:
            count_neg += 1
            total += 1
            if p > threshold:
                err += 1
                err_neg += 1
        else:
            remain_neg_sents.append(sent)
    print 'Dict-based Classifier Result:'
    print '%d Sentences classified in total.' % total
    print 'With precision %f' % (float(total - err) / total)
    print 'Positive : %f / %f' % (count_pos - err_pos, count_pos)
    print 'Negative : %f / %f' % (count_neg - err_neg, count_neg)
    print '---'
    return remain_pos_sents, remain_neg_sents, err, total

# 混合分类器，它是基于词典的分类器与朴素Bayes分类器的结合
def mixedClassifier(train_pos_sents, train_neg_sents, test_pos_sents, test_neg_sents, threshold, polar_dict):
    test_pos_sents, test_neg_sents, err1, total1 = dictBasedClassifier(test_neg_sents, test_pos_sents, polar_dict, threshold)
    polar_list = [word for word in polar_dict]
    pos_vec, neg_vec, p_pos = polar.trainBayesWithNoDict(train_pos_sents, train_neg_sents, polar_list, polar_dict, noDict)
    test_pos_vecs = polar.makeVecsWithNoDict(test_pos_sents, polar_list, polar_dict, noDict)
    test_neg_vecs = polar.makeVecsWithNoDict(test_neg_sents, polar_list, polar_dict, noDict)
    err2, total2 = polar.polarityIndentifier(test_pos_vecs, test_neg_vecs, pos_vec, neg_vec, p_pos)
    return err1 + err2, total1 + total2

if __name__ == '__main__':
    
    # 数据载入过程
    train_pos_sents, test_pos_sents = polar.getSnippet('rt-polarity.pos', 0, 4000)
    train_neg_sents, test_neg_sents = polar.getSnippet('rt-polarity.neg', 0, 4000)
    polar_dict = polar.getPolarDict('subjclueslen1-HLTEMNLP05.tff')
    polar_dict = addPolarCount(polar_dict)
    
    # 完全基于词典的分类器分类结果
    p, q, err, total = dictBasedClassifier(test_neg_sents, test_pos_sents, polar_dict, 0)
    
    # 混合分类器的分类结果
    err, total = mixedClassifier(train_pos_sents, train_neg_sents, 
                                test_pos_sents, 
                                test_neg_sents, 
                                0.4, 
                                polar_dict)
    print 'Mixed Classifier Result'
    print 'With precision : %f' % (float(total - err) / total)