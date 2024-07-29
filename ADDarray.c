#include <stdio.h>

void combinearr(int arr[], int arr2[], int b, int a)
{
    printf("aise a%d",a);

    int k;

    for (k = 0; k < b; k++)
    {
        arr[a++] = arr2[k];
    }

    printf("Combined array .\n");

    for (int j = 0; j < a; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}

int main()
{
    int a, b, c, i, j;
    printf("Enter the size of first array:");
    scanf("%d", &a);

    printf("Enter the size of second array:");
    scanf("%d", &b);

    int arr[50], arr2[50];

    for (i = 0; i < a; i++)
    {

        printf("Enter the element at %d psition of first array:", i);
        scanf("%d", &arr[i]);
    }

    printf("***************************************************************************************************************\n");

    for (j = 0; j < b; j++)
    {

        printf("Enter the element at %d psition of second array:", j);
        scanf("%d", &arr2[j]);
    }

    combinearr(arr, arr2, b, a);

    return 0;
}