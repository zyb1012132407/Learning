#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct CNode{
	ElemType data;
	struct CNode *next;
}CNode,*CLinkList;


Status initCList_L(CLinkList &L){		//初始化链表 
	L = new CNode;
	L->next = L;
	return OK;
};

int findCListLength_L(CLinkList L){		//统计长度 
	CLinkList target;
	target = L;
	int i;
	for(i = 1;target->next != L;i++){
		target = target->next;
	}
	return i-1;
}

Status findLocatedElem_L(CLinkList L,ElemType &e,int i){	//取值 
	CLinkList target;
	int j = 1;
	if(i > findCListLength_L(L)){
		return ERROR;
	}
	for(target = L;target->next != L;target = target->next);
	for(target = target->next;j <= i;j++){
		target = target->next;
	}
	e = target->data;
	return OK;
}

Status findLocation_L(CLinkList L,ElemType e,int &i){	//定位 
	CLinkList target;
	i = 1;
	for(target = L;target->next != L;target = target->next);
	for(target = target->next->next;(target->data != e) && (target->next != L);i++){
		target = target->next;
	}
	if(target->data == e){
		return OK;
	}else{
		return ERROR;
	}
}

Status insertCListRandom_L(CLinkList &L,ElemType t){	//尾插 
	CLinkList target;
	CLinkList tmp;
	for(target = L;target->next != L;target = target->next);
	tmp = new CNode;
	tmp->data = t;
	tmp->next = L;
	target->next = tmp;
	return OK; 
}

Status insertCList_L(CLinkList &L,int i,ElemType t){	//定点插入数值 
	CLinkList target;
	CLinkList tmp;
	int j = 1;
	if(i >findCListLength_L(L)+1){
		return ERROR;
	}else if( i == findCListLength_L(L)){
		if(insertCListRandom_L(L,t)){
			return OK;
		}else{
			return ERROR;
		}
	}
	for(target = L;target->next != L;target = target->next);
	for(;j <= i;j++){
		target = target->next;
	}
	tmp = new CNode;
	tmp->data = t;
	tmp->next = target->next;
	target->next = tmp;
	return OK;
}

Status deleteElem_L(CLinkList &L,int i){////////////删除元素 未完成 
	CLinkList target;
	CLinkList tmp;
	int j = 1;
	if(i > findCListLength_L(L) || i < 1){
		return ERROR;
	}
	if(i == 1){
		for(target = L;target->next != L;target = target->next);
		tmp = L;
		L = L->next;
		target->next = L;
		free(tmp);
		return OK;
	}else{
		for(target = L;target->next != L;target = target->next);
		for(;j<i+1;j++){
			target = target->next;
		}
		tmp = new CNode;
		tmp = target->next;
		target->next = tmp->next;
		free(tmp);
		return OK;
	}
	
	
	
} 

void showAll(CLinkList L){
	CLinkList target;
	for(target = L;target->next != L;target = target->next);
	for(target = target->next->next;target != L;target = target->next){
		printf("%d ",target->data);
	}
	printf("\n");
}

Status badTest(CLinkList L){	//测试链表是否正常循环 
	CLinkList target;
	for(target = L;target->next != NULL;target = target->next);
	return OK;
}

int main(){
	CLinkList L;
	ElemType e=11;
	printf("%d\n",initCList_L(L));
	printf("%d\n",insertCListRandom_L(L,1));
	printf("%d\n",insertCListRandom_L(L,2));
	printf("%d\n",insertCListRandom_L(L,3));
//	printf("%d\n",findCListLength_L(L));
//	printf("------\n");
//	printf("%d\n",e);
//	printf("%d\n",findLocation_L(L,100,e));
//	printf("%d\n",e);
	printf("------\n");
	printf("%d\n",findLocation_L(L,1,e));
	printf("%d\n",e);
	printf("------\n");
	printf("%d\n",findLocation_L(L,2,e));
	printf("%d\n",e);
	printf("------\n");
	printf("%d\n",findLocation_L(L,3,e));
	printf("%d\n",e);
	printf("------\n");
	showAll(L);
	printf("------\n");
	printf("%d\n",deleteElem_L(L,1));
	printf("%d\n",findCListLength_L(L));
	showAll(L);
	printf("------\n");
	printf("%d\n",findLocation_L(L,1,e));
	printf("%d\n",e);
	printf("------\n");
	printf("%d\n",findLocation_L(L,2,e));
	printf("%d\n",e);
	printf("------\n");
	printf("%d\n",findLocation_L(L,3,e));
	printf("%d\n",e);
	return 0;
}
