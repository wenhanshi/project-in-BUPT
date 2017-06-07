#include<stdio.h>

int i,j,k,l,m;

int check(int a){
	if (a=='A') 
		if (i=='E') return 1;
		else return 0;
	if (a=='B')
		if (j=='B') return 1;
		else return 0;
	if (a=='C')
		if (m=='A') return 1;
		else return 0;
	if (a=='D')
		if (i!='C') return 1;
		else return 0;
	if (a=='E')
		if (i=='D') return 1;
	    else return 0;
}

int main(){
	for (i='A';i<='E';i++)
		for (j='A';j<='D';j++)
			if (i!=j)
				for (k='A';k<='D';k++)
					if (k!=i&&k!=j)
						for (l='A';l<='E';l++)
							if (l!=i&&l!=j&&l!=k)
								for (m='A';m<='E';m++)
									if (m!=i&&m!=j&&m!=k&&m!=l)
										if (check(i)&&check(j)&&check(k)==0&&check(l)==0&&check(m)==0)
											printf("First:%c\nSecond:%c\nThird:%c\nFourth:%c\nFifth:%c\n",i,j,k,l,m);
	return 0; 
							
} 
