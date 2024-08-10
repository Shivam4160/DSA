#include <stdio.h>
#include <stdlib.h>
int R = -1; // rear
int F = -1; // front
int Size;

void EnQueue(int Queue[])
{
    int i;
    printf("Enter the element to be inserted: ");
    scanf("%d", &i);
    if (R == Size - 1)
    {
        printf("\nQueue is full.\n");
    }
    else if (R == -1 && F == -1)
    {
        R++;
        F++;
        Queue[R] = i;
    }
    else
    {
        R++;
        Queue[R] = i;
        printf("\nElement %d is added.\n", i);
    }
}

void DeQueue(int Queue[])
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
void Marge(int Queue[], int LB, int Mid, int UB)
{
    int i = LB;
    int j = Mid + 1;
    int k = LB;
    int arr1[Size];

    while (i <= Mid && j <= UB)
    {
        if (Queue[i] <= Queue[j])
        {
            arr1[k] = Queue[i];
            i++;
        }
        else
        {
            arr1[k] = Queue[j];
            j++;
        }
        k++;
    }
    if (i > Mid)
    {
        while (j <= UB)
        {
            arr1[k] = Queue[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= Mid)
        {
            arr1[k] = Queue[i];
            i++;
            k++;
        }
    }
    for (k = 0; k <= UB; k++)
    {
        Queue[k] = arr1[k];
    }
}

void MargeSort(int Queue[], int LB, int UB)
{
    if (LB < UB)
    {
        int Mid = (LB + UB) / 2;
        MargeSort(Queue, LB, Mid);
        MargeSort(Queue, LB, UB);
        Marge(Queue, LB, Mid, UB);
    }
}
void Display(int Queue[])
{
    for (int i = F; i <= R; i++)
    {
        printf("%d  ", Queue[i]);
    }
}

int main()
{
    int LB, UB, Mid;
    int Queue[Size], chioce;

    printf("Enter the size of Queue:");
    scanf("%d", &Size);

    while (1)
    {
        printf("\n1.EnQueue");
        printf("\n2.DeQueue");
        printf("\n3.MargeSort");
        printf("\n4.Display");
        printf("\n5.Exit\n");

        printf("Enter your choice:");
        scanf("%d", &chioce);

        switch (chioce)
        {
        case 1:
            EnQueue(Queue);

            break;
        case 2:
            DeQueue(Queue);

            break;
        case 3:
            MargeSort(Queue, 0, Size - 1);

            break;
        case 4:
            Display(Queue);

            break;
        case 5:
            goto Exit;
        }
    }
Exit:
    return 0;
}