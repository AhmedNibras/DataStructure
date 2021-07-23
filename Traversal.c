#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;
};

void linkedListTraversal(struct node* ptr)
{
    while(ptr!=NULL)
    {   
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }

};

int main(){

    struct node* head;
    struct node* second;
    struct node* third;
    struct node* fourth;

    // Allocate memory for node in the linked list in Heap
    head = (struct node* ) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node* ) malloc(sizeof(struct node));

    // Link first and second Node
    head->data = 7;
    head->next = second;

    // Link Second and third node
    second->data = 11;
    second->next = third;


    // Link Second and third node
    third->data = 51;
    third->next = fourth;

    //Terminate the list at third node
    fourth->data = 15;
    fourth->next = NULL;

    linkedListTraversal(head);

    return 0;
};