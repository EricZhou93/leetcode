/*******************************************************************************
 * Problem: 168. Excel Sheet Column Title
 * https://leetcode.com/problems/excel-sheet-column-title/
 * 问题：168. Excel表列名称
 * https://leetcode-cn.com/problems/excel-sheet-column-title/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-02
 * 
 * Summary:
 * This problem is similar to convert base from 10 to 26.
 * 
 * Recursive solution:
 * Base case: n = 0
 *  Return empty string "".
 * Recursive case: n > 0
 *  Let n = 26a + b.
 *  1. Convert b to a letter and use it as the last letter in the result. 
 *     Letter for b is ('A' + (n - 1) % 26).
 *     If we use ('A' + n % 26 - 1), b=26 will be converted to 'A' - 1 by 
 *     mistake, rather than 'Z'.
 *  2. Recursively convert a to string and use it as result except the last 
 *     letter.
 *     Let a = (n - 1) / 26, then recursively solve a.
 *     If a = n / 26, when n = 26, a will be 1 by mistake, rather than a = 0.
 *     To prevent the carry caused by b = 26 (the last letter is 'Z'), we first 
 *     decrease n by 1, then divide it by 26.
 *  3. Concatenate string of a and letter of b as the result.
 * 
 * 该问题可以近似看做10进制转26进制的问题。
 * 
 * 递归解法：
 * 基本情况：n=0
 *  返回空字符串""。
 * 递归情况：n>0
 *  令n = 26a + b。
 *  1. 将b直接转化为最后一个字母。
 *     b对应的字母为('A' + (n - 1) % 26)。
 *     若使用('A' + n % 26 - 1)，b=26时就无法转化为'Z。
 *  2. 递归处理a，将其对应的字符串作为最后一个字母之前的字符串。
 *     a = (n - 1) / 26，然后递归处理a.
 *     若a = n / 26，当n=26时，a=1而不是期望的a=0。为防止b=26，即最后一个字母为'Z'，
 *     导致的进位，先对n减1，在整除26.
 *  3. 合并a对应的字符串和b对应的字母作为结果。
 ******************************************************************************/

class Solution
{
public:
    string convertToTitle(int n)
    {
        string str;
        
        // Base case:
        if (n == 0)
        {
            return "";
        }

        // Recursive case:
        str = convertToTitle((n - 1) / 26) + string(1, 'A' + (n - 1) % 26);

        return str;
    }
};
