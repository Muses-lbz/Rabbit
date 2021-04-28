#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//函数状态结果代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status是函数的类型，其值是函数结果状态代码
typedef int Status;

typedef char TElemType;

typedef enum { Link, Thread } PointerTag;       //Link==0,表示指向左右孩子指针
                                                //Thread==1,表示指向前驱或后继的线索
//二叉树线索结点存储结构
typedef struct BiThrNode
{
    TElemType data;                       //结点数据
    struct BiThrNode* lchild, * rchild;   //左右孩子指针
    PointerTag LTag;
    PointerTag RTag;                      //左右标志
}BiThrNode, * BiThrTree;

//线索二叉树初始化
Status CreateBiThrNode(BiThrTree* B)
{
    char ch;
    scanf("%c", &ch);
    if (ch == '#') *B = NULL;
    else {
        if (!((*B) = (BiThrNode*)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);
        (*B)->data = ch;
        (*B)->LTag = Link;
        (*B)->RTag = Link;
        CreateBiThrNode(&(*B)->lchild);
        CreateBiThrNode(&(*B)->rchild);
    }
    return OK;
}

void InThreading(BiThrTree B, BiThrTree* pre)
{
    if (!B) return;

    InThreading(B->lchild, pre);
    //--------------------中间为修改空指针代码---------------------

    if (!B->lchild) {                   //没有左孩子 
        B->LTag = Thread;               //修改标志域为前驱线索
        B->lchild = *pre;               //左孩子指向前驱结点
    }

    if (!(*pre)->rchild) {              //没有右孩子
        (*pre)->RTag = Thread;          //修改标志域为后继线索
        (*pre)->rchild = B;             //前驱右孩子指向当前结点
    }

    *pre = B;                         //保持pre指向p的前驱
  //---------------------------------------------------------
    InThreading(B->rchild, pre);
}

//为线索二叉树添加头结点，使之可以双向操作
Status InOrderThreading(BiThrTree* Thrt, BiThrTree T)
{
    if (!(*Thrt = (BiThrTree)malloc(sizeof(BiThrNode)))) exit(OVERFLOW);  //开辟结点
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;               //设置标志域
    (*Thrt)->rchild = (*Thrt);            //右结点指向本身
    if (!T) {
        (*Thrt)->lchild = (*Thrt);
        return OK;       //若根结点不存在,则该二叉树为空,让该头结点指向自身.
    }
    BiThrTree pre;                //设置前驱结点
    //令头结点的左指针指向根结点
    pre = (*Thrt);
    (*Thrt)->lchild = T;
    //开始递归输入线索化
    InThreading(T, &pre);
    //此时结束了最后一个结点的线索化了,下面的代码把头结点的后继指向了最后一个结点.
    //并把最后一个结点的后继也指向头结点,此时树成为了一个类似双向链表的循环.
    pre->rchild = *Thrt;
    pre->RTag = Thread;
    (*Thrt)->rchild = pre;
    return OK;
}

//非递归遍历线索二叉树
Status InOrderTraverse(BiThrTree T)
{
    BiThrNode* p = T->lchild;
    while (p != T) {
        while (p->LTag == Link) p = p->lchild;    //走向左子树的尽头
        printf("%c", p->data);
        while (p->RTag == Thread && p->rchild != T) {  //访问该结点的后续结点
            p = p->rchild;
            printf("%c", p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main()
{
    BiThrTree B, T;
    CreateBiThrNode(&B);
    InOrderThreading(&T, B);
    printf("中序遍历二叉树的结果为：");
    InOrderTraverse(T);
    printf("\n");
}

//测试数据:ABC##DE#G##F###