///Recursive Binary Search
#include<stdio.h>
int RecursiveBinarySearch(int arr[],int data,int low,int size)
{
    int mid;
    int high=size;
    while(low<=high)
    {    mid=(low+high)/2;
        if(arr[mid]==data)
        {
            return mid;
        }
        else if(arr[mid]<data)
        {
           return RecursiveBinarySearch(arr,data,mid+1,size);
        }
        else{
            return RecursiveBinarySearch(arr,data,low,mid-1);
        }
    }
    return -1;
}
int main()
{ int size,data,low=0,arr[100];
    printf("Enter the size of array: ");
    scanf("%d",&size);
    printf("Enter the elements of array of the entered size in sorterd (ascending) order:");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be search: ");
    scanf("%d",&data);
    int result=RecursiveBinarySearch(arr,data,low,size);
    if(result==-1)
    {
        printf("Element not found!");
    }
    else{
    printf("The element %d found at index %d.",data,result);
    }
    return 0;
}
///Time complexity for Binary Search:
///Best Case: O(1)
///Worst case: O(log n)
///Average case: O(log n)
