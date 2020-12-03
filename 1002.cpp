//1002 Business (35分)
//DATE:20201203
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
int cmpfunc(const void *a, const void *b)
{
    int *pa = (int *)a, *pb = (int *)b;
    if (pa[2] == pb[2])
        return (pa[1] - pb[1]);
    else
        return (pa[2] - pb[2]);
}
int main()
{
    int i, j, tmp, N, A[MAXSIZE][3];
    int *value, MaxDay = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    qsort(A, N, sizeof(A[0]), cmpfunc);
    MaxDay = A[N - 1][2];
    value = (int *)malloc((MaxDay + 1) * sizeof(int));
    for (i = 0; i <= MaxDay; i++)
        value[i] = 0;
    for (i = 0; i < N; i++)
        for (j = A[i][2]; j >= A[i][1]; j--)
        {
            tmp = A[i][0] + value[j - A[i][1]];
            if (tmp > value[j])
                value[j] = tmp;
        }
    j = 0;
    for (i = 1; i <= MaxDay; i++)
    {
        if (value[i] > j)
            j = value[i];
    }
    printf("%d\n", j);
    free(value);
    return 0;
}