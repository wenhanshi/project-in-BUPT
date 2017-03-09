#-*- coding: UTF-8 -*-
import codecs
import re
import nltk
import math

# 数据输入以及清洗过程
def getLinesFromFile(filename,begin_train,end_train,end_test):
    fp = codecs.open(filename,encoding = 'gbk')
    lines_train = ''
    lines_test = ''
    train_list = []
    test_list = []
    count = begin_train
    sp = re.compile('.*?/\w+ *')
    tone = re.compile('\{.*?\}')
    left = re.compile('\[')
    right = re.compile('\]\w+')
    blank_line = re.compile('\r\n')
    for line in fp:
        line_clean = tone.sub('',line)
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
    trains = sp.findall(lines_train)
    tests = sp.findall(lines_test)
    for word in trains:
        tup = tuple(word.replace(' ','').split('/'))
        train_list.append(tup)
    for word in tests:
        tup = tuple(word.replace(' ','').split('/'))
        test_list.append(tup)
    return train_list , test_list

# 打印 词-标记 二元组
def printUnicodeList(list):
    for w in list:
        print '(%s,%s)' % (w[0],w[1]),

# 获取二元组标记频次字典     
def getTagBigramFreqDict(tag_list):
    tag_bigram = nltk.bigrams(tag_list)
    freq = nltk.FreqDist(tag_bigram)
    return freq

# 构造状态转移矩阵A
def getAij(tag_width,tag_i,tag_j,tag_freq_dict,tag_bigram_freq_dict,delta = 0.5):
    if (tag_i,tag_j) not in tag_bigram_freq_dict:
        return delta / ( tag_freq_dict[tag_i] + delta * tag_width )
    else:
        return float( tag_bigram_freq_dict[tag_i,tag_j] + delta ) / ( tag_freq_dict[tag_i] + delta * tag_width )

# 获得观测频次字典
def getTagObsFreqDict(word_list):
    freq = nltk.FreqDist(word_list)
    return freq

# 构造观测矩阵B
def getBjk(tag_width,tag_j,obs_k,tag_freq_dict,tag_obs_freq_dict,delta = 0.01):
    num_tag = sum(tag_freq_dict.values())
    if (obs_k,tag_j) not in tag_obs_freq_dict:
        return delta / ( tag_freq_dict[tag_j] + delta * num_tag )
    else:
        return float( tag_obs_freq_dict[obs_k,tag_j] + delta ) / ( tag_freq_dict[tag_j] + delta * num_tag )

# 构造初始分布PI
def getPiDict(tag_width, tag_dict,tag_bigram_freq_dict,delta = 0.5):
    Pi_freq_dict = {}
    Pi_dict = {}
    for tag in tag_dict:
        Pi_freq_dict[tag] = 0
    for tag_i , tag_j in tag_bigram_freq_dict:
        if ( tag_i[0] == u'w' or tag_i == u'm' ) and tag_j != u'm' :
            Pi_freq_dict[tag_j] += tag_bigram_freq_dict[tag_i , tag_j]
    for tag in tag_list:
        if tag in Pi_freq_dict:
            Pi_dict[tag] = float( Pi_freq_dict[tag] + delta ) /  ( sum(Pi_freq_dict.values()) + delta * tag_width )
        else:
            Pi_dict[tag] = delta / ( sum(Pi_freq_dict.values()) + delta * tag_width )
    return Pi_dict

# HMM标注器
def HMMTagger(word_list,tag_freq_dict,tag_bigram_freq_dict,tag_obs_freq_dict,Pi_dict):
    back = {}
    v = {}
    tag_seq = []
    tags = tag_freq_dict.keys()
    tag_width = len(tags)
    lenth = len(word_list)
    for tag in tags:
        v[tag,0] = math.log( Pi_dict[tag] * getBjk(tag_width, tag, word_list[0], tag_freq_dict, tag_obs_freq_dict) )
        back[tag,0] = u'#'
    for i in range(len(word_list)):
        if i == 0:
            continue
        if i % 100 == 0:
            print 'Tagging %d / %d words...' % (i,lenth)
        for tag in tags:
            maxp = -1e20 # v*a*b
            bjk = getBjk(tag_width, tag, word_list[i], tag_freq_dict, tag_obs_freq_dict)
            for pre_tag in tags:
                aij = getAij(tag_width, pre_tag, tag, tag_freq_dict, tag_bigram_freq_dict)
                if v[pre_tag,i-1] + math.log( aij * bjk ) > maxp:
                    maxp = v[pre_tag,i-1] + math.log( aij * bjk ) # 防止下溢
                    back[tag,i] = pre_tag
            v[tag,i] = maxp
            #print tag,i,v[tag,i]
    end_idx = len(word_list) - 1
    endp = -1e20
    for tag in tags:
        if v[tag,end_idx] > endp:
            endp = v[tag,end_idx]
            endt = tag
    p = end_idx
    tag_seq.append(endt)
    endt = back[endt,p]
    while endt != u'#':
        tag_seq.append(endt)
        p -= 1
        endt = back[endt,p]
    tag_seq = tag_seq[::-1]
    tagged_list = [(word_list[i],tag_seq[i]) for i in range(len(word_list))]
    print 'Finish tagging.'
    print 'Tagged %d words.' % len(tagged_list)
    return tagged_list

# 统计标注器的准确率
def prec(tagged_list ,test_list):
    crr = 0
    for i in range(len(tagged_list)):
        #print test_list[i][0],test_list[i][1],
        #print ' <- ',
        #print tagged_list[i][1]
        if test_list[i][1] == tagged_list[i][1]:
            crr += 1
    return float(crr) / len(tagged_list)

# 打印初始分布PI
def printPidict(Pi_dict):
    sort = sorted(Pi_dict.items(), key=lambda e:e[1],reverse=True)
    for item in sort:
        print item[0],item[1]

# 文件输出        
def fileOutPut(filename,tagged_list):
    fp = codecs.open(filename ,encoding='gbk',mode = 'w')
    mix = [w+'/'+t for w,t in tagged_list]
    tagged_str = '  '.join(mix)
    fp.write(tagged_str)
    fp.close()

# 平凡标注器
def trivialTagger(word_list,tag_freq_dict):
    sort = sorted(tag_freq_dict.items(), key=lambda e:e[1],reverse=True)
    max_tag = sort[0][0]
    tagged_list = [(w,max_tag) for w in word_list]
    return tagged_list

if __name__ == '__main__':
    
    # 构建数据集
    train_list,test_list = getLinesFromFile('renminribao.txt',0,18000,20000)
    
    # 提取测试集标记序列，构造PI，A，B参数
    tag_list = [t for (w,t) in train_list]
    tag_freq_dict = nltk.FreqDist(tag_list)
    tag_width = len(tag_freq_dict.keys())
    tag_bigram_freq_dict = getTagBigramFreqDict(tag_list)
    tag_obs_freq_dict = getTagObsFreqDict(train_list)
    Pi_dict = getPiDict(tag_width, tag_freq_dict, tag_bigram_freq_dict)
    
    # 进行HMM标注
    clean_test_list = [w for (w,t) in test_list]
    tagged_list = HMMTagger(clean_test_list, tag_freq_dict, tag_bigram_freq_dict, 
                            tag_obs_freq_dict, Pi_dict)
    
    # 输出标注结果
    fileOutPut('tagged.txt',tagged_list)
    print 'With precision (HMM) :',prec(tagged_list, test_list)
    
    # 进行平凡标注，输出对比结果
    trivial_tagged_list = trivialTagger(clean_test_list, tag_freq_dict)
    print 'With precision (Trivial) :',prec(trivial_tagged_list, test_list)    
