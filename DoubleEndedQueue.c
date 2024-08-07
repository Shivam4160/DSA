#include <stdio.h>
#include <stdlib.h>
int Size, F = -1, R = -1, Element;

void EnQueue_Front(int Queue[])
{
    if ((F == 0 && R == Size - 1) || F == R + 1)
    {
        printf("\n\nOverFlow\n\n");
    }
    else if (F == -1 && R == -1)
    {
        F = 0;
        R = 0;
        Queue[F] = Element;
    }
    else if (F == 0)
    {
        F = Size - 1;
        Queue[F] = Element;
    }
    else
    {
        F = F - 1;
        Queue[F] = Element;
    }
}
void EnQueue_Rear(int Queue[])
{
    if ((F == 0 && R == Size - 1) || F == R + 1)
    {
        printf("\n\nOverFlow\n\n");
    }
    else if (F == -1 && R == -1)
    {

        R = 0;
        Queue[R] = Element;
    }
    else if (R == Size - 1)
    {
        R = 0;
        Queue[F] = Element;
    }
    else
    {
        R++;
        Queue[R] = Element;
    }
}

void DeQueue_Front(int Queue[])
{

    if ((F == -1) && (R == -1))
    {
        printf("Queue is empty");
    }
    else if (F == R)
    {
        printf("\nThe deleted element is %d", Queue[F]);
        F = -1;
        R = -1;
    }
    else if (F == (Size - 1))
    {
        printf("\nThe deleted element is %d", Queue[F]);
        F = 0;
    }
    else
    {
        printf("\nThe deleted element is %d", Queue[F]);
        F = F + 1;
    }
}

void DeQueue_Rear(int Queue[])
{
    if ((F == -1) && (R == -1))
    {
        printf("Queue is empty");
    }
    else if (F == R)
    {
        printf("\nThe deleted element is %d", Queue[R]);
        F = -1;
        R = -1;
    }
    else if (R == 0)
    {
        printf("\nThe deleted element is %d", Queue[R]);
        R = Size - 1;
    }
    else
    {
        printf("\nThe deleted element is %d", Queue[R]);
        R = R - 1;
    }
}

void Display(int Queue[])
{

    int i = F;
    printf("\nElements in a deque\n\n\n");

    while (i != R)
    {
        printf("%d  ", Queue[i]);
        i = (i + 1) % Size;
    }
    printf("%d ", Queue[R]);
}
int main()
{
    printf("Enter the size of Queue");
    scanf("%d", &Size);
    int Queue[Size], choice;

    while (1)
    {

        printf("\n1.EnQueue_Front");
        printf("\n2.EnQueue_Rear");
        printf("\n3.DeQueue_Front");
        printf("\n4.DeQueue_Rear");
        printf("\n5.Display");
        printf("\n6.Exit");

        printf("\nEnter your choice:");
        scanf("%d", &choice);

        if (choice > 6)
        {
            printf("\n\nInvalid choice!! Re-enter it.\n\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter the element:");
            scanf("%d", &Element);

            EnQueue_Front(Queue);
            break;
        case 2:
            printf("Enter the element:");
            scanf("%d", &Element);
            
            EnQueue_Rear(Queue);
            break;
        case 3:
            DeQueue_Front(Queue);
            break;
        case 4:
            DeQueue_Rear(Queue);
            break;
        case 5:
            Display(Queue);
            break;
        case 6:
            goto Exit;
        }
    }
Exit:
    return 0;
}
