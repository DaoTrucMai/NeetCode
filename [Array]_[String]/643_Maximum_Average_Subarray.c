double findMaxAverage(int *nums, int numsSize, int k)
{
    int sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += nums[i];
    }

    int max = sum;
    for (int i = k; i < numsSize; i++)
    {
        sum = sum - nums[i - k] + nums[i];
        if (sum > max)
            max = sum;
    }
    return (double)max / k;
}