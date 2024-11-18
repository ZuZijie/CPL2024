#include "stdio.h"
#include "math.h"
#include "limits.h"
#include <stdlib.h>

typedef struct {
    int *data;   // 存储数据的数组
    int size;    // 当前数组的大小
    int capacity; // 数组的容量（分配的内存大小）
} DynamicArray;

// 初始化动态数组
void initArray(DynamicArray *array, int initialCapacity) {
    array->data = (int *)malloc(initialCapacity * sizeof(int));
    array->size = 0;
    array->capacity = initialCapacity;
}

// 动态调整数组容量
void resizeArray(DynamicArray *array, int newCapacity) {
    array->data = (int *)realloc(array->data, newCapacity * sizeof(int));
    array->capacity = newCapacity;
}

// 向数组添加元素
void append(DynamicArray *array, int value) {
    if (array->size == array->capacity) {
        resizeArray(array, array->capacity * 2); // 扩展容量
    }
    array->data[array->size++] = value;
}

// 平分元素的核心函数
int splitElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->size) return 0; // 索引无效
    if (array->data[index] % 2 != 0) return 0;      // 不能平分奇数

    int half = array->data[index] / 2;

    // 如果容量不足，扩展容量
    if (array->size + 1 >= array->capacity) {
        resizeArray(array, array->capacity * 2);
    }

    // 替换原值，并在后面插入新值
    array->data[index] = half;
    for (int i = array->size; i > index + 1; i--) {
        array->data[i] = array->data[i - 1];
    }
    array->data[index + 1] = half;
    array->size++;

    return 1; // 平分成功
}

// 打印数组
void printArray(DynamicArray *array) {
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

// 释放动态数组的内存
void freeArray(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

// 包装后的函数：平分某个元素并返回操作结果
int splitElementSafely(DynamicArray *array, int index) {
    return splitElement(array, index);
}
int getArraySize(DynamicArray *array) {
    return array->size; // 返回当前数组的大小
}
int getElement(DynamicArray *array, int index) {
    if (index < 0 || index >= array->size) {
        // 如果索引无效，返回一个特殊值（如 -1 或其他合适的值）
        return -1; 
    }
    return array->data[index];
}
int converter(int n)
{
    int i=0;
    while ((int)pow(2,i)<n)
    {
        i++;
    }
    return (int)pow(2,i);
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    DynamicArray arr;
    DynamicArray arr2;
    initArray(&arr,1);
    initArray(&arr2,1);
    append(&arr,(int)pow(2,n));
    {
        char input0;
        scanf(" %c",&input0);
        if(input0=='A')
        {
            int m;
            int id;
            scanf(" %d %d",&id,&m);
            int mem=converter(m);
            int valid=0;
            for(int i=0;i<getArraySize(&arr);i++)
            {
                if(getElement(&arr,i)==mem)
                {
                    valid=1;
                }
            }
            
        }
    }
}