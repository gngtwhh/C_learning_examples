//力扣3
#include <stdio.h>
#include <string.h>
char str[] = "pwwkew";
int lengthOfLongestSubstring(char* s) {//此代码优先遍历右指针
    int left = 0, right = 0, max = 0;
    int i = 0, j = 0;
    int len = strlen(s);
    int havesamechar = 0;
    for (i = 0; i < len; i++) {
        havesamechar = 0;
        if (left <= right) {
            for (j = left; j < right; j++) {
                if (s[j] == s[right]) {
                    havesamechar = 1;
                    break;
                }
            }
            if (havesamechar) {
                left = j + 1;
            }
            max = max < (right - left + 1) ? (right - left + 1) : max;
            right++;
        }
    }

    return max;
}
/*
int lengthOfLongestSubstring(char* s) {//自己的代码(效率低)
    int len = strlen(s), left = 0, right = 0;
    int tempNum, ans = 0, flag = 0;
    while (left < len) {
        tempNum = 1;
        while (right++ < len) {
            for (int idx = left; idx < right; ++idx)
                if (s[idx] == s[right]||s[right]=='\0') {
                    flag = 1;
                    break;
                }
            if (flag) {
                flag = 0;
                break;
            }
            tempNum++;
        }
        if (ans < tempNum)
            ans = tempNum;
        left++;
        right = left;
    }
    return ans;
}
 */
/*
还有一种思路:优先遍历左指针(?)---官方题解
(无c代码)
 */
int main() {
    printf("%d", lengthOfLongestSubstring(str));
    return 0;
}