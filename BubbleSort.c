#include <stdio.h>
#include <stdlib.h>

void pop(int size)
{

    if (size > 0)
    {
        size--;
    }
}

void display(int arr[], int size)
{

    if (size > 0)
    {
        printf("array elements are.\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d \t", arr[i]);
        }
        printf("\n");
    }
}
void LinearSearch(int arr[], int element, int size)
{

    int j;

    for (j = 0; j < size; j++)
    {
        if (arr[j] == element)
        {
            printf("Element %d is at %d position.\n", element, j);
            break;
        }
    }
    if (j == size)
    {
        printf("Element %d is not in array.\n", element);
    }
}

int BinarySearch(int arr[], int element, int size)
{
    int low, high, mid;
    low = 0;
    high = size - 1;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        else if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else if (arr[mid] > element)
        {
            high = mid - 1;
        }
    }

    return -1;
}


void BubbleSort(int arr[], int size)
{

    int i, j, k,temp;
    for (i = 0; i < size - 1; i++)
    {
        k = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                k = 1;
            }
        }

        if (k == 0)
            break;
    }
}

int main()
{

    int element, choice, size, N;

    printf("Enter the size of array:");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }

    while (1)
    {
        printf("\n1.pop\n");
        printf("2.display\n");
        printf("3.Linear Search Element\n");
        printf("4.Binary Search Element\n");
        printf("5.Sorted array\n");
        printf("6.exit\n");
        printf("Enter your choice.");
        scanf("%d", &choice);

        if (choice > 5)
        {
            printf("Invelid choice.\n");
            printf("*********************************************************************************\n");
            continue;
        }

        switch (choice)
        {

        case 1:
            pop(size);
            break;

        case 2:
            display(arr, size);
            break;

        case 3:

            printf("Enter the Element you want to search:");
            scanf("%d", &element);

            LinearSearch(arr, element, size);
            break;
        case 4:

            BubbleSort(arr, size);

            printf("Enter the Element you want to search:");
            scanf("%d", &element);

            N = BinarySearch(arr, element, size);

            if (N == -1)
            {

                printf("Element %d is not in stack.\n", element);
            }
            else
            {
                printf("Element %d is at %d position.\n", element, N);
            }

            break;

        case 5:

            printf("Sorted array.\n");
            printf("*********************************************************************************\n");
            for (int i = 0; i < size; i++)
            {

                printf("%d   ", arr[i]);
            }

            break;
        case 6:
            printf("visit again.\n");
            goto exit;
        }
    }
exit:

    return 0;
}