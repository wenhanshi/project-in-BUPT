#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<ctype.h>

using namespace std;

#define BUF_SIZE 10
#define TYPE_KEY 1
#define TYPE_ID 2
#define TYPE_NUM 3
#define TYPE_LITREAL 4
#define TYPE_CHAR 5
#define TYPE_SINGLE_OP 6
#define TYPE_ASSIGN_OP 7
#define TYPE_LOGIC_OP 8
#define TYPE_RELATION_OP 9
#define TYPE_ARITH_OP 10
#define TYPE_BITWISE_OP 11

class Token{
public:
    int _type;
    string * _pstr;
    string _op_or_ltr;
    double _num;
    char _ch;
    int _row;
    void output();
};

vector<string *>key_table;
vector<string *>sym_table;

Token * token = new Token;
int cur_row = 1;
ifstream in("in.txt");
char buffer[BUF_SIZE + 1];
char ch;
string str;
int state = 0;
int pf = 1;
int type_count[20];
int char_count = 0;

void initKeyTable()
{
    ifstream in("init.txt");
    while(!in.eof())
    {
        string key;
        in>>key;
        string * pstr = new string(key);
        key_table.push_back(pstr);
    }
    in.close();

    for(int i = 0;i <= 19 ; i++)
        type_count[i] = 0;
}

void Token::output()
{
    switch(_type)
    {
    case TYPE_NUM:
        cout<<"< NUM , "<<_num<<" >"<<endl;
        break;
    case TYPE_KEY:
        cout<<"< "<<"KEY"<<" , "<<*_pstr<<" >"<<endl;
        break;
    case TYPE_SINGLE_OP:
        cout<<"< "<<"SINGLE_OP"<<" , "<<_op_or_ltr<<" >"<<endl;
        break;
    case TYPE_ASSIGN_OP:
        cout<<"< "<<"ASSIGN_OP"<<" , "<<_op_or_ltr<<" >"<<endl;
        break;
    case TYPE_ARITH_OP:
        cout<<"< "<<"AIRTH_OP"<<" , "<<_op_or_ltr<<" >"<<endl;
        break;
    case TYPE_LOGIC_OP:
        cout<<"< "<<"LOGIC_OP"<<" , "<<_op_or_ltr<<" >"<<endl;
        break;
    case TYPE_RELATION_OP:
        cout<<"< "<<"REALATION_OP"<<" , "<<_op_or_ltr<<" >"<<endl;
        break;
    case TYPE_CHAR:
        if(_ch == '\n' ||_ch == '\t')
            cout<<"< "<<"CHAR"<<" , 'ESC' >"<<endl;
        else
            cout<<"< "<<"CHAR"<<" , '"<<_ch<<"' >"<<endl;
        break;
    case TYPE_LITREAL:
        cout<<"< "<<"LITERAL"<<" , \""<<_op_or_ltr<<"\" >"<<endl;
        break;
    default:
        cout<<"< "<<"ID"<<" , "<<*_pstr<<" >"<<endl;
        break;
    }
}

char get_char()
{
    char cur_ch = buffer[pf];
    //cout<<"cur_char is :"<<cur_ch<<endl;
    int len;
    if(pf == BUF_SIZE)
    {
        //cout<<"buffer full..."<<endl;
        buffer[0] = buffer[pf];
        len = in.read(&buffer[1],BUF_SIZE * sizeof(char)).gcount();
        char_count += len;
        if(len < BUF_SIZE)
        {
            buffer[len+1] = '\0';
        }
        pf = 1;
    }
    else pf++;
    return cur_ch;
}

void skipSpace()
{
    for(;;ch = get_char())
    {
        if(ch == '\n')
            cur_row++;
        else if (ch == '\t' || ch == ' ');
            //cout<<"jump white space..."<<endl;
        else break;
    }
}

void retract()
{
    pf--;
}

string * searchKeyTable()
{
    for(string * &r : key_table)
    {
        if(*r == str)
            return r;
    }
    return NULL;
}

string * searchSymTable()
{
    for(string * &r : sym_table)
    {
        if(*r == str)
            return r;
    }
    string * pstr = new string(str);
    sym_table.push_back(pstr);
    return pstr;
}

void otherProcess()
{
    state = 0;
    retract();
    token->_row = cur_row;
}

void errorProcess()
{
    state = 0;
    retract();
    cout<<"ERROR : Lexical error in line "<<cur_row<<endl;
}

void tokenizer()
{
    string * pstr;
    char save_char;
    while(true)
    {
        if(ch == '\0') break;
        switch(state)
        {
        case 0 :
            str = "";
            //<<"in case 0"<<endl;
            ch = get_char();
            skipSpace();
            if(ch == '\0') break;

            if(isalpha(ch) || ch == '_')
                state = 1; // ID or KEY
            else if (isdigit(ch))
                state = 2; // NUM
            else if (ch == ',' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';')
            {
                state = 0;
                token->_op_or_ltr = ch;
                token->_type = TYPE_SINGLE_OP;
                type_count[TYPE_SINGLE_OP] ++ ;
                token->output();
            }
            else if (ch == '=')
                state = 8;
            else if(ch == '!')
                state = 9;
            else if(ch == '>')
                state = 10;
            else if(ch == '<')
                state = 11;
            else if(ch == '+')
                state = 12;
            else if(ch == '-')
                state = 13;
            else if(ch == '*')
                state = 14;
            else if(ch == '/')
                state = 15;
            else if(ch == '&')
                state = 19;
            else if(ch == '|')
                state = 20;
            else if(ch == '\'')
                state = 21;
            else if(ch == '\"')
                state = 24;
            else
            {
                state = 0;
                cout<<"ERROR : Lexical error in line "<<cur_row<<endl;
            }
            break;
        case 1 :
            str += ch;
            ch = get_char();

            if(isalpha(ch) || isdigit(ch) || ch == '_')
                state = 1;
            else
            {
                otherProcess();
                pstr = searchKeyTable();
                if(pstr != NULL)
                {
                    token->_type = TYPE_KEY;
                    token->_pstr = pstr;
                    type_count[TYPE_KEY]++;
                    token->output();
                }
                else
                {
                    token->_type = TYPE_ID;
                    pstr = searchSymTable();
                    token->_pstr = searchSymTable();
                    type_count[TYPE_ID]++;
                    token->output();
                }
            }
            break;
        case 2:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 2;
            else if(ch == '.')
                state = 3;
            else if(ch == 'E')
                state = 5;
            else
            {
                otherProcess();
                token->_type = TYPE_NUM;
                token->_num = atof(str.c_str());
                type_count[TYPE_NUM]++;
                token->output();
            }
            break;
        case 3:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 4;
            else
                errorProcess();
            break;
        case 4:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 4;
            else if(ch == 'E')
                state = 5;
            else
            {
                otherProcess();
                token->_type = TYPE_NUM;
                token->_num = atof(str.c_str());
                type_count[TYPE_NUM]++;
                token->output();
            }
            break;
        case 5:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 7;
            else if(ch == '+' || ch == '-')
                state = 6;
            else
                errorProcess();
            break;
        case 6:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 7;
            else
                errorProcess();
            break;
        case 7:
            str += ch;
            ch = get_char();
            if(isdigit(ch))
                state = 7;
            else
            {
                otherProcess();
                token->_type = TYPE_NUM;
                token->_num = atof(str.c_str());
                type_count[TYPE_NUM]++;
                token->output();
            }
            break;
        case 8:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            break;
        case 9:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_LOGIC_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_LOGIC_OP] ++;
                token->output();
            }
            break;
        case 10:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            break;
        case 11:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_RELATION_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_RELATION_OP] ++;
                token->output();
            }
            break;
        case 12:
            str += ch;
            ch = get_char();
            if(ch == '+')
            {
                state = 0;
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            else if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            break;
        case 13:
            str += ch;
            ch = get_char();
            if(ch == '-')
            {
                state = 0;
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            else if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            break;
        case 14:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            break;
        case 15:
            str += ch;
            ch = get_char();
            if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else if(ch == '/')
                state = 18;
            else if(ch == '*')
                state = 16;
            else
            {
                otherProcess();
                token->_type = TYPE_ARITH_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_ARITH_OP] ++;
                token->output();
            }
            break;
        case 16:
            ch = get_char();
            while(ch != '*')
            {
                if(ch == '\n')
                    cur_row ++ ;
                ch = get_char();
            }
            if(ch == '*')
                state = 17;
            else
                state = 16;
            break;
        case 17:
            ch = get_char();
            if(ch == '/')
                state = 0;
            else
                state = 16;
            break;
        case 18:
            ch = get_char();
            if(ch == '\n')
                state = 0;
            else
                state = 18;
            break;
        case 19:
            str += ch;
            ch = get_char();
            if(ch == '&')
            {
                state = 0;
                token->_type = TYPE_LOGIC_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_LOGIC_OP] ++;
                token->output();
            }
            else if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_BITWISE_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_BITWISE_OP] ++;
                token->output();
            }
            break;
        case 20:
            str += ch;
            ch = get_char();
            if(ch == '|')
            {
                state = 0;
                token->_type = TYPE_LOGIC_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_LOGIC_OP] ++;
                token->output();
            }
            else if(ch == '=')
            {
                state = 0;
                token->_type = TYPE_ASSIGN_OP;
                token->_op_or_ltr = str + ch;
                token->_row = cur_row;
                type_count[TYPE_ASSIGN_OP] ++;
                token->output();
            }
            else
            {
                otherProcess();
                token->_type = TYPE_BITWISE_OP;
                token->_op_or_ltr = str;
                type_count[TYPE_BITWISE_OP] ++;
                token->output();
            }
            break;
        case 21:
            ch = get_char();
            if(ch == '\\')
                state = 22;
            else
            {
                state = 23;
                save_char = ch;
            }
            break;
        case 22:
            ch = get_char();
            if(ch == 't')
            {
                save_char = '\t';
                state = 23;
            }
            else if(ch == 'n')
            {
                save_char = '\n';
                state = 23;
            }
            else errorProcess();
            break;
        case 23:
            ch = get_char();
            if(ch == '\'')
            {
                state = 0;
                token->_type = TYPE_CHAR;
                token->_ch = save_char;
                token->_row = cur_row;
                type_count[TYPE_CHAR] ++;
                token->output();
            }
            else errorProcess();
            break;
        case 24:
            ch = get_char();
            if(ch == '\"')
            {
                state = 0;
                token->_op_or_ltr = str;
                token->_type = TYPE_LITREAL;
                token->_row = cur_row;
                type_count[TYPE_LITREAL] ++;
                token->output();
            }
            else
            {
                str += ch;
                state = 24;
            }
            break;
        default:
            cout<<"FATAL ERROR : NONE EXIST STATE ..."<<endl;
            exit(0);
            break;
        }
    }
    in.close();
}

void printTokenStat()
{
    cout<<"---Token Statistic---"<<endl;
    cout<<"total char : "<<char_count<<endl;
    for(int i = 1;;i++)
    {
        switch(i)
        {
        case TYPE_KEY :
            cout<<"KEY : "<<type_count[TYPE_KEY]<<endl;
            break;
        case TYPE_ID :
            cout<<"ID : "<<type_count[TYPE_ID]<<endl;
            break;
        case TYPE_NUM :
            cout<<"NUM : "<<type_count[TYPE_NUM]<<endl;
            break;
        case TYPE_LITREAL :
            cout<<"LITERAL : "<<type_count[TYPE_LITREAL]<<endl;
            break;
        case TYPE_CHAR :
            cout<<"CHAR : "<<type_count[TYPE_CHAR]<<endl;
            break;
        case TYPE_ASSIGN_OP :
            cout<<"ASSIGN_OP : "<<type_count[TYPE_ASSIGN_OP]<<endl;
            break;
        case TYPE_LOGIC_OP :
            cout<<"LOGIC_OP : "<<type_count[TYPE_LOGIC_OP]<<endl;
            break;
        case TYPE_RELATION_OP :
            cout<<"RELATION_OP : "<<type_count[TYPE_RELATION_OP]<<endl;
            break;
        case TYPE_BITWISE_OP :
            cout<<"BITWISE_OP : "<<type_count[TYPE_BITWISE_OP]<<endl;
            break;
        case TYPE_SINGLE_OP :
            cout<<"SINGLE_OP : "<<type_count[TYPE_SINGLE_OP]<<endl;
            break;
        case TYPE_ARITH_OP :
            cout<<"ARITH_OP : "<<type_count[TYPE_ARITH_OP]<<endl;
            break;
        default:
            return;
        }
    }

}

int main(void)
{
    char_count += in.read(&buffer[1],BUF_SIZE * sizeof(char)).gcount();
    initKeyTable();
    ch = buffer[pf];
    tokenizer();
    printTokenStat();
    return 0;
}
