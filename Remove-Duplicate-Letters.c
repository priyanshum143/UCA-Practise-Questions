#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack {
    int size;
    int top;
    char *arr;
};

void initialize(struct Stack *st, int size) {
    st->top = -1;
    st->size = size;
    st->arr = (char *) malloc(size * sizeof(char));
}

bool isEmpty(struct Stack *st) {
    return (st->top == -1);
}

bool push(struct Stack *st, char ele) {
    if (st->top == st->size - 1) return false;
    st->arr[++st->top] = ele;
    return true;
}

char pop(struct Stack *st) {
    if (isEmpty(st)) return '\0';
    return (st->arr[st->top--]);
}

char top(struct Stack *st) {
    if (isEmpty(st)) return '\0';
    return (st->arr[st->top]);
}

char* removeDuplicateLetters(char* s) {
    bool visited[26];
    int index[26];

    struct Stack st;
    initialize(&st, strlen(s));

    for(int i=0; i<strlen(s); i++){
        visited[s[i]- 'a'] = false;
        index[s[i] - 'a'] = i;
    }

    for(int i=0; i<strlen(s); i++){
        int curr = s[i] - 'a';
        if (visited[curr]) continue;
        while(!isEmpty(&st) && top(&st) > s[i] && i < index[top(&st) - 'a']){
            visited[pop(&st) - 'a'] = false;
        }
        push(&st, s[i]);
        visited[curr] = true;
    }

    int len = 0;
    char rev[1000] ;
    while(!isEmpty(&st)){
        rev[len++] = pop(&st);
    }
    char* ans = malloc((len + 1) * sizeof(char));

    for(int i=0; i<len; i++){
        ans[i] = rev[len - i - 1];
    }
    ans[len] = '\0';
    return ans;
}