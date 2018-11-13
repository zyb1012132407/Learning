/*
	Title:双向循环链表练习
	Owner:赵衍博
	Details:
		10.9进度：
			1、挖个坑。。。。。
		10.11进度：
			1、完成基本函数的定义、完善，并进行调试。（已解决） 
			2、controller的定义。（已解决）
			3、controller的测试。（待解决） 
		10.12进度：
			1、controller的测试。（已解决）
			2、mainTest的定义 。（已解决）
			3、mainTest的测试。（已解决） 
*/

//-----------------以下为头文件---------------------------------


#include <stdio.h>
#include <stdlib.h>

//-----------------以下为常量定义------------------------------- 


#define OK 1
#define ERROR 0


//-----------------以下为重定义---------------------------------  


typedef int Status;
typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinkList;



//-----------------以下为全局变量区-----------------------------


int InitFlag = 0;


//-----------------以下为函数定义区-----------------------------


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

//------测试函数定义 
void badTest(DLinkList L);
int mainDD();


//-----------------以下为表示菜单------------------------------- 


void mainMenu(DLinkList &L,DLinkList &L2){
	//定义选择变量x,n。 
	int x = 0;
	char n = 0;
	//死循环，利用break跳出 
	while(1){
	printf("\n          欢迎测试循环单链表\n\n");
	printf("---------------------------------\n");
	//实时检测链表存在状态以及长度（检测BUG快，应该也直观吧。。。） 
	if(!InitFlag){
		printf("单链表不存在，请新建单链表！\n");
	}else if (InitFlag == 1){
		printf("单链表的长度为： %d\n",getDLinkListLength_L(L));
	}else{
		printf("单链表1的长度为： %d\n",getDLinkListLength_L(L));
		printf("单链表2的长度为:  %d\n",getDLinkListLength_L(L2));
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
	printf("10、两表连接\n");
	printf("0、退出\n");
	printf("--------------------------------\n");
	//开始输入选择 
	printf("请输入您的选择：");
	scanf("%d",&x);
	fflush(stdin);
	//根据选择做出反应 
	if(x == 0){
		//break退出 
		printf("--------------------------------\n");
		printf("测试结束\n");
		break;
	}else if(x == 1){
		//构建单链表 
		printf("--------------------------------\n");
		controller(L,L2,1);
		printf("--------------------------------\n");
	}else if(x >=2 && x <=10){
		//对单链表进行操作，不过要先检测其状态，否则会报错 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("单链表不存在，请新建单链表！\n");
		}else{
			controller(L,L2,x);
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
}


//-----------------以下为主函数（启动核心）---------------------


int main(){
	DLinkList L,L2;
	DLinkList tmp;
	mainMenu(L,L2);
	return OK;
}


//-----------------以下为控制器--------------------------------- 


void controller(DLinkList &L,DLinkList &L2,int x){
	switch(x){
		case 1:{//初始化链表，将失败分为已存在或其他异常（防止找不到BUG） 
			if(InitFlag == 0){
				if(initDLinkList_L(L)){
					printf("初始化第一个链表成功!\n");
					InitFlag++;
					break; 
				}
			}else if(InitFlag == 1){
				if(initDLinkList_L(L2)){
					printf("初始化第二个链表成功!\n");
					InitFlag++;
					break;
				}
			}else if(InitFlag == 2){
				printf("初始化链表失败，链表数已经达到上限!\n");
				break;
			}else{
				printf("链表记录错误，请及时向作者提交BUG!!!\n");
				break;	
			}
		}
		case 2:{//默认插入，和定点插入类似，支持多次连续插入（Y/其他字符） 
			ElemType x;
			DLinkList tmp;
			char flag='y';
			tmp = choseDLinkList_L(L,L2);
			while(1){
				printf("\n");
				//输数值 
				printf("请输入你要输入的数字: ");
				while(1){
				if(scanf("%d",&x) && x >=0){//检测是否为数字，是否在范围内 
						if(insertDLinkListRandom_L(tmp,x)){
							printf("添加成功！\n\n");
							break;
						}else{
							printf("添加程序异常，请向作者提交BUG！！\n\n");
							break;
						}
				}else{//判断合法与否 
					fflush(stdin);
					printf("请输入正确数值！\n");
					printf("请输入你要输入的成绩:");
				}	
				}
				printf("请问您要继续输入吗？(y/other)  :");
				//清除数据缓冲区 
				fflush(stdin);
				scanf("%c",&flag);
				fflush(stdin);
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
			DLinkList tmp;
			char flag='y';
			int location;
			tmp = choseDLinkList_L(L,L2);
			while(OK){
				printf("\n");
				//输数值 
				printf("请输入你要输入的成绩: ");
				while(OK){
					//判断合法与否
					if(scanf("%d",&x)){
						//输位置 
						printf("请输入插入位置:  ");
						scanf("%d",&location);
						printf("\n");
						if(location > 0 && location <= getDLinkListLength_L(L)+1 ){
							if(insertDLinkList_L(tmp,x,location)){
								printf("添加成功！\n\n");
								break;
							}else{
								printf("添加程序错误，请向作者提交BUG!\n");
								break;
							}
						}else{
							fflush(stdin);
							printf("请输入正确数值！\n");
							printf("请输入你要输入的成绩:");
						}
					}
				}
					printf("请问您要继续输入吗？(y/other)  :");
					//清除数据缓冲区 
					fflush(stdin);
					scanf("%c",&flag);
					fflush(stdin);
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
			DLinkList tmp;
			tmp = choseDLinkList_L(L,L2);
			int location;
			printf("请输入你要删除的位置:");
			scanf("%d",&location);
			if(location > 0 && location <= getDLinkListLength_L(tmp)){
				if(deleteDLinkList_L(tmp,location)){
					printf("删除成功！\n");
				}else{
					printf("删除程序错误，请及时向作者提交BUG!\n");
				}
			}else{
				printf("输入不合法，请重新输入!\n");
			}
			break;
		}
		case 5:{//指定位置搜索数据，也很普通 
			int location;
			DLinkList tmp;
			ElemType t;
			tmp = choseDLinkList_L(L,L2);
			printf("请输入数的位置：");
			scanf("%d",&location);
			if(location > 0 && location <= getDLinkListLength_L(tmp)){
				if(findDLinkListElem_L(tmp,location,t)){
					printf("搜索成功，结果为: %d\n",t);
				}else{
					printf("搜索失败，没有此内容!\n");
				}
			}else{
				printf("输入不合法，请重新输入!\n");
			}
			break;
		}
		case 6:{//指定数据搜索位置 
			DLinkList p,tmp;
			ElemType t;
			int n,sum;
			sum = 0;
			tmp = choseDLinkList_L(L,L2);
			printf("请你输入数值: \n");
			scanf("%d",&t);
			p = findDLinkListLocation_L(tmp,n,t);
			if(p != tmp){
				sum += n;
				printf("搜索成功！数据在第%d个位置",sum);
				while(p != tmp){
					p = findDLinkListLocation_L(p,n,t);
					if(p != tmp){
						sum += n;
						if(sum >getDLinkListLength_L(tmp)){
							break;
						}
						printf("，第%d个位置",sum);
					}else{
						break;
					}
				}
				printf("\n");
			}else{
				printf("搜索失败，数据不存在！\n");
			}
			break;
		}
		case 7:{//显示全部数据，检测链表是否含数据 
			DLinkList tmp;
			tmp = choseDLinkList_L(L,L2);
			if(!getDLinkListLength_L(tmp)){
				printf("链表内无数据，请添加数据！\n"); 
			}else{
				showAllOfDLinkLIst_L(tmp);
			}
			break;
		}
		case 8:{//清除链表数据，很普通 
			DLinkList tmp;
			char flag;
			tmp = choseDLinkList_L(L,L2);
			fflush(stdin);
			printf("请慎重考虑！是否确定清除链表？ (y/other) ：");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(clearDLinkList_L(tmp)){
					printf("链表清除成功！\n");
				}else{//留个修BUG的余地 
					printf("链表清除失败！请向作者提交BUG！\n");
				}
			}
			break;
		}
		case 9:{//摧毁链表 //
			DLinkList tmp;
			DLinkList target;
			char flag;
			tmp = choseDLinkList_L(L,L2);
			fflush(stdin);
			printf("请慎重考虑！是否确定摧毁链表？ (y/other) ：");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(tmp == L){
					if(InitFlag == 1){
						if(destoryDLinkList_L(tmp)){
						printf("链表摧毁成功！\n");
						InitFlag--;
						}else{//留个修BUG的余地 
							printf("链表摧毁失败！请向作者提交BUG！\n");
						}
					}else if(InitFlag == 2){
						clearDLinkList_LN(tmp);
						combineDLinkList_L(L,L2);
						destoryDLinkList_LN(L2);
						printf("链表摧毁成功！\n");
						InitFlag--;
					}
				}else if(tmp == L2){
					destoryDLinkList_LN(L2);
					printf("链表摧毁成功！\n");
					InitFlag--;
				}
			}
			break;
			printf("--------------------------------\n");
			break;
		}
		case 10:{//两表连接 
			if(InitFlag == 1){
				printf("表不够啊，亲，再新建一个吧!\n");
			}else if(InitFlag == 2){
				combineDLinkList_L(L,L2);
				printf("链表连接成功!\n");
				InitFlag--;
			}else{
				printf("链表记录错误，请向作者提交BUG!\n");
			}
			break;
		} 
	}
}


//--------------以下为链表选择（辅助控制器）-------------------- 

DLinkList choseDLinkList_L(DLinkList &L,DLinkList &L2){
	char flag;
	if(InitFlag == 1){
		return L; 
	}else if(InitFlag == 2){
		fflush(stdin);
		printf("请确定一表还是二表（Y/other）?");
		scanf("%c",&flag);
		fflush(stdin);
		if(flag == 'y' || flag == 'Y'){
			return L;
		}else{
			return L2;
		}
	}
}


//-----------------以下为测试函数-------------------------------


void badTest(DLinkList L){//测试是否能正常循环 
	DLinkList target;
	for(target = L;target->next != NULL;target = target->next);
	printf("1\n"); 
}

int mainDD(){//测试基本函数 
	DLinkList L;
	int tmpN;
	DLinkList tmp;
	printf("初始化链表: ");
	printf("%d\n",initDLinkList_L(L));
	printf("链表长度为: %d\n",getDLinkListLength_L(L));
	printf("链表插入数据:");
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
	printf("链表长度为: %d\n",getDLinkListLength_L(L));
	showAllOfDLinkLIst_L(L);
	tmp = findDLinkListLocation_L(L,tmpN,1);
	printf("%d\n",tmpN);
//	printf("%d",findDLinkListElem_L(L,5,tmpN));
//	printf("%d",tmpN);
	
//	printf("清空链表：%d\n",clearDLinkList_L(L));
//	printf("链表长度为: %d\n",getDLinkListLength_L(L));
//	showAllOfDLinkLIst_L(L);
	
//	printf("摧毁链表：%d\n",destoryDLinkList_L(L));
//	badTest(L);
//	printf("链表长度为: %d\n",getDLinkListLength_L(L));
			
}


//---------------------基本函数区域-----------------------------// 


//OK
Status initDLinkList_L(DLinkList &L){	//初始化链表 返回状态 
	L = new DNode;
	L->next = L;
	L->prior = L;
	return OK;
}

void initDLinkList_LN(DLinkList &L){	//初始化链表 不带返回值 
	L = new DNode;
	L->next = L;
	L->prior = L;
} 

//OK
int getDLinkListLength_L(DLinkList &L){		//计算链表长度  返回长度 
	int n = 0;
	DLinkList target;
	for(target = L;target->next != L;target = target->next,n++);
	return n;
}

//OK
Status insertDLinkListRandom_L(DLinkList &L,ElemType e){	//末尾插入链表 返回状态  
	DLinkList target = new DNode;
	target->data = e;
	target->next = L;
	target->prior = L->prior;
	L->prior->next = target;
	L->prior = target;
	return OK;
}

//OK
void insertDLinkListRandom_LN(DLinkList &L,ElemType e){		//末尾插入链表 不带返回值 
	DLinkList target = new DNode;
	target->data = e;
	target->next = L;
	target->prior = L->prior;
	L->prior->next = target;
	L->prior = target;
}

//OK
Status insertDLinkList_L(DLinkList &L,ElemType e,int location){		//指定位置插入链表 返回状态 
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
Status deleteDLinkList_L(DLinkList &L,int location){	//指定位置删除链表	返回状态 
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
void showAllOfDLinkLIst_L(DLinkList &L){	//显示所有数据	无返回值
	int i;
	DLinkList target;
	if(!getDLinkListLength_L(L)){
		printf("表为空，请添加数据！！！\n");
	}else{
		printf("表的数据为:\n");
		for(i = 1,target = L->next;target != L;i++,target = target->next){
			printf("第%d个节点值为: %d\n",i,target->data);
		}
	}
}

//OK
Status findDLinkListElem_L(DLinkList &L,int location,ElemType &tmp){	//定位元素	返回状态  记录数据 
	DLinkList target;
	int i;
	for(i = 1,target = L->next;i < location;target = target->next,i++);
	tmp = target->data;
	return OK;
}

//OK
DLinkList findDLinkListLocation_L(DLinkList &L,int &location,ElemType tmp){		//元素定位	返回链表为重复数据查找做准备 
	DLinkList target;
	for(location = 1,target = L->next;(target->next != L) && (target->data != tmp);target = target->next,location++);
	return target;
}

//OK
Status clearDLinkList_L(DLinkList &L){	//清空链表 返回状态
	DLinkList target;
	int i;
	for(i = getDLinkListLength_L(L),target = L->next;i < 0;target = target->next,i--){
		deleteDLinkList_L(L,i);
	}
	L->next = L;
	L->prior = L;
	return OK;
} 

void clearDLinkList_LN(DLinkList &L){	//清空链表 无返回值 
	DLinkList target;
	int i;
	for(i = getDLinkListLength_L(L),target = L->next;i < 0;target = target->next,i--){
		deleteDLinkList_L(L,i);
	}
	L->next = L;
	L->prior = L;
} 


//OK???????
Status destoryDLinkList_L(DLinkList &L){	//摧毁链表		返回状态 
	clearDLinkList_L(L);
	L->next = NULL;
	L->prior = NULL;
	delete L;
	return OK;
}

void destoryDLinkList_LN(DLinkList &L){	//摧毁链表		无返回值
	clearDLinkList_L(L);
	L->next = NULL;
	L->prior = NULL;
	delete L;
}


void combineDLinkList_L(DLinkList &L,DLinkList &L2){	//两表结合  无返回值 
	DLinkList target,target2;
	target = L;
	target2 = L2;
	target->prior->next = target2->next;
	target2->next->prior = target->prior;
	target2->prior->next = target;
	target->prior = target2;
	delete L2;
}
