#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
typedef struct{
	int *elem;
	int length;
}SqList;

typedef int Status;
typedef int ElemType;
#define OK 1
#define ERROR 0
#define MAXSIZE 100

void mainTest(SqList &L);
void DestoryList(SqList &L);
void ClearList(SqList &L);
void ShowAll(SqList &L);
void controller(SqList &L,int x);
int GetLength(SqList &L);
int IsEmpty(SqList &L);
int GetElem(SqList &L,int i,ElemType e);
int LocateElem(SqList &L,ElemType e);
Status ListInsert(SqList &L,ElemType e);
Status InitList_Sq(SqList &L);
Status ListInsert_Sq(SqList &L,int i,ElemType e);
Status ListDelete_Sq(SqList &L,int i);

int main(){
	SqList L;
	mainTest(L);
	return 0;
}

void mainTest(SqList &L){
	int x=0;
	while(1){
	printf("��ӭ�������Ա�\n");
	printf("-------------------------\n");
	printf("�����������Խ������¹���\n");
	printf("1���½����Ա�\n");
	printf("2�����루���λ�ã�\n");
	printf("3�����루ָ��λ�ã�\n");
	printf("4��ɾ����ָ��λ�ã�\n");
	printf("5�����ң�ָ��λ�ã�\n");
	printf("6�����ң�ָ�����ݣ�\n"); 
	printf("7����ʾ��������\n");
	printf("8���˳�\n");
	printf("-------------------------\n");
	printf("����������ѡ��");
	scanf("%d",&x);
	if(x >=1 && x <=7){
		controller(L,x);
	}else if(x == 8){
		printf("���Խ���");
		break;
	}else{
		printf("ѡ��������������룡");
	}
	system("pause");
	system("cls");
	}
	
	return;

}

void controller(SqList &L,int x){
	switch(x){
		
		case 1: {
			if(InitList_Sq(L)){
				printf("�½����Ա�ɹ����������һ��������");
				break;
			}else{
			 	printf("�½����Ա�ʧ�ܣ������Ƿ��Ѵ������Ա�"); 
			}
			return;
		}
		
		
		case 2:{
			ElemType tmp=1;
			char flag;
			while(tmp){
				if(L.length >= MAXSIZE){
					printf("����������ֹ���룡");
					return; 
				} 
				printf("������Ҫ���������");
				scanf("%d",&tmp);
				if(ListInsert(L,tmp)){
					printf("��ӳɹ���\n");
				}else{
					printf("���ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n");
				}
				fflush(stdin);
				printf("������Ҫ����������");
				scanf("%c",&flag);
				getchar();
				if(flag != 'y' || flag != 'Y')
					break;
			}
			return;
		}
		
		case 3:{
			ElemType tmp;
			int location;
			char flag;
			while(1){
				if(L.length >= MAXSIZE){
					printf("����������ֹ���룡");
					return; 
				} 
				printf("������Ҫ���������");
				scanf("%d",&tmp);
				printf("������Ҫ�����λ�ã�");
				scanf("%d",&location); 
				if(ListInsert_Sq(L,location,tmp)){
					printf("��ӳɹ���\n");
				}else{
					printf("���ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n");
				}
//				printf("������Ҫ����������");
//				flag=getchar();
//				if(flag != 'y' || flag != 'Y')
//					break;
			}
			return;
		}
		
		case 4:{
			int location;
			printf("��������Ҫɾ����λ��:");
			scanf("%d",&location);
			if(ListDelete_Sq(L,location)){
				printf("ɾ���ɹ���\n");
			}else{
				printf("ɾ��ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n");
			}
			return;
		}
		
		case 5:{
			int location;
			ElemType tmp;
			printf("����������λ�ã�");
			scanf("%d",&location);
			tmp=GetElem(L,location,tmp);
			if(tmp){
				printf("�����ɹ������Ϊ��%d!",&tmp);
			}else{
				printf("����ʧ�ܣ�û�д����ݣ�");
			}
			return;
		}
		
		case 6:{
			ElemType e;
			int result;
			printf("������Ҫ������ݣ�");
			scanf("%d",&e);
			if(result = LocateElem(L,e)){
				printf("���ҳɹ�������λ��Ϊ%d",result);
			}else{
				printf("����ʧ�ܣ����ݲ����ڣ�");
			}
			return;
		}
		
		case 7:{
			ShowAll(L);
			return;
		}
		
	}
}

Status InitList_Sq(SqList &L){
	L.elem = new ElemType[100];
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

void ShowAll(SqList &L){
	int i;
	printf("���Ա����������Ϊ��\n");
	for(i=0;i<L.length;i++){
		printf("��%d���ڵ�����Ϊ%d��\n",i+1,L.elem[i]);
	}
	return;
}

int GetLength(SqList &L){
	return L.length;
}

int IsEmpty(SqList &L){
	if(L.length == 0){
		return OK;
	}else{
		return ERROR;
	}
}

int GetElem(SqList &L,int i,ElemType e){ 
	if(i < 1 || i >L.length)
		return ERROR;
	e=L.elem[i-1];
	return OK;
}

int LocateElem(SqList &L,ElemType e){
	int i = 0;
	for(i = 0; i < L.length;i++){
		if(L.elem[i] == e){
			return i+1;
		}
	}
	return ERROR;
}

Status ListInsert(SqList &L,ElemType e){
	if(L.length==MAXSIZE)
		return ERROR;
	L.length++;
	L.elem[L.length-1] = e;
	return OK;
}

Status ListInsert_Sq(SqList &L,int i,ElemType e){
	int j;
	if(i < 1 || i >L.length+1)
		return ERROR;
	if(L.length==MAXSIZE)
		return ERROR;
	for(j = L.length-1;j>=i-1;j--){
		L.elem[j+1] = L.elem[j];
	}
	L.elem[j] = e;
	L.length++;
	return OK;
}

Status ListDelete_Sq(SqList &L,int i){
	int j;
	if(i < 1 || i>L.length){
		return ERROR;
	}
	for(j = i-1;j < L.length-1;j++){
		L.elem[j] = L.elem[j+1];
	}
	L.length--;
	return OK;
}

