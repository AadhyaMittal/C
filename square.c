//To find the squares of numbers from n to m

#include<stdio.h>
print_square(int n, int m)
{
    int i, sq;
    sq = n*n;
    for(i = 0; i < m; i++)
    {
        printf("%d ",sq);
        sq = sq + ((n<<1) + 1);
        n++;
    }
}
int main()
{
    int n, m;
    scanf("%d",&n);
    scanf("%d",&m);
    print_square(n,m);
}
