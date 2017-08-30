//
//  main.c
//  DataStructure
//
//  Created by 刘浩 on 2017/8/26.
//  Copyright © 2017年 刘浩. All rights reserved.
//

#include <stdio.h>
#include "Complexity.h"
#include "SqList.h"

int main(int argc, const char * argv[]) {
    int a[10] = {2,4,6,8,10,12,14,16,18,20};
    int i;
    SqList L;
    InitList(&L, 5);                 //初始化分配线性表空间为5
    for (i = 0; i < 10; i++)
        InsertLastList(&L, a[i]);    //将数组中的元素依次插入线性表（空间不够，扩大2倍）
    InsertPosList(&L, 11, 48);       //在第11位插入48（空间不够，再次扩大2倍）
    InsertPosList(&L, 1, 64);        //在第1位插入64
    printf("%d\n", GetElem(&L, 4));  //输出第4个元素
    TraverseList(&L);                //遍历输出所有元素
    printf("%d\n", FindList(&L, 10));//查找输出数值为10的元素位置（下标）
    UpdatePosList(&L, 3, 20);        //把第三个元素修改为20
    DeleteFirstList(&L);             //删除表头元素
    DeleteFirstList(&L);
    DeleteLastList(&L);              //删除表尾元素
    DeleteLastList(&L);
    DeletePosList(&L, 5);            //删除第5个元素
    DeletePosList(&L, 7);            //删除第7个元素
    printf("%d\n", SizeList(&L));    //输出线性表长度
    printf("%d\n", EmptyList(&L));   //判断线性表是否为空
    TraverseList(&L);                //遍历输出所有元素
    ClearList(&L);                   //清空线性表，释放空间

    return 0;
}
