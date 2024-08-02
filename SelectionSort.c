#include <stdio.h>
#include <stdlib.h>

void Display(int arr[], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
}

void LinearSearch(int arr[], int size, int element)
{

    int j;
    for (j = 0; j < size; j++)
    {
        if (element == arr[j])
        {
            printf("Element %d is fount at position at %d\n", element, j);
            break;
        }
    }
    if (j == size)
    {
        printf("Element %d is not present in array.\n", element);
    }
}

void BinarySearch(int arr[], int size, int element)
{

    int low=0, mid, high = size - 1;

    while (low<high)
    {
        mid=(low+high)/2;
        if (arr[mid]==element)
        {
            
            printf("Element %d found at position %d\n", element, mid);
            break;
        }
        else if (arr[mid]<element)
        {
            low=mid+1;
        }
        else if (arr[mid]>element)
        {
            high=mid-1;
        }
        


    }
    if (element!=arr[mid])
    {
        printf("Element %d is not present in array.\n",element);
    }
    

}

void SelectionSort(int arr[], int size)
{

    int temp, i;

    for (i = 0; i < size - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[small])
            {
                small = j;
            }
        }
        if (small != i)
        {
            temp = arr[i];
            arr[i] = arr[small];
            arr[small] = temp;
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n********************************************************\n");
}

int main()
{
    int size, choice, element;
    printf("\nEnter the size of array:");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 1000;
    }
    while (1)
    {

        printf("\n1.Display");
        printf("\n2.Linear Search");
        printf("\n3.Binary Search");
        printf("\n4.Selection Sort");
        printf("\n5.Exit");

        printf("\nEnter your choice:");
        scanf("%d", &choice);
        if (choice > 5)
        {
            printf("\n******************************************************\n");
            printf("Choice is unvalid!! Please re-enter it:");
            continue;
        }

        switch (choice)
        {
        case 1:
            Display(arr, size);
            break;
        case 2:
            printf("Enter the element you want search:");
            scanf("%d", &element);
            LinearSearch(arr, size, element);
            break;
        case 3:
            SelectionSort(arr, size);
            printf("Enter the element you want search:");
            scanf("%d", &element);
            BinarySearch(arr, size, element);
            break;
        case 4:
            SelectionSort(arr, size);
            break;
        case 5:
            goto Exit;
        }
    }

Exit:

    return 0;
}