#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printListNode(Node* head) {
    Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int getlength(Node* head) {
    Node* temp = head;
    int length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

void searchMid(Node* head, int* outIndex, int* outValue) {
    int len = getlength(head);
    
    if (len == 0) {
        if (outIndex != NULL) *outIndex = -1;
        if (outValue != NULL) *outValue = 0;
        return;
    }
    
    int midIndex = len / 2; 
    
    Node* temp = head;
    for (int i = 0; i < midIndex; i++) {
        temp = temp->next;
    }
    
    if (outIndex != NULL) *outIndex = midIndex;
    if (outValue != NULL) *outValue = temp->data;
}

void searchMidAlternative(Node* head, int* outIndex, int* outValue) {
    int len = getlength(head);
    
    if (len == 0) {
        if (outIndex != NULL) *outIndex = -1;
        if (outValue != NULL) *outValue = 0;
        return;
    }
    
    int midIndex = (len - 1) / 2; 
    
    Node* temp = head;
    for (int i = 0; i < midIndex; i++) {
        temp = temp->next;
    }
    
    if (outIndex != NULL) *outIndex = midIndex;
    if (outValue != NULL) *outValue = temp->data;
}

int main() {
    Node* head = createNode(5);
    Node* node2 = createNode(4);
    Node* node3 = createNode(2);
    Node* node4 = createNode(11);
    Node* node5 = createNode(1);

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    printf("Danh sach:\n");
    printListNode(head);
    
    printf("Do dai danh sach: %d\n", getlength(head));

    int midIndex, midValue;
    searchMid(head, &midIndex, &midValue);
    printf("\nPhan tu giua (phuong phap 1): Gia tri = %d, Index = %d\n", midValue, midIndex);

    searchMidAlternative(head, &midIndex, &midValue);
    printf("Phan tu giua (phuong phap 2): Gia tri = %d, Index = %d\n", midValue, midIndex);

    return 0;
}
