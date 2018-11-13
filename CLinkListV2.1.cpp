/*
	Title:ѭ������ļ���ϰ
	Timeline:2018.9.30
	Owner: ���ܲ�
	Details:
		9.30����
			1�����ѭ��������������Ĵ�������ԡ�(�ѽ����
			2��controller�����Ĵ��������ڽ���� 

*/ 











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

int InitList = 0;


Status initCList_L(CLinkList &L){		//��ʼ������ 
	L = new CNode;
	L->next = L;
	return OK;	
};

int findCListLength_L(CLinkList L){		//ͳ�Ƴ��� 
	CLinkList target;
	target = L;
	int i;
	for(i = 0;target->next != L;i++){
		target = target->next;
	}
	return i;
}

Status findLocatedElem_L(CLinkList L,int i,ElemType &e){	//ȡֵ 
	CLinkList target;
	int j = 1;
	if(i > findCListLength_L(L)){
		return ERROR;
	}
	for(target = L;target->next != L;target = target->next);
	for(target = target->next->next;j < i;j++){
		target = target->next;
	}
	e = target->data;
	return OK;
}

Status findLocation_L(CLinkList L,int &i,ElemType e){	//��λ 
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

Status insertCListRandom_L(CLinkList &L,ElemType t){	//β�� 
	CLinkList target;
	CLinkList tmp;
	for(target = L;target->next != L;target = target->next);
	tmp = new CNode;
	tmp->data = t;
	tmp->next = L;
	target->next = tmp;
	return OK; 
}

Status insertCList_L(CLinkList &L,int i,ElemType t){	//���������ֵ 
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

Status deleteElem_L(CLinkList &L,int i){//ɾ��Ԫ�� 
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
		for(;j<i;j++){
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

Status badTest(CLinkList L){	//���������Ƿ�����ѭ�� 
	CLinkList target;
	for(target = L;target->next != NULL;target = target->next);
	return OK;
}

Status combineCList(CLinkList &L,CLinkList &L2){	//ѭ���б�ϲ���L2�ݻ�û����̫���˰�������������������죡 
	CLinkList target_L;
	CLinkList target_L2;
	CLinkList tmp;
	if(L2 == NULL){
		return ERROR;
	}else{
		for(target_L = L;target_L->next != L;target_L = target_L->next);
		for(target_L2 = L2;target_L2->next != L2;target_L2 = target_L2->next);
		tmp = L2;
		target_L->next = L2->next;
		target_L2->next = L;
		return OK;
	}
}

Status destoryCList(CLinkList &L){	//	�ݻ����� 
	CLinkList target;
	for(target = L;target->next != L;target = target->next);
	target->next = NULL;
		while(L)
		{
			target=L;
			L=L->next;
			delete target;
		}
	return OK;
}

void JosephusTools(L,m){
	
}

void Josephus(CLinkList &L,int n,int m){
	CLinkList target;
	CLinkList target1;
	CLinkList tmp = new CNode;
	int i,j;
	ElemType e;
	for(target = L;target->next != L;target = target->next);
	target = target->next->next;
	for(i = 0;i < n-1;i++){
		for(j = 0;j <m-1;j++){
			if(target->next == L){
				target = target->next;
				target = target->next;
			}else{
				target = target->next;
			}
		}
		printf("���е���Ϊ%d\n",target->data);
			for(target1 = L;target1->next != target;target1 = target1->next);
				target1 = target->next;
				tmp = target;
				target = target->next;
				free(tmp);
	}
}



int main(){
	CLinkList L;
	CLinkList L2;
	ElemType e=11;
	printf("��ʼ������:\n");
	printf("%d\n",initCList_L(L));
	printf("%d\n",initCList_L(L2));
	printf("%d\n",findCListLength_L(L));
	printf("--------------\n");
	printf("�������\n");
	printf("%d\n",insertCListRandom_L(L,1));
	printf("%d\n",insertCListRandom_L(L,2));
	printf("%d\n",insertCListRandom_L(L,3));
	printf("%d\n",insertCListRandom_L(L,4));
	printf("%d\n",insertCListRandom_L(L,5));
	printf("%d\n",insertCListRandom_L(L,6));
	printf("%d\n",insertCListRandom_L(L,7));
	printf("%d\n",insertCListRandom_L(L,8));
	printf("%d\n",findCListLength_L(L));
	showAll(L);	
	printf("--------------\n");
	printf("Լɪ������Ľ��:\n");
	Josephus(L,findCListLength_L(L),3);
//	printf("����������\n");
//	printf("%d\n",insertCList_L(L2,1,3));
//	printf("%d\n",insertCList_L(L2,2,4));
//	printf("%d\n",findCListLength_L(L));
//	showAll(L2);
//	printf("--------------\n");
//	printf("������Ҳ���\n");
//	printf("%d",findLocatedElem_L(L,1,e));
//	printf(" %d\n",e);
//	printf("%d",findLocatedElem_L(L,2,e));
//	printf(" %d\n",e);
//	printf("%d",findLocation_L(L,e,3));
//	printf(" %d\n",e);
//	printf("%d",findLocation_L(L,e,1));
//	printf(" %d\n",e);
//	showAll(L);
//	printf("--------------\n");
//	printf("����ɾ������\n");
//	printf("%d\n",deleteElem_L(L,1));
//	printf("%d\n",deleteElem_L(L,3));
//	printf("%d\n",findCListLength_L(L));
//	showAll(L);
//	printf("--------------\n");
//	printf("�����ϲ���\n");
//	printf("%d\n",combineCList(L,L2));
//	showAll(L);
//	printf("�ݻ��������\n");
//	printf("%d\n",destoryCList(L));
//	showAll(L);
	return 0;
}
