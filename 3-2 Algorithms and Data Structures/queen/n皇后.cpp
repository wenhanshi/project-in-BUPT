#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

typedef struct{
    int x;
	int y;		
}chessman;

int whetherKill(chessman q1,chessman q2){
	if(q1.y==q2.y||q1.x==q2.x)return 1;
	if(q1.x-q2.x==q1.y-q2.y)return 1;
	if(q1.x-q2.x==q2.y-q1.y)return 1;
	return 0;
}

int compare(chessman a,chessman b){
	return a.x<b.x;
}

void Transpose(chessman *ptr,chessman *ptr2,int n){
	int i;
	for(i=1;i<=n;i++){
		ptr2[i].x=ptr[i].y;
		ptr2[i].y=ptr[i].x;
	}
	sort(ptr2+1,ptr2+n+1,compare);
}

int whetherMirror(int n,chessman *ptr,int method){
	ifstream file("Queen.txt");
	int i,flag=1,j=0;
	char ch;
	chessman *ptr1,*ptr2;
	ptr1=new chessman[n+1];
	ptr2=new chessman[n+1];
	while(flag&&j<method){
		for(i=1;i<=n;i++){
		    file>>ch>>ptr1[i].x>>ch>>ptr1[i].y>>ch;
	    }
	    file.get(ch);
	    Transpose(ptr,ptr2,n);
	    for(i=1;i<=n;i++){
		    if(ptr[n+1-i].y!=ptr1[i].y)break;
		    else if(i==n)flag=0;
    	}
    	for(i=1;flag&&i<=n;i++){
	    	if(ptr[i].y+ptr1[i].y!=n+1)break;
	    	else if(i==n)flag=0;	
    	}
    	for(i=1;flag&&i<=n;i++){
	    	if(ptr[n+1-i].y+ptr1[i].y!=n+1)break;
	    	else if(i==n)flag=0;	
    	}
    	for(i=1;flag&&i<=n;i++){
    		if(ptr1[i].y!=ptr2[i].y)break;
	    	else if(i==n)flag=0;	
    	}
    	for(i=1;flag&&i<=n;i++){
	    	if(ptr1[n+1-i].y!=ptr2[i].y)break;
	    	else if(i==n)flag=0;
    	}
    	for(i=1;flag&&i<=n;i++){
    		if(ptr1[i].y+ptr2[i].y!=n+1)break;
     		else if(i==n)flag=0;	
    	}
    	for(i=1;flag&&i<=n;i++){
	    	if(ptr1[n+1-i].y+ptr2[i].y!=n+1)break;
		    else if(i==n)flag=0;	
	    }
	    j++;
	}
	delete []ptr1;
	delete []ptr2;
	file.close();
	return flag;
}

void outputQ(chessman *ptr,int n,ofstream &file){	
	int i;
	for(i=1;i<=n;i++){
		file<<"("<<ptr[i].x<<","<<ptr[i].y<<")";
	}
	file<<endl;
}

void Queen(int n,int row,chessman *ptr,int &method,int mirror,ofstream &file){
	if(row==n+1){
		if(mirror||whetherMirror(n,ptr,method)){
			outputQ(ptr,n,file);
			method++;
		}		
	}
	else{
		int i,j,flag=1;
		for(i=1;i<=n;i++){
			chessman Q;
			flag=1;
			Q.x=row,Q.y=i;
			for(j=1;j<row;j++){
				if(whetherKill(ptr[j],Q))flag=0;
			}
			if(flag){
				ptr[row]=Q;
				Queen(n,row+1,ptr,method,mirror,file);
			}
		}
	}	
}



int main(){
	int n,method=0,mirror;
	cout<<"Please input the size of chessboard:";
	cin>>n;
	cout<<"Want to have the mirror example? 1---yes  0---no"<<endl;
	cin>>mirror;
	if(mirror)mirror=1;
	chessman *ptr;
	ptr=new chessman[n+1];
	ofstream file("Queen.txt");
	Queen(n,1,ptr,method,mirror,file);
	cout<<"There is "<<method<<" methods."<<endl;
	cout<<"The answer is in file<Queen>."<<endl;
	delete []ptr;
	file.close();
	system("pause");
	return 0;
}
