/*
	Title:˫��ѭ��������ϰ
	Owner:���ܲ�
	Details:
		10.9���ȣ�
			1���ڸ��ӡ���������
		10.11���ȣ�
			1����ɻ��������Ķ��塢���ƣ������е��ԡ����ѽ���� 
			2��controller�Ķ��塣���ѽ����
			3��controller�Ĳ��ԡ���������� 
		10.12���ȣ�
			1��controller�Ĳ��ԡ����ѽ����
			2��mainTest�Ķ��� �����ѽ����
			3��mainTest�Ĳ��ԡ����ѽ���� 
*/

//-----------------����Ϊͷ�ļ�---------------------------------


#include <stdio.h>
#include <stdlib.h>

//-----------------����Ϊ��������------------------------------- 


#define OK 1
#define ERROR 0


//-----------------����Ϊ�ض���---------------------------------  


typedef int Status;
typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;



//-----------------����Ϊȫ�ֱ�����-----------------------------


int InitFlag = 0;


//-----------------����Ϊ����������-----------------------------


Status initDLinkList_L(DLinkList &L);
void initDLinkList_LN(DLinkList &L);
int getDLinkListLength_L(DLinkList &L);
Status insertDLinkListRandom_L(DLinkList &L,ElemType e);
void insertDLinkListRandom_LN(DLinkList &L,ElemType e);
Status insertDLinkList_L(DLinkList &L,ElemType e,int location);
void showAllOfDLinkLIst_L(DLinkList &L);
Status findDLinkListElem_L(DLinkList &L,int location,ElemType &tmp);
Status clearDLinkList_L(DLinkList &L);
void clearDLinkList_LN(DLinkList &L);
DLinkList findDLinkListLocation_L(DLinkList &L,int &location,ElemType tmp);
Status destoryDLinkList_L(DLinkList &L);
void destoryDLinkList_LN(DLinkList &L);
Status deleteDLinkList_L(DLinkList &L,int location);
void controller(DLinkList &L,DLinkList &L2,int x);
void combineDLinkList_L(DLinkList &L,DLinkList &L2);
DLinkList choseDLinkList_L(DLinkList &L,DLinkList &L2);
void mainMenu(DLinkList &L,DLinkList &L2);

//------���Ժ������� 
void badTest(DLinkList L);
int mainDD();


//-----------------����Ϊ��ʾ�˵�------------------------------- 


void mainMenu(DLinkList &L,DLinkList &L2){
	//����ѡ�����x,n�� 
	int x = 0;
	char n = 0;
	//��ѭ��������break���� 
	while(1){
	printf("\n          ��ӭ����ѭ��������\n\n");
	printf("---------------------------------\n");
	//ʵʱ����������״̬�Լ����ȣ����BUG�죬Ӧ��Ҳֱ�۰ɡ������� 
	if(!InitFlag){
		printf("���������ڣ����½�������\n");
	}else if (InitFlag == 1){
		printf("������ĳ���Ϊ�� %d\n",getDLinkListLength_L(L));
	}else{
		printf("������1�ĳ���Ϊ�� %d\n",getDLinkListLength_L(L));
		printf("������2�ĳ���Ϊ:  %d\n",getDLinkListLength_L(L2));
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
	printf("10����������\n");
	printf("0���˳�\n");
	printf("--------------------------------\n");
	//��ʼ����ѡ�� 
	printf("����������ѡ��");
	scanf("%d",&x);
	fflush(stdin);
	//����ѡ��������Ӧ 
	if(x == 0){
		//break�˳� 
		printf("--------------------------------\n");
		printf("���Խ���\n");
		break;
	}else if(x == 1){
		//���������� 
		printf("--------------------------------\n");
		controller(L,L2,1);
		printf("--------------------------------\n");
	}else if(x >=2 && x <=10){
		//�Ե�������в���������Ҫ�ȼ����״̬������ᱨ�� 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("���������ڣ����½�������\n");
		}else{
			controller(L,L2,x);
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
}


//-----------------����Ϊ���������������ģ�---------------------


int main(){
	DLinkList L,L2;
	DLinkList tmp;
	mainMenu(L,L2);
	return OK;
}


//-----------------����Ϊ������--------------------------------- 


void controller(DLinkList &L,DLinkList &L2,int x){
	switch(x){
		case 1:{//��ʼ��������ʧ�ܷ�Ϊ�Ѵ��ڻ������쳣����ֹ�Ҳ���BUG�� 
			if(InitFlag == 0){
				if(initDLinkList_L(L)){
					printf("��ʼ����һ������ɹ�!\n");
					InitFlag++;
					break; 
				}
			}else if(InitFlag == 1){
				if(initDLinkList_L(L2)){
					printf("��ʼ���ڶ�������ɹ�!\n");
					InitFlag++;
					break;
				}
			}else if(InitFlag == 2){
				printf("��ʼ������ʧ�ܣ��������Ѿ��ﵽ����!\n");
				break;
			}else{
				printf("�����¼�����뼰ʱ�������ύBUG!!!\n");
				break;	
			}
		}
		case 2:{//Ĭ�ϲ��룬�Ͷ���������ƣ�֧�ֶ���������루Y/�����ַ��� 
			ElemType x;
			DLinkList tmp;
			char flag='y';
			tmp = choseDLinkList_L(L,L2);
			while(1){
				printf("\n");
				//����ֵ 
				printf("��������Ҫ���������: ");
				while(1){
				if(scanf("%d",&x) && x >=0){//����Ƿ�Ϊ���֣��Ƿ��ڷ�Χ�� 
						if(insertDLinkListRandom_L(tmp,x)){
							printf("��ӳɹ���\n\n");
							break;
						}else{
							printf("��ӳ����쳣�����������ύBUG����\n\n");
							break;
						}
				}else{//�жϺϷ���� 
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
		case 3:{//ָ��λ�ò������ݣ�֧�ֶ���������루Y/�����ַ��� 
			ElemType x;
			DLinkList tmp;
			char flag='y';
			int location;
			tmp = choseDLinkList_L(L,L2);
			while(OK){
				printf("\n");
				//����ֵ 
				printf("��������Ҫ����ĳɼ�: ");
				while(OK){
					//�жϺϷ����
					if(scanf("%d",&x)){
						//��λ�� 
						printf("���������λ��:  ");
						scanf("%d",&location);
						printf("\n");
						if(location > 0 && location <= getDLinkListLength_L(L)+1 ){
							if(insertDLinkList_L(tmp,x,location)){
								printf("��ӳɹ���\n\n");
								break;
							}else{
								printf("��ӳ���������������ύBUG!\n");
								break;
							}
						}else{
							fflush(stdin);
							printf("��������ȷ��ֵ��\n");
							printf("��������Ҫ����ĳɼ�:");
						}
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
			DLinkList tmp;
			tmp = choseDLinkList_L(L,L2);
			int location;
			printf("��������Ҫɾ����λ��:");
			scanf("%d",&location);
			if(location > 0 && location <= getDLinkListLength_L(tmp)){
				if(deleteDLinkList_L(tmp,location)){
					printf("ɾ���ɹ���\n");
				}else{
					printf("ɾ����������뼰ʱ�������ύBUG!\n");
				}
			}else{
				printf("���벻�Ϸ�������������!\n");
			}
			break;
		}
		case 5:{//ָ��λ���������ݣ�Ҳ����ͨ 
			int location;
			DLinkList tmp;
			ElemType t;
			tmp = choseDLinkList_L(L,L2);
			printf("����������λ�ã�");
			scanf("%d",&location);
			if(location > 0 && location <= getDLinkListLength_L(tmp)){
				if(findDLinkListElem_L(tmp,location,t)){
					printf("�����ɹ������Ϊ: %d\n",t);
				}else{
					printf("����ʧ�ܣ�û�д�����!\n");
				}
			}else{
				printf("���벻�Ϸ�������������!\n");
			}
			break;
		}
		case 6:{//ָ����������λ�� 
			DLinkList p,tmp;
			ElemType t;
			int n,sum;
			sum = 0;
			tmp = choseDLinkList_L(L,L2);
			printf("����������ֵ: \n");
			scanf("%d",&t);
			p = findDLinkListLocation_L(tmp,n,t);
			if(p != tmp){
				sum += n;
				printf("�����ɹ��������ڵ�%d��λ��",sum);
				while(p != tmp){
					p = findDLinkListLocation_L(p,n,t);
					if(p != tmp){
						sum += n;
						if(sum >getDLinkListLength_L(tmp)){
							break;
						}
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
			DLinkList tmp;
			tmp = choseDLinkList_L(L,L2);
			if(!getDLinkListLength_L(tmp)){
				printf("�����������ݣ���������ݣ�\n"); 
			}else{
				showAllOfDLinkLIst_L(tmp);
			}
			break;
		}
		case 8:{//����������ݣ�����ͨ 
			DLinkList tmp;
			char flag;
			tmp = choseDLinkList_L(L,L2);
			fflush(stdin);
			printf("�����ؿ��ǣ��Ƿ�ȷ��������� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(clearDLinkList_L(tmp)){
					printf("��������ɹ���\n");
				}else{//������BUG����� 
					printf("�������ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
		}
		case 9:{//�ݻ����� //
			DLinkList tmp;
			DLinkList target;
			char flag;
			tmp = choseDLinkList_L(L,L2);
			fflush(stdin);
			printf("�����ؿ��ǣ��Ƿ�ȷ���ݻ����� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(tmp == L){
					if(InitFlag == 1){
						if(destoryDLinkList_L(tmp)){
						printf("����ݻٳɹ���\n");
						InitFlag--;
						}else{//������BUG����� 
							printf("����ݻ�ʧ�ܣ����������ύBUG��\n");
						}
					}else if(InitFlag == 2){
						clearDLinkList_LN(tmp);
						combineDLinkList_L(L,L2);
						destoryDLinkList_LN(L2);
						printf("����ݻٳɹ���\n");
						InitFlag--;
					}
				}else if(tmp == L2){
					destoryDLinkList_LN(L2);
					printf("����ݻٳɹ���\n");
					InitFlag--;
				}
			}
			break;
			printf("--------------------------------\n");
			break;
		}
		case 10:{//�������� 
			if(InitFlag == 1){
				printf("���������ף����½�һ����!\n");
			}else if(InitFlag == 2){
				combineDLinkList_L(L,L2);
				printf("�������ӳɹ�!\n");
				InitFlag--;
			}else{
				printf("�����¼�������������ύBUG!\n");
			}
			break;
		} 
	}
}


//--------------����Ϊ����ѡ�񣨸�����������-------------------- 

DLinkList choseDLinkList_L(DLinkList &L,DLinkList &L2){
	char flag;
	if(InitFlag == 1){
		return L; 
	}else if(InitFlag == 2){
		fflush(stdin);
		printf("��ȷ��һ���Ƕ���Y/other��?");
		scanf("%c",&flag);
		fflush(stdin);
		if(flag == 'y' || flag == 'Y'){
			return L;
		}else{
			return L2;
		}
	}
}


//-----------------����Ϊ���Ժ���-------------------------------


void badTest(DLinkList L){//�����Ƿ�������ѭ�� 
	DLinkList target;
	for(target = L;target->next != NULL;target = target->next);
	printf("1\n"); 
}

int mainDD(){//���Ի������� 
	DLinkList L;
	int tmpN;
	DLinkList tmp;
	printf("��ʼ������: ");
	printf("%d\n",initDLinkList_L(L));
	printf("������Ϊ: %d\n",getDLinkListLength_L(L));
	printf("�����������:");
	printf("%d ",insertDLinkListRandom_L(L,1));
	printf("%d ",insertDLinkListRandom_L(L,5));
	printf("%d ",insertDLinkListRandom_L(L,345));
	printf("%d ",insertDLinkListRandom_L(L,412));
	printf("%d ",insertDLinkListRandom_L(L,556));
//	printf("%d ",deleteDLinkList_L(L,3));
//	printf("%d\n",insertDLinkListRandom_L(L,3));
//	insertDLinkListRandom_LN(L,4);
//	printf("%d\n",insertDLinkList_L(L,0,1));
//	printf("%d\n",insertDLinkList_L(L,0,3));
//	printf("%d\n",insertDLinkList_L(L,0,4));
	printf("������Ϊ: %d\n",getDLinkListLength_L(L));
	showAllOfDLinkLIst_L(L);
	tmp = findDLinkListLocation_L(L,tmpN,1);
	printf("%d\n",tmpN);
//	printf("%d",findDLinkListElem_L(L,5,tmpN));
//	printf("%d",tmpN);
	
//	printf("�������%d\n",clearDLinkList_L(L));
//	printf("������Ϊ: %d\n",getDLinkListLength_L(L));
//	showAllOfDLinkLIst_L(L);
	
//	printf("�ݻ�����%d\n",destoryDLinkList_L(L));
//	badTest(L);
//	printf("������Ϊ: %d\n",getDLinkListLength_L(L));
			
}


//---------------------������������-----------------------------// 


//OK
Status initDLinkList_L(DLinkList &L){	//��ʼ������ ����״̬ 
	L = new DNode;
	L->next = L;
	L->prior = L;
	return OK;
}

void initDLinkList_LN(DLinkList &L){	//��ʼ������ ��������ֵ 
	L = new DNode;
	L->next = L;
	L->prior = L;
} 

//OK
int getDLinkListLength_L(DLinkList &L){		//����������  ���س��� 
	int n = 0;
	DLinkList target;
	for(target = L;target->next != L;target = target->next,n++);
	return n;
}

//OK
Status insertDLinkListRandom_L(DLinkList &L,ElemType e){	//ĩβ�������� ����״̬  
	DLinkList target = new DNode;
	target->data = e;
	target->next = L;
	target->prior = L->prior;
	L->prior->next = target;
	L->prior = target;
	return OK;
}

//OK
void insertDLinkListRandom_LN(DLinkList &L,ElemType e){		//ĩβ�������� ��������ֵ 
	DLinkList target = new DNode;
	target->data = e;
	target->next = L;
	target->prior = L->prior;
	L->prior->next = target;
	L->prior = target;
}

//OK
Status insertDLinkList_L(DLinkList &L,ElemType e,int location){		//ָ��λ�ò������� ����״̬ 
	DLinkList target;
	DLinkList tmp = new DNode;
	int i;
	tmp->data = e;
	for(i = 1,target = L;i < location;i++,target = target->next);
	tmp->next = target->next;
	tmp->prior = target;
	target->next->prior = tmp;
	target->next = tmp;
	return OK;	
}

//OK
Status deleteDLinkList_L(DLinkList &L,int location){	//ָ��λ��ɾ������	����״̬ 
	DLinkList target;
	DLinkList tmp;
	int i;
	for(i = 1,target = L;i < location;i++,target = target->next);
	tmp = target->next;
	tmp->next->prior = target;
	target->next = tmp->next;
	delete tmp;
	return OK;
}

//OK
void showAllOfDLinkLIst_L(DLinkList &L){	//��ʾ��������	�޷���ֵ
	int i;
	DLinkList target;
	if(!getDLinkListLength_L(L)){
		printf("��Ϊ�գ���������ݣ�����\n");
	}else{
		printf("�������Ϊ:\n");
		for(i = 1,target = L->next;target != L;i++,target = target->next){
			printf("��%d���ڵ�ֵΪ: %d\n",i,target->data);
		}
	}
}

//OK
Status findDLinkListElem_L(DLinkList &L,int location,ElemType &tmp){	//��λԪ��	����״̬  ��¼���� 
	DLinkList target;
	int i;
	for(i = 1,target = L->next;i < location;target = target->next,i++);
	tmp = target->data;
	return OK;
}

//OK
DLinkList findDLinkListLocation_L(DLinkList &L,int &location,ElemType tmp){		//Ԫ�ض�λ	��������Ϊ�ظ����ݲ�����׼�� 
	DLinkList target;
	for(location = 1,target = L->next;(target->next != L) && (target->data != tmp);target = target->next,location++);
	return target;
}

//OK
Status clearDLinkList_L(DLinkList &L){	//������� ����״̬
	DLinkList target;
	int i;
	for(i = getDLinkListLength_L(L),target = L->next;i < 0;target = target->next,i--){
		deleteDLinkList_L(L,i);
	}
	L->next = L;
	L->prior = L;
	return OK;
} 

void clearDLinkList_LN(DLinkList &L){	//������� �޷���ֵ 
	DLinkList target;
	int i;
	for(i = getDLinkListLength_L(L),target = L->next;i < 0;target = target->next,i--){
		deleteDLinkList_L(L,i);
	}
	L->next = L;
	L->prior = L;
} 


//OK???????
Status destoryDLinkList_L(DLinkList &L){	//�ݻ�����		����״̬ 
	clearDLinkList_L(L);
	L->next = NULL;
	L->prior = NULL;
	delete L;
	return OK;
}

void destoryDLinkList_LN(DLinkList &L){	//�ݻ�����		�޷���ֵ
	clearDLinkList_L(L);
	L->next = NULL;
	L->prior = NULL;
	delete L;
}


void combineDLinkList_L(DLinkList &L,DLinkList &L2){	//������  �޷���ֵ 
	DLinkList target,target2;
	target = L;
	target2 = L2;
	target->prior->next = target2->next;
	target2->next->prior = target->prior;
	target2->prior->next = target;
	target->prior = target2;
	delete L2;
}
