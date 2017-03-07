bool createBiTree_BUF(BiTree &T,char s[MAX],int &n)
{
	if(s[n])
	{
		if(s[n]=='#')
		{
			T=NULL;
			n++;
		}
		else
		{
			T=(treeNode*)malloc(sizeof(treeNode));
			T->data=s[n];
			n++;
			createBiTree_BUF(T->lc,s,n);
			createBiTree_BUF(T->rc,s,n);
		}
	}
	return 1;
}

bool createBiTree_BRK_BUF(BiTree &T,char s[MAX],int &n)
{
	char t[MAX];
	char *ht=t,*hs=s;
	while(*hs)
	{
		if( *hs=='#' || ( *hs>='A' && *hs<='Z' ) )
		{
			*ht++=*hs++;
		}
		else hs++;
	}
	*ht='\0';
	createBiTree_BUF(T,t,n);
	return 1;
}



bool blank(int x)
{
	if(x<0) return 0;
	else for(int i=1;i<=x;i++) printf("  ");
	return 1;
}


if(num>0)
		{//use string funcs to create next dlr,ldr
			if(num==strlen(dlr)-1)
			{
				T->rc=NULL;
				
			}
			else
			{
				
			}	
		}
		else if(num==0)
		{//can't use string funcs
				T->lc=NULL;
				
		}

