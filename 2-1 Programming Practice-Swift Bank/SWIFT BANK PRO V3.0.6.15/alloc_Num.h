#ifndef			__ALLOC_NUM_H__
#define			__ALLOC_NUM_H__

void alloc_Num_Orient(void);//to alloc client under the orient strategy
void alloc_Num_BTW(void);//to alloc client under the By The Way strategy
void sort_Rest(void);//to sort the rest list

extern NORM_PTR cur_Norm_P;
extern NORM_PTR head_Norm_P;
 
extern VIP_PTR cur_VIP_P;
extern VIP_PTR head_VIP_P;

extern REST_PTR cur_Rest_P;
extern REST_PTR head_Rest_P;

extern WIN_PTR windows[MAXWIN];

extern int cur_Norm_Num;
extern int cur_VIP_Num;

#endif

