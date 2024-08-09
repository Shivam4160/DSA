#include <stdio.h>
#include <stdlib.h>
int Size;

void EnQueue(int Queue[], int Size, int UB, int LB)
{
    int i;
    printf("Enter the element to be inserted: ");
    scanf("%d", &i);
    if (UB == Size - 1)
    {

        printf("\nQueue is full\n");
    }
    else if (UB == -1 && LB == -1)
    {
        LB = 0;
        UB = 0;
        Queue[UB] = i;
        printf("\nElement inserted successfully\n");
    }

    else
    {
        UB++;
        Queue[UB] = i;
        printf("\nElement %d added successfully.\n", i);
    }
}

void DeQueue(int Queue[], int Size, int UB, int LB)
{
    if (LB == -1 && UB == -1)
    {
        printf("\nQueue is empty\n");
    }
    else if (LB == UB)
    {
        printf("\nElement %d deleted.\n", Queue[UB]);
        LB = -1;
        UB = -1;
    }
    else
    {
        printf("\nElement %d deleted.\n", Queue[LB]);
        LB++;
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
        MargeSort(Queue, LB, UB);
        MargeSort(Queue, LB, UB);
        Marge(Queue, LB, Mid, UB);
    }
}
void Display(int Queue[], int LB, int UB)
{
    for (int i = LB; i <= UB; i++)
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
        printf("\n5.Exit");

        printf("Enter your choice:");
        scanf("%d", &chioce);

        switch (chioce)
        {
        case 1:
            EnQueue(Queue, Size, UB, LB);

            break;
        case 2:
            DeQueue(Queue, Size, UB, LB);

            break;
        case 3:
            MargeSort(Queue, LB, UB);

            break;
        case 4:
            Display(Queue, LB, UB);

            break;
        case 5:
            goto Exit;
        }
    }
Exit:
    return 0;
}