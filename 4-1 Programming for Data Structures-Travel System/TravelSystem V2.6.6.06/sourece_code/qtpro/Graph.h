#ifndef GRAPH_H
#define GRAPH_H
#include"struct&typ.h"
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<QString>
#include<QFile>
#define CITY_TYPE int



class Graph
{
private:
    int _mat[MAX_CITIES][MAX_ROUTE]; // incidence matrix
    void getAdj_Time(STATE_NOW state,int& num_AdjCity);
    void getAdj_Cost(STATE_NOW state,int& num_AdjCity);
    int getAdjNode(QUEUE_NODE tempNode);

public:
    Graph();
    Graph(QString& file_name); // init the graph from file
    string _arrCity[MAX_CITIES]; // array for cities
    EDGE _arrEdge[MAX_ROUTE]; // array for edges
    int DIJ_MiniTime(STATE_NOW state, int dest_city, STML &r_stml); // MINITIME strategy
    int DIJ_MiniCost(STATE_NOW state, int dest_city, STML &r_stml); // MINICOST strategy
    int MiniCost_TimeLimt(STATE_NOW state, int dest_city, unsigned int limtTime, STML &r_stml); // LIMIT stategy
    int DIJ_MiniTime(STATE_NOW state, int dest_city,int * arr_MidCity, int arr_size, STML &r_stml); // MIDWAY mode
    int DIJ_MiniCost(STATE_NOW state, int dest_city,int * arr_MidCity, int arr_size, STML &r_stml);
    int MiniCost_TimeLimt(STATE_NOW state, int dest_city, unsigned int limtTime, int * arr_MidCity, int arr_size, STML &r_stml);
    int getRealDur(STATE_NOW state,int e); // realcost = f ( STATE_NOW , EDGE_NOW )
    int getTimeUse(STML & r_stml , STATE_NOW state); // real timeuse = f ( STATE_NOW , SET( EDGE ) )
    int getMoneyUse(STML & r_stml); // money use = f( SET(EDGE) )
    void printMat(void);
    void printEdge(void);
};

#endif // GRAPH_H
