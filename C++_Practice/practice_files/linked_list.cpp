#include <cstddef>
#include <iostream>

struct Node{
    int data;
    Node *next;
};

void traversal(struct Node* n)
{
    while(n!=NULL)
    {
        printf("%d\n", n->data);
        n=n->next;
    }
}

void insertHead(Node **head, int new_data){
    Node *newNode = new Node();
    newNode->data = new_data;
    newNode->next = (*head);
    (*head) = newNode;
}

void insertTail(Node *n, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;
    n->next = temp;
}

void insertMiddle(Node*n, int data){
    Node *temp = new Node();
    temp->data = data;
    temp->next = n->next;
    n->next = temp;
}

int main(){
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    //allocate nodes in heap
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third -> data= 5;
    third->next =NULL;

    insertTail(third, 6);
    insertMiddle(second, 3);
    insertHead(&head, 1);

    traversal(head);

    return 0;
}