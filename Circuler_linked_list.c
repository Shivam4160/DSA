#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int Data;
    struct Node *Next;
};
struct Node *head = NULL;
struct Node *tail = NULL;

void Insert_End(int element)
{

    struct Node *temp = malloc(sizeof(struct Node));
    temp->Data = element;
    temp->Next = head;
    if (head == NULL && tail == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }

    tail->Next = temp;
    tail = temp;
}

void Delete_End()
{
    struct Node *ptr = tail;
    struct Node *p = head;

    if (head == NULL)
    {
        printf("\nList is Empty!!\n");
        return;
    }
    else if (head == tail)
    {
        head = NULL;
        free(ptr);
        return;
    }

    while (p->Next != ptr)
    {

        p = p->Next;
    }

    p->Next = head;
    tail = p;
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
        while (ptr != tail)
        {
            printf("%d ", ptr->Data);
            ptr = ptr->Next;
        }

        printf("%d ", ptr->Data);
        printf("\n");
    }
}

int main()
{
    int Choice, Data;
    while (1)
    {

        printf("1. Insert at the end\n");
        printf("2. Delete from the end\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &Choice);

        if (!(Choice < 8 || Choice > 0))
        {
            printf("Invalid Choice!! Enter Again..");

            continue;
        }

        switch (Choice)
        {

        case 1:

            printf("Enter Data to ber enserted:");
            scanf("%d", &Data);

            Insert_End(Data);
            break;

        case 2:

            Delete_End();

            break;

        case 3:

            Display();

            break;

        case 4:

            exit(0);
        }
    }
}
