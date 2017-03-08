#include<iostream>
using namespace std;


struct student
{
    char * id;
    int score;
    double rate;
};

int main(void)
{
    while(true)
    {
        legal = get_input(student.id);
        if(legal)
        {
            choose = get_choose();
            if(choose == START)
            {
                clk_start = start_clock();
                num = 0;
                while(num!=10)
                {
                    ans_true = show_ques();
                    ans_user = get_ans();
                    if(ans_true == ans_user)
                    {
                        correct();
                    }
                    else;
                    num++;
                }
                clk_end = end_clock();
                time = clk_end - clk_start;
                output_file();
            }
            else if(choose == CHECK)
        }
    }
    return 0;
}

int is_legal_id( char* str)
{
    int len;
    len = strlen(str);
    if(len > 6)
        return 0;
    else
        return 1;
}
