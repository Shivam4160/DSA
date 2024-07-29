#include<stdio.h>


void change(int arr[],int size)
{
    int a=1,c;
        c=arr[0];
    for (int k = 0; k < size; k++)
    {
        arr[k]=arr[k+1];

    }
    arr[size-1]=c;
     for (int i = 0; i <size; i++)
    {

        printf("Value of %d elment of array is:%d\n",a++,arr[i]);
        
    
    }
   
}

int main()
{

    int n,size;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
  


    size=sizeof(arr)/sizeof(arr[0]);
 


    for (int i = 0; i < n; i++)
    {

        printf("Enter the value of %d elment of array:",i);
        scanf("%d",&arr[i]);
    
    }

    change(arr ,size);

    

    return 0;

}