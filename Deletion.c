#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;  
    struct node* next;
};

void linkedlistTraversal(struct node*ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Case 1: deleting the first element from the linked list
struct node* deleteFirst(struct node* head)
{
    struct node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Case 2: deleting the element at a give index from the linked list
struct node* deleteAtIndex(struct node* head, int index)
{
    struct node* p = head;
    struct node* q = head->next;
    for(int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;

    free(q);

    return head;

}

// Case3: Deleting the last  element
struct node* deleteLast(struct node* head)
{
    struct node* p =head;
    struct node* q = head->next;
    while(q->next !=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

// Case4: Deleting the element at a given index from the linked list
struct node* deleteAtValue(struct node* head, int value){
    struct node* p = head;
    struct node* q= head->next;
    while(q->data != value && q->next != NULL)
    {
        p = p -> next;
        q = q -> next;
    }

    if(q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{   
    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    head->data = 87;
    head->next = second;

    second->data = 45;
    second->next = third;

    third->data = 96;
    third->next = fourth;

    fourth->data = 31;
    fourth->next = NULL;

    printf("Linked list before deletion\n");
    linkedlistTraversal(head);

    head = deleteFirst(head); // For deleting first element of the linked list
    head = deleteAtIndex(head, 2); // For deleting at a given index of the linked list
    head = deleteLast(head); // For deleting last element of the linked list
    head = deleteAtValue(head, 45); // For deleting the value from the linkedlist
    printf("Linked list After deletion\n");
    linkedlistTraversal(head);

    return 0;
}