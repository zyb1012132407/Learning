#include "stdio.h"                    //ͷ�ļ�
#include "windows.h"

#define size 10                     //����max

struct list
{
 char a[size];
 int num;
};

int paint();                          //��������
list newList();
list insertEnd(list);
list insertRandom(list);
list deleteList(list);
list listFindPoint(list);
void findDataList(list);
void view(list);

int choseMenu;

int paint()                          //��ӡ˵��
{
 char chose;
 printf("���Ա�˳�򴢴���Գ���\n");
 printf("-----------------------\n");
 printf("0: �½�\n");
 printf("1: β����\n");
 printf("2: ָ������\n");
 printf("3: ɾ��\n");
 printf("4: ���ҽڵ�\n");
 printf("5: ��������\n");
 printf("6: ��ʾ\n");
 printf("7: �˳�\n");
 printf("����ѡ����: ");
 fflush(stdin);
 scanf("%c",&chose);
 while(chose<0X30||chose>0X37)
 {
  printf("������������������0~7֮�������: ");
  fflush(stdin);
  scanf("%c",&chose);
 
 }
 return chose-0X30;
}

list newList()              //�½�����
{
 list list1;
 list1.num = 0;
 printf("�����ɹ�!");
 system("pause");
 return list1;
}

list insertEnd(list listInsert)      //β���뺯��
{
 char data;
 while(1)
 {
  if(listInsert.num==size)
  {
   printf("���Ա�������");
   system("pause");
   return listInsert;
  }
  else
  {
   printf("����������(press ENTER to exit):");
   fflush(stdin);
   scanf("%c",&data);
   if(data=='\n')
    break;
   listInsert.a[listInsert.num] = data;
   listInsert.num++;
   printf("����ɹ���\n");
  }
 }
 system("pause");
 return listInsert;
 
}

list insertRandom(list listInsertRandom)      //ָ�����뺯��
{
 char data;
 int insertPoint;
 if(listInsertRandom.num==size)
 {
  printf("���Ա�������");
  system("pause");
  return listInsertRandom;
 }
 else
 {
  printf("����������:");
  fflush(stdin);
  scanf("%c",&data);
  printf("����������(��1��%d֮��):",listInsertRandom.num+1);
  fflush(stdin);
  scanf("%d",&insertPoint);
  if(insertPoint<1||insertPoint>listInsertRandom.num+1)
  {
   printf("��������������1��%d֮�����: ",listInsertRandom.num+1);
   fflush(stdin);
      scanf("%d",&insertPoint);
  }
  for(int n=listInsertRandom.num;n>=insertPoint;n--)
  {
   listInsertRandom.a[n] = listInsertRandom.a[n-1]; 
  }
  listInsertRandom.a[insertPoint-1] = data;
  listInsertRandom.num++;
  printf("����ɹ���");
  system("pause");
  return listInsertRandom;
 }
}
list deleteList(list listDelete)    //ɾ������
{
 int deletePoint;
 printf("������Ҫɾ���Ľڵ�����");
 fflush(stdin);
 scanf("%d",&deletePoint);
 while(deletePoint<1||deletePoint>listDelete.num)
 {
  printf("��������������1��%d֮�����: ",listDelete.num);
  fflush(stdin);
  scanf("%d",&deletePoint);
 }
 
 for(;deletePoint<listDelete.num;deletePoint++)
     listDelete.a[deletePoint-1] = listDelete.a[deletePoint];
 listDelete.num--;
 printf("ɾ���ɹ���");
 system("pause");
 return listDelete;
}

list listFindPoint(list listFind)           //����ָ���ڵ�
{
 int searchPoint;
 printf("������ڵ�����");
 fflush(stdin);
 scanf("%d",&searchPoint);
 if(searchPoint<0 || searchPoint>listFind.num)
 {
  printf("�ڵ����");
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
 printf("������Ҫ���ҵ�����: ");
 fflush(stdin);
 scanf("%c",&FindData);
 for(int roll=0;roll<listFindData.num;roll++)
 {
  if(listFindData.a[roll]==FindData)
  {
   printf("��%d���ڵ��ֵ��%c��ͬ\n",roll+1,FindData);
   findOrNot++;
  }
 }
 if(findOrNot==0)
  printf("�˽ڵ㲻����!");
 system("pause");

}
void view(list listView)        //�鿴��������
{
 int roll;
 for(roll=0;roll<listView.num;roll++)
 {
  printf("��%d���ڵ��ֵΪ%c\n",roll+1,listView.a[roll]);
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


