#include "stdio.h"                    //头文件
#include "windows.h"

#define size 10                     //数据max

struct list
{
 char a[size];
 int num;
};

int paint();                          //函数声明
list newList();
list insertEnd(list);
list insertRandom(list);
list deleteList(list);
list listFindPoint(list);
void findDataList(list);
void view(list);

int choseMenu;

int paint()                          //打印说明
{
 char chose;
 printf("线性表顺序储存测试程序\n");
 printf("-----------------------\n");
 printf("0: 新建\n");
 printf("1: 尾插入\n");
 printf("2: 指定插入\n");
 printf("3: 删除\n");
 printf("4: 查找节点\n");
 printf("5: 查找数据\n");
 printf("6: 显示\n");
 printf("7: 退出\n");
 printf("您的选择是: ");
 fflush(stdin);
 scanf("%c",&chose);
 while(chose<0X30||chose>0X37)
 {
  printf("输入有误，请输入数字0~7之间的数字: ");
  fflush(stdin);
  scanf("%c",&chose);
 
 }
 return chose-0X30;
}

list newList()              //新建函数
{
 list list1;
 list1.num = 0;
 printf("创建成功!");
 system("pause");
 return list1;
}

list insertEnd(list listInsert)      //尾插入函数
{
 char data;
 while(1)
 {
  if(listInsert.num==size)
  {
   printf("线性表已满！");
   system("pause");
   return listInsert;
  }
  else
  {
   printf("请输入数据(press ENTER to exit):");
   fflush(stdin);
   scanf("%c",&data);
   if(data=='\n')
    break;
   listInsert.a[listInsert.num] = data;
   listInsert.num++;
   printf("插入成功！\n");
  }
 }
 system("pause");
 return listInsert;
 
}

list insertRandom(list listInsertRandom)      //指定插入函数
{
 char data;
 int insertPoint;
 if(listInsertRandom.num==size)
 {
  printf("线性表已满！");
  system("pause");
  return listInsertRandom;
 }
 else
 {
  printf("请输入数据:");
  fflush(stdin);
  scanf("%c",&data);
  printf("请输入插入点(在1到%d之间):",listInsertRandom.num+1);
  fflush(stdin);
  scanf("%d",&insertPoint);
  if(insertPoint<1||insertPoint>listInsertRandom.num+1)
  {
   printf("输入有误，请输入1到%d之间的数: ",listInsertRandom.num+1);
   fflush(stdin);
      scanf("%d",&insertPoint);
  }
  for(int n=listInsertRandom.num;n>=insertPoint;n--)
  {
   listInsertRandom.a[n] = listInsertRandom.a[n-1]; 
  }
  listInsertRandom.a[insertPoint-1] = data;
  listInsertRandom.num++;
  printf("插入成功！");
  system("pause");
  return listInsertRandom;
 }
}
list deleteList(list listDelete)    //删除函数
{
 int deletePoint;
 printf("请输入要删除的节点数：");
 fflush(stdin);
 scanf("%d",&deletePoint);
 while(deletePoint<1||deletePoint>listDelete.num)
 {
  printf("输入有误，请输入1到%d之间的数: ",listDelete.num);
  fflush(stdin);
  scanf("%d",&deletePoint);
 }
 
 for(;deletePoint<listDelete.num;deletePoint++)
     listDelete.a[deletePoint-1] = listDelete.a[deletePoint];
 listDelete.num--;
 printf("删除成功！");
 system("pause");
 return listDelete;
}

list listFindPoint(list listFind)           //查找指定节点
{
 int searchPoint;
 printf("请输入节点数：");
 fflush(stdin);
 scanf("%d",&searchPoint);
 if(searchPoint<0 || searchPoint>listFind.num)
 {
  printf("节点错误");
  system("pause");
  return listFind;
 }
 else
 {
  printf("%c",listFind.a[searchPoint-1]);
  system("pause");
  return listFind;
 }
}
void findDataList(list listFindData)
{
 char FindData;
 int findOrNot=0;
 printf("请输入要查找的数据: ");
 fflush(stdin);
 scanf("%c",&FindData);
 for(int roll=0;roll<listFindData.num;roll++)
 {
  if(listFindData.a[roll]==FindData)
  {
   printf("第%d个节点的值与%c相同\n",roll+1,FindData);
   findOrNot++;
  }
 }
 if(findOrNot==0)
  printf("此节点不存在!");
 system("pause");

}
void view(list listView)        //查看所有数据
{
 int roll;
 for(roll=0;roll<listView.num;roll++)
 {
  printf("第%d个节点的值为%c\n",roll+1,listView.a[roll]);
 }
 system("pause");
}

int main()
{
 list listTest;
 while(1)
 {
  system("cls");
  choseMenu = paint();
  if(choseMenu==7)
   break;
  switch(choseMenu)
  {
  case 0:listTest = newList();break;
  case 1:listTest = insertEnd(listTest);break;
  case 2:listTest = insertRandom(listTest);break;
  case 3:listTest = deleteList(listTest);break;
  case 4:listTest = listFindPoint(listTest);break;
  case 5:findDataList(listTest);break;
  case 6:view(listTest);break;
  }
 }
 return 0;
}


