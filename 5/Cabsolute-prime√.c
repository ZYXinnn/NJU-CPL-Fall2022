#include <stdio.h>
#include <math.h>
int judge(int x)
{
    int flag = 1;
    for (int i = 2; i <= sqrt(x + 0.5); i++)
        if (x % i == 0)
        {
            flag = 0;
        }
    return flag;
}
int n, num = 0;
int main()
{
    scanf("%d", &n);
    if (n > 1000)
        n = 1000;
    for (int i = 2; i <= n; i++)
    {
        int t = i;
        int j = 0;
        while (t)
        {
            j *= 10;
            j += t % 10;
            t /= 10;
        }
        if (judge(i) == 1 && judge(j) == 1)
            num++;
    }
    printf("%d", num);
    return 0;
}