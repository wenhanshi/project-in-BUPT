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

# 辅助过程求解一个产生式的FIRST集
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

# 求解增广文法
def extendG(P,VN,START_VN):
    start = 'S'
    P['S'] = [START_VN]
    VN.add(start)
    return P , VN , start

# 辅助过程，得到.之后的第一个字母
def getLetterAfterPoint(right_form):
    if right_form[-1] == '.':
        return '#'
    else:
        index = right_form.index('.')
        return right_form[index+1]

# 闭包计算函数
def getClosure(I,VN,P):
    J = copy.deepcopy(I)
    while True:
        J_new = copy.deepcopy(J)
        for item in J_new:
            v = getLetterAfterPoint(item[1])
            if v in VN:
                for right_form in P[v]:
                    r = '.' + right_form
                    new_form = (v,r)
                    if new_form not in J:
                        J.add(new_form)
        if J == J_new :
            return J
        
# 辅助过程，得到一个项目集所有的可拓展vn
def getLettersFromItems(cur_items):
    letters = []
    for item in cur_items:
        v = getLetterAfterPoint(item[1])
        if v != '#' and ( v not in letters ):
            letters.append(v)
    return letters

# 辅助过程，得到一个新项目集中的kernel
def getNextItemsHead(letter,cur_items):
    heads = set()
    for item in cur_items:
        v = getLetterAfterPoint(item[1])
        if v == letter:
            right = item[1]
            index = right.index('.')
            l = right[0:index]
            mid = right[index + 1]
            r = right[index + 2::]
            new_right = l + mid + '.' + r
            new_form = (item[0] , new_right)
            heads.add(new_form)
    return heads

# 判断过程，是否为规约项目
def isReduceItem(item,START_VN):
    if item[1][-1] == '.' and item[0] != START_VN:
        return True
    return False

# 构造LR分析表(SLR1)
def makeLRTable(P,VN,VT,START_VN,FOLLOW_SET):
    ACTION_TABLE = {}
    GOTO_TABLE = {}
    GO_FOR_DFA = {}
    init_set = set()
    init_item = (START_VN,'.' + P[START_VN][0])
    init_set.add(init_item)
    items = []
    I0 = getClosure(init_set, VN, P)
    items.append(I0)
    items_stack = []
    items_stack.append(I0)
    
    while True:
        if len(items_stack) == 0:
            break
        cur_items = items_stack.pop()
        cur_index = items.index(cur_items)
        
        for item in cur_items:
            if item[0] == START_VN and cur_index != 0:
                ACTION_TABLE[(cur_index,'$')] = (0,'ACC')
            if isReduceItem(item,START_VN):
                form = (item[0],item[1][0:-1])
                for v in FOLLOW_SET[item[0]]:
                    ACTION_TABLE[(cur_index,v)] = (2,form)
                    
        letters = getLettersFromItems(cur_items)
        for letter in letters:
            next_items_head = getNextItemsHead(letter,cur_items)
            new_items = set()
            new_items = new_items | next_items_head
            for head in next_items_head:
                new_head = set()
                new_head.add(head)
                new_items = new_items | getClosure(new_head, VN, P)
            if new_items not in items:
                items.append(new_items)
                items_stack.append(new_items)
                new_index = items.index(new_items)
            else:
                new_index = items.index(new_items)
            GO_FOR_DFA[(cur_index,letter)] = new_index
            if letter in VN:
                GOTO_TABLE[(cur_index,letter)] = new_index
            else:
                ACTION_TABLE[(cur_index,letter)] = (1,new_index)            
                
    return ACTION_TABLE , GOTO_TABLE , GO_FOR_DFA ,items

# LR语法分析器
def grammerLR(test_tokens , ACTION_TABLE , GOTO_TABLE):
    state = []
    symble = []
    stack = []
    remains = []
    tokens = test_tokens + '$'
    ip = 0
    state.append(0)
    symble.append('@')
    stack.append('@')
    remains.append(tokens)
    
    while True:
        S = state[-1]
        a = tokens[ip]
        act = ACTION_TABLE[(S,a)]
        if act[0] == 0:
            break
        elif act[0] == 1:
            symble.append(tokens[ip])
            ip += 1
            remains.append(tokens[ip::])
            state.append(act[1])
            stack.append(''.join(symble))
        elif act[0] == 2:
            form = act[1]
            lenth = len(form[1])
            for i in range(lenth):
                state.pop()
                symble.pop()
            symble.append(form[0])
            tup = (state[-1],symble[-1])
            if tup in GOTO_TABLE:
                state.append(GOTO_TABLE[tup])
            else:
                errorProcess()
            remains.append(tokens[ip::])
            stack.append(''.join(symble))
        else:
            errorProcess()
    return stack , remains

# 简单的错误中断
def errorProcess():
    print 'FATAL ERROR !'
    exit(1)

# DFA打印函数
def printDFA(ITEMS , GO_FOR_DFA):
    print '---Items---'
    for i in range(len(ITEMS)):
        print 'I%i : ' %i,
        for left,right in ITEMS[i]:
            print '%s -> %s |' %(left,right),
        print ''
    print '---GO_FOR_DFA---'
    for move in GO_FOR_DFA:
        print 'I%i with %s go I%i' % (move[0],move[1],GO_FOR_DFA[move])

# SLR1 分析表打印函数
def printLRTable(ACTION_TABLE,GOTO_TABLE):
    print '---ACTION_TABLE---'
    for item,vt in ACTION_TABLE:
        print 'I%d with %s :' % (item,vt),
        if ACTION_TABLE[item,vt][0] == 0:
            print ACTION_TABLE[item,vt][1]
        elif ACTION_TABLE[item,vt][0] == 1:
            print 'S %d' % ACTION_TABLE[item,vt][1]
        else:
            print 'R %s->%s' % (ACTION_TABLE[item,vt][1][0],ACTION_TABLE[item,vt][1][1])
    print '---GOTO_TABLE---'
    for item,vn in GOTO_TABLE:
        print 'I%d with %s : goto I%d' % (item,vn,GOTO_TABLE[item,vn])

# 输出LR分析过程
def printLRResult(stack,remains):
    print '---LR Result---'
    for i in range(len(stack)):
        print stack[i],
        print ' <--> ',
        print remains[i]
        
# 文件输出分析结果
def fileOutPut(filename,stack,remains,ACTION_TABLE,GOTO_TABLE,ITEMS , GO_FOR_DFA,test_tokens):
    fp = open(filename ,mode = 'w')
    
    fp.writelines('\n---Items---\n')
    for i in range(len(ITEMS)):
        fp.write('I%i : ' %i)
        for left,right in ITEMS[i]:
            fp.write('%s -> %s |' %(left,right))
        fp.write('\n')
            
    fp.writelines('\n---GO_FOR_DFA---\n')
    for move in GO_FOR_DFA:
        fp.write('I%i with %s go I%i' % (move[0],move[1],GO_FOR_DFA[move]) + '\n')  
    
    fp.writelines('\n---ACTION TABLE---\n')
    for item,vt in ACTION_TABLE:
        fp.write('I%d with %s :' % (item,vt) )
        if ACTION_TABLE[item,vt][0] == 0:
            fp.write(ACTION_TABLE[item,vt][1] + '\n')
        elif ACTION_TABLE[item,vt][0] == 1:
            fp.write('S %d' % ACTION_TABLE[item,vt][1] + '\n')
        else:
            fp.write('R %s->%s' % (ACTION_TABLE[item,vt][1][0],ACTION_TABLE[item,vt][1][1]) + '\n')
            
    fp.writelines('\n---GOTO_TABLE---\n') 
    for item,vn in GOTO_TABLE:
        fp.write('I%d with %s : goto I%d' % (item,vn,GOTO_TABLE[item,vn]) + '\n')
        
    fp.writelines('\n---LR Result---\n')
    for i in range(len(stack)):
        fp.write(stack[i] + ' <-- ' + remains[i] + '\n')
    fp.close()
        
if __name__ == '__main__':
    
    # 从文件中获取文法信息
    START_VN, P, VN, VT = getExpressionFromFile('grammarInput.txt')
    
    # 输入测试
    test_tokens = getTokens('tokens.txt')    
    
    # 增广文法，求FIRST/FOLLOW集，构造SLR1分析表
    P , VN , START_VN = extendG(P, VN, START_VN)
    FIRST_SET = getFirstSet(VN, VT, P)
    FOLLOW_SET = getFollowSet(VN, VT, P, FIRST_SET, START_VN)
    ACTION_TABLE , GOTO_TABLE , GO_FOR_DFA , ITEMS = makeLRTable(P, VN, VT, START_VN, FOLLOW_SET)
    
    # LR语法分析
    stack , remains = grammerLR(test_tokens, ACTION_TABLE, GOTO_TABLE)
    
    # 打印DFA，SLR1分析表，LR分析过程
    printLRTable(ACTION_TABLE, GOTO_TABLE)
    printDFA(ITEMS, GO_FOR_DFA)
    printLRResult(stack, remains)
    
    # 文件输出
    fileOutPut('LRResult.txt', stack, remains, ACTION_TABLE, GOTO_TABLE, ITEMS, GO_FOR_DFA, test_tokens)    


