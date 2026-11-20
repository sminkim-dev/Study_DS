
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX_ELEMENT 200

typedef struct {
    int key;
    int data;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

typedef struct {
    HeapType *heap;
    int priortiy;
} StackType;

typedef struct {
    HeapType *heap;
    int priortiy;
} QueueType;


// 생성 함수
HeapType* create()
{
    return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h)
{
    h->heap_size = 0;
}


// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
void insert_max_heap(HeapType* h, element item)
{
    int i;
    i = ++(h->heap_size);

    while ((i != 1) && (item.key > h->heap[i / 2].key)) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }

    h->heap[i] = item;
}


// 삭제 함수
element delete_max_heap(HeapType* h)
{
    int parent, child;
    element item, temp;

    item = h->heap[1];
    temp = h->heap[(h->heap_size)--];

    parent = 1;
    child = 2;

    while (child <= h->heap_size) {

        if ((child < h->heap_size) &&
            (h->heap[child].key < h->heap[child + 1].key))
            child++;

        if (temp.key >= h->heap[child].key) break;

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}


// Stack 생성
StackType* create_s()
{
    StackType *s = (StackType*)malloc(sizeof(StackType));

    s->heap = create();
    init(s->heap);
    s->priortiy = 0;

    return s;
}


// Stack Push
void push(StackType *s, int data)
{
    element e = {s->priortiy++, data};
    insert_max_heap(s->heap, e);
}


// Stack Pop
int pop(StackType *s)
{
    element e = delete_max_heap(s->heap);
    return e.data;
}


// Queue 생성
QueueType* create_q()
{
    QueueType *s = (QueueType*)malloc(sizeof(QueueType));

    s->heap = create();
    init(s->heap);
    s->priortiy = 0;

    return s;
}


// Queue Enqueue
void enqueue(QueueType *s, int data)
{
    element e = {s->priortiy--, data};
    insert_max_heap(s->heap, e);
}


// Queue Dequeue
int dequeue(QueueType *s)
{
    element e = delete_max_heap(s->heap);
    return e.data;
}


int main(void)
{
    StackType *s = create_s();

    for(int i = 0; i < 100; i += 10) {
        push(s, i);
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << pop(s) << " ";
    }

    cout << endl;
    cout << "---------------------" << endl;

    QueueType *q = create_q();

    for(int i = 0; i < 100; i += 10) {
        enqueue(q, i);
        cout << i << " ";
    }
    cout << endl;
    for(int i = 0; i < 10; i++) {
        cout << dequeue(q) << " ";
    }

    return 0;
}
