/*
	Title:ѭ������ļ���ϰ
	Timeline:2018.9.30
	Owner: ���ܲ�
	Details:
		9.30����
			1�����ѭ��������������Ĵ�������ԡ�(�ѽ����
			2��controller�����Ĵ������ѽ���� 
		10.7���� 
			3�����������ѽ��������λ���ѽ������ɾ�����ѽ�������ݻ٣���һ�����ܣ��ѽ���� 
		10.8����	
			4�����Ӻ�����׼�������ѽ���� 
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

int InitFlag = 0;


Status initCList_L(CLinkList &L){		//��ʼ������ 
	L = new CNode;
	L->next = L;
	return OK;	
};

void initCList_LN(CLinkList &L){
	L = new CNode;
	L->next = L;
} 

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

CLinkList findLocation_L(CLinkList L,int &i,ElemType e){	//��λ 
	CLinkList target;
	i = 1;
	for(target = L;target->next != L;target = target->next);
	for(target = target->next->next;(target->data != e) && (target->next != L);i++){
		target = target->next;
	}
	if(target->data == e){
		return target;
	}else{
		return NULL;
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

void showAll(CLinkList L){///��ʾȫ����Ϣ 
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

void crushList(CLinkList &L){ //�޷���ֵ�ݻ����� 
	CLinkList target;
	for(target = L;target->next != L;target = target->next);
	target->next = NULL;
		while(L)
		{
			target=L;
			L=L->next;
			delete target;
		}
}

Status combineCList(CLinkList &L,CLinkList &L2){
	CLinkList target_L;
	CLinkList target_L2;
	CLinkList tmp;
	if(L2->next == L2){
		return ERROR;
		printf("����Ϊ�գ��˳�\n");
	}else{
		for(target_L = L;target_L->next != L;target_L = target_L->next);
		for(target_L2 = L2;target_L2->next != L2;target_L2 = target_L2->next);
		tmp = L2;
		target_L->next = tmp->next;
		target_L2->next = L;
		delete tmp;
		return OK;
		printf("���ӳɹ�����鿴Ч��\n");
	}
	
}

Status combineCListN(CLinkList &L,CLinkList &L2){	//ѭ���б�ϲ���L2�ݻ�û����̫���˰�������������������죡 
	CLinkList p = L2->next;
	int i;
	for(i = 1; i <= findCListLength_L(L2);p = p->next){
		i += insertCListRandom_L(L,p->data);
	}
	printf("���ӳɹ�����鿴Ч��\n");
	return 0;
}




Status clearList(CLinkList &L){	//�������������
 CLinkList p,q;
	p=L->next;
	while(p != L){
		q=p->next;
		delete p;
		p=q;
	}
	L->next=L;
	return OK;
}

Status clearListL(CLinkList &L){ //�������Legend���� 
	crushList(L);
	initCList_LN(L);
	return OK;	
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


void JosephusRemoveTools(CLinkList &L,CLinkList &target){//Լɪ��ɾ������ 
	CLinkList tmp;
	CLinkList del;
	del = target;
	for(tmp = L;tmp->next != L;tmp = tmp->next);
	tmp = tmp->next->next;
	for(;tmp->next != target;tmp = tmp->next){
		if(tmp == L){
			tmp = tmp->next;
		}
	}
	target = target->next;
	if(target == L){
		tmp->next = target;
		target = target->next;
	}else{
		tmp->next = target;
	}
	
	free(del);
}

void Josephus(CLinkList L,int n,int m){//β�ڵ�ɾ��δ��� 
	CLinkList target;
	CLinkList target1;
	CLinkList test;
	int i,j;
	ElemType e;
	for(target = L;target->next != L;target = target->next);
	target = target->next->next;
	for(i = 0;i < n-1;i++){
		for(j = 0;j <m;j++){
			target = target->next;
			if(target == L){
				target = target->next;
			}
		}
		printf("���е���Ϊ%d\n",target->data);
	for(test = L;test->next != L;test = test->next);
	test = test->next;
	printf("��ǰ����ѭ������\n");
		JosephusRemoveTools(L,target);
	showAll(L);
//		for(target1 = L;target1->next != target;target1 = target1->next);
//		target1 = target-1111>next;
//		if(target1 == L){
//			target1 = target1->next;
//		}
//		tmp = target;
//		target = target->next;
//		target1->next = target;
//		free(tmp);
	}
}

void controller(CLinkList &L,int x){
	switch(x){
		case 1:{//��ʼ��������ʧ�ܷ�Ϊ�Ѵ��ڻ������쳣����ֹ�Ҳ���BUG�� 
			if(initCList_L(L)){
				printf("��ʼ������ɹ���\n");
				InitFlag++;
			}else{
				if(InitFlag){
					printf("��ʼ������ʧ�ܣ��Ѵ�������\n");
				}else{
					printf("��ʼ������ʧ�ܣ����������ύBug!\n");
				}
			}
			break;
		}
		case 2:{//Ĭ�ϲ��룬�Ͷ���������ƣ�֧�ֶ���������루Y/�����ַ��� 
			ElemType x;
			CLinkList p;
			char flag='y';
			while(1){
				p = L;
				printf("\n");
				//����ֵ 
				printf("��������Ҫ���������: ");
				while(1){
				if(scanf("%d",&x) && x >=0){//����Ƿ�Ϊ���֣��Ƿ��ڷ�Χ�� 
						if(insertCListRandom_L(p,x)){
							printf("��ӳɹ���\n\n");
							break;
						}else{
							printf("���ʧ�ܣ����������ύBUG����\n\n");
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
			CLinkList p;
			char flag='y';
			int location;
			while(1){
				p = L;
				printf("\n");
				//����ֵ 
				printf("��������Ҫ����ĳɼ�: ");
				while(1){
					//�жϺϷ����
					if(scanf("%d",&x)){
						//��λ�� 
						printf("���������λ��:  ");
						scanf("%d",&location);
						printf("\n");
						if(insertCList_L(p,location,x)){
							printf("��ӳɹ���\n\n");
							break;
						}else{
							printf("���ʧ�ܣ�����������ݻ����鳤���Ƿ�Ϸ�!\n\n");
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
			printf("��������Ҫɾ����λ��:");
			scanf("%d",&location);
			if(deleteElem_L(L,location)){
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
			if(findLocatedElem_L(L,location,tmp)){
				printf("�����ɹ������Ϊ: %d\n",tmp);
			}else{
				printf("����ʧ�ܣ�û�д����ݣ�\n");
			}
			return;
			break;
		}
		case 6:{//ָ����������λ�� 
			CLinkList p;
			ElemType tmp;
			int sum = 0;
			int n;
			printf("����������ֵ: \n");
			scanf("%d",&tmp);
			p = findLocation_L(L,n,tmp);
			if(p){
				sum += n;
				printf("�����ɹ��������ڵ�%d��λ��",sum);
				while(p){
					p = findLocation_L(p,n,tmp);
					if(p){
						sum += n;
						if(sum > findCListLength_L(L)){
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
			if(!findCListLength_L(L)){
				printf("�����������ݣ���������ݣ�\n"); 
			}else{
				showAll(L);
			}
			break;
		}
		case 8:{//����������ݣ�����ͨ 
			char flag;
			fflush(stdin);
			printf("�����ؿ��ǣ��Ƿ�ȷ��������� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(clearList(L)){
					printf("��������ɹ���\n");
				}else{//������BUG����� 
					printf("�������ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
		}
		case 9:{
			char flag;
			fflush(stdin);
			printf("�����ؿ��ǣ��Ƿ�ȷ���ݻ����� (y/other) ��");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(destoryCList(L)){
					printf("����ݻٳɹ���\n");
					InitFlag--;
				}else{//������BUG����� 
					printf("����ݻ�ʧ�ܣ����������ύBUG��\n");
				}
			}
			break;
			printf("--------------------------------\n");
			break;
		} 
	}
}

int mainMenu(CLinkList &L,CLinkList &L2){
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
		printf("������ĳ���Ϊ�� %d\n",findCListLength_L(L));
	}else{
		printf("������1�ĳ���Ϊ�� %d\n",findCListLength_L(L));
		printf("������2�ĳ���Ϊ:  %d\n",findCListLength_L(L2));
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
		//�Ե�������в���������Ҫ�ȼ����״̬������ᱨ�� 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("���������ڣ����½�������\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("��ѡ������YΪ��һ��������Ϊ�ڶ�����");
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
			printf("���������ڣ����½�������\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("��ѡ������YΪ��һ��������Ϊ�ڶ�����");
			scanf("%c",&n);
			fflush(stdin);
			if(n == 'y' || n == 'Y'){
				clearList(L);
				combineCList(L,L2);
				crushList(L2);
				InitFlag--;
			}else{
				crushList(L2);
				InitFlag--;
			}
			printf("�Ѵݻٵ�����\n");
		}
		printf("--------------------------------\n");			
	}else if(x == 10){
		printf("--------------------------------\n");
		if(InitFlag == 0){
		printf("���������ڣ����½�������\n");
		}
		else if(InitFlag == 1){
			printf("�����������ף����ٽ�һ����\n"); 
		}else if(InitFlag == 2){
			combineCList(L,L2);
			InitFlag--;
			printf("���ӳɹ�����鿴Ч��\n");
		}else{
			InitFlag = 0;
			printf("�������������µ�BUG���������ύ������һ��\n");
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
	return 0;
}


int main(){
	CLinkList L;
	CLinkList L2;
	mainMenu(L,L2);
	return 0;
}

int mainTest(){
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
	Josephus(L,findCListLength_L(L),2);
	
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
