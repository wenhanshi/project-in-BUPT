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

# 辅助过程，得到消除左递归后的新产生式        
def getNewForm(new_name,vn,forms):
    pre_forms = []
    new_forms = ['#']
    for form in forms:
        if form[0] == vn:
            f = form[1::] + new_name
            new_forms.append(f)
        else:
            f = form + new_name
            pre_forms.append(f)
    return pre_forms , new_forms

# 消除左递归
def delLeftRecursion(VN,VT,P):
    name_VN = ['P','Q','R','S']
    new_P = {}
    new_VN = set()
    new_VN = new_VN | VN
    count = 0
    need_turn = 0
    for vn in VN:
        need_turn = 0
        for form in P[vn]:
            if form[0] == vn:
                need_turn = 1
                pre_forms , new_forms = getNewForm(name_VN[count],vn,P[vn])
                new_VN.add(name_VN[count])
                new_P[name_VN[count]] = new_forms
                new_P[vn] = pre_forms
                count += 1
                break
        if need_turn == 0:
            new_P[vn] = P[vn]
    return new_VN , new_P

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

# 构造LL1分析表
def makeTable(VN,VT,P,FIRST_SET,FOLLOW_SET):
    TABLE = {}
    for vn in VN:
        for form in P[vn]:
            fiset = getFiSetForForm(form,FIRST_SET)
            for vt in fiset:
                if vt is not '#':
                    TABLE[(vn,vt)] = (vn,form)
            if '#' in fiset:
                for vt in FOLLOW_SET[vn]:
                    TABLE[(vn,vt)] = (vn,form)
    return TABLE
    
def isEqual(p,q):
    if p == q:
        return True
    else:
        if p == 'a' and isinstance(type(q),int):
            return True
    return False

# 简单的错误中断
def errorProcess():
    print 'FATAL ERROR !'
    exit(1)

# 构造LL1分析程序
def grammarLL(test_tokens,TABLE,START_VN,VN,VT):
    stack = []
    left_reasons = []
    forms = []
    input_tokens = test_tokens + '$'
    left_reasons.append(START_VN)
    stack.append('$')
    stack.append(START_VN)
    ip = 0
    while stack[-1] != '$':
        if stack[-1] in VT or stack[-1] == '$':
            if isEqual(stack[-1] , input_tokens[ip]):
                stack.pop()
                ip += 1
            else:
                errorProcess()
        else:
            if (stack[-1] , input_tokens[ip]) in TABLE:
                form = TABLE[(stack[-1] , input_tokens[ip])]
                stack.pop()
                forms.append(form)
                form_left = form[0]
                form_right = form[1]
                if form_right == '#':
                    form_right = ''
                for i in range(len(form_right)):
                    stack.append(form_right[-1-i])                
                for v in left_reasons[-1]:
                    if v == form_left:
                        new = left_reasons[-1].replace(v,form_right,1)
                        left_reasons.append(new)
                        break
            else:
                errorProcess()
    return left_reasons , forms

# 生成LL1分析结果
def printLLResult(left_reasons,forms,test_tokens):
    print 'TABLE:'
    for t in TABLE:
        print t,
        print ':',
        print '%s->%s' % (TABLE[t][0],TABLE[t][1])
    print 'LL1 Process:'
    for i in range(len(forms)):
        print left_reasons[i],
        print ' with ',
        print forms[i][0],
        print '->',
        print forms[i][1]
    print test_tokens

# 文件输出分析结果
def fileOutPut(filename,lef_reasons,forms,test_tokens):
    fp = open(filename ,mode = 'w')
    
    fp.writelines('\n---LL1 TABLE---\n')
    for t in TABLE:
        line = str(t) + ':' + TABLE[t][0] + '->' + TABLE[t][1] + '\n'
        fp.writelines(line)
        
    fp.writelines('\n---LL1 Process---\n')
    for i in range(len(forms)):
        line = left_reasons[i] + ' with ' + forms[i][0] + ' -> ' + forms[i][1] + '\n'
        fp.writelines(line)
    fp.writelines(test_tokens + '\n')
    fp.close()
    
if __name__ == '__main__':
    
    # 从文件中获取文法信息
    START_VN, P, VN, VT = getExpressionFromFile('grammarInput.txt')
    
    # 输入测试
    test_tokens = getTokens('tokens.txt')
    
    # 文法消除左递归，求解FIRST/FOLLOW集，构造LL1分析表
    VN , P = delLeftRecursion(VN, VT, P)
    FIRST_SET = getFirstSet(VN, VT, P)
    FOLLOW_SET = getFollowSet(VN, VT, P, FIRST_SET, START_VN)
    TABLE = makeTable(VN,VT,P,FIRST_SET,FOLLOW_SET)
    
    # LL1语法分析过程
    left_reasons , forms = grammarLL(test_tokens,TABLE,START_VN,VN,VT)
    
    # 输出分析结果
    printLLResult(left_reasons, forms, test_tokens)
    
    # 文件输出
    fileOutPut('LL1Result.txt', left_reasons, forms, test_tokens)