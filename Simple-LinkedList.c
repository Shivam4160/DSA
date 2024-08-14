#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};

struct Node *head = NULL;

void Insert_Front(int Element)
{
    struct Node *ptr = head;
    struct Node *temp = malloc(sizeof(struct Node));
    temp->Data = Element;
    temp->Next = head;
    head = temp;
}
void Delete_Front()
{
    struct Node *ptr = head;
    head = ptr->Next;
    free(ptr);
}
void Insert_Mid(int Element, int Position)
{
    struct Node *ptr = head;
    struct Node *p;
    struct Node *temp = malloc(sizeof(struct Node));

    temp->Data = Element;
    temp->Next = NULL;

    while (ptr->Data != Position)
    {
        p = ptr;
        ptr = ptr->Next;
    }

    p->Next = temp;
    temp->Next = ptr;
}
void Delete_Mid(int Position)
{
    struct Node *ptr = head;
    struct Node *p;

    while (ptr->Data != Position)
    {
        p = ptr;
        ptr = ptr->Next;
    }

    p->Next = ptr->Next;
    free(ptr);
}
void Insert_End(int Element)
{
    struct Node *ptr = head;

    struct Node *temp = malloc(sizeof(struct Node));

    temp->Data = Element;
    temp->Next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    while (ptr->Next != NULL)
    {
        ptr = ptr->Next;
    }
    ptr->Next = temp;
    return;
}
void Delete_End()
{
    struct Node *ptr = head;
    struct Node *p;

    if (head->Next == NULL)
    {
        head = NULL;
        free(ptr);
        return;
    }

    while (ptr->Next != NULL)
    {
        p = ptr;
        ptr = ptr->Next;
    }

    p->Next = NULL;
    free(ptr);
    return;
}

void Display()
{
    struct Node *ptr = head;
    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->Data);
            ptr = ptr->Next;
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