#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void linkedlistTraversal(struct node* head){
    struct node* ptr = head;
    
    do{
        printf("Element is %d\n", ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
}

struct node* insertAtFirst(struct node *head, int data){
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;

    struct node* p = head->next;
    while(p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list.

    p->next  = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    // Allocate memory for node in the linked list in Heap
    head = (struct node* ) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node* ) malloc(sizeof(struct node));

    // Link first and second Node
    head->data = 15;
    head->next = second;

    // Link Second and third node
    second->data = 11;
    second->next = third;


    // Link Second and third node
    third->data = 51;
    third->next = fourth;

    //Terminate the list at third node
    fourth->data = 99;
    fourth->next = head;


    printf("Circular Linked list Before insertion\n");
    linkedlistTraversal(head);
    head = insertAtFirst(head, 80);
    printf("Circular Linked list after insertion\n");
    linkedlistTraversal(head);

    return 0;
}