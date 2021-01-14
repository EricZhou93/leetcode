/*******************************************************************************
 * Problem: 剑指 Offer 05. 替换空格
 * https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
 * 
 * Authors: Keren Zhou
 * 
 * Date: 2020-12-26
 * 
 * Summary:
 * In-place modification method:
 * 1. Traverse the original string and count ' 's.
 * 2. Since each ' ' will be replaced with "%20", we need 2 more slots for each 
 *    ' '.
 * 3. Traverse the original string in reverse order and write corresponding 
 *    characters to the extended string. ' 's will be replaced with "%20" and 
 *    other characters will be directly copied.
 *    If all ' 's have been replaced, the stop. Only if there is ' ' left, the 
 *    positions of unprocessed characters may be changed. Otherwise, the 
 *    unprocessed characters stay at the same place; we don't have to copy them 
 *    in place.
 * 
 * 原位修改法：
 * 1. 遍历一遍字符串，统计空格的数量。
 * 2. 由于每个' '需要被替换成"%20"，对于k个' '，字符串需要扩展2k个位置。
 * 3. 倒序遍历原字符串，并将对应内容写入扩展后的字符串。非' '内容直接拷贝，而' '用
 *    "%20"替换。
 *    若所有' '都已经被替换，则结束。因为只有当剩余的原字符串中还有' '需要被替换时，剩
 *    余的原字符串的字符的位置才会有改动。否则，剩余字符将保持原位，因而无需继续处理。
 ******************************************************************************/

class Solution {
public:
    string replaceSpace(string s)
    {
        // Count white-space.
        // 统计空格数。
        int len = s.size();
        int count = 0; // Number of white space. 空格数。
        for (int i = 0; i < len; i++)
        {
            if (s[i] == ' ')
            {
                count++;
            }
        }

        // Since each ' ' will be replaced with "%20", we need 2 more slots for 
        // each ' '.
        // 每个' '需要被"%20"替换，因此对于每个空格需要增加2个字符的位置。
        s.resize(len + 2 * count);

        // Traverse the original string in reverse order and write 
        // corresponding characters to the extended string.
        // 倒序遍历原字符串内容，并将对应内容写入扩展后的字符串。
        int i = len - 1; // The last slot of the original string. 
                         // 原字符串的最后一位。
        int j = i + 2 * count; // The last slot of the extended string. 
                               // 扩展后字符串的最后一位。
        // If there is ' ' left, then continue replacing; if not, then stop.
        // 若还有' '未被替换，则继续倒序拷贝。若所有' '已被替换，则结束。
        while(count > 0)
        {
            // Replace ' ' with "%20".
            // 将' '替换为"%20"。
            if (s[i] == ' ')
            {
                s[j] = '0';
                j--;
                s[j] = '2';
                j--;
                s[j] = '%';
                count--;
            }
            // Copy non-space contents.
            // 拷贝非' '内容。
            else
            {
                s[j] = s[i];
            }
            j--;
            i--;
        }
        return s;
    }
};
