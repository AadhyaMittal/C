#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
/*
 * Complete the function below.
 */
char* encode(char* input)
{
    int len, x, y, z, i, m, n, nzero, num = 0, j = 0, rem , sum;
    char* s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/0123456789";
    char* result;
    result = (char *)malloc(20480 * sizeof(char));
    len = strlen(input);
    m = len%3;
    if(m != 0)
    {
        nzero = 3 - m;
        for(i = 0; i < nzero; i++)
        {
            input[len] = '0';
            len++;
        }
    }
    x = 8;
    n = len*8;
    int l = n/6;
    int arr[n];
    for(i = 0; input[i] != '\0'; i++)
    {
        num = input[i];
        y = x;
        z = y-8;
        while(y > z)
        {
            rem = num%2;
            num = num/2;
            arr[y] = rem;
            y--;
        }
        x = x+8;
    }
    x = 6;
    while((x <= n) && (j < l))
    {
        y = x;
        z = y - 6;
        sum = 0;
        i = 0;
        while(y > z)
        {
            sum = sum + ((arr[y]) * pow(2,i));
            i++;
            y--;
        }
        x = x + 6;
        result[j] = s[sum];
        j++;
    }

    if(m == 2)
    {
        result[l-1] = '=';
    }
    else if(m == 1)
    {
        result[l-1] = '=';
        result[l-2] = '=';
    }
    return result;
}
int main() {
    //FILE *f = fopen(getenv("OUTPUT_PATH"), "w");
    char* res;
    char* _input;
    _input = (char *)malloc(10240 * sizeof(char));
    scanf("\n%[^\n]",_input);
    res = encode(_input);
    printf("%s\n", res);

    //fclose(f);
    return 0;
}
