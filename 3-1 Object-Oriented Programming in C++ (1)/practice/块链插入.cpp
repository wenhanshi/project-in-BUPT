// 块链结构的串插入
;
#define CHUNKSIZE 4
typedef struct Chunk{
	char ch[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct{
	Chunk* head,* tail;
	int curlen;
}LString;

bool getchPos(char ch,LString T,int& pos,Chunk*& pChunk)
{
	Chunk* curp=T.head;
	pChunk=NULL;
	while(!pChunk)
	{
		for(int i=0;i<=CHUNKSIZE;i++)
		{
			if(ch==curp->ch[i])
			{
				pos=i;
				pChunk=cur;
				return 1;
			} 
		 } 
		 curp=curp->next;
	}
	return 0;
 }
 
 bool makeChunk(LString& T,int pos,Chunk* pChunk)
 {
 	Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));
 	
 	for(int i=0;i<=CHUNKSIZE-1;i++)
 	{
 		if(i>pos) 
		 {
 			newChunk->ch[i]=pChunk->ch[i];
 			pChunk->ch[i]='#';
		 }
 		else newChunk->ch[i]='#';
	 }
	insertVal(pChunk,newChunk,T);
	return 1;
 }
 
 bool insertVal(Chunk* pChunk,Chunk* newChunk,LString& T)
 {
 	newChunk->next=pChunk->next;
 	pChunk->next=newChunk;
 	return 1;
 }
 
 bool concatTH(LString& T,LString S)
 {
 	T.tail->next=S.head;
 	return 1;
 }
 
 bool concatVal(LString& T,LString S,char ch)
 {
 	int pos;
 	Chunk* pChunk;
 	if(getchPos(ch,T,pos,pChunk))
 	{
 		if(pos==CHUNKSIZE-1)
 		{
 			insertVal(pChunk,S.head,T);
 			return 1;
		 }
		 else
		 {
		 	makeChunk(T,pos,pChunk);
		 	insertVal(pChunk,S.head,T);
		 	return 1;
		 }
	 }
	 else
	 {
	 	concatTH(T,S);
	 	return 1;
	 }
	 return 0;
 }
