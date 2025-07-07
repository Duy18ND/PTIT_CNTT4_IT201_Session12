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

//Tao ham xoa
Node* removeAll(Node* head, int value) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == value) {
            Node* toDelete = temp;

            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }

    return head;
}


int main() {
    //Xoa du lieu co du lieu xac dinh
    Node* head = createNode(1);
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

    //Xoa du lieu chi dinh
    int value;
    printf("Moi ban nhap so nguyen bat ky de xoa");
    scanf("%d", &value);
    head = removeAll(head, value);
    printListNode(head);
    return 0;
}