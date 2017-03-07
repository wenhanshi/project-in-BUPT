 #include<stdio.h>
 #define MAXLEN 255
 
 
 int main(void)
 {
 	char Stack[MAXLEN];
 	char ch;
 	int flag=1,p=0;
 	ch=getchar();
 	while(ch!='#'&&flag)
 	{
 		if(p==0&&(ch==')'||ch==']'||ch=='}'))
 		{
 			flag=0;
 			break;
		 }
 		if(ch=='('||ch=='['||ch=='{')
 		{
 			Stack[p]=ch;
 			p++;
		 }
		 else if(ch==')')
		 {
		 	if(Stack[p-1]!='(')
		 	{
		 		flag=0;
			 }
			 p--;
		 }
		 else if(ch==']')
		 {
		 	if(Stack[p-1]!='[')
		 	{
		 		flag=0;
			 }
			 p--;
		 }
		 else if(ch=='}')
		 {
		 	if(Stack[p-1]!='{') flag=0;
		 	p--;
		 }
		 else ;
		 ch=getchar();
	 }
	 printf(flag?"Yes\n":"No\n");
	 return 0;
 }
