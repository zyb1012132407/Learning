/*
	Title:链表的简单制作与复习
	TimeLine:2018.9.19
	Owner:赵衍博 
	Details:
		9.19进度 
		1、“********”为链表基础函数，且已测试好，检测BUG优先级最低
		2、“ElemChangeable”为可改变选项，主要关于ElemType的定义，出现时即为可更改，不过需要做改动
		9.20进度 
		3、 由实训所感（可能也麻烦），独立出控制函数void controller(LinkList &L,int x),利用基本函数表示 
		4、	添加了对链表存在状态检测(利用int类型全局变量InitFlag)，防止错误弹出	
		5、 （已解决）链表根据数据搜索需要改进，只考虑单数据，未考虑多个相同数据
				（可能需要改的地方：case 6;
									int LocateElem_L(LinkList L,ElemType e);
									void mainTest(LinkList &L);
									etc....） 
									
		6、	（已解决一部分）链表扩展功能未添加（	1、末位置添加					（已解决） 
													2、清除链表（基础函数已写）		（已解决） 
													3、摧毁链表（基础函数已写）		（已解决） 
																								） 
		9.21进度：用学生表吧，谁知道做得出来做不出来呢，敬业先锋可能就是这样吧，太真实了 


*/

//-----------------以下为头文件---------------------------------

 
#include <stdio.h>
#include <cstdlib>
#include <string.h>


//-----------------以下为重定义---------------------------------  


//typedef int ElemType; //重定义数据类型（先用int），以供后续类型修改 
typedef int Status;	  //重定义状态，表示函数是否正常运行

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


//-----------------以下为常量定义-------------------------------  


#define OK 1
#define ERROR 0
#define MAXSIZE 100


//-----------------以下为函数定义区-----------------------------


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


//-----------------以下为全局变量区-----------------------------


int InitFlag = 0;	//检测链表是否创建
int ListSearch_Y_or_N = 1; //检测搜索状态  


//-----------------以下为主函数（启动核心）---------------------


int main(){
	LinkList L;
	mainTest(L);
	return 0;
}


//-----------------以下为表示菜单------------------------------- 


void mainTest(LinkList &L){//主菜单 
	//定义选择变量X。 
	int x=0;
	//死循环，利用break跳出 
	while(1){
	printf("\n          欢迎测试单链表\n\n");
	printf("---------------------------------\n");
	//实时检测链表存在状态以及长度（检测BUG快，应该也直观吧。。。） 
	if(!InitFlag){
		printf("单链表不存在，请新建单链表！\n");
	}else{
		printf("单链表的长度为： %d\n",ListLength_L(L));
	} 
	//选择菜单 
	printf("---------------------------------\n");
	printf("请输入数字以进行以下功能\n");
	printf("1、新建单链表\n");
	printf("2、插入（后续位置）\n");
	printf("3、插入（指定位置）\n");
	printf("4、删除（指定位置）\n");
	printf("5、查找（指定位置）\n");
	printf("6、查找（指定数据）\n"); 
	printf("7、显示所有数据\n");
	printf("8、清除链表数据（慎重选择）\n");
	printf("9、摧毁链表（慎重选择）\n");
	printf("0、退出\n");
	printf("--------------------------------\n");
	//开始输入选择 
	printf("请输入您的选择：");
	scanf("%d",&x);
	//根据选择做出反应 
	if(x == 0){
		//break退出 
		printf("--------------------------------\n");
		printf("测试结束\n");
		break;
	}
	else if(x == 1){
		//构建单链表 
		printf("--------------------------------\n");
		controller(L,1);
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=9){
		//对单链表进行操作，不过要先检测其状态，否则会报错 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("单链表不存在，请新建单链表！\n");
		}else{
			controller(L,x);
		}
		printf("--------------------------------\n");
	}else{
		printf("选择错误，请重新输入！\n");
	}
	//完成操作后暂停一下，防止输出结果闪过（借用老师源代码方法，getchar()也可以不过相比来说要差一些） 
	system("pause");
	//清屏操作 
	system("cls");
	}
	return;
}


//-----------------以下为控制器--------------------------------- 


void controller(LinkList &L,int x){
	switch(x){
		case 1:{//初始化链表，将失败分为已存在或其他异常（防止找不到BUG） 
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
//		case 2:{//链表长度，没啥用，为了和样本对应（绝对不是凑数！绝对不是凑数！绝对不是凑数！） 
//			printf("链表长度为:  %d\n",ListLength_L(L));
//			break;
//		}
		case 2:{//默认插入，和定点插入类似，支持多次连续插入（Y/其他字符） 
			ElemType x;
			LinkList p;
			char flag='y';
			while(1){
				p = L;
				printf("\n");
				//输数值 
				printf("请输入你要输入的姓名: ");
				scanf("%s",x.name);
				printf("请输入你要输入的学号: ");
				scanf("%s",x.num);
				printf("请输入你要输入的成绩: ");
				scanf("%d",&x.grade);
				//判断合法与否
				if(ListInsertRandom_L(p,x)){
					printf("添加成功！\n\n");
				}else{
					printf("添加失败，请向作者提交BUG！！\n\n");
				}
				printf("请问您要继续输入吗？(y/other)  :");
				//清除数据缓冲区 
				fflush(stdin);
				scanf("%c",&flag);
				//画线 
				if(flag == 'y' ||  flag == 'Y'){
					printf("---------------------------------\n");
				}else{
					break;
				}
			}
			break;
		}
		case 3:{//指定位置插入数据，支持多次连续插入（Y/其他字符） 
			ElemType x;
			LinkList p;
			char flag='y';
			int location;
			while(1){
				p = L;
				printf("\n");
				//输数值 
				printf("请输入你要输入的姓名: ");
				scanf("%s",x.name);
				printf("请输入你要输入的学号: ");
				scanf("%s",x.num);
				printf("请输入你要输入的成绩: ");
				scanf("%d",&x.grade);
				//输位置 
				printf("请输入插入位置:  ");
				scanf("%d",&location);
				printf("\n");
				//判断合法与否
				if(ListInsert_L(p,location,x)){
					printf("添加成功！\n\n");
				}else{
						printf("添加失败，请检查插入数据或数组长度是否合法!\n\n");
				}
				printf("请问您要继续输入吗？(y/other)  :");
				//清除数据缓冲区 
				fflush(stdin);
				scanf("%c",&flag);
				//画线 
				if(flag == 'y' ||  flag == 'Y'){
					printf("---------------------------------\n");
				}else{
					break;
				}
			}
			break;
		}
		case 4:{//指定位置删除数据，很普通 
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
		case 5:{//指定位置搜索数据，也很普通 
			int location;
			ElemType tmp;
			printf("请输入数的位置：");
			scanf("%d",&location);
			if(GetElem_L(L,location,tmp)){
				printf("搜索成功，结果为: \n姓名: %s,学号: %s,成绩: %d\n",tmp.name,tmp.num,tmp.grade);
			}else{
				printf("搜索失败，没有此内容！\n");
			}
			return;
			break;
		}
		case 6:{//指定数据搜索位置，实现重复数据全部搜索（修复相关BUG优先级最高，因为做的时候一遍过= =） 
			LinkList p;
			ElemType tmp;
			int sum = 0;
			int n;
			printf("请你输入姓名: \n");
			scanf("%s",tmp.name);
			p = LocateElem_L_EX(L,tmp,n);
			if(p){
				sum += n;
				printf("搜索成功！数据在第%d个位置",sum);
				p = p->next;
				while(p){
					p = LocateElem_L_EX(p,tmp,n);
					sum += n;
					printf("，第%d个位置",sum);
				}
				printf("\n");
			}else{
				printf("搜索失败，数据不存在！\n");
			}
			break;
		}
		case 7:{//显示全部数据，检测链表是否含数据 
			if(!ListLength_L(L)){
				printf("链表内无数据，请添加数据！\n"); 
			}else{
				ShowAll(L);
			}
			break;
		}
		case 8:{//清除链表数据，很普通 
			char flag;
			printf("请慎重考虑！是否确定清除链表？ (y/other) ：");
			fflush(stdin);
			scanf("%c",&flag);
			if(flag == 'y' || flag == 'Y'){
				if(ClearList(L)){
					printf("链表清除成功！\n");
				}else{//留个修BUG的余地 
					printf("链表清除失败！请向作者提交BUG！\n");
				}
			}
			break;
		} 
		case 9:{//摧毁链表，很普通 
			char flag;
			printf("请慎重考虑！是否确定摧毁链表？ (y/other) ：");
			fflush(stdin);
			scanf("%c",&flag);
			if(flag == 'y' || flag == 'Y'){
				if(DestoryList_L(L)){
					printf("链表摧毁成功！\n");
					InitFlag = 0;
				}else{//留个修BUG的余地 
					printf("链表摧毁失败！请向作者提交BUG！\n");
				}
			}
			break;
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

//int LocateElem_L(LinkList L,char e[]){//取值（值定位）		********
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

LinkList LocateElem_L_EX(LinkList L,ElemType e,int &n){//取值修改版（实现重复数据全部搜索，修复相关BUG优先级最高） 
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

//LinkList OldLocateElem_L_EX(LinkList L,ElemType e,int &n){//取值修改版（实现重复数据全部搜索，修复相关BUG优先级最高） 
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

Status ListInsertRandom_L(LinkList &L,ElemType e){//随机插入（后面接上） 
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

Status OldListInsert_L(LinkList &L,int i,ElemType e){//定点插入    ******** 
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

Status OldListDelete_L(LinkList &L,int i,ElemType &e){//定点删除	******** 
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
		printf("您的第%d个节点为: \n姓名: %s,学号: %s,成绩: %d\n",i,p->data.name,p->data.num,p->data.grade);
		p = p->next;
		i++;
	}
	return;
}

void OldShowAll(LinkList &L){//全部输出 							********
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

