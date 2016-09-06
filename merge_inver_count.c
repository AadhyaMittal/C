//To find the INVERSION COUNT of a Merge Sort Algorithm

#include<stdio.h>
//using namespace std;
int merge_sort(int arr[], int, int);
int merge(int arr[], int, int, int);
int main()
{
    int n, i;
    int result_inv;
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
    result_inv = merge_sort(arr,0,n-1);
    printf("The sorted array is ");
    for(i = 0; i < n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n the inversion count is %d",result_inv);
}
int merge_sort(int arr[], int beg, int end)
{
    int mid;
    int inv = 0;
    if(beg < end)
    {
        mid=(beg+end)/2;
        inv = inv + merge_sort(arr,beg,mid);
        inv = inv + merge_sort(arr,mid+1,end);
        inv = inv + merge(arr,beg,mid,end);
    }
    return inv;
}
int merge(int arr[], int beg, int mid,int end)
{
    int i, j, k = beg, x, temp[20];
    int inv = 0;
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
            inv = inv + (mid-i+1);
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
    return inv;
}
