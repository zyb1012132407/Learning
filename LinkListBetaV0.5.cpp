/*
	Title:����ļ������븴ϰ
	Date:2018.9.19
	Owner:���ܲ� 
	Details:
		1����********��Ϊ����������������Ѳ��Ժã����BUG���ȼ���͡�
		2����ElemChangeable��Ϊ�ɸı�ѡ���Ҫ����ElemType�Ķ��壬����ʱ��Ϊ�ɸ��ģ�������Ҫ���Ķ���
		3�� ��ʵѵ���У�����Ҳ�鷳�������������ƺ���controller(LinkList &L,int x),���û���������ʾ�� 
		4��	����˶��������״̬���(����int����ȫ�ֱ���InitFlag)����ֹ���󵯳���
		 


*/

//-----------------����Ϊͷ�ļ�---------------------------------

 
#include <stdio.h>
#include <cstdlib>


//-----------------����Ϊ�ض���---------------------------------  


typedef int ElemType; //�ض����������ͣ�����int�����Թ����������޸� 
typedef int Status;	  //�ض���״̬����ʾ�����Ƿ���������
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


//-----------------����Ϊ��������-------------------------------  


#define OK 1
#define ERROR 0
#define MAXSIZE 100


//-----------------����Ϊ����������-----------------------------


Status ClearList(LinkList &L);
Status InitList_L(LinkList &L);
Status DestoryList_L(LinkList &L);
Status GetElem_L(LinkList L,int i,ElemType &tmp);
Status ListInsert_L(LinkList &L,int i,ElemType e);
Status ListDelete_L(LinkList &L,int i,ElemType &e);
int ListEmpty(LinkList L);
int ListLength_L(LinkList L);
int LocateElem_L(LinkList L,ElemType e);
void ShowAll(LinkList &L);
void mainTest(LinkList &L);
void controller(LinkList &L,int x);

//-----------------����Ϊȫ�ֱ�����-----------------------------


int InitFlag = 0;


//-----------------����Ϊ���������������ģ�---------------------


int main(){
	LinkList L;
	mainTest(L);
	return 0;
}


//-----------------����Ϊ��ʾ�˵�------------------------------- 


void mainTest(LinkList &L){//���˵� 
	int x=0;
	while(1){
	printf("\n          ��ӭ���Ե�����\n\n");
	printf("---------------------------------\n");
	if(!InitFlag){
		printf("���������ڣ����½�������\n");
	}else{
		printf("������ĳ���Ϊ�� %d\n",ListLength_L(L));
	} 
	printf("---------------------------------\n");
	printf("�����������Խ������¹���\n");
	printf("1���½�������\n");
	printf("2��ͳ��������\n");
	printf("3�����루ָ��λ�ã�\n");
	printf("4��ɾ����ָ��λ�ã�\n");
	printf("5�����ң�ָ��λ�ã�\n");
	printf("6�����ң�ָ�����ݣ�\n"); 
	printf("7����ʾ��������\n");
	printf("8���˳�\n");
	printf("--------------------------------\n");
	printf("����������ѡ��");
	scanf("%d",&x);
	if(x == 1){
		printf("--------------------------------\n");
		controller(L,1);
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=7){
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("���������ڣ����½�������\n");
		}else{
			controller(L,x);
		}
		printf("--------------------------------\n");
	}else if(x == 8){
		printf("--------------------------------\n");
		printf("���Խ���\n");
		break;
	}else{
		printf("ѡ��������������룡\n");
	}
	system("pause");
	system("cls");
	}
	return;
}


//-----------------����Ϊ������--------------------------------- 


void controller(LinkList &L,int x){
	switch(x){
		case 1:{
			if(InitList_L(L)){
				printf("��ʼ������ɹ���\n");
				InitFlag = 1;
			}else{
				if(InitFlag){
					printf("��ʼ������ʧ�ܣ��Ѵ�������\n");
				}else{
					printf("��ʼ������ʧ�ܣ����������ύBug!\n");
				}
				
			}
			break;
		}
		case 2:{
			printf("������Ϊ:  %d\n",ListLength_L(L));
			break;
		}
		case 3:{
			ElemType x;
			ElemType tmp;
			LinkList p;
			char flag='y';
			int location;
			while(flag == 'y' ||  flag == 'Y'){
				p = L;
				printf("��������Ҫ�����ֵ: ");
				scanf("%d",&x);
				printf("���������λ��:  ");
				scanf("%d",&location);
				if(ListInsert_L(p,location,x)){
					printf("��ӳɹ���\n");
				}else{
						printf("���ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n");
				}
				printf("������Ҫ����������(y/other)  :");
				fflush(stdin);
				scanf("%c",&flag);
			}
			break;
		}
		case 4:{
			int location;
			ElemType tmp;
			printf("��������Ҫɾ����λ��:");
			scanf("%d",&location);
			if(ListDelete_L(L,location,tmp)){
				printf("ɾ���ɹ���\n");
			}else{
				printf("ɾ��ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n");
			}
			break;
		}
		case 5:{
			int location;
			ElemType tmp;
			printf("����������λ�ã�");
			scanf("%d",&location);
			if(GetElem_L(L,location,tmp)){
				printf("�����ɹ������Ϊ��%d!\n",tmp);
			}else{
				printf("����ʧ�ܣ�û�д����ݣ�\n");
			}
			return;
			break;
		}
		case 6:{
			int p;
			ElemType tmp;
			printf("������������: \n");
			scanf("%d",&tmp);
			p = LocateElem_L(L,tmp);
			if(p){
				printf("�����ɹ��������ڵ�%d��λ��",p);
			}else{
				printf("����ʧ�ܣ����ݲ����ڣ�");
			}
			break;
		}
		case 7:{
			if(!ListLength_L(L)){
				printf("�����������ݣ���������ݣ�\n"); 
			}else{
				ShowAll(L);
			}
			break;
		}
	}
}


//-----------------����Ϊ��������------------------------------- 


Status InitList_L(LinkList &L){	//��ʼ��������ͷ��㣬����ռ�  ********
	L=new LNode;
	L->next=NULL;
	return OK;
}

Status DestoryList_L(LinkList &L){//�ݻ�����					********
	LinkList p;
		while(L)
		{
			p=L;
			L=L->next;
			delete p;
		}
	return OK;
}

Status ClearList(LinkList &L){//��������������� 				********
	LinkList p,q;
	p=L->next;
	while(p){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
	return OK;
}

int ListLength_L(LinkList L){//���������� 					********
	int i = 0;
	LinkList p;
	p=L->next;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

int ListEmpty(LinkList L){//��������Ƿ�Ϊ�� 					********
	if(L->next)
		return 0;
	else
		return 1;
}

Status GetElem_L(LinkList L,int i,ElemType &tmp){//ȡֵ			********
	LinkList p = L->next;
	int j =1;
	while(p && j <i){
		p = p->next;
		j++;
	}
	if(!p || i > j){
		return ERROR;
	}else{
		tmp = p->data;
		return OK;
	}
}

int LocateElem_L(LinkList L,ElemType e){//ȡֵ��ֵ��λ��		********
	int n=1;
	LinkList p = L->next;
	while(p && p->data !=e){
		p = p->next;
		n++;
	}
	if(p){
		return n;
	}else{
		return 0;
	}
}

Status ListInsert_L(LinkList &L,int i,ElemType e){//�������    ******** 
	LinkList p = L;
	LinkList s = new LNode;
	int j = 0;
	while(p && j < i-1){
		p=p->next;
		j++;
	}
	if(!p || j > i-1){
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
	
}

Status ListDelete_L(LinkList &L,int i,ElemType &e){//����ɾ��	******** 
	LinkList p = L;
	LinkList q = new LNode;
	int j = 0;
	while(p->next && j<i-1){
		p = p->next;
		j++;
	}
	if(!(p->next) || j>i-1){
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	delete q;
	return OK;	
} 

void ShowAll(LinkList &L){//ȫ����� 							********
	LinkList p = L->next;
	int i = 1;
	printf("������Ľ��Ϊ:\n");
	while(p){
		printf("���ĵ�%d���ڵ�Ϊ%d\n",i,p->data);
		p = p->next;
		i++;
	}
	return;
}

