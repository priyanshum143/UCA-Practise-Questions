#include <stdlib.h>
#include <string.h>
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

void push(struct Stack *st, int ch){
    if(st->top == st->size - 1) return;

    st->arr[++st->top] = ch;
}

void pop(struct Stack *st){
    if(st->top == -1) return;

    st->top--;
}

bool isEmpty(struct Stack *st) { return (st->top == -1); }

int peek(struct Stack *st){
    if(st->top == -1) return -1;
    return st->arr[st->top];
}

int longestValidParentheses(char* s) {
    struct Stack st;
    initializeStack(&st, strlen(s));
    push(&st, -1);

    int maxCount = 0;
    for(int i=0; i<strlen(s); i++){
        if(s[i] == '(') push(&st, i);
        else{
            pop(&st);
            if(!isEmpty(&st)){
                if(maxCount < (i - peek(&st)) ) maxCount = (i - peek(&st));
            }
            else push(&st, i);
        }
    }
    return maxCount;
}