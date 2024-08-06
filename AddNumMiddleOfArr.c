#include <stdio.h>
#include <stdlib.h>
int main()
{
    int size;
    printf("Enter the size of array.");
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    int element, pos, i;

    printf("Enter position \n");
    scanf("%d", &pos);
    printf("Enter element\n");
    scanf("%d", &element);

    if (pos <= size && pos >= 0)
    {
        // shift all the elements from the last index to pos by 1 position to right
        for (i = size; i > pos; i--)
            arr[i] = arr[i - 1];

        // insert element at the given position
        arr[pos] = element;

        /*
         * print the new array
         * the new array size will be size+1(actual size+new element)
         * so, use i <= size in for loop
         */
        for (i = 0; i <= size; i++)
            printf("%d ", arr[i]);
    }
    else
        printf("Invalid Position\n");

    return 0;
}