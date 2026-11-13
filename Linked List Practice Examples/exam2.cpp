#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct ListNode { // 노드 타입
	int coef;
	int expon;
	struct ListNode *link;
} ListNode;

// 연결 리스트 헤더
typedef struct ListType { // 리스트 헤더 타입
	int size;
	ListNode *head;
	ListNode *tail;
} ListType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//  리스트 헤더 생성 함수
ListType* create()
{
	ListType *plist = (ListType *)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

// plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, 
// expon는 지수
void insert_last(ListType* plist, int coef, int expon)
{
	ListNode* temp =
		(ListNode *)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

// list3 = list1 + list2
void poly_add(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   // a의 차수 > b의 차수
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  // a의 차수 == b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {					// a의 차수 < b의 차수
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, b->coef, b->expon);
}
void poly_sub(ListType* plist1, ListType* plist2, ListType* plist3)
{
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;

	while (a && b) {
		if (a->expon == b->expon) {   // a의 차수 > b의 차수
			sum = a->coef - b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link; b = b->link;
		}
		else if (a->expon > b->expon) {  // a의 차수 == b의 차수 
			insert_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {					// a의 차수 < b의 차수
			insert_last(plist3, (-1)*b->coef, b->expon);
			b = b->link;
		}
	}
	// a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 
	// 결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_last(plist3, (-1)*b->coef, b->expon);
}

// c
void poly_mult(ListType* plist1, ListType* plist2, ListType* plist3)
{
    ListNode* a = plist1->head;
    ListNode* b = plist2->head;

    int max1 = a->expon;
    int max2 = b->expon;
    int d = max1 + max2;

    int aa[101];
    int bb[101];
    int cc[201];

    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    memset(cc, 0, sizeof(cc));

    // 첫 번째 다항식 저장
    for (; a != NULL; a = a->link)
        aa[a->expon] = a->coef;

    // 두 번째 다항식 저장
    for (; b != NULL; b = b->link)
        bb[b->expon] = b->coef;

    // 다항식 곱셈
    for (int i = 0; i <= max1; i++) {
        for (int j = 0; j <= max2; j++) {
            cc[i+j] += aa[i] * bb[j];
        }
    }

    // 결과를 연결 리스트에 저장
    for (int i = d; i >= 0; i--) {
        if (cc[i] != 0)
            insert_last(plist3, cc[i], i);
    }
}
//
//
void poly_print(ListType* plist)
{
	ListNode* p = plist->head;

	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%dx^%d + ", p->coef, p->expon);
	}
	printf("\n");
}


int main(){
    ListType *list1, *list2, *list3, *list4, *list5;

	// 연결 리스트 헤더 생성
	list1 = create();
	list2 = create();
	list3 = create();
    list4 = create();
	list5 = create();

	// 다항식 1을 생성 
	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	// 다항식 2를 생성 
	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);

    cout << "----------------------------" << endl;
	poly_print(list1);
	poly_print(list2);

    cout << "----------------------------" << endl;

	// 다항식 3 = 다항식 1 + 다항식 2
	poly_add(list1, list2, list3);
	poly_print(list3);
    
    cout << "----------------------------" << endl;

    poly_sub(list1, list2, list4);
    poly_print(list4);
    
    cout << "----------------------------" << endl;

    poly_mult(list1, list2, list5);
    poly_print(list5);


	free(list1); free(list2); free(list3);

    return 0;
}