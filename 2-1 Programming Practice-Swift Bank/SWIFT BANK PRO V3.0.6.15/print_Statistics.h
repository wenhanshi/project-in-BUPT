#ifndef			__PRINT_STATISTICS_H__
#define			__PRINT_STATISTICS_H__

void print_Statistics(void);//to print the statistics message
void window_Statistics(STA_WIN_PTR,WIN_PTR);//to count the window's message
void universe_Statistics(WIN_PTR,int);//to count the univrse message
int is_Reach_Standard(STA_WIN_PTR);//to judge if the window has reach the standard

extern FILE* file_Statistics_P; 

extern STA_WIN_PTR sta_Windows[MAXWIN];
extern STA_ALL_PTR universe_P;

extern int strategy;

#endif

