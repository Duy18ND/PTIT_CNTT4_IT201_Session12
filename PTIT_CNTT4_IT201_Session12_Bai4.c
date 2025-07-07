#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

//Tao ham create
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
//Ham in
void printListNode(Node* head) {
    Node* temp = head;
    printf("NULL <-> ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Tao ham them cuoi DSLKD
Node* removeEnd(Node* head) {
    if (head == NULL) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}
int main() {
    //Xoa cuoi  DSLKD
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    printListNode(head);

    //Xoa cuoi
    head = removeEnd(head);
    printListNode(head);
    return 0;
}