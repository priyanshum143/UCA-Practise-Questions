#include <stdlib.h>
#include <stdbool.h>

struct Stack{
    int size;
    int top;
    int* arr;
};

void initializeStack(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->arr = (int *) (malloc(size * sizeof(int)));
}

void push(struct Stack *st, int val){
    if(st->top == st->size - 1) return;
    st->arr[++st->top] = val;
}

int pop(struct Stack *st){
    if(st->top == -1) return -1;
    return st->arr[st->top--];
}

bool isEmpty(struct Stack *st) { return (st->top == -1); }

int peek(struct Stack *st){
    if(st->top == -1) return -1;
    return st->arr[st->top];
}

typedef struct {
    struct Stack st1;
    struct Stack st2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue *obj = (MyQueue *)malloc(sizeof(MyQueue));
    initializeStack(&obj->st1, 100);
    initializeStack(&obj->st2, 100);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    if(isEmpty(&obj->st1)){
        push(&obj->st1, x);
        return;
    }

    while(!isEmpty(&obj->st1)){
        push(&obj->st2, peek(&obj->st1));
        pop(&obj->st1);
    }
    push(&obj->st1, x);

    while(!isEmpty(&obj->st2)){
        push(&obj->st1, peek(&obj->st2));
        pop(&obj->st2);
    }
}

int myQueuePop(MyQueue* obj) {
    return pop(&obj->st1);
}

int myQueuePeek(MyQueue* obj) {
    return peek(&obj->st1);
}

bool myQueueEmpty(MyQueue* obj) {
    return isEmpty(&obj->st1);
}

void myQueueFree(MyQueue* obj) {
    while(!isEmpty(&obj->st1)){
        pop(&obj->st1);
    }
}