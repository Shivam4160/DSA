#include <stdio.h>
#include <stdlib.h>
int position, element;

struct Node
{
    int Data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void Insert_Front()
{
    struct Node *ptr = head;
    struct Node *temp = malloc(sizeof(struct Node));

    printf("\nEnter Element to be entered.");
    scanf("%d", &element);

    temp->Data = element;
    temp->prev = NULL;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        head = temp;
        temp->next = ptr;
        temp->prev = tail;
        ptr->prev = temp;
    }
}

void Delete_Front()
{

    struct Node *ptr = head;

    if (head == NULL || tail == NULL)
    {
        printf("\nList is Empty...\n");
        return;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        free(ptr);
        return;
    }

    head = head->next;
    head->prev = tail;
    tail->next = head;
    free(ptr);
}

void Insert_Mid()
{

    if (head == NULL || tail == NULL)
    {
        printf("\nList is Empty...\n");
        return;
    }
    else if (head->next == NULL)
    {
        printf("\nList has only one Element..Insert mid can't be done.\n ");
        return;
    }
    else
    {
        struct Node *ptr = head;
        struct Node *p;
        struct Node *temp = malloc(sizeof(struct Node));

        printf("\nEnter the Data where you want to add new Data:");
        scanf("%d", &position);

        printf("\nEnter Element to be entered.");
        scanf("%d", &element);

        temp->Data = element;
        temp->next = NULL;
        temp->prev = NULL;

        while (ptr->Data != position)
        {
            p = ptr;
            ptr = ptr->next;
        }
        ptr->prev = temp;
        p->next = temp;
        temp->prev = p;
        temp->next = ptr;
    }
}

void Delete_Mid(int position)
{

    if (head == NULL || tail == NULL)
    {
        printf("\nList is Empty...\n");
        return;
    }
    else if (head->next == NULL)
    {
        printf("\nList has only one Element..Delete mid can't be done.\n");
        return;
    }

    struct Node *ptr = head;
    struct Node *p;

    printf("\nEnter the Data which you want to delete:");
    scanf("%d", &position);

    while (ptr->Data != position)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next->prev = p;
    free(ptr);
}

void Insert_End(int element)
{

    if (head == NULL || tail == NULL)
    {
        printf("\nList is Empty...\n");
        return;
    }

    struct Node *ptr = head;
    struct Node *p;
    struct Node *temp = malloc(sizeof(struct Node));

    printf("\nEnter Element to be entered.");
    scanf("%d", &element);

    temp->Data = element;
    temp->next = NULL;
    temp->prev = NULL;

    while (ptr != tail)
    {
        p = ptr;
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    temp->next = head;
    tail = temp;
}

void Delete_End()
{
    struct Node *ptr = head;
    struct Node *p;

    if (head == NULL || tail == NULL)
    {
        printf("\nList is Empty...\n");
        return;
    }

    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        free(ptr);
        return;
    }
    else
    {
        while (ptr != tail)
        {
            p = ptr;
            ptr = ptr->next;
        }
        p->next = head;
        tail = p;
        free(ptr);
    }
}

void Display()
{

    if (head == NULL)
    {
        printf("Your List is Alerady Empty!!");
        return;
    }
    else
    {

        struct Node *ptr = head;

        while (ptr != tail)
        {
            printf("%d ", ptr->Data);
            ptr = ptr->next;
        }
        printf("%d", ptr->Data);
        printf("\n");
    }
}

int main()
{

    int choice, element, position;

    while (1)
    {
        printf("\n1.Insert from front\n");
        printf("2.Delete from front\n");
        printf("3.Insert from Mid\n");
        printf("4.Delete from Mid\n");
        printf("5.Insert from End\n");
        printf("6.Delete from End\n");
        printf("7.Display\n");
        printf("8.Exit\n");

        printf("Enter Your Choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            Insert_Front(element);

            break;
        case 2:

            Delete_Front();

            break;
        case 3:

            Insert_Mid(element, position);

            break;
        case 4:

            Delete_Mid(position);

            break;
        case 5:

            Insert_End(element);

            break;
        case 6:

            Delete_End();

            break;
        case 7:

            Display();

            break;
        case 8:

            exit(0);

            break;
        }
    }

    return 0;
}