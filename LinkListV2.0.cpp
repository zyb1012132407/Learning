/*
	Title:�����ļ������븴ϰ
	TimeLine:2018.9.19
	Owner:���ܲ� 
	Details:
		9.19���� ���ѽ���� 
		1����********��Ϊ�����������������Ѳ��Ժã����BUG���ȼ����
		2����ElemType��Ϊ�ɸı�ѡ���Ҫ����ElemType�Ķ��壬����ʱ��Ϊ�ɸ��ģ�������Ҫ���Ķ�
		9.20���� ���ѽ���� 
		3�� ��ʵѵ���У�����Ҳ�鷳�������������ƺ���void controller(LinkList &L,int x),���û���������ʾ 
		4��	�����˶���������״̬���(����int����ȫ�ֱ���InitFlag)����ֹ���󵯳�	
		5�� ���ѽ����������������������Ҫ�Ľ���ֻ���ǵ����ݣ�δ���Ƕ����ͬ����
				��������Ҫ�ĵĵط���case 6;
									int LocateElem_L(LinkList L,ElemType e);
									void mainTest(LinkList &L);
									etc....�� 
									
		6��	���ѽ����������չ����δ���ӣ�	1��ĩλ������					���ѽ���� 
											2���������������������д��		���ѽ���� 
											3���ݻ�����������������д��		���ѽ���� 
																								�� 
		9.21����
		7�����ѽ��������ѧ���ṹ���Ӧ�ã��������ͺ��ѣ�������������
		7.5�� ����������У��ɼ��ļ�⣨�ַ���⡢������Χ��⡢ʧ�ܺ��ַ��������룩��
			û�и�λ�ô��������������빦�ܣ��о�����ʵ���ࣩ 
		8����ģģ�����Ľ���˰ɣ�����ʦ˵���Գ���˫�����������������ӣ�emmmmmmmmm���о�����ѧϰ�¡� 

*/

//-----------------����Ϊͷ�ļ�---------------------------------

 
#include <stdio.h>
#include <cstdlib>
#include <string.h>


//-----------------����Ϊ�ض���---------------------------------  


//typedef int ElemType; //�ض����������ͣ�����int�����Թ����������޸ģ��Ѿ����ˣ� 

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
void mainTest(LinkList &L,LinkList &L2);
void controller(LinkList &L,int x);
LinkList LocateElem_L_EX(LinkList L,ElemType e,int &n);
void ConnectionList_L(LinkList &L,LinkList &L2);
void ClearListN(LinkList &L);
void DestoryList_LN(LinkList &L);
void CrushList_L(LinkList &L,LinkList &L2,char n);
//-----------------����Ϊȫ�ֱ�����-----------------------------


int InitFlag = 0;	//��������Ƿ񴴽�


//-----------------����Ϊ���������������ģ�---------------------


int main(){
	LinkList L;
	LinkList L2;
	mainTest(L,L2);
	return 0;
}


//-----------------����Ϊ��ʾ�˵�------------------------------- 


void mainTest(LinkList &L,LinkList &L2){//���˵� 
	//����ѡ�����x,n�� 
	int x = 0;
	char n = 0;
	//��ѭ��������break���� 
	while(1){
	printf("\n          ��ӭ���Ե�����\n\n");
	printf("---------------------------------\n");
	//ʵʱ�����������״̬�Լ����ȣ����BUG�죬Ӧ��Ҳֱ�۰ɡ������� 
	if(!InitFlag){
		printf("�����������ڣ����½���������\n");
	}else if (InitFlag == 1){
		printf("�������ĳ���Ϊ�� %d\n",ListLength_L(L));
	}else{
		printf("������1�ĳ���Ϊ�� %d\n",ListLength_L(L));
		printf("������2�ĳ���Ϊ:  %d\n",ListLength_L(L2));
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
	printf("9���ݻ�����������ѡ��\n");
	printf("10����������\n");
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
		if(!InitFlag){
			controller(L,1);
			printf("��һ���������ѽ���\n");
		}else if(InitFlag == 1){
			controller(L2,1);
			printf("�ڶ����������ѽ���\n");
		}
		
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=8){
		//�Ե��������в���������Ҫ�ȼ����״̬������ᱨ�� 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("�����������ڣ����½���������\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("��ѡ��������YΪ��һ����������Ϊ�ڶ�������");
			scanf("%c",&n);
			fflush(stdin);
			if(n == 'y' || n == 'Y'){
				controller(L,x);
			}else{
				controller(L2,x);
			}
		} 
		printf("--------------------------------\n");
		
	}else if(x == 9){
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("�����������ڣ����½�������\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("��ѡ��������YΪ��һ����������Ϊ�ڶ�������");
			scanf("%c",&n);
			fflush(stdin);
			if(n == 'y' || n == 'Y'){
				CrushList_L(L,L2,n);
				InitFlag--;
			}else{
				CrushList_L(L,L2,n);
				InitFlag--;
			}
			printf("�Ѵݻٵ�����\n");
		}
		printf("--------------------------------\n");			
	}else if(x == 10){
		if(InitFlag == 0){
		printf("�����������ڣ����½���������\n");
		}
		else if(InitFlag == 1){
			printf("�������������ף����ٽ�һ����\n"); 
		}else if(InitFlag == 2){
			ConnectionList_L(L,L2);
		}else{
			InitFlag = 0;
			printf("�������������µ�BUG���������ύ������һ��\n");
		}
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
		case 1:{//��ʼ����������ʧ�ܷ�Ϊ�Ѵ��ڻ������쳣����ֹ�Ҳ���BUG�� 
			if(InitList_L(L)){
				printf("��ʼ�������ɹ���\n");
				InitFlag++;
			}else{
				if(InitFlag){
					printf("��ʼ������ʧ�ܣ��Ѵ���������\n");
				}else{
					printf("��ʼ������ʧ�ܣ����������ύBug!\n");
				}
			}
			break;
		}
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
				while(1){
				if(scanf("%d",&x.grade) && x.grade >=0 && x.grade <=100){//����Ƿ�Ϊ���֣��Ƿ��ڷ�Χ�� 
						if(ListInsertRandom_L(p,x)){
							printf("���ӳɹ���\n\n");
							break;
						}else{
							printf("����ʧ�ܣ����������ύBUG����\n\n");
							break;
						}
				}else{
					fflush(stdin);
					printf("��������ȷ��ֵ��\n");
					printf("��������Ҫ����ĳɼ�:");
				}	
			}
				
				//�жϺϷ����
				
				printf("������Ҫ����������(y/other)  :");
				//������ݻ����� 
				fflush(stdin);
				scanf("%c",&flag);
				fflush(stdin);
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
				fflush(stdin);
				scanf("%s",x.name);
				fflush(stdin);
				printf("��������Ҫ�����ѧ��: ");
				fflush(stdin);
				scanf("%s",x.num);
				printf("��������Ҫ����ĳɼ�: ");
				while(1){
					//�жϺϷ����
					if(scanf("%d",&x.grade) && x.grade >=0 && x.grade <=100){
						//��λ�� 
						printf("���������λ��:  ");
						scanf("%d",&location);
						printf("\n");
						if(ListInsert_L(p,location,x)){
							printf("���ӳɹ���\n\n");
							break;
						}else{
							printf("����ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n\n");
							break;
						}
					}else{
						fflush(stdin);
						printf("��������ȷ��ֵ��\n");
						printf("��������Ҫ����ĳɼ�:");
					}
				}	
				printf("������Ҫ����������(y/other)  :");
				//������ݻ����� 
				fflush(stdin);
				scanf("%c",&flag);
				fflush(stdin);
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
					if(p){
						sum += n;
						printf("����%d��λ��",sum);
					}else{
						break;
					}
					
				}
				printf("\n");
			}else{
				printf("����ʧ�ܣ����ݲ����ڣ�\n");
			}
			break;
		}
		case 7:{//��ʾȫ�����ݣ���������Ƿ����� 
			if(!ListLength_L(L)){
				printf("�����������ݣ����������ݣ�\n"); 
			}else{
				ShowAll(L);
			}
			break;
		}
		case 8:{//����������ݣ�����ͨ 
			char flag;
			printf("�����ؿ��ǣ��Ƿ�ȷ����������� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(ClearList(L)){
					printf("��������ɹ���\n");
				}else{//������BUG����� 
					printf("�������ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
		} 
		case 9:{//�ݻ�����������ͨ 
			char flag;
			fflush(stdin);
			printf("�����ؿ��ǣ��Ƿ�ȷ���ݻ������� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(DestoryList_L(L)){
					printf("�����ݻٳɹ���\n");
					InitFlag--;
				}else{//������BUG����� 
					printf("�����ݻ�ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
		}
	}
}


//-----------------����Ϊ��������------------------------------- 

void CrushList_L(LinkList &L,LinkList &L2,char n){
	if(n == 'Y' || n == 'y'){
		ClearListN(L);
		ConnectionList_L(L,L2);
		DestoryList_LN(L2);
	}else{
		DestoryList_LN(L2);
	}
}

void ConnectionList_L(LinkList &L,LinkList &L2){//�������ӣ����BUG���ȼ���ߣ�  
	LinkList p = L2->next;
	int i;
	for(int i = 1; i <= ListLength_L(L2);){
		i += ListInsertRandom_L(L,p->data);
	}
	DestoryList_L(L2);
	InitFlag--;
	printf("���ӳɹ�����鿴Ч��\n");
}

Status InitList_L(LinkList &L){	//��ʼ��������ͷ��㣬����ռ�  ********
	L=new LNode;
	L->next=NULL;
	return OK;
}

void DestoryList_LN(LinkList &L){//�ݻ�����					********
	LinkList p;
		while(L)
		{
			p=L;
			L=L->next;
			delete p;
		}
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

void ClearListN(LinkList &L){//��������������� 				********
	LinkList p,q;
	p=L->next;
	while(p){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=NULL;
	return ;
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

int ListLength_L(LinkList L){//������������ 					********
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
		printf("���ĵ�%d���ڵ�Ϊ: \n����: %s,ѧ��: %s,�ɼ�: %d\n",i,p->data.name,p->data.num,p->data.grade);
		p = p->next;
		i++;
	}
	return;
}
