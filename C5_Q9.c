/*Insert an element into a doubly linked list in any position. */

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *preptr;
    struct node *nextptr;
} * stnode, *ennode;

void insertAtBegining(int num)
{
    struct node *newnode;
    if (stnode == NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = stnode;
        newnode->preptr = NULL;
        stnode->preptr = newnode;
        stnode = newnode;
    }
}

void insertAtEnd(int num)
{
    struct node *newnode;

    if (ennode == NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->num = num;
        newnode->nextptr = NULL;
        newnode->preptr = ennode;
        ennode->nextptr = newnode;
        ennode = newnode;
    }
}

void insertAtAny(int num, int pos)
{
    int i;
    struct node *newnode, *tmp;
    if (ennode == NULL)
    {
        printf("List is Empty.\n");
    }
    else
    {
        tmp = stnode;
        i = 1;
        while (i < pos - 1 && tmp != NULL)
        {
            tmp = tmp->nextptr;
            i++;
        }
        if (pos == 1)
        {
            insertAtBegining(num);
        }
        else if (tmp == ennode)
        {
            insertAtEnd(num);
        }
        else if (tmp != NULL)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            newnode->num = num;
            newnode->nextptr = tmp->nextptr;
            newnode->preptr = tmp;
            if (tmp->nextptr != NULL)
            {
                tmp->nextptr->preptr = newnode;
            }
            tmp->nextptr = newnode; 
        }
        else
        {
            printf("Please Enter a Valid Position.\n");
        }
    }
}

void displayList(int m)
{
    struct node *tmp;
    int n = 1;
    if (stnode == NULL)
    {
        printf("Lsit is Emoty.");
    }
    else
    {
        tmp = stnode;
        if (m == 1)
        {
            printf("\nData in the list are:\n");
        }
        else
        {
            printf("\nAfter insertion the new list are :\n");
        }
        while (tmp != NULL)
        {
            printf("%d\n", tmp->num);
            n++;
            tmp = tmp->nextptr;
        }
    }
}

void createList(int n)
{
    int i, num;
    struct node *fnNode;

    if (n >= 1)
    {
        stnode = (struct node *)malloc(sizeof(struct node));

        if (stnode != NULL)
        {
            printf("node 1 : ");
            scanf("%d", &num);

            stnode->num = num;
            stnode->preptr = NULL;
            stnode->nextptr = NULL;
            ennode = stnode;
            for (i = 2; i <= n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if (fnNode != NULL)
                {
                    printf("node %d : ", i);
                    scanf("%d", &num);
                    fnNode->num = num;
                    fnNode->preptr = ennode;
                    fnNode->nextptr = NULL;
                    ennode->nextptr = fnNode;
                    ennode = fnNode;
                }else
                {
                    printf("Memory allocation not Possible.");
                    break;
                }
            }
        }
        else
        {
            printf("Memory allocation not Possibled.");
        }
    }
}

int main()
{
    int n, num1, a, insPlc;
    stnode = NULL;
    ennode = NULL;
    printf("\nEnter the size of the List:\n");
    scanf("%d", &n);
    createList(n);
    a = 1;
    displayList(a);
    printf("\nEnter the position ( 1 to %d ) to insert a new node: ", n + 1);
    scanf("%d", &insPlc);
    printf("Enter the the element to insert: ", insPlc);
    scanf("%d", &num1);
    insertAtAny(num1, insPlc);
    a = 2;
    displayList(a);
    return 0;
}