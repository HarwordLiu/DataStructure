//
//  SqList.c
//  DataStructure
//
//  Created by 刘浩 on 2017/8/30.
//  Copyright © 2017年 刘浩. All rights reserved.
//

// 线性表的顺序存储结构的操作实现
#include "SqList.h"
#include <stdlib.h>

//1、初始化线性表L，即进行动态存储空间分配并置L为一个空表
void InitList(SqList *L, int ms)
{
    if (ms < 0) //检查ms是否有效
    {
        printf("ms值非法！\n");
        exit(1);
    }
    L->MaxSize = ms; //置线性表初始存储容量为ms
    L->list = (ElemType *)malloc(ms*sizeof(ElemType)); //动态存储空间分配
    if (!L->list)
    {
        printf("动态存储分配失败！\n");
        exit(1);
    }
    L->size = 0; //初始置线性表为空
}

//2、清除线性表L中的所有元素，释放动态存储空间，使之成为一个空表
void ClearList(SqList *L)
{
    if (L->list != NULL)
    {
        free(L->list);
        L->list = 0;
        L->size = L->MaxSize = 0;
    }
}

//3、返回线性表L的长度，若L为空则返回0
int SizeList(SqList *L)
{
    return L->size;
}

//4、判断线性表L是否为空，若为空则返回1，否则返回0
int EmptyList(SqList *L)
{
    if (L->size == 0)
        return 1;
    else
        return 0;
}

//5、返回线性表L中第pos个元素的值，若pos超出范围，则停止程序运行
ElemType GetElem(SqList *L, int pos)
{
    if (pos < 1 || pos > L->size)
    {
        printf("元素序号越界！\n");
        exit(1);
    }
    return L->list[pos - 1];
}

//6、顺序扫描（即遍历）输出线性表L中的每个元素
void TraverseList(SqList *L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d,", L->list[i]);
    printf("\n");
}

//7、从线性表L中查找值与x相等的元素（第一个），若查找成功则返回其位置（下标），否则返回-1
int FindList(SqList *L, ElemType x)
{
    int i;
    for (i = 0; i < L->size; i++) //此处类型ElemType为整型，当为字符串类型（char *）时，
        if (L->list[i] == x)      //if语句应改为: if (strcmp(L->list[i], x) == 0)
            return i;
    return -1;
}

//8、把线性表L中第pos个元素的值修改为x的值，若修改成功返回1，否则返回0
int UpdatePosList(SqList *L, int pos, ElemType x)
{
    if (pos < 1 || pos > L->size)  //若pos越界则修改失败
        return 0;
    L->list[pos - 1] = x;
    return 1;
}

//9、向线性表L的表头插入元素x
//此时需要考虑到线性表存储空间已满的情况，则需要重新分配更大的动态存储空间，具体实现如下：
void againMalloc(SqList *L)
{
    ElemType *p = realloc(L->list, 2*L->MaxSize*sizeof(ElemType));//此处重新分配的空间为原来的2倍
    if (!p)  //重新分配失败
    {
        printf("存储空间用完！\n");
        exit(1);
    }
    L->list = p;             //使list指向新线性表空间
    L->MaxSize = 2 * L->MaxSize;
    printf("存储空间已扩大为当前的2倍！\n");//输出提示已扩充空间
}

void InserFirstList(SqList *L, ElemType x) //表头插入元素
{
    int i;
    if (L->size == L->MaxSize) //存储空间已满
        againMalloc(L);        //重新分配更大空间
    for (i = L->size - 1; i >= 0; i--)
        L->list[i + 1] = L->list[i];
    L->list[0] = x;
    L->size++;
}

//10、向线性表L的表尾插入元素x
void InsertLastList(SqList *L, ElemType x)
{
    if (L->size == L->MaxSize)
        againMalloc(L);
    L->list[L->size] = x;
    L->size++;
}

//11、向线性表L中第pos个元素位置插入元素x，若插入成功返回1，否则返回0
int InsertPosList(SqList *L, int pos, ElemType x)
{
    int i;
    if (pos < 1 || pos > L->size + 1) //pos的合法位置是第一位到最后一位的后一位之间
        return 0;
    if (L->size == L-> MaxSize)
        againMalloc(L);
    for (i = L->size - 1; i >= pos - 1; i--)
        L->list[i + 1] = L->list[i];
    L->list[pos - 1] = x;
    L->size++;
    return 1;
}

//12、向有序（递增）线性表L中插入元素x，使得插入后仍然有序
void InsertOrderList(SqList *L, ElemType x)
{
    int i, j;
    if (L->size == L->MaxSize)
        againMalloc(L);
    for (i = 0; i < L->size; i++)
        if (x < L->list[i])
            break;   //此时i的值即为要插入的位置。若x比所有元素都大，则i自增后的值为size，下面的for循环不执行。
    for (j = L->size - 1; j >= i; j--)
        L->list[j + 1] = L->list[j];
    L->list[i] = x;
    L->size++;
}

//13、从线性表L中删除表头元素并返回它，若删除失败则停止程序运行
ElemType DeleteFirstList(SqList *L)
{
    ElemType temp; //临时变量，用于存储表头元素
    int i;
    if (L->size == 0)
    {
        printf("线性表为空，不能删除！\n");
        exit(1);
    }
    temp = L->list[0];
    for (i = 1; i < L->size; i++)
        L->list[i - 1] = L->list[i];
    L->size--;
    return temp;
}

//14、从线性表L中删除表尾元素并返回它，若删除失败则停止程序运行
ElemType DeleteLastList(SqList *L)
{
    if (L->size == 0)
    {
        printf("线性表为空，不能删除！\n");
        exit(1);
    }
    L->size--;
    return L->list[L->size];
}

//15、从线性表L中删除第pos个元素并返回它，若删除失败则停止程序运行
ElemType DeletePosList(SqList *L, int pos)
{
    ElemType temp;
    int i;
    if (pos < 1 || pos > L->size)
    {
        printf("pos值越界，不能删除！\n");
        exit(1);
    }
    temp = L->list[pos - 1];
    for (i = pos; i < L->size; i++)
        L->list[i - 1] = L->list[i];
    L->size--;
    return temp;
}

//16、从线性表L中删除值为x的第一个元素，若删除成功返回1否则返回0
int DeleteValueList(SqList *L, ElemType x)
{
    int i, j;
    for (i = 0; i < L->size; i++)
        if (L->list[i] == x)
            break; //此时的i即是要删除的位置,
    if (i == L->size)//若找不到，上面的i自增后为size
        return 0;
    for (j = i + 1; j < L->size; j++)
        L->list[j - 1] = L->list[j];
    L->size--;
    return 1;
}
