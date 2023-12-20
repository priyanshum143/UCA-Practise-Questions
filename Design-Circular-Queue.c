#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int size;
    int rear, front;
    int* arr;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* que = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    que->size = k;
    que->rear = que->front = -1;
    que->arr = (int *) malloc(k * sizeof(int));
    return que;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if((obj->rear+1) % obj->size == obj->front) return false;

    if(obj->front == -1) obj->front++;
    obj->rear = (obj->rear+1) % obj->size;
    obj->arr[obj->rear] = value;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if(obj->front == -1 && obj->rear == -1) return false;

    if(obj->front == obj->rear) obj->front = obj->rear = -1;
    else obj->front = (obj->front+1) % obj->size;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if(obj->front == -1 && obj->rear == -1) return -1;
    return obj->arr[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if(obj->front == -1 && obj->rear == -1) return -1;
    return obj->arr[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->front == -1 && obj->rear == -1);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return ((obj->rear+1) % obj->size == obj->front);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    obj->front = -1;
    obj->rear = -1;
}
