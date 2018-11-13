/*
	Title:循环链表的简单练习
	Timeline:2018.9.30
	Owner: 赵衍博
	Details:
		9.30进度
			1、完成循环链表基础函数的创建与测试。(已解决）
			2、controller函数的创建（已解决） 
		10.7进度 
			3、解决清除（已解决）、定位（已解决）、删除（已解决），摧毁（表一）功能（已解决） 
		10.8进度	
			4、连接函数标准化。（已解决） 
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


Status initCList_L(CLinkList &L){		//初始化链表 
	L = new CNode;
	L->next = L;
	return OK;	
};

void initCList_LN(CLinkList &L){
	L = new CNode;
	L->next = L;
} 

int findCListLength_L(CLinkList L){		//统计长度 
	CLinkList target;
	target = L;
	int i;
	for(i = 0;target->next != L;i++){
		target = target->next;
	}
	return i;
}

Status findLocatedElem_L(CLinkList L,int i,ElemType &e){	//取值 
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

CLinkList findLocation_L(CLinkList L,int &i,ElemType e){	//定位 
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

Status insertCListRandom_L(CLinkList &L,ElemType t){	//尾插 
	CLinkList target;
	CLinkList tmp;
	for(target = L;target->next != L;target = target->next);
	tmp = new CNode;
	tmp->data = t;
	tmp->next = L;
	target->next = tmp;
	return OK; 
}

Status insertCList_L(CLinkList &L,int i,ElemType t){	//定点插入数值 
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

Status deleteElem_L(CLinkList &L,int i){//删除元素 
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

void showAll(CLinkList L){///显示全部信息 
	CLinkList target;
	for(target = L;target->next != L;target = target->next);
	for(target = target->next->next;target != L;target = target->next){
		printf("%d ",target->data);
	}
	printf("\n");
}

Status badTest(CLinkList L){	//测试链表是否正常循环 
	CLinkList target;
	for(target = L;target->next != NULL;target = target->next);
	return OK;
}

void crushList(CLinkList &L){ //无返回值摧毁链表 
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
		printf("二表为空，退出\n");
	}else{
		for(target_L = L;target_L->next != L;target_L = target_L->next);
		for(target_L2 = L2;target_L2->next != L2;target_L2 = target_L2->next);
		tmp = L2;
		target_L->next = tmp->next;
		target_L2->next = L;
		delete tmp;
		return OK;
		printf("连接成功，请查看效果\n");
	}
	
}

Status combineCListN(CLinkList &L,CLinkList &L2){	//循环列表合并，L2摧毁没处理，太冷了啊！！！！！！这个破天！ 
	CLinkList p = L2->next;
	int i;
	for(i = 1; i <= findCListLength_L(L2);p = p->next){
		i += insertCListRandom_L(L,p->data);
	}
	printf("连接成功，请查看效果\n");
	return 0;
}




Status clearList(CLinkList &L){	//清空链表（正经向）
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

Status clearListL(CLinkList &L){ //清空链表（Legend！） 
	crushList(L);
	initCList_LN(L);
	return OK;	
}

Status destoryCList(CLinkList &L){	//	摧毁链表 
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


void JosephusRemoveTools(CLinkList &L,CLinkList &target){//约瑟夫环删除工具 
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

void Josephus(CLinkList L,int n,int m){//尾节点删除未解决 
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
		printf("出列的数为%d\n",target->data);
	for(test = L;test->next != L;test = test->next);
	test = test->next;
	printf("当前链表循环正常\n");
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
		case 1:{//初始化链表，将失败分为已存在或其他异常（防止找不到BUG） 
			if(initCList_L(L)){
				printf("初始化链表成功！\n");
				InitFlag++;
			}else{
				if(InitFlag){
					printf("初始化链表失败，已存在链表！\n");
				}else{
					printf("初始化链表失败，请向作者提交Bug!\n");
				}
			}
			break;
		}
		case 2:{//默认插入，和定点插入类似，支持多次连续插入（Y/其他字符） 
			ElemType x;
			CLinkList p;
			char flag='y';
			while(1){
				p = L;
				printf("\n");
				//输数值 
				printf("请输入你要输入的数字: ");
				while(1){
				if(scanf("%d",&x) && x >=0){//检测是否为数字，是否在范围内 
						if(insertCListRandom_L(p,x)){
							printf("添加成功！\n\n");
							break;
						}else{
							printf("添加失败，请向作者提交BUG！！\n\n");
							break;
						}
				}else{
					fflush(stdin);
					printf("请输入正确数值！\n");
					printf("请输入你要输入的成绩:");
				}	
			}
				//判断合法与否
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
			CLinkList p;
			char flag='y';
			int location;
			while(1){
				p = L;
				printf("\n");
				//输数值 
				printf("请输入你要输入的成绩: ");
				while(1){
					//判断合法与否
					if(scanf("%d",&x)){
						//输位置 
						printf("请输入插入位置:  ");
						scanf("%d",&location);
						printf("\n");
						if(insertCList_L(p,location,x)){
							printf("添加成功！\n\n");
							break;
						}else{
							printf("添加失败，请检查插入数据或数组长度是否合法!\n\n");
							break;
						}
					}else{
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
		case 4:{//指定位置删除数据，很普通 
			int location;
			printf("请输入你要删除的位置:");
			scanf("%d",&location);
			if(deleteElem_L(L,location)){
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
			if(findLocatedElem_L(L,location,tmp)){
				printf("搜索成功，结果为: %d\n",tmp);
			}else{
				printf("搜索失败，没有此内容！\n");
			}
			return;
			break;
		}
		case 6:{//指定数据搜索位置 
			CLinkList p;
			ElemType tmp;
			int sum = 0;
			int n;
			printf("请你输入数值: \n");
			scanf("%d",&tmp);
			p = findLocation_L(L,n,tmp);
			if(p){
				sum += n;
				printf("搜索成功！数据在第%d个位置",sum);
				while(p){
					p = findLocation_L(p,n,tmp);
					if(p){
						sum += n;
						if(sum > findCListLength_L(L)){
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
			if(!findCListLength_L(L)){
				printf("链表内无数据，请添加数据！\n"); 
			}else{
				showAll(L);
			}
			break;
		}
		case 8:{//清除链表数据，很普通 
			char flag;
			fflush(stdin);
			printf("请慎重考虑！是否确定清除链表？ (y/other) ：");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(clearList(L)){
					printf("链表清除成功！\n");
				}else{//留个修BUG的余地 
					printf("链表清除失败！请向作者提交BUG！\n");
				}
			}
			break;
		}
		case 9:{
			char flag;
			fflush(stdin);
			printf("请慎重考虑！是否确定摧毁链表？ (y/other) ：");
			scanf("%c",&flag);
			fflush(stdin);
			if(flag == 'y' || flag == 'Y'){
				if(destoryCList(L)){
					printf("链表摧毁成功！\n");
					InitFlag--;
				}else{//留个修BUG的余地 
					printf("链表摧毁失败！请向作者提交BUG！\n");
				}
			}
			break;
			printf("--------------------------------\n");
			break;
		} 
	}
}

int mainMenu(CLinkList &L,CLinkList &L2){
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
		printf("单链表的长度为： %d\n",findCListLength_L(L));
	}else{
		printf("单链表1的长度为： %d\n",findCListLength_L(L));
		printf("单链表2的长度为:  %d\n",findCListLength_L(L2));
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
		if(!InitFlag){
			controller(L,1);
			printf("第一个单链表已建立\n");
		}else if(InitFlag == 1){
			controller(L2,1);
			printf("第二个单链表已建立\n");
		}
		
		printf("--------------------------------\n");
	}
	else if(x >=2 && x <=8){
		//对单链表进行操作，不过要先检测其状态，否则会报错 
		printf("--------------------------------\n");
		if(!InitFlag){
			printf("单链表不存在，请新建单链表！\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("请选择单链表（Y为第一个表，其他为第二个表）");
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
			printf("单链表不存在，请新建单链表\n");
		}else if(InitFlag == 1){
			controller(L,x);
		}else{
			fflush(stdin);
			printf("请选择单链表（Y为第一个表，其他为第二个表）");
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
			printf("已摧毁单链表\n");
		}
		printf("--------------------------------\n");			
	}else if(x == 10){
		printf("--------------------------------\n");
		if(InitFlag == 0){
		printf("单链表不存在，请新建单链表！\n");
		}
		else if(InitFlag == 1){
			printf("单链表不够啊亲，请再建一个吧\n"); 
		}else if(InitFlag == 2){
			combineCList(L,L2);
			InitFlag--;
			printf("连接成功，请查看效果\n");
		}else{
			InitFlag = 0;
			printf("作者又生产了新的BUG，请向他提交并打他一顿\n");
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
	printf("初始化测试:\n");
	printf("%d\n",initCList_L(L));
	printf("%d\n",initCList_L(L2));
	printf("%d\n",findCListLength_L(L));
	printf("--------------\n");
	printf("插入测试\n");
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
	printf("约瑟夫问题的解决:\n");
	Josephus(L,findCListLength_L(L),2);
	
//	printf("定点插入测试\n");
//	printf("%d\n",insertCList_L(L2,1,3));
//	printf("%d\n",insertCList_L(L2,2,4));
//	printf("%d\n",findCListLength_L(L));
//	showAll(L2);
//	printf("--------------\n");
//	printf("定点查找测试\n");
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
//	printf("定点删除测试\n");
//	printf("%d\n",deleteElem_L(L,1));
//	printf("%d\n",deleteElem_L(L,3));
//	printf("%d\n",findCListLength_L(L));
//	showAll(L);
//	printf("--------------\n");
//	printf("两表结合测试\n");
//	printf("%d\n",combineCList(L,L2));
//	showAll(L);
//	printf("摧毁链表测试\n");
//	printf("%d\n",destoryCList(L));
//	showAll(L);
	return 0;
}
