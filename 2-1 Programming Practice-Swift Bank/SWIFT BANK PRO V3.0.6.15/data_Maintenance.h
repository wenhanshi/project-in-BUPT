#ifndef			__DATA_MAINTENANCE_H__
#define    		__DATA_MAINTENANCE_H__

void data_Maintenance(void);//to maintain the VIP information
void save_Information(void);//to save the updated VIP information
void add_Information(void);//to add new a VIP information
void modify_Information(void);//to modify the information of a VIP client
void search_Information(void);//to search a VIP's information
void delete_Information(void);//move out a VIP client from the VIP data
void print_Information(void);//print all of the VIP information 
void initialize_Information(void);//to initialize the VIP information
int enter_Choice(void);   

extern INFOR_PTR head_Infor_P;
extern INFOR_PTR cur_Infor_P;

extern FILE* fPtr;
extern int VIP_sum;

#endif

