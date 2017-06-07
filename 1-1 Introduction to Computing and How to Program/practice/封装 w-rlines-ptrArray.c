#include<stdio.h>
#include<string.h>
 
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

void readlines(char *lineptr[],int maxlines,int nlines)
{
	int len;
	char *p,line[MAXLEN];
	extern int getline(char [],int);
	for(int i=0;i<=nlines-1;i++)
	{
		len=getline(line,MAXLEN);
		p=malloc(len);
		if(p==NULL)
		{
			printf("Error:the buf is full.");
		}
		strcpy(p,line);
		lineptr[i]=p;
	}
}
int getline(char*line,int maxlen)
{
	char *begin=NULL,c;
	begin=line;
	while((c=getchar())!='\n')
	{
		*(line++)=c;
	}
	*line='\0';
	return line-begin;
}
void writelines(char *lineptr[], int nlines)
{
	for(int i=0;i<=nlines-1;i++)
	{
		printf("%s\n",lineptr[i]);
	}
}
void qsort(char *v[],int left,int right)
{
	
	int i,last;
	extern void swap(char *[],int,int);
	if(left>=right)
	{
		return ;
	}
	swap(v,left,(left+right)/2);
	last=left;
	for(i=left+1;i<=right;i++)
	{
		if(strcmp(v[i],v[left])<=0)
		{
			swap(v,++last,i);
		}
	}
	swap(v,left,last);
	qsort(v,left,last-1);
	qsort(v,last+1,right);
}
void swap(char *v[],int left,int right)
{
	char *temp=NULL;
	temp=v[left];
	v[left]=v[right];
	v[right]=temp;
}
int main(void)
{
	int nlines;
	scanf("%d",&nlines);
	getchar();
	readlines(lineptr,MAXLINES,nlines);
	qsort(lineptr,0,nlines-1);
	writelines(lineptr,nlines);
	return 0;	
}
