//A C program to implement MERGE SORT ALGORITHM 

#include<stdio.h>
//using namespace std;
void merge_sort(int arr[], int, int);
void merge(int arr[], int, int, int);
int main()
{
    int n, i;
    printf("Enter the nmbr of elem ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements ");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
    merge_sort(arr,0,n-1);
    printf("The sorted array is ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
}
void merge_sort(int arr[], int beg, int end)
{
    int mid;
    if(beg < end)
    {
        mid=(beg+end)/2;
        merge_sort(arr,beg,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,beg,mid,end);
    }
}
void merge(int arr[], int beg, int mid,int end)
{
    int i, j, k = beg, x, temp[20];
    //int mid = (beg+end)/2;
    i = beg;
    j = mid+1;

    while((i <= mid) && (j <= end))
    {
        if(arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else //if(arr[j] < arr[i])
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid)
    {
        while(j <= end)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    else if( j > end)
    {
        while(i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    for(i = beg; i < k; i++)
    {
        arr[i] = temp[i];
    }
}
