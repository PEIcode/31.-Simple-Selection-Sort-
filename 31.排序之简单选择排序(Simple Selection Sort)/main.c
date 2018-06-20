//
//  main.c
//  31.排序之简单选择排序(Simple Selection Sort)
//
//  Created by sunny&pei on 2018/6/19.
//  Copyright © 2018年 sunny&pei. All rights reserved.
//

/* 简单选择排序： 就是通过n-i次关键字间的比较，从n-i+1个记录中选出关键字最小的记录，并和第i（1<=i<=n）个记录交换之*/
#include <stdio.h>
#define MAXSIZE 10 /* 用于要排序数组个数最大值，可根据需要修改*/
typedef struct{
    int r[MAXSIZE+1];/* 用于存储要排序的数组，r[0]用作哨兵或临时变量*/
    int length; /* 用于记录顺序表的长度*/
}Sqlist;

/**
 交换L中 下标为i和j的数组
 */
void swap (Sqlist *L,int i,int j){
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

/**
 简单选择排序
 */
void SimpleSort (Sqlist *L){
    int i , j , min ;
    for (i = 1 ; i< L->length; i++) {
        min = i;
        for (j = i + 1; j<=L->length;j++ ) {
            if (L->r[min]>L->r[j]) {
                min = j;
            }
        }
        if (i != min) {//说明找到最小值了，可以互换位置
            swap(L, i, min);
        }
    }
}

/**
 总结：简单选择排序的时间复杂度
 最好情况：0次；
 最坏情况：n(n-1)/2次，O[n*n];
 比冒泡排序的性能好。
 */
int main(int argc, const char * argv[]) {
    Sqlist ll;
    ll.length = 11;
    ll.r[1] = 9;
    ll.r[2] = 3;
    ll.r[3] = 2;
    ll.r[4] = 5;
    ll.r[5] = 1;
    ll.r[6] = 7;
    ll.r[7] = 8;
    ll.r[8] = 4;
    ll.r[9] = 6;
    ll.r[10] = 10;
    SimpleSort(&ll);
    //打印
    for (int i = 1; i<ll.length; i++) {
        printf("%d\n",ll.r[i]);
    }
    return 0;
}
