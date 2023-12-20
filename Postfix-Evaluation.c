#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Stack Data Structure
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

void pop(struct Stack *st){
    if(st->top == -1) return;

    st->top--;
}

bool isEmpty(struct Stack *st) { return (st->top == -1); }

int peek(struct Stack *st){
    if(st->top == -1) return '\0';
    return st->arr[st->top];
}

// Function to take input
int takeInput(char* str){
    int len = 0;
    while(true){
        scanf("%c", &str[len]);
        if(str[len] == '?') break;
        len++;
    }
    return len;
}

int postfixEvaluation(char* str, int len){
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    initializeStack(st, len);

    for(int i=0; i<len; i++){
        if(str[i] >= '0' && str[i] <= '9'){
            int num = 0;
            while(str[i] != ' '){
                num = (num * 10) + (str[i] - '0');
                i++;
            }
            push(st, num);
        }
        else if(str[i] == ' ') continue;
        else{
            char operator = str[i];

            int operand1 = peek(st);
            pop(st);
            int operand2 = peek(st);
            pop(st);

            switch(operator){
                case '+':
                    push(st, (operand2 + operand1));
                    break;

                case '-':
                    push(st, (operand2 - operand1));
                    break;

                case '*':
                    push(st, (operand2 * operand1));
                    break;

                case '/':
                    push(st, (operand2 / operand1));
                    break;
            }
        }
    }
    int ans = peek(st);
    free(st->arr);
    free(st);
    return ans;
}

// Main function
int main(){
    int testCases;
    scanf("%d", &testCases);

    while(testCases--){
        char *str = (char *)malloc(10000 * sizeof(char));
        int len = takeInput(str);

        int ans = postfixEvaluation(str, len);
        printf("%d\n", ans);

        free(str);
    }
}