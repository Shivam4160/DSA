#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void Insert_End(int val)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->prev = ptr;
    }
}

void Delete_End()
{
    struct node *ptr = head;
    struct node *p;
    if (head->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }
    else
    {
        while (ptr->next != NULL)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = NULL;
        free(ptr);
    }
}

void Insert_Front(int val)
{

    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));

    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    else
    {
        head = temp;
        temp->next = ptr;
        ptr->prev = temp;
    }
}

void Delete_Front()
{
    struct node *ptr = head;
    if (head->next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
        free(ptr);
    }
}

void Insert_Mid(int val, int pos)
{
    struct node *ptr = head;
    struct node *p;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = temp;
    temp->prev = p;
    temp->next = ptr;
    ptr->prev = temp;
}

void Delete_Mid(int pos)
{
    struct node *ptr = head;
    struct node *p;

    while (ptr->data != pos)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next->prev = p;
    free(ptr);
}

void Display()
{
    struct node *ptr = head;

    if (head == NULL)
    {
        printf("Your List is Alerady Empty!!");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int Choice, Element, Position;

    while (1)
    {
        printf("\n1.Insert Front");
        printf("\n2.Delete Front");
        printf("\n3.Insert Mid");
        printf("\n4.Delete Mid");
        printf("\n5.Insert End");
        printf("\n6.Delete End");
        printf("\n7.Display");
        printf("\n8.Exit");

        printf("\nEnter your Choice:");
        scanf("%d", &Choice);

        if (!(Choice < 8 || Choice > 0))
        {
            printf("Invalid Choice!! Enter Again..");

            continue;
        }

        switch (Choice)
        {
        case 1:

            printf("\nEnter Element to be Inserted:");
            scanf("%d", &Element);

            Insert_Front(Element);
            break;

        case 2:

            Delete_Front();

            break;
        case 3:

            Display();
            printf("\nEnter the Data where you want to add new Data:");
            scanf("%d", &Position);

            printf("\nEnter Element to be Inserted:");
            scanf("%d", &Element);

            Insert_Mid(Element, Position);

            break;

        case 4:

            printf("\nEnter the Data which you want to delete:");
            scanf("%d", &Position);

            Delete_Mid(Position);

            break;
        case 5:

            printf("\nEnter Element to be Inserted:");
            scanf("%d", &Element);

            Insert_End(Element);

            break;
        case 6:

            Delete_End();

            break;
        case 7:

            Display();

            break;
        case 8:

            goto Exit;
        }
    }

Exit:
    return 0;
}