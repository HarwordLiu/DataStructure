//
//  SqList.h
//  DataStructure
//
//  Created by 刘浩 on 2017/8/30.
//  Copyright © 2017年 刘浩. All rights reserved.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10   //线性表存储空间的分配增量(当存储空间不够时要用到)


typedef int ElemType;       //定义元素类型
typedef struct {               //定义单链表结点类型

    ElemType *list;//存储空间基址
    int size;      //当前长度
    int MaxSize;   //当前分配的存储容量，即存储线性表的最大长度
} SqList;


//1、初始化线性表L，即进行动态存储空间分配并置L为一个空表
void InitList(SqList *L, int ms);

//2、清除线性表L中的所有元素，释放动态存储空间，使之成为一个空表
void ClearList(SqList *L);

//3、返回线性表L的长度，若L为空则返回0
int SizeList(SqList *L);

//4、判断线性表L是否为空，若为空则返回1，否则返回0
int EmptyList(SqList *L);

//5、返回线性表L中第pos个元素的值，若pos超出范围，则停止程序运行
ElemType GetElem(SqList *L, int pos);

//6、顺序扫描（即遍历）输出线性表L中的每个元素
void TraverseList(SqList *L);

//7、从线性表L中查找值与x相等的元素（第一个），若查找成功则返回其位置（下标），否则返回-1
int FindList(SqList *L, ElemType x);

//8、把线性表L中第pos个元素的值修改为x的值，若修改成功返回1，否则返回0
int UpdatePosList(SqList *L, int pos, ElemType x);

//9、向线性表L的表头插入元素x
//此时需要考虑到线性表存储空间已满的情况，则需要重新分配更大的动态存储空间，具体实现如下：
void againMalloc(SqList *L);

void InserFirstList(SqList *L, ElemType x); //表头插入元素

//10、向线性表L的表尾插入元素x
void InsertLastList(SqList *L, ElemType x);

//11、向线性表L中第pos个元素位置插入元素x，若插入成功返回1，否则返回0
int InsertPosList(SqList *L, int pos, ElemType x);

//12、向有序（递增）线性表L中插入元素x，使得插入后仍然有序
void InsertOrderList(SqList *L, ElemType x);

//13、从线性表L中删除表头元素并返回它，若删除失败则停止程序运行
ElemType DeleteFirstList(SqList *L);

//14、从线性表L中删除表尾元素并返回它，若删除失败则停止程序运行
ElemType DeleteLastList(SqList *L);

//15、从线性表L中删除第pos个元素并返回它，若删除失败则停止程序运行
ElemType DeletePosList(SqList *L, int pos);

//16、从线性表L中删除值为x的第一个元素，若删除成功返回1否则返回0
int DeleteValueList(SqList *L, ElemType x);


#endif /* SqList_h */
