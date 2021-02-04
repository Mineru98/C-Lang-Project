#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
    char data[10];
    struct ListNode* link;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void);
void freeLinkedList_h(linkedList_h*);
void addLastNode(linkedList_h*, char*);
void reverse(linkedList_h*);
void deleteLastNode(linkedList_h*);
void printList(linkedList_h*);

// 단일 연결 리스트 생성
linkedList_h* createLinkedList_h() {
    linkedList_h* L;
    L = (linkedList_h*)malloc(sizeof(linkedList_h));
    L -> head = NULL;
    return L;
}

// 리스트에 원소 추가
void addLastNode(linkedList_h* L, char* x) {
    listNode* newNode;
    listNode* p;
    newNode = (listNode*)malloc(sizeof(listNode));
    strcpy(newNode -> data, x);
    newNode -> link = NULL;
    if (L -> head == NULL) {
        L -> head = newNode;
        return;
    }
    p = L -> head;
    while (p -> link != NULL) p = p -> link;
    p -> link = newNode;
}

// 리스트 역전 재배치
void reverse(linkedList_h* L) {
    listNode* p;
    listNode* q;
    listNode* r;

    p = L -> head;
    q = NULL;
    r = NULL;

    while (p != NULL) {
        r = q;
        q = p;
        p = p -> link;
        q -> link = r;
    }
    L -> head = q;
}

// 리스트 원소 삭제
void deleteLastNode(linkedList_h* L) {
    listNode* previous;
    listNode* current;
    if (L -> head == NULL) return;
    if (L -> head -> link == NULL) {
        free(L -> head);
        L -> head = NULL;
        return;
    } else {
        previous = L -> head;
        current = L -> head -> link;
        while (current -> link != NULL) {
            previous = current;
            current = current -> link;
        }
        free(current);
        previous -> link = NULL;
    }
}

// 리스트 메모리 해제
void freeLinkedList_h(linkedList_h* L) {
    listNode* p;
    while (L -> head != NULL) {
        p = L -> head;
        L -> head = L -> head -> link;
        free(p);
        p = NULL;
    }
}

// 리스트 원소 출력
void printList(linkedList_h* L) {
    listNode* p;
    printf("L = (");
    p = L -> head;
    while (p != NULL) {
        printf("%s", p -> data);
        p = p -> link;
        if (p != NULL) printf(", ");
    }
    printf(") \n");
}


int main() {
    linkedList_h* L;
    L = createLinkedList_h();
    printf("(1) 공백 리스트 생성\n");
    printList(L); getchar();

    printf("(2) 리스트에 3개의 노드 추가\n");
    addLastNode(L, "월");
    addLastNode(L, "화");
    addLastNode(L, "수");
    printList(L); getchar();

    printf("(3) 리스트 역순으로 배치\n");
    reverse(L);
    printList(L); getchar();

    printf("(4) 리스트의 마지막 노드 삭제\n");
    deleteLastNode(L);
    printList(L); getchar();

    printf("(5) 리스트의 마지막에 1개의 노드 추가\n");
    addLastNode(L, "목");
    printList(L); getchar();

    printf("(6) 공백 리스트로 초기화\n");
    freeLinkedList_h(L);
    printList(L); getchar();

    return 0;
}