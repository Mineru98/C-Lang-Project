#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[10];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} circularLinkedList_h;

circularLinkedList_h* createCircularLinkedList_h(void);
void freeCircularLinkedList_h(circularLinkedList_h*);
void insertFirstNode(circularLinkedList_h*, char*);
void insertMiddleNode(circularLinkedList_h*, listNode*, char*);
void reverse(circularLinkedList_h*);
void deleteNode(circularLinkedList_h*, listNode*);
void printList(circularLinkedList_h*);

// 원형 연결 리스트 생성
circularLinkedList_h* createCircularLinkedList_h() {
    circularLinkedList_h* CL;
    CL = (circularLinkedList_h*)malloc(sizeof(circularLinkedList_h));
    CL -> head = NULL;
    return CL;
}

// 원형 연결 리스트의 머리에 원소 추가
void insertFirstNode(circularLinkedList_h* CL, char* x) {
    listNode* newNode;
    listNode* p;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    if (CL -> head == NULL) {
        CL -> head = newNode;
        newNode -> link = newNode;
    } else {
        p = CL -> head;
        while (p -> link != CL -> head) {
            p = p -> link;
        }
        p -> link = newNode;
        newNode -> link = CL -> head;
    }
}

// 원형 연결 리스트의 사이에 원소 추가
void insertMiddleNode(circularLinkedList_h* CL, listNode* pre, char* x) {
    listNode* newNode;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    if (CL -> head == NULL) {
        CL -> head = newNode;
        newNode -> link = newNode;
    } else {
        newNode -> link = pre -> link;
        pre -> link = newNode;
    }
}

// 리스트 역전 재배치
void reverse(circularLinkedList_h* CL) {
    listNode* t;
    listNode* p;
    listNode* q;
    listNode* r;

    t = CL -> head;
    p = CL -> head;
    if (p != NULL) {
        do {
            p = p -> link;
        } while (p -> link != CL -> head);
    }
    p -> link = NULL;

    p = CL -> head;
    q = NULL;
    r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p -> link;
        q -> link = r;
    }
    CL -> head = q;
    t -> link = q;
}

// 원형 연결 리스트 원소 삭제
void deleteNode(circularLinkedList_h* CL, listNode* pre) {
    listNode* p;
    if (CL -> head == NULL) {

    } else {
        p = pre -> link;
        pre -> link = p -> link;
        if (p == CL -> head) {
            CL -> head = p -> link;
        }
    }
}

// 리스트 메모리 해제
void freeLinkedList_h(circularLinkedList_h* CL) {
    listNode* p;
    p = CL -> head;
    if (p != NULL) {
        do {
            p = p -> link;
        } while (p -> link != CL -> head);
    }
    p -> link = NULL;

    while (CL -> head != NULL) {
        p = CL -> head;
        CL -> head = CL -> head -> link;
        free(p);
        p = NULL;
    }
}

// 리스트 원소 출력
void printList(circularLinkedList_h* CL) {
    listNode* p;
    printf("CL = (");
    p = CL -> head;
    if (p != NULL) {
        do {
            printf("%s", p -> data);
            p = p -> link;
            if (p != CL -> head) printf(", ");
        } while (p != CL -> head);
    }
    printf(") \n");
}

int main() {
    circularLinkedList_h* CL;
    CL = createCircularLinkedList_h();

    printf("(1) 공백 리스트 생성\n");
    printList(CL); getchar();

    printf("(2) 리스트에 3개의 노드 추가\n");
    insertFirstNode(CL, "월");
    insertFirstNode(CL, "화");
    insertFirstNode(CL, "수");
    printList(CL); getchar();

    printf("(3) 리스트 사이에 노드 추가\n");
    insertMiddleNode(CL, CL -> head -> link, "목");
    printList(CL); getchar();

    printf("(4) 리스트 역순으로 배치\n");
    reverse(CL);
    printList(CL); getchar();

    printf("(5) 리스트 두번째 원소 삭제\n");
    deleteNode(CL, CL -> head);
    printList(CL); getchar();

    printf("(6) 공백 리스트로 초기화\n");
    freeLinkedList_h(CL);
    printList(CL); getchar();

    return 0;
}