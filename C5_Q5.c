/* WAP to traverse a circular linked list. */

#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * next;
}*head;

void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;
    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->next = NULL;
        prevNode = head;
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->next = NULL;
            prevNode->next = newNode;
            prevNode = newNode;
        }
        prevNode->next = head;
        printf("\n");
    }
}


void displayList()
{
    struct node *current;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("Data in the List:\n");

        do {
            printf("Node %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}
int main()
{
    int n;
    printf("\nEnter the number of nodes:\n");
    scanf("%d", &n);
    printf("\nEntered data  in the list:\n");
    createList(n);
    displayList();
    return 0;
}