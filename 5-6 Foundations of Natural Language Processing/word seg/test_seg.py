#-*- coding: UTF-8 -*-
import codecs
import nltk
import re

# 数据输入以及清洗过程
def getLinesFromFile(filename,begin_train,end_train,end_test):
    fp = codecs.open(filename,encoding = 'gbk')
    lines_train = ''
    lines_test = ''
    count = begin_train
    tag = re.compile('/\w+') 
    data = re.compile('\d+-\d+-\d+-\d+\s+')
    tone = re.compile('\{.*?\}')
    left = re.compile('\[')
    right = re.compile('\]\w+')
    blank_line = re.compile('\r\n')
    for line in fp:
        line_clean = tag.sub('',line)
        line_clean = data.sub('',line_clean)
        line_clean = tone.sub('',line_clean)
        line_clean = left.sub('',line_clean)
        line_clean = right.sub('',line_clean)
        line_clean = blank_line.sub('',line_clean)
        if count < end_train:
            lines_train += line_clean
        elif count < end_test:
            lines_test += line_clean
        else:
            break
        count += 1
    train_list = lines_train.split('  ')
    test_list = lines_test.split('  ')
    return train_list , test_list

# 反分词过程
def getRaw(test_list):
    raw_str = ''
    for w in test_list:
        raw_str += w
    return raw_str

# 确定最大词长
def getMaxLen(test_list):
    lenth = 0
    for w in test_list:
        if len(w) > lenth :
            lenth = len(w)
    return lenth

# 利用FMM算法分词
def segByMM(raw_str,freq_dict,test_list):
    max_len = getMaxLen(test_list)
    seg_list = []
    count_fault = 0
    cur_word = u''
    target = u'|'.join(test_list)
    target += u'$'
    raw_str += u'$'
    p_start = 0
    p_right = 0
    p_pre = 0
    while True:
        if raw_str[p_start] == u'$':
            break
        for i in range(max_len):
            if p_start + max_len - i > len(raw_str):
                p_end = len(raw_str) - 1
            else:
                p_end = max_len - i + p_start
            if ( raw_str[p_start:p_end] in freq_dict ) or ( p_end - p_start == 1 ):
                word = raw_str[p_start:p_end]
                seg_list.append(word)
                if word != test_list[p_right]:
                    count_fault += 1
                p_start = p_end
                for i in range(len(word)):
                    p_pre += 1
                    if target[p_pre] == u'|':
                        p_pre += 1
                        p_right += 1
                break
                        
    precise = float(len(seg_list) - count_fault) / len(seg_list)
    recall = float(len(seg_list) - count_fault) / len(test_list)
    f = precise * recall * 2 / (precise + recall)
    print 'precise : %f' % precise
    print 'recall : %f' % recall
    print 'f measure : %f' % f
    return seg_list , f

# 分词结果输出函数
def fileOutPut(filename,seg_list):
    fp = codecs.open(filename ,encoding='gbk',mode = 'w')
    seg_str = '|'.join(seg_list)
    fp.write(seg_str)
    fp.close()

test_list , train_list = getLinesFromFile('renminribao.txt',0,1000,20000)
raw_str = getRaw(test_list)
freq_dict = nltk.FreqDist(train_list)
seg_list , f = segByMM(raw_str,freq_dict,test_list)
fileOutPut('seg.txt',seg_list)