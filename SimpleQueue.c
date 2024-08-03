#include <stdio.h>
#include <stdlib.h>
int R = -1; // rear
int F = -1; // front
int Size;   // size of Queue

void EnQueue(int Queue[], int element)
{

    if (R == Size - 1)
    {
        printf("\nQueue is full.\n");
    }
    else if (R == -1 && F == -1)
    {
        R++;
        F++;
        Queue[R] = element;
    }
    else
    {
        R++;
        Queue[R] = element;
        printf("\nElement %d is added.\n", element);
    }
}

void DeQueue()
{

    if (R == -1 && F == -1)
    {

        printf("\nQueue is empty.\n");
    }
    else if (R == F)
    {
        F = -1;
        R = -1;
        printf("DeQueued");
    }
    else
    {
        F++;
        printf("DeQueued");
    }
}

void Display(int Queue[])
{
    printf("Queue \n\n\n********************************************************************************\n\n");
    if (R == -1 && F == -1)
    {

        printf("\nQueue is empty.\n");
    }
    else
    {

        for (int i = F; i <= R; i++)
        {
            printf("%d  ", Queue[i]);
        }
    }
}

int main()
{

    int choice, element;
    printf("Enter the size of Queue:");
    scanf("%d", &Size);
    int Queue[Size];

    for (int i = 0; i < Size; i++)
    {
        Queue[i] = rand() % 1000;
    }

    while (1)
    {

        printf("\n1.EnQueue");
        printf("\n2.DeQueue");
        printf("\n3.display");
        printf("\n4.Exit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);
        if (choice > 4)
        {
            printf("Invalid choice.");
        }

        switch (choice)
        {
        case 1:
            printf("Enter the elment you want to enter:");
            scanf("%d", &element);
            EnQueue(Queue, element);
            break;

        case 2:
            DeQueue();
            break;

        case 3:
            Display(Queue);
            break;

        case 4:
            goto Exit;
            break;
        }
    }
Exit:

    return 0;
}
