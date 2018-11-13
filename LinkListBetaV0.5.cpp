/*
	Title:链表的简单制作与复习
	Date:2018.9.19
	Owner:赵衍博 
	Details:
		1、“********”为链表基础函数，且已测试好，检测BUG优先级最低。
		2、“ElemChangeable”为可改变选项，主要关于ElemType的定义，出现时即为可更改，不过需要做改动。
		3、 由实训所感（可能也麻烦），独立出控制函数controller(LinkList &L,int x),利用基本函数表示。 
		4、	添加了对链表存在状态检测(利用int类型全局变量InitFlag)，防止错误弹出。
		 


*/

//-----------------以下为头文件---------------------------------

 
#include <stdio.h>
#include <cstdlib>


//-----------------以下为重定义---------------------------------  


typedef int ElemType; //重定义数据类型（先用int），以供后续类型修改 
typedef int Status;	  //重定义状态，表示函数是否正常运行
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode,*LinkList;


//-----------------以下为常量定义-------------------------------  


#define OK 1
#define ERROR 0
#define MAXSIZE 100


//-----------------以下为函数定义区-----------------------------


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

//-----------------以下为全局变量区-----------------------------


int InitFlag = 0;


//-----------------以下为主函数（启动核心）---------------------


int main(){
	LinkList L;
	mainTest(L);
	return 0;
}


//-----------------以下为表示菜单------------------------------- 


void mainTest(LinkList &L){//主菜单 
	int x=0;
	while(1){
	printf("\n          欢迎测试单链表\n\n");
	printf("---------------------------------\n");
	if(!InitFlag){
		printf("单链表不存在，请新建单链表！\n");
	}else{
		printf("单链表的长度为： %d\n",ListLength_L(L));
	} 
	printf("---------------------------------\n");
	printf("请输入数字以进行以下功能\n");
	printf("1、新建单链表\n");
	printf("2、统计链表长度\n");
	printf("3、插入（指定位置）\n");
	printf("4、删除（指定位置）\n");
	printf("5、查找（指定位置）\n");
	printf("6、查找（指定数据）\n"); 
	printf("7、显示所有数据\n");
	printf("8、退出\n");
	printf("--------------------------------\n");
	printf("请输入您的选择：");
	scanf("%d",&x);
	if(x == 1){
		printf("--------------------------------\n");
		controller(L,1);
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=7){
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("单链表不存在，请新建单链表！\n");
		}else{
			controller(L,x);
		}
		printf("--------------------------------\n");
	}else if(x == 8){
		printf("--------------------------------\n");
		printf("测试结束\n");
		break;
	}else{
		printf("选择错误，请重新输入！\n");
	}
	system("pause");
	system("cls");
	}
	return;
}


//-----------------以下为控制器--------------------------------- 


void controller(LinkList &L,int x){
	switch(x){
		case 1:{
			if(InitList_L(L)){
				printf("初始化链表成功！\n");
				InitFlag = 1;
			}else{
				if(InitFlag){
					printf("初始化链表失败，已存在链表！\n");
				}else{
					printf("初始化链表失败，请向作者提交Bug!\n");
				}
				
			}
			break;
		}
		case 2:{
			printf("链表长度为:  %d\n",ListLength_L(L));
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
				printf("请输入你要输入的值: ");
				scanf("%d",&x);
				printf("请输入插入位置:  ");
				scanf("%d",&location);
				if(ListInsert_L(p,location,x)){
					printf("添加成功！\n");
				}else{
						printf("添加失败，请检查插入数据或数组长度是否合法!\n");
				}
				printf("请问您要继续输入吗？(y/other)  :");
				fflush(stdin);
				scanf("%c",&flag);
			}
			break;
		}
		case 4:{
			int location;
			ElemType tmp;
			printf("请输入你要删除的位置:");
			scanf("%d",&location);
			if(ListDelete_L(L,location,tmp)){
				printf("删除成功！\n");
			}else{
				printf("删除失败，请检查插入数据或数组长度是否合法!\n");
			}
			break;
		}
		case 5:{
			int location;
			ElemType tmp;
			printf("请输入数的位置：");
			scanf("%d",&location);
			if(GetElem_L(L,location,tmp)){
				printf("搜索成功，结果为：%d!\n",tmp);
			}else{
				printf("搜索失败，没有此内容！\n");
			}
			return;
			break;
		}
		case 6:{
			int p;
			ElemType tmp;
			printf("请你输入数据: \n");
			scanf("%d",&tmp);
			p = LocateElem_L(L,tmp);
			if(p){
				printf("搜索成功！数据在第%d个位置",p);
			}else{
				printf("搜索失败，数据不存在！");
			}
			break;
		}
		case 7:{
			if(!ListLength_L(L)){
				printf("链表内无数据，请添加数据！\n"); 
			}else{
				ShowAll(L);
			}
			break;
		}
	}
}


//-----------------以下为基本函数------------------------------- 


Status InitList_L(LinkList &L){	//初始化链表与头结点，申请空间  ********
	L=new LNode;
	L->next=NULL;
	return OK;
}

Status DestoryList_L(LinkList &L){//摧毁链表					********
	LinkList p;
		while(L)
		{
			p=L;
			L=L->next;
			delete p;
		}
	return OK;
}

Status ClearList(LinkList &L){//清空链表所有数据 				********
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

int ListLength_L(LinkList L){//计算链表长度 					********
	int i = 0;
	LinkList p;
	p=L->next;
	while(p){
		i++;
		p=p->next;
	}
	return i;
}

int ListEmpty(LinkList L){//检测链表是否为空 					********
	if(L->next)
		return 0;
	else
		return 1;
}

Status GetElem_L(LinkList L,int i,ElemType &tmp){//取值			********
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

int LocateElem_L(LinkList L,ElemType e){//取值（值定位）		********
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

Status ListInsert_L(LinkList &L,int i,ElemType e){//定点插入    ******** 
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

Status ListDelete_L(LinkList &L,int i,ElemType &e){//定点删除	******** 
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

void ShowAll(LinkList &L){//全部输出 							********
	LinkList p = L->next;
	int i = 1;
	printf("您输出的结果为:\n");
	while(p){
		printf("您的第%d个节点为%d\n",i,p->data);
		p = p->next;
		i++;
	}
	return;
}

