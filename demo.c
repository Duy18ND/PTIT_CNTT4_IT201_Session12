#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;
//Ham create
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
//Ham in
void printList(Node* head) {
    Node* current = head;
    printf("NULL <->");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//them dau
Node* insertNode(Node* head, int data) {
    Node* node = createNode(data);
    node->next = head;
    node->prev = head;
    head = node;
    return head;
}

//Them cuoi
Node* inserNodeEnd(Node* head, int data) {
    Node* node = createNode(data);
    if (head == NULL) return node;

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = node;
    node->prev = temp;

    return head;
}

//Them vao vi tri bat ky
Node* insertRandom(Node* head, int data, int index) {
    Node* node = createNode(data);
    if (index < 0 || index > head->data) return NULL;

    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    return head;
}
int main(){
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

    printList(head);

    // head = insertNode(head, 2);
    // printList(head);
    //
    // head = inserNodeEnd(head, 3);
    // printList(head);

    head = insertRandom(head, 2, 3);
    printList(head);
return 0;
}