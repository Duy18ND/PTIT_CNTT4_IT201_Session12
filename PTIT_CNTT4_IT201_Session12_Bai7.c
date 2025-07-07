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

//Tao ham sap xep tang dan
Node* sortList(Node* head) {
    if (head == NULL) return NULL;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }

        lptr = ptr1;
    } while (swapped);

    return head;
}

int main() {
    //Sap xep tang dan
    Node* head = createNode(23);
    Node* node2 = createNode(2);
    Node* node3 = createNode(2);
    Node* node4 = createNode(2);
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

    //sap xep tang dan
    head = sortList(head);
    printListNode(head);

    return 0;
}