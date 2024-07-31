#include <stdio.h>
#include <stdlib.h>
int size;




void pop()
{

    if (size >0)
    {
        size--;
    }
   
}

void display(int arr[])
{

   
    if(size >0 )
    {
        printf("array elements are.\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d \t", arr[i]);
        }
        printf("\n");
    }
}
void Search(int arr[], int element)
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
        printf("Elemwnt %d is not in array.\n", element);
    }
}

int main()
{

    int  element, choice;
    printf("Enter the size of array:");
    scanf("%d", &size);

    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100+1;
    }

    while (1)
    {
        printf("1.pop\n");
        printf("2.display\n");
        printf("3.Search Element\n");
        printf("4.exit\n");
        printf("Enter your choice.");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            pop();
            break;

        case 2:
            display(arr);
            break;

        case 3:

            printf("Enter the Element you want to search:");
            scanf("%d", &element);

            Search(arr, element);
            break;
        case 4:
            printf("visit again.\n");
            goto exit;
        }
    }
exit:

    return 0;
}