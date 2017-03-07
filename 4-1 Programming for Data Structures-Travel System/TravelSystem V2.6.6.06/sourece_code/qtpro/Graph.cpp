#include<iostream>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<fstream>
#include<cstdlib>
#include<QFile>
#include<QTextStream>
#include"struct&typ.h"
#include"Graph.h"

using namespace std;

infoAdj arr_InfoAdj[MAX_CITIES]; // store the info of adj for DIJ
QUEUE_NODE arr_node[MAX_ROUTE]; // for BFS
int num_city = 0;
int num_route = 0;
extern Graph tg;

Graph::Graph()
{
    num_city = 6 ;
    num_route = 12 ;
    _arrEdge[0]={ 8 , 0 , 0 , 1 , 4 ,""};
    _arrEdge[1]={ 10 , 0 , 1 , 2 , 2,"" };
    _arrEdge[2]={ 11 , 0 , 1 , 2 , 3 ,""};
    _arrEdge[3]={ 7 , 0 , 0 , 2 , 9 ,""};
    _arrEdge[4]={12,0,2,3,4,""};
    _arrEdge[5]={14,0,3,4,2,""};
    _arrEdge[6]={15,0,3,4,3,""};
    _arrEdge[7]={11,0,2,4,9,""};
    _arrEdge[8]={16,0,4,5,2,""};
    _arrEdge[9]={17,0,4,5,13,""};
    _arrEdge[10]={16,0,4,5,7,""};
    _arrEdge[11]={13,0,2,5,15,""};
    for(int row=0;row<=num_city-1;row++)
    {
        for(int col=0;col<=num_route-1;col++)
        {
            if(_arrEdge[col].derive_city==row)
            {
                _mat[row][col]=-1;
            }
            else if(_arrEdge[col].dest_city==row)
            {
                _mat[row][col]=1;
            }
            else _mat[row][col]=0;
        }
    }
    for(int i=0;i<=num_city-1;i++)
    {
        _arrCity[i]="";
    }
}
Graph::Graph(QString& file_name)
{
    string cur_time = "", departure_city = "", arrive_city = "", number = "", price = "", lineString[1000] = "", duration = "";
    int departure_time = 0, arrive_time = 0;
    int count1 = 0, count2 = 0, m = 0, k = 0, flag = 0;
    for (k = 0; k < MAX_CITIES; k++) _arrCity[k] = "";
    QFile infile(file_name);
    if (infile.open(QIODevice::ReadOnly) == false)
        cout << "FILE ERROR!" <<endl;
    QTextStream stream(&infile);
    QString line;

    while (!stream.atEnd())
    {
        line = stream.readLine();
        lineString[count1] = line.toStdString();
        if(0 == lineString[count1].size()) continue;
        count1++;
    }
    infile.close();
    for(int i = 0; i < count1; i++)
    {
        //cout << "lineString:" << "No." << i << " " << lineString[i] << endl;
        if(0 == lineString[i].size()) continue;
        count2 = lineString[i].size();
        for(int j = 0; j < count2; j++)
        {
            if(lineString[i][j] == '#') m++;
            else continue;
        }
        int startIntex = 0;
        int nextIntex = lineString[i].find( " ", startIntex);
        number = lineString[i].substr( 0, nextIntex);

        startIntex = nextIntex + 1;
        nextIntex = lineString[i].find( ":", startIntex);
        cur_time = lineString[i].substr( startIntex, nextIntex-startIntex);
        departure_time = atoi(cur_time.c_str());

        startIntex = nextIntex + 1;
        nextIntex = lineString[i].find( " ", startIntex);
        cur_time = lineString[i].substr( startIntex, nextIntex-startIntex);
        _arrEdge[num_route].derive_time = departure_time;

        startIntex = nextIntex + 1;
        nextIntex = lineString[i].find( "#", startIntex);
        departure_city = lineString[i].substr( startIntex, nextIntex-startIntex);
        for (k = 0; k <= num_city; k++)
        {
            if (_arrCity[k] == departure_city)
            {
                _arrEdge[num_route].derive_city = k;
                break;
            }
        }
        if (k > num_city)
        {
            _arrCity[num_city] = departure_city;
            _arrEdge[num_route].derive_city = num_city;
            num_city++;
        }

        for(int j = 0; j < (m - 1) / 3; j++)
        {
            startIntex = nextIntex + 1;
            nextIntex = lineString[i].find( ":", startIntex);
            cur_time = lineString[i].substr( startIntex, nextIntex-startIntex);
            arrive_time = atoi(cur_time.c_str());
           // _arrEdge[num_route].derive_time = arrive_time;

            startIntex = nextIntex + 1;
            nextIntex = lineString[i].find( " ", startIntex);
            cur_time = lineString[i].substr( startIntex, nextIntex-startIntex);

            startIntex = nextIntex + 1;
            nextIntex = lineString[i].find( "#", startIntex);
            arrive_city = lineString[i].substr( startIntex, nextIntex-startIntex);
            for (k = 0; k < num_city; k++)
            {
                if (_arrCity[k] == arrive_city)
                {
                    _arrEdge[num_route].dest_city = k;
                    break;
                }
            }
            if (k >= num_city)
            {
                _arrCity[num_city] = arrive_city;
                _arrEdge[num_route].dest_city = num_city;
                num_city++;
            }

            startIntex = nextIntex + 1;
            nextIntex = lineString[i].find( "#", startIntex);
            duration = lineString[i].substr( startIntex, nextIntex-startIntex);
            _arrEdge[num_route].dur = atoi(duration.c_str());

            startIntex = nextIntex + 1;
            nextIntex = lineString[i].find( "#", startIntex);
            price = lineString[i].substr( startIntex, nextIntex-startIntex);
            _arrEdge[num_route].cost = atoi(price.c_str());

            _arrEdge[num_route].derive_time = departure_time;
            if ( flag == 1) _arrEdge[num_route].derive_city = _arrEdge[num_route - 1].dest_city;
            departure_city = arrive_city;
            departure_time = arrive_time;
            _arrEdge[num_route].number = number;
            flag = 1;
            num_route++;
        }
        m = 0;
        flag = 0;
    }
    for (int m = 0; m < num_route; m++)
    {
        cout << _arrEdge[m].cost << "\t" << _arrEdge[m].derive_city << "\t"
             << _arrEdge[m].dest_city << "\t" << _arrEdge[m].derive_time << "\t"
             << _arrEdge[m].dur << "\t" << _arrEdge[m].number << endl;
    }

    for (int m = 0; m < num_city; m++)
    {
        cout << m << " " << _arrCity[m] << endl;
    }

    for (int row = 0; row <= num_city - 1; row++)
    {
        for (int col = 0; col <= num_route - 1; col++)
        {
            if (_arrEdge[col].derive_city == row)
            {
                _mat[row][col] = -1;
            }
            else if (_arrEdge[col].dest_city == row)
            {
                _mat[row][col] = 1;
            }
            else _mat[row][col] = 0;
        }
    }
}
void Graph::printEdge(void)
{
    cout<<"ARR_EDGE:"<<endl;
    for(int e = 0 ; e <= num_route - 1 ; e++)
    {
        cout<<e<<": "<<_arrEdge[e].number<<" from:"
           <<_arrEdge[e].derive_city<<" to:"<<_arrEdge[e].dest_city<<" time:"
          <<_arrEdge[e].derive_time<<" dur:"<<_arrEdge[e].dur<<" cost:"<<_arrEdge[e].cost<<endl;
    }
    cout<<endl;
}

void printSTML(STML *p_stml)
{
    cout<<"STML:"<<endl;
    for(int e=0;e<=p_stml->size_arr-1;e++)
    {
        cout<<p_stml->arr_opEdge[e]<<"->";
    }
    cout<<"#"<<endl;
}
void printSTML(STML &r_stml)
{
    cout<<"STML:"<<endl;
    for(int e=0;e<=r_stml.size_arr-1;e++)
    {
        cout<<r_stml.arr_opEdge[e]<<"->";
    }
    cout<<"#"<<endl;
}
void getEdge(STML *p_stml,miniPath *VT,int dept,int dest)
{
    int cityCount=0;
    for(int c=dest;c!=dept;c=VT[c].pre_city)
    {
        cityCount++;
    }
    p_stml->size_arr=cityCount;
    for(int i=cityCount-1;i>=0;i--)
    {
        p_stml->arr_opEdge[i]=VT[dest].chosen_edge;
        dest=VT[dest].pre_city;
    }
}
void printArr(infoAdj* arr,int arr_size)
{
    cout<<"adj->"<<endl;
    for(int i=0;i<=arr_size-1;i++)
    {
        cout<<arr[i].adjCity<<":"<<arr[i].finalCost<<" ";
    }
    cout<<endl;
}
void printVT(miniPath* VT,int arr_size)
{
    cout<<"VT->[city/cost/isFind/pre/edgechosen]"<<endl;
    for(int i=0;i<=arr_size-1;i++)
    {
        cout<<i<<"/"<<VT[i].cost<<"/"<<VT[i].isFind<<"/"<<VT[i].pre_city<<"/"<<VT[i].chosen_edge<<"  ";
    }
    cout<<endl;
}
void printArrNode(QUEUE_NODE *arr_node,int arr_size)
{
    for(int i = 0;i<=arr_size-1;i++)
    {
        cout<<"node:"<<i<<endl;
        cout<<"edge_from->"<<arr_node[i].edge_from<<endl;
        cout<<"city:time->"<<arr_node[i].state_now.city_now<<":"<<arr_node[i].state_now.time_now<<endl;
        cout<<"total cost:time->"<<arr_node[i].total_cost<<":"<<arr_node[i].total_time<<endl;
        cout<<"stml in nodearr->"<<endl;
        printSTML(arr_node[i].route_stml);
    }
}
int findMiniCost(miniPath *VT)
{
    int miniCost=MAX_WEIGHT;
    int flag=0;
    int mini_v=-1;
    for(int i=0;i<=num_city-1;i++)
    {
        if(!VT[i].isFind&&VT[i].cost<miniCost)
        {
            mini_v=i;
            miniCost=VT[i].cost;
            flag=1;
        }
    }
    if(!flag) return -1;
    return mini_v;
}

int Graph::getRealDur(STATE_NOW state,int e) // real dur can be calculated by state and dur for edge
{
    int realDur;
    if(_arrEdge[e].derive_city!=state.city_now) return -1;
    else
    {
        if(_arrEdge[e].derive_time-state.time_now>=0)
        {
            realDur=_arrEdge[e].derive_time-state.time_now+_arrEdge[e].dur;
        }
        else
        {
            //cout<<">24here"<<endl;
            realDur=_arrEdge[e].derive_time-state.time_now+_arrEdge[e].dur+24;
        }
        return realDur;
    }
}

void Graph::getAdj_Time(STATE_NOW state,int& num_AdjCity)//give you a state , try to find out all the adj with state city in some alo
{
    int num_count=0;
    int flag=0;
    infoAdj temp_arr_InfoAdj[MAX_CITIES];
    for(int e=0;e<=num_route-1;e++)
    {
        if(_mat[state.city_now][e]==-1)//find the adj
        {
            flag=0;
            for(int c=0;c<=num_count-1;c++)
            {
                if(temp_arr_InfoAdj[c].adjCity==_arrEdge[e].dest_city)
                {
                    flag = 1;
                    if(temp_arr_InfoAdj[c].finalCost>getRealDur(state,e))
                    {
                        temp_arr_InfoAdj[c].finalCost=getRealDur(state,e);
                        temp_arr_InfoAdj[c].adj_chosen_edge=e;
                        break;
                    }
                }
            }
            if(!flag)
            {
                temp_arr_InfoAdj[num_count].adjCity=_arrEdge[e].dest_city;
                temp_arr_InfoAdj[num_count].finalCost=getRealDur(state,e);
                temp_arr_InfoAdj[num_count].adj_chosen_edge=e;
                num_count++;
            }
        }
    }
    num_AdjCity=num_count;
    for(int i=0;i<=num_count-1;i++)
    {
        arr_InfoAdj[i]=temp_arr_InfoAdj[i];
    }
}
int Graph::DIJ_MiniTime(STATE_NOW state, int dest_city, STML &r_stml)
{
    miniPath VT[MAX_CITIES];//store the state for city if find and cost,vertex terminal
    int mini_v=0; // for DIJ
    int num_AdjCity; // for count arr_info
    int start_v=state.city_now;
    int state_t = state.time_now;
    int dist;
    r_stml.size_arr = 0;
    // init process
    for(int i=0;i<=num_city-1;i++)
    {
        VT[i].cost = MAX_WEIGHT;
        VT[i].isFind = false;
        VT[i].pre_city = -1;
        VT[i].chosen_edge = -1;
    }
    VT[start_v].isFind=true;
    VT[start_v].cost=0;

    getAdj_Time(state,num_AdjCity);
    for(int c=0;c<=num_AdjCity-1;c++)
    {
        VT[arr_InfoAdj[c].adjCity].cost=arr_InfoAdj[c].finalCost;
        VT[arr_InfoAdj[c].adjCity].pre_city=state.city_now;
        VT[arr_InfoAdj[c].adjCity].chosen_edge=arr_InfoAdj[c].adj_chosen_edge;
    }
    printArr(arr_InfoAdj,num_AdjCity);
    printVT(VT,num_city);
    //end initial
    while(1)
    {
        if(VT[dest_city].isFind) break;
        mini_v=findMiniCost(VT);
        state.city_now=mini_v;
        state.time_now = (state_t + VT[mini_v].cost)%24;
        //cout<<"mini_v:time->"<<mini_v<<":"<<state.time_now<<endl;
        if(mini_v<0)
            break;
        else
        {
            VT[mini_v].isFind=true;
            getAdj_Time(state,num_AdjCity);
            //printArr(arr_InfoAdj,num_AdjCity);
            for(int c=0;c<=num_AdjCity-1;c++)
            {	//c is adj to mini_v
                if(!VT[arr_InfoAdj[c].adjCity].isFind)
                {
                    dist=arr_InfoAdj[c].finalCost;
                    //cout<<"dist"<<dist<<endl;
                    if(VT[mini_v].cost+dist<VT[arr_InfoAdj[c].adjCity].cost)
                    {
                        VT[arr_InfoAdj[c].adjCity].cost=VT[mini_v].cost+dist;
                        VT[arr_InfoAdj[c].adjCity].pre_city=mini_v;
                        VT[arr_InfoAdj[c].adjCity].chosen_edge=arr_InfoAdj[c].adj_chosen_edge;
                    }
                }
            }
            printVT(VT,num_city);
        }
    }
    if(VT[dest_city].isFind == 0)
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }
    STML* p_stml=&r_stml;
    getEdge(p_stml,VT,start_v,dest_city);
    return VT[dest_city].cost;
}
void Graph::getAdj_Cost(STATE_NOW state,int& num_AdjCity)//give you a state , try to find out all the adj with state city in some alo
{
    // similar to DIJ for simple graph
    // to slove the dual edges for c ( e1 , e2 ... )
    // only need to do is pick up the lowest e
    // which is the only possible for c to adj

    int num_count=0;
    int flag=0;
    infoAdj temp_arr_InfoAdj[MAX_CITIES];
    for(int e=0;e<=num_route-1;e++)
    {
        if(_mat[state.city_now][e]==-1)//find the adj
        {
            flag=0;
            for(int c=0;c<=num_count-1;c++)
            {
                if(temp_arr_InfoAdj[c].adjCity==_arrEdge[e].dest_city)
                {
                    flag =1;
                    if(temp_arr_InfoAdj[c].finalCost>_arrEdge[e].cost)
                    {
                        temp_arr_InfoAdj[c].finalCost=_arrEdge[e].cost;
                        temp_arr_InfoAdj[c].adj_chosen_edge=e;
                        break;
                    }
                }
            }
            if(!flag)
            {
                temp_arr_InfoAdj[num_count].adjCity=_arrEdge[e].dest_city;
                temp_arr_InfoAdj[num_count].finalCost=_arrEdge[e].cost;
                temp_arr_InfoAdj[num_count].adj_chosen_edge=e;
                num_count++;
            }
        }
    }
    num_AdjCity=num_count;
    for(int i=0;i<=num_count-1;i++)
    {
        arr_InfoAdj[i]=temp_arr_InfoAdj[i];
    }
}
int Graph::getTimeUse(STML & r_stml,STATE_NOW state)
{
    int timeUse = 0;
    int realDur;
    if(r_stml.size_arr == 0)
        return MAX_WEIGHT;
    else
    {
        for(int e = 0 ;e<=r_stml.size_arr-1;e++)
        {
            realDur = getRealDur(state,r_stml.arr_opEdge[e]);
            timeUse += realDur;
            state.city_now = _arrEdge[r_stml.arr_opEdge[e]].dest_city;
            state.time_now = ( state.time_now + realDur )%24;
        }
    }
    return timeUse;
}
int Graph::getMoneyUse(STML &r_stml)
{
    int moneyUse = 0;
    if(r_stml.size_arr == 0)
        return MAX_WEIGHT;
    else
    {
        for(int e = 0 ;e<=r_stml.size_arr-1;e++)
            moneyUse += _arrEdge[r_stml.arr_opEdge[e]].cost;
    }
    return moneyUse;
}

int Graph::DIJ_MiniCost(STATE_NOW state, int dest_city, STML &r_stml)
{
    // alo is based on DIJ for simple graph
    // for the dual edges in such graph
    // 1. calculate the realdur for e
    // 2. for e related such c , pick up the possible e

    miniPath VT[MAX_CITIES];//store the state for city if find and cost,vertex terminal
    int mini_v=0;//for DIJ
    int num_AdjCity;//for count arr_info
    int start_v=state.city_now;//initial
    int dist;
    r_stml.size_arr = 0;
    //initial
    for(int i=0;i<=num_city-1;i++)
    {
        VT[i].cost = MAX_WEIGHT;
        VT[i].isFind = false;
        VT[i].pre_city = -1;
        VT[i].chosen_edge = -1;
    }
    VT[start_v].isFind=true;
    VT[start_v].cost=0;
    getAdj_Cost(state,num_AdjCity);
    for(int c=0;c<=num_AdjCity-1;c++)
    {
        VT[arr_InfoAdj[c].adjCity].cost=arr_InfoAdj[c].finalCost;
        VT[arr_InfoAdj[c].adjCity].pre_city=state.city_now;
        VT[arr_InfoAdj[c].adjCity].chosen_edge=arr_InfoAdj[c].adj_chosen_edge;
    }
    //printArr(arr_InfoAdj,num_AdjCity);
    //printVT(VT,MAX_CITIES);
    //end initial
    while(1)
    {
        if(VT[dest_city].isFind) break;
        mini_v=findMiniCost(VT);
        state.city_now=mini_v;
        //cout<<"mini_v:"<<mini_v<<endl;
        if(mini_v<0) break;
        else
        {
            VT[mini_v].isFind=true;
            getAdj_Cost(state,num_AdjCity);
            //printArr(arr_InfoAdj,num_AdjCity);
            for(int c=0;c<=num_AdjCity-1;c++)
            {	//c is adj to mini_v
                if(!VT[arr_InfoAdj[c].adjCity].isFind)
                {
                    dist=arr_InfoAdj[c].finalCost;
                    //cout<<"dist"<<dist<<endl;
                    if(VT[mini_v].cost+dist<VT[arr_InfoAdj[c].adjCity].cost)
                    {
                        VT[arr_InfoAdj[c].adjCity].cost=VT[mini_v].cost+dist;
                        VT[arr_InfoAdj[c].adjCity].pre_city=mini_v;
                        VT[arr_InfoAdj[c].adjCity].chosen_edge=arr_InfoAdj[c].adj_chosen_edge;
                    }
                }
            }
            //printVT(VT,num_city);
        }
    }
    if(VT[dest_city].isFind == 0)
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }
    STML* p_stml=&r_stml;
    getEdge(p_stml,VT,start_v,dest_city);
    return VT[dest_city].cost;
}
void Graph::printMat(void)
{
    cout<<"_mat:"<<endl;
    for(int row=0;row<=num_city-1;row++)
    {
        for(int col=0;col<=num_route-1;col++)
        {
            cout<<_mat[row][col]<<" ";
        }
        cout<<endl;
    }
    for(int i = 0; i <= num_city - 1; i++)
    {
        cout << i <<  _arrCity[i] << endl;
    }
}
bool need_cutNode(QUEUE_NODE tempNode,int arr_node_size ,int e)
{
    for(int n = 0;n<=arr_node_size - 1;n++)
    {
        if(arr_node[n].state_now.city_now == tempNode.state_now.city_now
                && arr_node[n].total_cost < tempNode.total_cost + tg._arrEdge[e].cost
                && arr_node[n].total_time < tempNode.total_time + tg.getRealDur(tempNode.state_now,e))
            return true;
    }
    return false;
}

int Graph::getAdjNode(QUEUE_NODE tempNode)
{
    int arr_node_size = 0;
    int stml_size;
    for(int e = 0; e <= num_route - 1; e ++)
    {
        if(_mat[tempNode.state_now.city_now][e] == -1)
        {
            for(int c = 0 ;c<=num_city-1 ;c++)
            {
                if(_mat[c][e] == 1
                        /*&& c != _arrEdge[tempNode.edge_from].derive_city*/
                        && !need_cutNode(tempNode,arr_node_size,e)) // find out the adj edges
                {

                    //cout<<"c:e->"<<c<<":"<<e<<endl;
                    arr_node[arr_node_size].state_now.city_now = c;
                    arr_node[arr_node_size].state_now.time_now = (tempNode.state_now.time_now + getRealDur(tempNode.state_now,e))%24;
                    arr_node[arr_node_size].edge_from = e;
                    arr_node[arr_node_size].total_cost = tempNode.total_cost + _arrEdge[e].cost;
                    arr_node[arr_node_size].total_time = tempNode.total_time + getRealDur(tempNode.state_now,e);
                    stml_size = tempNode.route_stml.size_arr;
                    memcpy(arr_node[arr_node_size].route_stml.arr_opEdge,tempNode.route_stml.arr_opEdge,stml_size*sizeof(int));
                    arr_node[arr_node_size].route_stml.arr_opEdge[stml_size] = e;
                    arr_node[arr_node_size].route_stml.size_arr = stml_size + 1;
                    arr_node_size++;
                    break;
                }
            }
        }
    }
    return arr_node_size;
}
int Graph::MiniCost_TimeLimt(STATE_NOW state, int dest_city, unsigned int limtTime, STML &r_stml)
{
    // based on the alo of BFS
    // use cut off for following situations
    // to consider all situations , when pushing the queuenode
    // every e for c is needed to consider
    // which means , each node can be pushed in queue for more than once

    queue<QUEUE_NODE> q;
    int miniMoney = MAX_WEIGHT;
    int arr_node_size = 1;
    int max_queue_node = 1;
    QUEUE_NODE tempNode;
    tempNode.edge_from = -1;
    tempNode.route_stml.size_arr = 0;
    tempNode.state_now = state;
    tempNode.total_time = 0;
    tempNode.total_cost = 0;
    r_stml.size_arr = 0;

    int pre_result = DIJ_MiniTime(state,dest_city,r_stml);
    cout<<"PRE-TIME:"<<pre_result<<endl;
    if(pre_result > limtTime) // do such pre-work for empty result
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }

    q.push(tempNode);
    while(!q.empty())
    {
        tempNode=q.front();
        q.pop(); // deal with the tempnode ,find adjs for tempnode
        max_queue_node -- ;
        if(tempNode.total_time > limtTime || tempNode.total_cost > miniMoney); // cut off path
            //cout<<"cut off!!!"<<endl;
        else if (tempNode.state_now.city_now == dest_city)
        {
            if(tempNode.total_cost < miniMoney) // update the path
            {
                miniMoney = tempNode.total_cost;
                r_stml = tempNode.route_stml;
                //cout<<"---ONE PATH HAS BEEN CHOSEN."<<endl;
            }
        }
        else
        {
            arr_node_size=getAdjNode(tempNode);
            //cout<<"arr_node_size: "<<arr_node_size<<endl;
            for(int n=0;n<=arr_node_size-1;n++)
            {
               //cout<<"push:"<<max_queue_node<<endl;
               max_queue_node ++;
               if(max_queue_node > MAX_QUEUE_NODE)
               {
                   cout<<"BAD ALLOC!"<<endl;
                   goto jump;
               }
               q.push(arr_node[n]); // push the related edges for tempnode
            }
            //printArrNode(arr_node,arr_node_size);
        }
    }
    cout<<"end"<<endl;
    jump:
    if(miniMoney == MAX_WEIGHT)
        r_stml.size_arr = 0;
    return miniMoney;
}
int Graph::DIJ_MiniTime(STATE_NOW state, int dest_city,int * arr_MidCity, int arr_size, STML &r_stml)
{
    // overwrite DIJ_MiniTime
    // construct array of temp_city
    // use DIJ_MiniTime for each two cities
    // orderd cities for alo
    int temp_city[MAX_CITIES];
    STML temp_stml;
    int minitime = MAX_WEIGHT;
    int final_minitime = 0;
    int p = 0;//point to where to start
    r_stml.size_arr = 0;
    temp_stml.size_arr = 0;
    temp_city[0] = state.city_now;
    for(int c = 1 ; c <= arr_size ; c++)
        temp_city[c] = arr_MidCity[c - 1];
    temp_city[arr_size + 1] = dest_city;
    for(int c = 1 ; c <= arr_size + 1 ; c++)
    {
        minitime = DIJ_MiniTime(state,temp_city[c],temp_stml);
        //printSTML(temp_stml);
        if(minitime == MAX_WEIGHT) break;
        final_minitime += minitime;
        state.time_now = (state.time_now + getTimeUse(temp_stml,state))%24 ;
        state.city_now = temp_city[c];
        //cout<<"NOW STATE:NOW TIME->"<<state.time_now<<":"<<state.city_now<<endl;
        memcpy(&r_stml.arr_opEdge[p],temp_stml.arr_opEdge,temp_stml.size_arr*sizeof(int));
        r_stml.size_arr += temp_stml.size_arr;
        p += temp_stml.size_arr;
    }
    if(minitime == MAX_WEIGHT)
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }
    return final_minitime;
}
int Graph::DIJ_MiniCost(STATE_NOW state, int dest_city,int * arr_MidCity, int arr_size, STML &r_stml)
{
    // similar to overwritten DIJ_MiniTime

    int temp_city[MAX_CITIES];
    STML temp_stml;
    int minicost = MAX_WEIGHT;
    int final_minicost = 0;
    int p = 0; // point to where to start
    r_stml.size_arr = 0;
    temp_stml.size_arr = 0;
    temp_city[0] = state.city_now;
    for(int c = 1 ; c <= arr_size ; c++)
        temp_city[c] = arr_MidCity[c - 1];
    temp_city[arr_size + 1] = dest_city;
    for(int c = 1 ; c <= arr_size + 1 ; c++)
    {
        minicost = DIJ_MiniCost(state,temp_city[c],temp_stml);
        if(minicost == MAX_WEIGHT) break;
        final_minicost += minicost;
        state.time_now = (state.time_now + getTimeUse(temp_stml,state))%24 ;
        state.city_now = temp_city[c];
        memcpy(&r_stml.arr_opEdge[p],temp_stml.arr_opEdge,temp_stml.size_arr*sizeof(int));
        r_stml.size_arr += temp_stml.size_arr;
        p += temp_stml.size_arr;
    }
    if(minicost == MAX_WEIGHT)
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }
    return final_minicost;
}
bool isMatch(int * arr_MidCity,int arr_midsize,STML &r_stml)
{
    int p_mid = 0;
    for(int e = 0;e<=r_stml.size_arr-1;e++)
    {
        if(p_mid == arr_midsize) break;
        if(tg._arrEdge[r_stml.arr_opEdge[e]].dest_city == arr_MidCity[p_mid]) p_mid++;
    }
    if(p_mid == arr_midsize) return true;
    //cout<<"false"<<endl;
    return false;
}
int Graph::MiniCost_TimeLimt(STATE_NOW state, int dest_city, unsigned int limtTime, int * arr_MidCity, int arr_size, STML &r_stml)
{
    // based on the alo of BFS
    // use cut off for following situations
    // to consider all situations , when pushing the queuenode
    // every e for c is needed to consider
    // which means , each node can be pushed in queue for more than once

    queue<QUEUE_NODE> q;
    int miniMoney = MAX_WEIGHT;
    int arr_node_size = 1;
    int max_queue_node = 1;
    QUEUE_NODE tempNode;
    tempNode.edge_from = -1;
    tempNode.route_stml.size_arr = 0;
    tempNode.state_now = state;
    tempNode.total_time = 0;
    tempNode.total_cost = 0;
    r_stml.size_arr = 0;

    int pre_result = DIJ_MiniTime(state,dest_city,arr_MidCity,arr_size,r_stml);
    cout<<"PRE-TIME:"<<pre_result<<endl;
    if(pre_result > limtTime)
    {
        r_stml.size_arr = 0;
        return MAX_WEIGHT;
    }

    q.push(tempNode);
    while(!q.empty())
    {
        tempNode=q.front();
        q.pop(); // deal with the tempnode ,find adjs for tempnode
        max_queue_node -- ;
        if(tempNode.total_time > limtTime || tempNode.total_cost > miniMoney); // cut off path
            //cout<<"cut off!!!"<<endl;
        else if (tempNode.state_now.city_now == dest_city)
        {
            if(tempNode.total_cost < miniMoney && isMatch(arr_MidCity,arr_size,tempNode.route_stml)) // update the path
            {
                miniMoney = tempNode.total_cost;
                r_stml = tempNode.route_stml;
                //cout<<"---ONE PATH HAS BEEN CHOSEN."<<endl;
            }
        }
        else
        {
            arr_node_size=getAdjNode(tempNode);
            //cout<<"arr_node_size: "<<arr_node_size<<endl;
            for(int n=0;n<=arr_node_size-1;n++)
            {
               //cout<<"push:"<<max_queue_node<<endl;
               max_queue_node ++;
               if(max_queue_node > MAX_QUEUE_NODE)
               {
                   cout<<"BAD ALLOC!"<<endl;
                   goto jump;
               }
               q.push(arr_node[n]); // push the related edges for tempnode
            }
            //printArrNode(arr_node,arr_node_size);
        }
    }
    cout<<"end"<<endl;
    jump:
    if(miniMoney == MAX_WEIGHT)
        r_stml.size_arr = 0;
    return miniMoney;
}

