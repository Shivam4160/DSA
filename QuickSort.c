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
int Partition(int Queue[], int LB, int UB)
{
    int pivot = Queue[LB];
    int Start = LB;
    int End = UB;
    int temp;

    while (Start < End)
    {
        while (Queue[Start] <= pivot)
        {
            Start++;
        }
        while (Queue[End] > pivot)
        {
            End--;
        }
        if (Start < End)
        {
            temp = Queue[Start];
            Queue[Start] = Queue[End];
            Queue[End] = temp;
        }
    }
    temp = Queue[LB];
    Queue[LB] = Queue[End];
    Queue[End] = temp;

    return End;
}

void QuickSort(int Queue[], int LB, int UB)
{
    if (LB < UB)
    {
        int loc = Partition(Queue, LB, UB);
        QuickSort(Queue, LB, loc - 1);
        QuickSort(Queue, loc + 1, UB);
    }
}
void Display(int Queue[])
{
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
            QuickSort(Queue, 0, Size - 1);
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