#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct subject {

    struct subject* next;
    struct subject* prev;
    int digit;
}   Subject;

typedef struct list {

    Subject* head;
    Subject* tail;
    int amount;
}   List;

List Calculation(List number) {
    List num = number;

    Subject* temp = num.tail;
    while (num.tail) {
        num.tail->digit *= 3;
        num.tail = num.tail->prev;
    }
    num.tail = temp;
    while (num.tail->prev) {
        if (num.tail->digit / 10 > 0) {
            int tmp = num.tail->digit / 10;
            num.tail->prev->digit += tmp;
            num.tail->digit %= 10;
        }
        num.tail = num.tail->prev;
    }
    num.tail = temp;

    if (num.head->digit / 10 > 0) {
        Subject* p = (Subject*)malloc(sizeof(Subject));
        p->digit = num.head->digit / 10;
        p->prev = NULL;
        num.head->digit %= 10;
        p->next = num.head;
        num.head->prev = p;
        num.head = p;
        num.amount++;
    }
    return num;
}


List CreateNum(int pow) {
    List number = { NULL,NULL,0 };
    for (int i = 0; i < pow; i++)
    {
        if (!number.head) {
            Subject* n = (Subject*)malloc(sizeof(Subject));
            n->digit = 3;
            n->next = n->prev = NULL;
            number.head = number.tail = n;
            number.amount++;
        }
        else {
            number = Calculation(number);
        }
    }
    return number;
}

void Print(List num) {
    Subject* p = num.head;
    while (p) {
        printf("%d", p->digit);
        p = p->next;
    }

}

int main()
{
    int n;
    while (true)
    {
        printf("What is the power of 3?\n n = ");
        while ((!scanf("%d", &n)) || (n <= 0))
        {
            printf("Wrong input! Try again. n =\n");
            rewind(stdin);
        }
        List num = CreateNum(n);
        Print(num);
        printf("\n\n");
    }
    return 0;
}