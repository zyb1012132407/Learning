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
	printf("欢迎测试线性表\n");
	printf("-------------------------\n");
	printf("请输入数字以进行以下功能\n");
	printf("1、新建线性表\n");
	printf("2、插入（最后位置）\n");
	printf("3、插入（指定位置）\n");
	printf("4、删除（指定位置）\n");
	printf("5、查找（指定位置）\n");
	printf("6、查找（指定数据）\n"); 
	printf("7、显示所有数据\n");
	printf("8、退出\n");
	printf("-------------------------\n");
	printf("请输入您的选择：");
	scanf("%d",&x);
	if(x >=1 && x <=7){
		controller(L,x);
	}else if(x == 8){
		printf("测试结束");
		break;
	}else{
		printf("选择错误，请重新输入！");
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
				printf("新建线性表成功，请进行下一步操作。");
				break;
			}else{
			 	printf("新建线性表失败，请检查是否已存在线性表。"); 
			}
			return;
		}
		
		
		case 2:{
			ElemType tmp=1;
			char flag;
			while(tmp){
				if(L.length >= MAXSIZE){
					printf("表已满，禁止插入！");
					return; 
				} 
				printf("请输入要插入的数：");
				scanf("%d",&tmp);
				if(ListInsert(L,tmp)){
					printf("添加成功！\n");
				}else{
					printf("添加失败，请检查插入数据或数组长度是否合法!\n");
				}
				fflush(stdin);
				printf("请问您要继续输入吗？");
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
					printf("表已满，禁止插入！");
					return; 
				} 
				printf("请输入要插入的数：");
				scanf("%d",&tmp);
				printf("请输入要插入的位置：");
				scanf("%d",&location); 
				if(ListInsert_Sq(L,location,tmp)){
					printf("添加成功！\n");
				}else{
					printf("添加失败，请检查插入数据或数组长度是否合法!\n");
				}
//				printf("请问您要继续输入吗？");
//				flag=getchar();
//				if(flag != 'y' || flag != 'Y')
//					break;
			}
			return;
		}
		
		case 4:{
			int location;
			printf("请输入你要删除的位置:");
			scanf("%d",&location);
			if(ListDelete_Sq(L,location)){
				printf("删除成功！\n");
			}else{
				printf("删除失败，请检查插入数据或数组长度是否合法!\n");
			}
			return;
		}
		
		case 5:{
			int location;
			ElemType tmp;
			printf("请输入数的位置：");
			scanf("%d",&location);
			tmp=GetElem(L,location,tmp);
			if(tmp){
				printf("搜索成功，结果为：%d!",&tmp);
			}else{
				printf("搜索失败，没有此内容！");
			}
			return;
		}
		
		case 6:{
			ElemType e;
			int result;
			printf("请输入要查的数据：");
			scanf("%d",&e);
			if(result = LocateElem(L,e)){
				printf("查找成功！数据位置为%d",result);
			}else{
				printf("查找失败！数据不存在！");
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
	printf("线性表的所有数据为：\n");
	for(i=0;i<L.length;i++){
		printf("第%d个节点数据为%d。\n",i+1,L.elem[i]);
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

