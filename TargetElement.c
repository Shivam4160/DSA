#include <stdio.h>
#include <math.h>

void Sum1(int arr[], int size, int target, int Index, int Sum, int Combination[], int Length)
{
    if (Sum == target)
    {
        printf("Elements at positions: ");
        for (int i = 0; i < Length; i++)
        {
            printf("%d ", Combination[i]);
        }
        printf("the sum %d\n", target);

        return;
    }

    if (Sum > target || Index == size)
    {
        return;
    }
    Combination[Length] = Index;
    Sum1(arr, size, target, Index + 1, Sum + arr[Index], Combination, Length + 1);

    Sum1(arr, size, target, Index + 1, Sum, Combination, Length);
}

int main()
{
    int size;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target: ");
    scanf("%d", &target);

    int Combination[size];
    int found = 0;

    Sum1(arr, size, target, 0, 0, Combination, 0);

    if (!found)
    {
        printf("No combination found that sums up to %d\n", target);
    }

    return 0;
}