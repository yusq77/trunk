/*-----------------------------------------------------------------------------
文件功能:实现了动态建立一个学生信息的链表包括链表的
创建、插入、删除、和打印输出学生信息包括姓名和分数
本链表是带有头结点的，头结点的内容为空内容
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include "color.h"
#include "unionerror.h"
#include "unionerrinfo.h"

#define DEBUG(format,...) printf(L_RED "["__FILE__"]:[%05d]#   "format"\n"NONE, __LINE__, ##__VA_ARGS__)

typedef struct Node
{
    char name[10];
    int score;
    struct Node *next;
}ListNode, *PListNode;

//typedef struct Node ListNode;

/*
 * 函数名称：UnionGetErrMsg
 * 函数功能：根据提供的错误码获取错误信息
 * 参数说明：
 *   ErrNo     错误码
 * 返 回 值：
 *   NULL      没有指定的错误码
 *   ErrMsg    错误信息
 * 修改历史：
 *   修改日期     修改人     修改内容
 *   2018-4-12   yusq 创建
 */
const char *UnionGetErrMsg(int ErrNo)
{
    int i = 0;

    for (i = 0; i < sizeof(SKVErrInfo) / sizeof(SKVErrInfo[0]); i++)
    {
        if (SKVErrInfo[i].ErrNo == ErrNo)
        {
            return SKVErrInfo[i].ErrMsg;
        }
    }

    return NULL;
}

/* 函数名称：UnionGetErrDetail
 * 函数功能：根据提供的错误码获取错误详细信息
 * 参数说明：
 *   ErrNo     错误码
 * 返 回 值：
 *   NULL             没有指定的错误码
 *   ErrDetailInfo    错误详细信息
 * 修改历史：
 *   修改日期     修改人     修改内容
 *   2015-12-12   gongf      创建
 */
const char *UnionGetErrDetail(int ErrNo)
{
    int i = 0;

    for (i = 0; i < sizeof(SKVErrInfo) / sizeof(SKVErrInfo[0]); i++)
    {
        if (SKVErrInfo[i].ErrNo == ErrNo)
        {
            return SKVErrInfo[i].ErrDetailInfo;
        }
    }

    return NULL;
}

/*在链表的末端插入新的节点，建立链表*/
ListNode *CreateList()
{
    int n;
    DEBUG("node number：");
    scanf("%d",&n);
    if (n<1)
    {
        DEBUG("error input. please try again.\n");
        return NULL;
    }

    int i = 1;
    ListNode *head = NULL;//head node
    ListNode *pre = NULL;//intermediate variable
    ListNode *p = NULL;//new node

    head=(ListNode *)malloc(sizeof(ListNode));
    head->next=NULL;//null list
    pre=head;

    for(i=1;i<=n;i++)
    {
        p=(ListNode *)malloc(sizeof(ListNode));//add new node

        printf("name[%d]:",i);
        scanf("%s",p->name);//input name
        printf("score[%d]",i);
        scanf("%d",&p->score);//input score

        pre->next=p;//将p指向新结点插入链表也就是头结点指针域指向下个结点第一个结点就是p指向的，因为头结点内容为空
        pre=p;//next node
    }
    p->next=NULL;//clear pointer domain
    return head;
}

void PrintList(ListNode *head)
{
  //parameters check
  if(head == NULL)
  {
    DEBUG("null list！\n");
    return ;
  }

  ListNode *p = NULL;
  p=head->next;

  DEBUG_GREEN("print list：");
  int i = 1;
  while(p)
  {
    DEBUG_GREEN("node[%d]： %s,%d ",i,p->name,p->score);
    p=p->next;
    i++;
  }
}

/*--------------------------------------------------------------------
函数名称:InsertList(ListNode *head,int i,char name[],int score,int n)
函数功能:插入链表结点
入口参数:
head: 头结点地址
i:插入到第几个结点
name:插入结点的姓名
score:插入结点的成绩
n:链表中结点的个数(除下头结点外的个数)

出口参数:
--------------------------------------------------------------------*/
void InsertList(ListNode *head,int i,char name[],int score, int n)
{
 ListNode *q = NULL,*p = NULL;//先定义2个指向一个结点的指针
 int j = 0;
 //参数检查
 if (head == NULL)
 {
   DEBUG("链表为空！\n");
   return ;
 }
 if(i<1 || i>n+1)
 {
   DEBUG("输入参数有误，请重新输入 ！\n");
   return ;
 }
 else
 {
   j=0;
   p=head;//将指针p指向链表的头结点
   while(j<i-1)
   {
     p=p->next;
     j++;
   }
   q=(ListNode *)malloc(sizeof(ListNode));/*为要插入的结点分配内存空间*/

   //----赋值操作---------
   strcpy(q->name,name); //将名字拷到要插入的节点内
   q->score=score; //将要插入的节点中成绩赋值

   //调整指针域
   q->next = p->next; /*这个是将新插入的结点指针域指向上一个结点指针域指向的结点地址即为p->next*/

   p->next=q;/*将要插入结点位置前面的结点指针域指向现在插入的结点首地址*/
  }
}
//    定义链表查询函数
void QueryList(ListNode *head)
{
    PListNode p = head->next;    //    定义临时指针P指向首节点的地址
    int num = 0;    //    用于记录链表节点位置
    int val = 0;    //    用于存放要查询的值
    printf("query score：");
    scanf("%d", &val);    //    输入要查询的数值
    while (p != NULL&&p->score != val) {
        p = p->next;
        num++;
    }
    if (p != NULL)
        printf("找到的节点为：%d", num + 1);
    else
        printf("找不到该节点");
    printf("\n");
    return ;
}
/*--------------------------------------------------------------------
函数名称:DeleteList(ListNode *head,int i,char name[],int score,int n)
函数功能:删除链表结点
入口参数:
head: 头结点地址
i:要删除的结点所在位置
name:插入结点的姓名
score:插入结点的分数
n:链表中结点的个数(除下头结点外的个数)

出口参数:
--------------------------------------------------------------------*/
void DeleteList(ListNode *head,int i,char name[],int score, int n)
{
  ListNode *p = NULL,*q = NULL;//首先定义2个指向结点型结构体的指针
  int j = 0;
  //参数检查
  if(head == NULL)
  {
    DEBUG("链表为空！\n");
    return ;
  }
  if(i<1 || i>n)//如果位置超出了1和n的范围的话则打印出错误信息
  {
    DEBUG("输入参数有误，请重新输入\n");
    return ;
  }
  else//没有超出除头结点外的1到n 的范围的话那么执行删除操作
  {
   j=0;
   p=head;//将指针指向链表的头结点首地址
   while(j<i-1)
    {
     p=p->next;
     j++;
    }
   q=p->next; /*q指向要删除的位置之前的那个结点指针域指向的地址, q指向的结点就是要删除的结点*/

   p->next=q->next;/*这个就是将要删除的结点的前面那个结点的指针域指向要删除的结点指针域中存放的下个结点的首地址,从而实现了删除第i个结点的作用*/

   strcpy(name,q->name);
   score=q->score;

   free(q);//释放q指向的结点
   printf("name=%s,score=%d\n",name,score);
  }
}


/*------------------------链表反转函数-------------------------*/
/* 函数名称：Reverse(ListNode *head)
 * 函数功能：链表反转
 * 入口参数：
 *     head: 链表头结点地址
 *
 * 出口参数：
 *     head: 链表头结点地址
 */
ListNode *Reverse(ListNode *head)
{
  //参数检查
  if(head == NULL)
  {
    printf("链表为空！\n");
    return head;
  }
  ListNode *p =NULL, *q = NULL, *pr = NULL;
  //断开头结点
  p = head->next;
  //为q结点分配内存
  //q = (ListNode *)malloc(sizeof(ListNode));
  head->next = NULL;

  //反转
  while(p)
  {
    pr = p->next;
    p->next = q;
    q = p;
    p = pr;
  }
  //将头结点指针指向反转的最后一个结点
  head->next = q;

  return head;

}
//定义删除整个链表函数
void DeleteWholeList(PListNode head) {
    PListNode p, tmp;
    p = head->next;    //定义指针P指向链表要删除的链表List的第一个点节点
    head->next = NULL;
    while (p != NULL)
    {
        tmp = p->next;        //临时Tmp指向要删除的节点的下个节点
        free(p);    //释放指针P指向的节点
        p = tmp;    //重新赋值
    }
    printf("删除链表成功！\n");
}

void menu()
{
    printf(L_GREEN "\n\t\t\t         主菜单\n");
    printf(L_GREEN "\t\t\t#***************************#\n" NONE);
    printf(L_GREEN "\t\t\t#       0--退出程序         #\n" NONE);
    printf(L_GREEN "\t\t\t#       1--返回菜单         #\n" NONE);
    printf(L_GREEN "\t\t\t#       2--创建链表         #\n" NONE);
    printf(L_GREEN "\t\t\t#       3--输出元素         #\n" NONE);
    printf(L_GREEN "\t\t\t#       4--添加元素         #\n" NONE);
    printf(L_GREEN "\t\t\t#       5--删除元素         #\n" NONE);
    printf(L_GREEN "\t\t\t#       6--查询元素         #\n" NONE);
    printf(L_GREEN "\t\t\t#       7--更新元素         #\n" NONE);
    printf(L_GREEN "\t\t\t#       8--反转链表         #\n" NONE);
    printf(L_GREEN "\t\t\t#       9--删除链表         #\n" NONE);
    printf(L_GREEN "\t\t\t#***************************#\n" NONE);
    printf(L_GREEN "\t\t\t      请选择(0 ~ 9) =:" NONE);
}


int  main(int argc , char *argv[])
{
    PListNode head = NULL;
    int i = 0, n = 0, score = 0;
    char name[10] = {0};
    //DEBUG("%s",UnionGetErrMsg(USYCERR_XMLCREATE_ERR));

    while ( 1 )
    {
        menu();
        scanf("%d",&i);
        //return menu
        if ( i == 1) continue;
        switch(i)
        {
            case 0://exit
                return 0;
                break;

            case 2://create
                head=CreateList();
                break;

            case 3://print
                PrintList(head);
                break;

            case 4://add
                printf("\naddition location：");
                scanf("%d",&i);
                printf("name： ");
                scanf("%s",name);
                printf("score： ");
                scanf("%d",&score);
                InsertList(head,i,name,score, n);
            break;

            case 5://delete node
                printf("\ndeletion node location： ");
                scanf("%d",&i);
                DeleteList(head,i,name,score, n);
                break;

            case 6://query
                QueryList(head);
                break;

            case 7://update
                break;

            case 8://reverse
                head = Reverse(head); //reverse
                break;
            case 9: //delete whole list
                DeleteWholeList(head);

            default:
                DEBUG("\nerror parameters\n");
        }
    }
    return 0;
}

