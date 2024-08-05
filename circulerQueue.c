#include <stdio.h>
#include <stdlib.h>
int Size;
int f = -1, r = -1;

int Display(int Queue[])
{
    int i = f;

    if (f < 0)
    {
        printf("queue is empty");
    }
    else
    {

        while (i != (r + 1) % Size)
        {
            printf("%d  ", Queue[i]);
            i = (i + 1) % Size;
        }
        // printf("%d  \n", Queue[r]);
    }
}
int EnQueue(int Queue[], int val)
{
    if (r < 0)
    {
        f = r = 0;
        Queue[r] = val;
    }
    else if ((r + 1) % Size == f)
    {
        printf("queue is full");
    }
    else
    {
        r = (r + 1) % Size;
        Queue[r] = val;
    }
}

int DeQueue()
{
    if (f < 0)
    {
        printf("queue is empty");
    }
    else if (f == r)
    {
        f = r = -1;
    }
    else
    {
        f = (f + 1) % Size;
    }
}
int main()
{
    int choice, element;
    printf("Enter the size of Queue:");
    scanf("%d", &Size);
    int Queue[Size];

   

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