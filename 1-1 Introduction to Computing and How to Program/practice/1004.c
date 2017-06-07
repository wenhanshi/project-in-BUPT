#include<stdio.h>
int main(void)
{
   int i=1;
   float a,sum=0;
   do
   {
   	scanf("%f",&a);
   	sum+=a;
   	i++;
   }
   while(i<=12);
   printf("$%.2f",sum/12);
   return 0;
}
  
  
