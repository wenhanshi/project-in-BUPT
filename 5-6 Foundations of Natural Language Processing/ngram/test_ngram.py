#-*- coding: UTF-8 -*-
import codecs
import nltk
import math
import copy
import numpy as np
import matplotlib.pyplot as plt

global SENTENCE_COUNT

def printListSentence(seg):
    print 'Seg sentences are : '
    for w in seg:
        print w,
    print '\n'
    
def countSentences(seg_list):
    count = 0
    for w in seg_list:
        if w == u'，/wd' or w == u'。/wj':
            count += 1
    return count

# gram搜索函数
def searchGramInDict(gram,freq_dict):
    if gram in freq_dict:
        return freq_dict[gram]
    return 0

# Bigram数据预处理，添加 START 分界符
def setDivInBigram(seg):
    str_seg = '  '.join(seg)
    str_seg = str_seg.replace(u'，/wd',u'START/wj').replace(u'。/wj',u'START/wj')
    new_seg = str_seg.split('  ')
    start = [u'START/wj']
    new_seg = start + new_seg
    return new_seg

# Trigram数据预处理，添加 START  START 分界符
def setDivInTrigram(seg):
    str_seg = '  '.join(seg)
    str_seg = str_seg.replace(u'，/wd',u'START/wj  START/wj').replace(u'。/wd',u'START/wj  START/wj')
    new_seg = str_seg.split('  ')
    start = [u'START/wj',u'START/wj']
    new_seg = start + new_seg
    return new_seg

# 利用delta平滑构建Unigram模型
def getPPForUnigram(sentence , delta ,width ,unigram_freq_dict):
    num_words = sum(unigram_freq_dict.values())
    seg = setDivInBigram(sentence)
    logpp = 0
    count = 0
    for unigram in seg:
        if unigram == u'START/wj':
            continue
        pw = float(unigram_freq_dict[unigram] + delta)/(num_words + width*delta)
        #print "pw1 = %f / %f" %(float(unigram_freq_dict[unigram] + delta),(num_words + width*delta))
        logpp += - math.log(pw,2)
        #print "logpp1 : %f" % logpp
        count += 1
    pp = 2 ** (float(logpp)/count)
    return pp

# 利用delta平滑构建Bigram模型    
def getPPForBigram(sentence,delta,width,unigram_freq_dict,bigram_freq_dict):
    seg = setDivInBigram(sentence)
    seg_bigram = list(nltk.bigrams(seg))
    logpp = 0
    count = 0
    for bigram in seg_bigram:
        pw = float(searchGramInDict(bigram,bigram_freq_dict) + delta)/(unigram_freq_dict[bigram[0]] + width*delta)
        #print "pw2 = %f / %f" % ((float(searchGramInDict(bigram,bigram_freq_dict))+ delta) , (unigram_freq_dict[bigram[0]] + width*delta))
        logpp += - math.log(pw,2)
        #print "logpp2 : %f" % logpp
        count += 1
    pp = 2 ** (float(logpp)/count)
    return pp

# 利用delta平滑构建Trigram模型
def getPPForTrigram(sentence,delta,width,bigram_freq_dict,trigram_freq_dict):
    seg = setDivInTrigram(sentence)
    seg_trigram = list(nltk.trigrams(seg))
    #printListSentence(seg_trigram)
    logpp = 0
    count = 0
    for trigram in seg_trigram:
        pw = float(searchGramInDict(trigram,trigram_freq_dict) + delta) / (searchGramInDict((trigram[0],trigram[1]),bigram_freq_dict) + width*delta)
        #print "pw3 = %f / %f" %(float(searchGramInDict(trigram,trigram_freq_dict) + delta),(searchGramInDict((trigram[0],trigram[1]),bigram_freq_dict) + width*delta))
        #print "logpp3 : %f" % logpp
        logpp += - math.log(pw,2)
        count += 1
    pp = 2 ** (float(logpp)/count)
    return pp

#def getPPForBigramWithInter(sentence,width,unigram_freq_dict,bigram_freq_dict,k):
    #seg = setDivInBigram(sentence)
    #seg_bigram = list(nltk.bigrams(seg))
    #num_words = sum(unigram_freq_dict.values())
    #num_bigrams = sum(bigram_freq_dict.values())
    #logpp = 0
    #count = 0
    #for bigram in seg_bigram:
        #if searchGramInDict(bigram,bigram_freq_dict) == 0:
            #pw = float(1) / num_bigrams
        #else:
            #pw = k * float( searchGramInDict(bigram,bigram_freq_dict) ) / (unigram_freq_dict[bigram[0]]) + (1 - k) * float( unigram_freq_dict[bigram[1]] ) / num_words
        #logpp += - math.log(pw,2)
        #count += 1
    #pp = 2 ** (float(logpp)/count)
    #return pp

#def getNr(freq_dict,seg_sentence,r):
    #count = 0
    #if r == 0:
        #for gram in seg_sentence:
            #if gram not in freq_dict :
                #count += 1
    #else:
        #for gram in seg_sentence:
            #if gram in freq_dict:
                #if freq_dict[gram] == r:
                    #count += 1
    #return count
#def getPPForBigramWithGoodTurning(sentence,width,seg_unigram_list,seg_bigram_list):
    #unigram_freq_dict = nltk.FreqDist(seg_unigram_list)
    #bigram_freq_dict = nltk.FreqDist(seg_bigram_list)
    #N = sum(bigram_freq_dict.values())
    #seg = setDivInBigram(sentence)
    #seg_bigram = list(nltk.bigrams(seg))
    #logpp = 0
    #pws = []
    #for bigram in seg_bigram:
        #if bigram in bigram_freq_dict:
            #count_r = bigram_freq_dict[bigram]
        #else:
            #count_r = 0
        #pw = float(count_r + 1)*(getNr(bigram_freq_dict,seg_bigram,count_r + 1)) / (N * getNr(bigram_freq_dict,seg_bigram,count_r))
        #print '%f / %f' % (float(count_r + 1)*(getNr(bigram_freq_dict,seg_bigram,count_r + 1)) , (N * getNr(bigram_freq_dict,seg_bigram,count_r)))
        #if pw == 0:
            #print 'failed pw for gt'
            #pw = float(countGramInText(bigram , seg_bigram_list))/(unigram_freq_dict[bigram[0]])
        #pws.append(pw)
    #sum_pw = sum(pws)
    #print 'sum_pw : %f' % sum_pw
    #for i in range(len(pws)):
        #logpp += - math.log(float(pws[i])/sum_pw,2)
    #pp = 2 ** (float(logpp)/len(pws))
    #return pp

#def getPPForTrigramWithGoodTurning(sentence,width,seg_unigram_list,seg_bigram_list,seg_trigram_list):
    #unigram_freq_dict = nltk.FreqDist(seg_unigram_list)
    #bigram_freq_dict = nltk.FreqDist(seg_bigram_list)
    #trigram_freq_dict = nltk.FreqDist(seg_trigram_list)
    #N = sum(trigram_freq_dict.values())
    #seg = setDivInTrigram(sentence)
    #seg_trigram = list(nltk.trigrams(seg))
    #logpp = 0
    #pws = []
    #for trigram in seg_trigram:
        #if trigram in trigram_freq_dict:
            #count_r = trigram_freq_dict[trigram]
        #else:
            #count_r = 0
        #pw = float(count_r + 1)*(getNr(trigram_freq_dict,seg_trigram,count_r + 1)) / (N * getNr(trigram_freq_dict,seg_trigram,count_r))
        #print '%f / %f' % ( float(count_r + 1)*(getNr(trigram_freq_dict,seg_trigram,count_r + 1)), (N * getNr(trigram_freq_dict,seg_trigram,count_r)))
        #if pw == 0:
            #print 'failed pw for gt'
            #pw = float(countGramInText(trigram,seg_trigram_list))/(countGramInText((trigram[0],trigram[1]) ,seg_bigram_list))
        #pws.append(pw)
    #sum_pw = sum(pws)
    #print 'sum_pw : %f' % sum_pw
    #for i in range(len(pws)):
        #logpp += - math.log(float(pws[i])/sum_pw,2)
    #pp = 2 ** (float(logpp)/len(pws))
    #return pp
    
# 数据集输入以及清洗函数
def getLinesFromFile(filename,begin_train,end_train,end_test):
    fp = codecs.open(filename,encoding = 'gbk')
    lines_train = []
    lines_test = []
    count = begin_train
    for line in fp:
        line_del_date = line.strip('1234567890-\r\n ')
        cur_line = line_del_date.split('  ')
        if count < end_train:
            lines_train += cur_line
        elif count < end_test:
            lines_test += cur_line
        else:
            break
        count += 1
    return lines_train , lines_test

lines_train ,lines_test = getLinesFromFile('renminribao.txt',0,18000,20000)

SENTENCE_COUNT = countSentences(lines_train)

# 构建Unigram词典
seg_unigram_list = setDivInBigram(lines_train)
unigram_freq_dict = nltk.FreqDist(seg_unigram_list)
width = len(unigram_freq_dict.keys())

# 构建Bigram词典
seg_bigram_list = setDivInBigram(lines_train)
seg_bigram_list = list(nltk.bigrams(seg_bigram_list))
bigram_freq_dict = nltk.FreqDist(seg_bigram_list)

# 构建Trigram词典
seg_trigram_list = setDivInTrigram(lines_train)
seg_trigram_list = list(nltk.trigrams(seg_trigram_list))
trigram_freq_dict = nltk.FreqDist(seg_trigram_list)

# 利用得到的词典，步进delta测试性能
deltas = np.arange(0.00001,0.0001,0.00001)
pp1list = []
pp2list = []
pp3list = []
for i in range(len(deltas)):
    pp1 = getPPForUnigram(lines_test,deltas[i],width, unigram_freq_dict)
    pp1list.append(pp1)
    pp2 = getPPForBigram(lines_test, deltas[i],width, unigram_freq_dict,bigram_freq_dict)
    pp2list.append(pp2)
    #pp2i = getPPForBigramWithInter(lines_test,width,unigram_freq_dict,bigram_freq_dict,0.5)
    pp3 = getPPForTrigram(lines_test, deltas[i],width, bigram_freq_dict,trigram_freq_dict)
    pp3list.append(pp3)
    print 'calcu done'
    print "delta = %f  pp1 : %f , pp2 : %f,pp3 : %f "%(deltas[i],pp1,pp2,pp3)

plt.plot(deltas , pp2list , 'r' ,deltas , pp3list,deltas , pp1list,':')
plt.show()







