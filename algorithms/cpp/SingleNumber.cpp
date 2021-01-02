/*******************************************************************************
 * Problem: 136. Single Number
 * https://leetcode.com/problems/single-number/
 * 问题：136. 只出现一次的数字
 * https://leetcode-cn.com/problems/single-number/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-02
 * 
 * Summary:
 * We could use exclusive or (xor) to solve this problem.
 * 
 * Properties of xor:
 * a ^ a = 0
 * 0 ^ a = a
 * Commutative law: a ^ b = b ^ a
 * Associative law: a ^ b ^ c = a ^ (b ^ c)
 * 
 * Assume m is the only number that appears exact once in the array and other 
 * numbers appear exact twice.
 * Xor all numbers together:
 *  (a ^ a) ^ (b ^ b) ^ ... ^ m ^ ... (z ^ z)
 * = 0 ^ 0 ^ ... ^ m ^ ...^ 0 
 * = m
 * In the end, we get m, the only number that appears exact once.
 * 
 * 
 * 利用异或运算处理。
 * 
 * 异或运算特性：
 * a ^ a = 0
 * 0 ^ a = a
 * 交换律：a ^ b = b ^ a
 * 结合律：a ^ b ^ c = a ^ (b ^ c)
 * 
 * 假设m是数组中唯一一个只出现一次的数字，其他数字都出现2次。
 * 那么将数组中所有数字进行异或计算：
 *   (a ^ a) ^ (b ^ b) ^ ... ^ m ^ ... (z ^ z)
 * = 0 ^ 0 ^ ... ^ m ^ ...^ 0 
 * = m
 * 最终得到只出现一次的数字m。
 ******************************************************************************/

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int result = 0;
        for (auto i = nums.begin(); i != nums.end(); i++)
        {
            result ^= *i;
        }
        return result;
    }
};
