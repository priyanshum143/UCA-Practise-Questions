#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack{
    int size;
    int top;
    char* arr;
};

void initializeStack(struct Stack *st, int size){
    st->size = size;
    st->top = -1;
    st->arr = (char *) (malloc(size * sizeof(char)));
}

void push(struct Stack *st, char ch){
    if(st->top == st->size - 1) return;

    st->arr[++st->top] = ch;
}

void pop(struct Stack *st){
    if(st->top == -1) return;

    st->top--;
}

bool isEmpty(struct Stack *st) { return (st->top == -1); }

char peek(struct Stack *st){
    if(st->top == -1) return '\0';
    return st->arr[st->top];
}

bool isValid(char* s) {
    struct Stack st;
    initializeStack(&st, strlen(s));

    for(int i=0; i<strlen(s); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') push(&st, s[i]);
        else if(s[i] == ')'){
            if(peek(&st) == '(') pop(&st);
            else return false;
        }
        else if(s[i] == '}'){
            if(peek(&st) == '{') pop(&st);
            else return false;
        }
        else if(s[i] == ']'){
            if(peek(&st) == '[') pop(&st);
            else return false;
        }
    }

    return (isEmpty(&st));
}