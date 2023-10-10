#include <stdio.h>

int main()
{
    int n, a = 0;
    int arr[100000];
    char arr1[100000];
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        arr[i] = getchar();
    }
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        if (arr[i] == arr[n - i + 1] && arr[i] != 63)
        {
            arr1[i] = (char)arr[i];
            arr1[n - i + 1] = (char)arr[n - i + 1];
        }
        else if (arr[i] != arr[n - i + 1])
        {
            if (arr[i] == 63)
            {
                arr[i] = arr[n - i + 1];
                arr1[i] = (char)arr[i];
                arr1[n - i + 1] = (char)arr[n - i + 1];
            }
            else if (arr[n - i + 1] == 63)
            {
                arr[n - i + 1] = arr[i];
                arr1[i] = (char)arr[i];
                arr1[n - i + 1] = (char)arr[n - i + 1];
            }
        }
        else if (arr[i] == arr[n - i + 1] && arr[i] == 63)
        {
            arr[i] = a;
            arr[n - i + 1] = a / 10 + 10 * (a % 10);
            a++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr1[i] != 0)
            putchar(arr1[i]);
        else
            printf("%.2d", arr[i]);
    }
    return 0;
}