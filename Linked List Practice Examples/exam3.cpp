
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <climits>

using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode *link;
} ListNode;

typedef struct ListType {
    int size;
    ListNode *head;
    ListNode *tail;
} ListType;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListType* create()
{
    ListType *plist = (ListType *)malloc(sizeof(ListType));
    plist->size = 0;
    plist->head = plist->tail = NULL;
    return plist;
}

void poly_print(ListType* plist)
{
    ListNode* p = plist->head;

    printf("=> ");
    for (; p; p = p->link) {
        printf("%d ", p->data);
    }
    printf("\n");
}

void insert_first(ListType *plist, int value)
{
    ListNode *head = plist->head;

    ListNode *p =
        (ListNode *)malloc(sizeof(ListNode));

    p->data = value;
    p->link = head;
    plist->head = p;

    if (plist->tail == NULL)
        plist->tail = p;

    plist->size++;
}

void insert_last(ListType *plist, int value)
{
    ListNode *p =
        (ListNode *)malloc(sizeof(ListNode));

    p->data = value;
    p->link = NULL;

    if (plist->tail == NULL) {
        plist->head = plist->tail = p;
    }
    else {
        plist->tail->link = p;
        plist->tail = p;
    }

    plist->size++;
}

int delete_first(ListType *plist)
{
    ListNode *head = plist->head;

    if (head == NULL) return INT_MIN;

    int r = head->data;

    ListNode *removed;
    removed = head;
    plist->head = removed->link;

    if (plist->head == NULL)
        plist->tail = NULL;

    free(removed);

    plist->size--;

    return r;
}

int delete_last(ListType *plist)
{
    ListNode *p = plist->head;

    if (p == NULL) return INT_MIN;

    if (p->link == NULL) {
        int r = p->data;

        free(p);
        plist->head = plist->tail = NULL;
        plist->size--;

        return r;
    }

    for (int i = 0; i < plist->size - 2; i++) {
        p = p->link;
    }

    int r = p->link->data;

    ListNode *removed;
    removed = p->link;
    p->link = NULL;

    free(removed);

    plist->tail = p;
    plist->size--;

    return r;
}

int main()
{
    ListType *list1, *list2, *list3, *list4, *list5;

    list1 = create();

    for (int i = 10; i < 80; i += 10) {
        insert_first(list1, i);
        poly_print(list1);
    }

    for (int i = 10; i < 80; i += 10) {
        delete_first(list1);
        poly_print(list1);
    }

    cout << "----------------------------" << endl;

    for (int i = 10; i < 80; i += 10) {
        insert_last(list1, i);
        poly_print(list1);
    }

    for (int i = 10; i < 80; i += 10) {
        delete_first(list1);
        poly_print(list1);
    }

    return 0;
}
