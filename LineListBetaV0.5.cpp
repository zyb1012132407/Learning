#include <stdio.h>
#include <cstdlib>
typedef struct{
	int *elem;
	int length;
}SqList;

typedef int Status;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

Status InitList_Sq(SqList &L){
	L.elem = new int[100];
	if(!L.elem)
		exit(1);
	L.length = 0;
	return OK;
}

void DestoryList(SqList &L){
	if(L.elem)
		delete[] L.elem;
}

void ClearList(SqList &L){
	L.length = 0;
}

int GetLength(SqList &L){
	return (L.length);
}

int IsEmpty(SqList &L){
	if(L.length == 0)
		return 1;
	else
		return 0;
}

int GetElem(SqList &L,int i,int &e){
	if(i < 1 || i > L.length)
		return ERROR;
	e=L.elem[i-1];
	return OK;
}

int LocateElem(SqList &L,int e){
	int i;
	for(i=0;i<L.length;i++)
		if(L.elem[i]==e)
			return i+1;
	return 0;
}

Status ListInsert_Sq(SqList &L,int i,int e){
	int j;
	if(i<1 || i>L.length+1)
		return ERROR;
	if(L.length==MAXSIZE)
		return ERROR;
	for(j=L.length-1;j>=i-1;j--){
		L.elem[j+1]=L.elem[j];
	L.elem[i-1]=e;
	++L.length;
	return OK;
	}
}

Status ListDelete_Sq(SqList &L,int i){
	int j;
	if((i<1) || (i>L.length))
		return ERROR;
	for(j=i;j<=L.length-1;j++)
		L.elem[j-1]=L.elem[j];
	--L.length;
	return OK;
}

int main(){
	SqList L;
	int e;
	printf("%d\n",InitList_Sq(L));
	L.elem[0] = 1;
	L.length=5;
	printf("%d\n",GetLength(L));
	printf("%d ",ListInsert_Sq(L,2,5));
	printf("%d\n",GetLength(L));
	printf("%d ",GetElem(L,1,e));
	printf("%d\n",L.elem[0]);
	printf("%d\n",GetLength(L));
	printf("%d ",ListDelete_Sq(L,1));
	printf("%d\n",GetLength(L));
	printf("%d\n",LocateElem(L,20));
	printf("%d\n",IsEmpty(L));
	ClearList(L);
	printf("%d\n",GetLength(L));
	
	return 0;
}
