#ifndef STRUCT&TYP_H_INCLUDED
#define STRUCT&TYP_H_INCLUDED
#include<string>
#include<QPainter>

#define MAX_CITIES 30
#define MAX_ROUTE 200
#define MAX_WEIGHT 8192
#define MAX_TST 5
#define MAX_QUEUE_NODE 1000000
#define __MUTI_TST_LOOP__ for(int i = 0 ; i <= MAX_TST-1 ; i++)

using namespace std;
enum STRATEGY
{
    MINICOST,
    MINITIME,
    MINICOST_LIMITIME
};

struct Edge
{
    int derive_time;
    int dur; // duration in one edge
    int derive_city;
    int dest_city;
    unsigned int cost;
    string number; // the name of edge
};
typedef struct Edge EDGE;
struct s_state // simtulation decision
{
    int city; // city_from
    int state_dur; // duration of such state_n
    bool ismove; // city == dest iff ismove == false
    int dest; // city_dest
};
typedef struct s_state S_STATE;
struct state_now // algorithm decision
{
    int time_now;
    int city_now;
};
typedef struct state_now STATE_NOW;
typedef struct{
	int cost;
	bool isFind;
	int pre_city;
	int chosen_edge;
}miniPath; // for DIJ
typedef struct
{
    int adjCity;
    int finalCost;
    int adj_chosen_edge;
}infoAdj; // for DIJ to decide adj city
struct stml // the set of chosen edges
{
    int arr_opEdge[MAX_ROUTE];
    int size_arr;
};
typedef struct stml STML;
struct queueNode // for BFS
{
    STATE_NOW state_now;
    int edge_from;
    STML route_stml;
    int total_time;
    int total_cost;
};
typedef queueNode QUEUE_NODE;
struct sim_para // the coordinate of tourist
{
    qreal x; // position
    qreal y;
    qreal dx; // speed
    qreal dy;
};
typedef sim_para SIM_PARA;
struct result
{
    int result_money;
    int result_time;
};
typedef struct result RESULT;
struct Tst // tourist
{
    int ID; // name
    S_STATE state_n;
    int timepass; // counter for state_dur
    STATE_NOW state_now;
    int mid[MAX_CITIES]; // cities in midway
    int size_mid; // how many
    int midflag; // consider the midway
    int lmt; // time limitation
    int strgy; // chosen strategy
    int dest; // destination
    RESULT res;
    STML _stml; // the set of chosen edges
    int e_now; // on which edge now
    SIM_PARA sp; // simultation parameters
    int moveflag; // for the state trans
};
typedef struct Tst TST;


#endif // STRUCT&TYP_H_INCLUDED
