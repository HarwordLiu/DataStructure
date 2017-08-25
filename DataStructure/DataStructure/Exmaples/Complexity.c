//
//  Complexity.c
//  DataStructure
//
//  Created by 刘浩 on 2017/8/26.
//  Copyright © 2017年 刘浩. All rights reserved.
//

#include "Complexity.h"

// 常数阶 O(1)
int sumFromZeroToN(int n) {
    int sum = 0;
    sum = (1 + n) * n / 2;
    return sum;
}

// 线性阶 O(n)
void printFromZeroToN(int n) {
    if (n < 0) return;
    for (int i = 0; i < n; i++) {
        printf("i = %d /n", i);
    }
}

// 对数阶 O(logn)
int logn(int n) {
    int count = 1;
    while (count < n) {
        count = count * 2;
    }
    return count;
}

// 平方阶 O(n^2)
int nn(int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result++;
        }
    }
    return result;
}












