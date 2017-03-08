#-*- coding: UTF-8 -*-
import copy
import re

# 获取测试token串
def getTokens(filename):
    tokens = ''
    fp = open(filename,mode = 'r')
    tokens = fp.readline().replace(' ','')
    return tokens

# 获取文法信息，包括P，START_VN，VN和VT
def getExpressionFromFile(filename):
    VN = set()
    VT = set()
    P = {}
    START_VN = ''
    fp = open(filename,mode='r')
    vn_re = re.compile('.*?->')
    form_re = re.compile('(?<=\|).*?(?=\|)')
    for line in fp:
        vn = re.findall(vn_re,line)
        if len(vn) == 0:
            continue
        vn = vn[0].replace(' ','').replace('->','')
        if not any(VN):
            START_VN = vn
        VN.add(vn)
        P[vn] = []
        forms = re.findall(form_re,line)
        for form in forms:
            form = form.replace(' ','').replace('|','')
            P[vn].append(form)
            for v in form:
                if not v.isupper() and v not in VT:
                    VT.add(v)
    return START_VN, P, VN, VT
    
# 求解FIRST集
def getFirstSet(VN,VT,P):
    FIRST_SET = {}
    for vn in VN:
        FIRST_SET[vn] = set()
    while True:
        FIRST_SET_PRE = copy.deepcopy(FIRST_SET)
        for vn in VN:
            for form in P[vn]:
                if form[0] in VT or form[0] == '#':
                    FIRST_SET[vn].add(form[0])
                else:
                    for v in form:
                        if v in VN:
                            FIRST_SET[vn] = FIRST_SET[vn] | FIRST_SET_PRE[v]
                            if '#' not in FIRST_SET[v]:
                                break
        if FIRST_SET == FIRST_SET_PRE:
            return FIRST_SET   
        
# 得到一个产生式的FIRST集
def getFiSetForForm(form,FIRST_SET):
    fiset = set()
    for v in form:
        if v in VT or v == '#':
            fiset.add(v)
            return fiset
        else:
            if '#' not in FIRST_SET[v]:
                fiset = fiset | FIRST_SET[v]
                return fiset
            else:
                fiset = fiset | FIRST_SET[v]
    fiset.add('#')
    return fiset

# 求解FOLLOW集
def getFollowSet(VN,VT,P,FIRST_SET,START_VN):
    FOLLOW_SET = {}
    for vn in VN:
        FOLLOW_SET[vn] = set()
    FOLLOW_SET[START_VN].add('$')
    
    while True:
        FOLLOW_SET_PRE = copy.deepcopy(FOLLOW_SET)
        for vn in VN:
            for form in P[vn]:
                for i in range(len(form)):
                    if form[i] in VN:
                        if i == len(form) - 1:
                            FOLLOW_SET[form[i]] = FOLLOW_SET[form[i]] | FOLLOW_SET_PRE[vn]
                        else:
                            fiset = getFiSetForForm(form[i+1::],FIRST_SET)
                            FOLLOW_SET[form[i]] = FOLLOW_SET[form[i]] | fiset
                            if '#' in fiset:
                                FOLLOW_SET[form[i]] = FOLLOW_SET[form[i]] | FOLLOW_SET_PRE[vn]
                                FOLLOW_SET[form[i]].remove('#')
        if FOLLOW_SET == FOLLOW_SET_PRE:
            return FOLLOW_SET

def setsFileOutput(filename,FIRST_SET,FOLLOW_SET):
    fp = open(filename, mode='w')
    fp.writelines('---FIRST_SET---\n')
    for vn in FIRST_SET:
        fp.writelines(vn + ' : ')
        for vt in FIRST_SET[vn]:
            fp.writelines(vt + '  ')
        fp.writelines('\n')
    fp.writelines('---FOLLOW_SET---\n')
    for vn in FOLLOW_SET:
        fp.writelines(vn + ' : ')
        for vt in FOLLOW_SET[vn]:
            fp.writelines(vt + '  ')
        fp.writelines('\n')
        
if __name__ == '__main__':
    START_VN , P , VN , VT = getExpressionFromFile('grammar_test.txt')
    FIRST_SET = getFirstSet(VN, VT, P)
    FOLLOW_SET = getFollowSet(VN, VT, P, FIRST_SET, START_VN)
    setsFileOutput('FIRST_AND_FOLLOW_SET.txt', FIRST_SET, FOLLOW_SET)
    print 'Done.'
    print 'See your result in FIRST_AND_FOLLOW_SET.txt!'