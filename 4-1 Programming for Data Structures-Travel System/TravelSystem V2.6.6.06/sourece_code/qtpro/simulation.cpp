#include<iostream>
#include"Graph.h"

using namespace std ;

extern int Time;// 系统时间
extern TST arr_tst[MAX_TST];

S_STATE state_trans(Graph &travel_graph,int target) // 用以计算下一个状态S_STATE ，参量 state_n作为全局变量被该函数窥视
{
    S_STATE state_next;
    int diff;
    cout<<"e_now"<<arr_tst[target].e_now<<endl;
    if(arr_tst[target].state_n.ismove == false)//如果它现在是静止的，那么下一S_STATE一定是移动的 // 6.1 debug
    {
        state_next.city = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].derive_city;
        state_next.ismove = true;
        state_next.state_dur = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dur;
        state_next.dest = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dest_city;
    }
    else//如果他在移动 ， 下一状态未必是静止的 ，需要看下一条边的信息
    {
        if(!arr_tst[target].moveflag)//移动时更新
        {
            cout<<"!!!!nomoveflag"<<endl;
            state_next.city = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dest_city;
            if(arr_tst[target].e_now + 1 == arr_tst[target]._stml.size_arr)
                return {state_next.city,MAX_WEIGHT,false,state_next.city};
            diff =(( travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now + 1]].derive_time -
            (travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].derive_time
                    + travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dur) )+72)%24;
            arr_tst[target].e_now ++;
            if(diff)//下一状态是静止的
            {
                state_next.ismove = false ;
                state_next.state_dur = diff;
                state_next.dest = state_next.city;
            }
            else//下一状态是移动的
            {
                state_next.ismove = true ;
                state_next.state_dur = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dur;
                state_next.dest = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dest_city;

            }
        }
        else
        {
            cout<<"yes has move flag!!!"<<endl;
            if(arr_tst[target]._stml.size_arr == 0)
            {
                arr_tst[target].moveflag = 0;
                return {arr_tst[target].state_n.dest,MAX_WEIGHT,false,arr_tst[target].state_n.dest};
            }
            state_next.city = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].derive_city;
            diff =( travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].derive_time -  Time + 72 ) % 24;
            if(diff)//下一状态是静止的
            {
                state_next.ismove = false ;
                state_next.state_dur = diff;
                state_next.dest = state_next.city;
            }
            else//下一状态是移动的
            {
                state_next.ismove = true ;
                state_next.state_dur = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dur;
                state_next.dest = travel_graph._arrEdge[arr_tst[target]._stml.arr_opEdge[arr_tst[target].e_now]].dest_city;

            }
            cout<<"close move flag!!!"<<endl;
            arr_tst[target].moveflag = 0;
        }
    }
    return state_next;
}
void printState(void)
{
    cout<<"Time:"<<Time<<endl;
    cout<<"city->"<<arr_tst[0].state_n.city<<endl;
    cout<<"timepass/will dur ->"<<arr_tst[0].timepass<<"/"<<arr_tst[0].state_n.state_dur<<endl;
    cout<<"ismove?->"<<arr_tst[0].state_n.ismove<<endl;
}
void _simulation(Graph &travel_graph)
{
    printState();
    //cout<<"MOVE FLAG : "<<moveflag<<endl;
    __MUTI_TST_LOOP__
    {
        arr_tst[i].timepass++;
        if(arr_tst[i].timepass == arr_tst[i].state_n.state_dur)
        {
            arr_tst[i].state_n = state_trans(travel_graph,i);
            arr_tst[i].timepass = 0;
        }
    }
}
