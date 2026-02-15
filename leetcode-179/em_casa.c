#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *x, const void *y)
{
    char xy[21];
    char yx[21];

    sprintf(xy, "%d%d", *(int *)x, *(int *)y);
    sprintf(yx, "%d%d", *(int *)y, *(int *)x);

    return strcmp(yx, xy);
}

char *largestNumber(int *nums, int numsSize)
{
    char *result;
    char *ptr;
    int   i;

    qsort(nums, numsSize, sizeof(int), cmp);

    if (nums[0] == 0)
    {
        result = (char *)malloc(2);
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    result = (char *)malloc(numsSize * 11 + 1);
    ptr = result;

    for (i = 0; i < numsSize; i++)
    {
        ptr += sprintf(ptr, "%d", nums[i]);
    }

    *ptr = '\0';

    return result;
}

int main(void)
{
    int nums[] = {3, 30, 34, 5, 9};
    int size   = sizeof(nums) / sizeof(nums[0]);
    char *res;

    res = largestNumber(nums, size);

    printf("%s\n", res);

    free(res);

    return 0;
}