#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void linkedlistTraversal(struct node* ptr)
{   
    while (ptr != NULL)
    {
    printf("Element is %d\n", ptr->data);
    ptr = ptr->next;
    }
    
};

// Case 1:
struct node* insertAtFirst(struct node *head, int data)
{
     struct node * ptr = (struct node*) malloc(sizeof(struct node));
     ptr->next = head;
     ptr->data = data;
     return ptr;
};

// Case 2:

struct node* insertAtIndex(struct node *head, int data, int index)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    struct node* p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
};

// Case 3:

struct node* insertAtEnd(struct node* head, int data)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;

    while(p->next!=NULL)
    {
        p = p->next;

    }
    p->next = ptr;
    ptr->next= NULL;
    return head;

};

//Case 4:

struct node* insertAfter(struct node* head, struct node* prevNode, int data)
{
    struct node* ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
};

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
    fourth->next = NULL;
    
    linkedlistTraversal(head);
    // head = insertAtFirst(head, 56);
    // head = insertAtIndex(head, 45, 1);
    // head = insertAtEnd(head, 10);
    head = insertAfter(head, second, 22);
    printf("New List\n");
    linkedlistTraversal(head);
    return 0;
};