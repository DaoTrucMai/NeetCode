/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies, int *returnSize)
{
    *returnSize = candiesSize;
    bool *results = (bool *)malloc(candiesSize * sizeof(bool));

    int maxCandies = candies[0];
    for (int i = 0; i < candiesSize; i++)
    {
        if (maxCandies < candies[i])
        {
            maxCandies = candies[i];
        }
    }
    for (int i = 0; i < candiesSize; i++)
    {
        results[i] = (maxCandies <= candies[i] + extraCandies);
    }
    return results;
}