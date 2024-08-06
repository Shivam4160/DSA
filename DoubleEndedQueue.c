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

        if (choice > 4)
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
            EnQueue_Rear(Queue);
            break;
        case 3:
            DeQueue_Front();
            break;
        case 4:
            DeQueue_Rear();
            break;
        case 5:
            Display();
            break;
        case 6:
            goto Exit;
        }
    }
Exit:
    return 0;
}