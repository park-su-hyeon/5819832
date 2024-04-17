#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    return (sptr->top == sptr->capacity - 1);
}

int is_empty(StackType* sptr) {
    return (sptr->top == -1);
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    sptr->data[++(sptr->top)] = item;
    printf("Push : %d\n", item); // Print the pushed element
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    return sptr->data[(sptr->top)--];
}

void stack_print(StackType* sptr) {
    printf("Stack elements : ");
    if (is_empty(sptr)) {
        printf("Empty\n");
    } else {
        for (int i = sptr->top; i >= 0; i--) {
            printf("%d ", sptr->data[i]);
        }
    }
    printf("\n");
}

int main() {
    StackType s;
    init(&s, MAX_STACK_SIZE);
    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        int rand_num = rand() % 100 + 1; // Generating random number between 1 and 100
        printf("Random number : %d\n", rand_num);
        printf("Current rand_num : %d | ", rand_num);
        if (rand_num % 2 == 0) {
            printf("Even\n");
            push(&s, rand_num);
        } else {
            printf("Odd\n");
            if (!is_empty(&s)) {
                printf("Pop : %d\n", pop(&s));
            } else {
                printf("Stack is Empty\n");
            }
        }

        stack_print(&s);
        printf("\n");
    }

    free(s.data); // Freeing allocated memory
    return 0;
}
