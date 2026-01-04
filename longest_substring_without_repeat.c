/*Given a string s, find the length of the longest substring without duplicate characters.*/

/*Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

#include <string.h>

int lengthOfLongestSubstring(char *s)
{
    int mai[256];
    for (int i = 0; i < 256; i++)
    {
        mai[i] = -1;
    }
    int lenght = 0;
    int left = 0;
    for (int right = 0; s[right] != '\0'; right++)
    {
        unsigned char currentChar = s[right];
        if (mai[currentChar] >= left)
        {
            left = mai[currentChar] + 1;
        }
        mai[currentChar] = right;
        int currentLength = right - left + 1;
        if (currentLength > lenght)
        {
            lenght = currentLength;
        }
    }
    return lenght;
}