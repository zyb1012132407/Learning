/*
	Title:����ļ������븴ϰ
	TimeLine:2018.9.19
	Owner:���ܲ� 
	Details:
		9.19���� 
		1����********��Ϊ����������������Ѳ��Ժã����BUG���ȼ����
		2����ElemChangeable��Ϊ�ɸı�ѡ���Ҫ����ElemType�Ķ��壬����ʱ��Ϊ�ɸ��ģ�������Ҫ���Ķ�
		9.20���� 
		3�� ��ʵѵ���У�����Ҳ�鷳�������������ƺ���void controller(LinkList &L,int x),���û���������ʾ 
		4��	����˶��������״̬���(����int����ȫ�ֱ���InitFlag)����ֹ���󵯳�	
		5�� ���ѽ���������������������Ҫ�Ľ���ֻ���ǵ����ݣ�δ���Ƕ����ͬ����
				��������Ҫ�ĵĵط���case 6;
									int LocateElem_L(LinkList L,ElemType e);
									void mainTest(LinkList &L);
									etc....�� 
									
		6��	���ѽ��һ���֣�������չ����δ��ӣ�	1��ĩλ�����					���ѽ���� 
													2�������������������д��		���ѽ���� 
													3���ݻ���������������д��		���ѽ���� 
																								�� 
		9.21���ȣ���ѧ����ɣ�˭֪�����ó������������أ���ҵ�ȷ���ܾ��������ɣ�̫��ʵ�� 


*/

//-----------------����Ϊͷ�ļ�---------------------------------

 
#include <stdio.h>
#include <cstdlib>
#include <string.h>


//-----------------����Ϊ�ض���---------------------------------  


//typedef int ElemType; //�ض����������ͣ�����int�����Թ����������޸� 
typedef int Status;	  //�ض���״̬����ʾ�����Ƿ���������

typedef struct{
	char num[10];
	char name[10];
	int grade;
}student;

typedef student ElemType;


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
Status ListInsertRandom_L(LinkList &L,ElemType e);
Status ListInsert_L(LinkList &L,int i,ElemType e);
Status ListDelete_L(LinkList &L,int i,ElemType &e);
int ListEmpty(LinkList L);
int ListLength_L(LinkList L);
int LocateElem_L(LinkList L,ElemType e);
void ShowAll(LinkList &L);
void mainTest(LinkList &L);
void controller(LinkList &L,int x);
LinkList LocateElem_L_EX(LinkList L,ElemType e,int &n);


//-----------------����Ϊȫ�ֱ�����-----------------------------


int InitFlag = 0;	//��������Ƿ񴴽�
int ListSearch_Y_or_N = 1; //�������״̬  


//-----------------����Ϊ���������������ģ�---------------------


int main(){
	LinkList L;
	mainTest(L);
	return 0;
}


//-----------------����Ϊ��ʾ�˵�------------------------------- 


void mainTest(LinkList &L){//���˵� 
	//����ѡ�����X�� 
	int x=0;
	//��ѭ��������break���� 
	while(1){
	printf("\n          ��ӭ���Ե�����\n\n");
	printf("---------------------------------\n");
	//ʵʱ����������״̬�Լ����ȣ����BUG�죬Ӧ��Ҳֱ�۰ɡ������� 
	if(!InitFlag){
		printf("���������ڣ����½�������\n");
	}else{
		printf("������ĳ���Ϊ�� %d\n",ListLength_L(L));
	} 
	//ѡ��˵� 
	printf("---------------------------------\n");
	printf("�����������Խ������¹���\n");
	printf("1���½�������\n");
	printf("2�����루����λ�ã�\n");
	printf("3�����루ָ��λ�ã�\n");
	printf("4��ɾ����ָ��λ�ã�\n");
	printf("5�����ң�ָ��λ�ã�\n");
	printf("6�����ң�ָ�����ݣ�\n"); 
	printf("7����ʾ��������\n");
	printf("8������������ݣ�����ѡ��\n");
	printf("9���ݻ���������ѡ��\n");
	printf("0���˳�\n");
	printf("--------------------------------\n");
	//��ʼ����ѡ�� 
	printf("����������ѡ��");
	scanf("%d",&x);
	//����ѡ��������Ӧ 
	if(x == 0){
		//break�˳� 
		printf("--------------------------------\n");
		printf("���Խ���\n");
		break;
	}
	else if(x == 1){
		//���������� 
		printf("--------------------------------\n");
		controller(L,1);
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=9){
		//�Ե�������в���������Ҫ�ȼ����״̬������ᱨ�� 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("���������ڣ����½�������\n");
		}else{
			controller(L,x);
		}
		printf("--------------------------------\n");
	}else{
		printf("ѡ��������������룡\n");
	}
	//��ɲ�������ͣһ�£���ֹ������������������ʦԴ���뷽����getchar()Ҳ���Բ��������˵Ҫ��һЩ�� 
	system("pause");
	//�������� 
	system("cls");
	}
	return;
}


//-----------------����Ϊ������--------------------------------- 


void controller(LinkList &L,int x){
	switch(x){
		case 1:{//��ʼ��������ʧ�ܷ�Ϊ�Ѵ��ڻ������쳣����ֹ�Ҳ���BUG�� 
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
//		case 2:{//�����ȣ�ûɶ�ã�Ϊ�˺�������Ӧ�����Բ��Ǵ��������Բ��Ǵ��������Բ��Ǵ������� 
//			printf("������Ϊ:  %d\n",ListLength_L(L));
//			break;
//		}
		case 2:{//Ĭ�ϲ��룬�Ͷ���������ƣ�֧�ֶ���������루Y/�����ַ��� 
			ElemType x;
			LinkList p;
			char flag='y';
			while(1){
				p = L;
				printf("\n");
				//����ֵ 
				printf("��������Ҫ���������: ");
				scanf("%s",x.name);
				printf("��������Ҫ�����ѧ��: ");
				scanf("%s",x.num);
				printf("��������Ҫ����ĳɼ�: ");
				scanf("%d",&x.grade);
				//�жϺϷ����
				if(ListInsertRandom_L(p,x)){
					printf("��ӳɹ���\n\n");
				}else{
					printf("���ʧ�ܣ����������ύBUG����\n\n");
				}
				printf("������Ҫ����������(y/other)  :");
				//������ݻ����� 
				fflush(stdin);
				scanf("%c",&flag);
				//���� 
				if(flag == 'y' ||  flag == 'Y'){
					printf("---------------------------------\n");
				}else{
					break;
				}
			}
			break;
		}
		case 3:{//ָ��λ�ò������ݣ�֧�ֶ���������루Y/�����ַ��� 
			ElemType x;
			LinkList p;
			char flag='y';
			int location;
			while(1){
				p = L;
				printf("\n");
				//����ֵ 
				printf("��������Ҫ���������: ");
				scanf("%s",x.name);
				printf("��������Ҫ�����ѧ��: ");
				scanf("%s",x.num);
				printf("��������Ҫ����ĳɼ�: ");
				scanf("%d",&x.grade);
				//��λ�� 
				printf("���������λ��:  ");
				scanf("%d",&location);
				printf("\n");
				//�жϺϷ����
				if(ListInsert_L(p,location,x)){
					printf("��ӳɹ���\n\n");
				}else{
						printf("���ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n\n");
				}
				printf("������Ҫ����������(y/other)  :");
				//������ݻ����� 
				fflush(stdin);
				scanf("%c",&flag);
				//���� 
				if(flag == 'y' ||  flag == 'Y'){
					printf("---------------------------------\n");
				}else{
					break;
				}
			}
			break;
		}
		case 4:{//ָ��λ��ɾ�����ݣ�����ͨ 
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
		case 5:{//ָ��λ���������ݣ�Ҳ����ͨ 
			int location;
			ElemType tmp;
			printf("����������λ�ã�");
			scanf("%d",&location);
			if(GetElem_L(L,location,tmp)){
				printf("�����ɹ������Ϊ: \n����: %s,ѧ��: %s,�ɼ�: %d\n",tmp.name,tmp.num,tmp.grade);
			}else{
				printf("����ʧ�ܣ�û�д����ݣ�\n");
			}
			return;
			break;
		}
		case 6:{//ָ����������λ�ã�ʵ���ظ�����ȫ���������޸����BUG���ȼ���ߣ���Ϊ����ʱ��һ���= =�� 
			LinkList p;
			ElemType tmp;
			int sum = 0;
			int n;
			printf("������������: \n");
			scanf("%s",tmp.name);
			p = LocateElem_L_EX(L,tmp,n);
			if(p){
				sum += n;
				printf("�����ɹ��������ڵ�%d��λ��",sum);
				p = p->next;
				while(p){
					p = LocateElem_L_EX(p,tmp,n);
					sum += n;
					printf("����%d��λ��",sum);
				}
				printf("\n");
			}else{
				printf("����ʧ�ܣ����ݲ����ڣ�\n");
			}
			break;
		}
		case 7:{//��ʾȫ�����ݣ���������Ƿ����� 
			if(!ListLength_L(L)){
				printf("�����������ݣ���������ݣ�\n"); 
			}else{
				ShowAll(L);
			}
			break;
		}
		case 8:{//����������ݣ�����ͨ 
			char flag;
			printf("�����ؿ��ǣ��Ƿ�ȷ��������� (y/other) ��");
			fflush(stdin);
			scanf("%c",&flag);
			if(flag == 'y' || flag == 'Y'){
				if(ClearList(L)){
					printf("��������ɹ���\n");
				}else{//������BUG����� 
					printf("�������ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
		} 
		case 9:{//�ݻ���������ͨ 
			char flag;
			printf("�����ؿ��ǣ��Ƿ�ȷ���ݻ����� (y/other) ��");
			fflush(stdin);
			scanf("%c",&flag);
			if(flag == 'y' || flag == 'Y'){
				if(DestoryList_L(L)){
					printf("����ݻٳɹ���\n");
					InitFlag = 0;
				}else{//������BUG����� 
					printf("����ݻ�ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
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

//int LocateElem_L(LinkList L,char e[]){//ȡֵ��ֵ��λ��		********
//	int n=1;
//	LinkList p = L->next;
//	while(p && p->data !=e){
//		p = p->next;
//		n++;
//	}
//	if(p){
//		return n;
//	}else{
//		return 0;
//	}
//}

LinkList LocateElem_L_EX(LinkList L,ElemType e,int &n){//ȡֵ�޸İ棨ʵ���ظ�����ȫ���������޸����BUG���ȼ���ߣ� 
	int numbers=1;
	LinkList p = L->next;
	while(p && (strcmp(p->data.name,e.name) != 0)){
		p = p->next;
		numbers++;
	}
	if(p){
		n = numbers;
		return p;
	}else{
		return NULL;
	}
}

//LinkList OldLocateElem_L_EX(LinkList L,ElemType e,int &n){//ȡֵ�޸İ棨ʵ���ظ�����ȫ���������޸����BUG���ȼ���ߣ� 
//	int numbers=1;
//	LinkList p = L->next;
//	while(p && p->data !=e){
//		p = p->next;
//		numbers++;
//	}
//	if(p){
//		n = numbers;
//		return p;
//	}else{
//		return NULL;
//	}
//}  

Status ListInsertRandom_L(LinkList &L,ElemType e){//������루������ϣ� 
	LinkList p = L;
	LinkList s = new LNode;
	while(p->next){
		p = p->next;
	}
	s->data = e;
	s->next = p->next;
	p->next = s; 
	return OK;
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

Status OldListInsert_L(LinkList &L,int i,ElemType e){//�������    ******** 
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

Status OldListDelete_L(LinkList &L,int i,ElemType &e){//����ɾ��	******** 
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
		printf("���ĵ�%d���ڵ�Ϊ: \n����: %s,ѧ��: %s,�ɼ�: %d\n",i,p->data.name,p->data.num,p->data.grade);
		p = p->next;
		i++;
	}
	return;
}

void OldShowAll(LinkList &L){//ȫ����� 							********
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

