/*******************************************************************************
 * Problem: 264. Ugly Number II
 * https://leetcode.com/problems/ugly-number-ii/
 * 问题：264. 丑数 II
 * https://leetcode-cn.com/problems/ugly-number-ii/
 * 剑指 Offer 49. 丑数
 * https://leetcode-cn.com/problems/chou-shu-lcof/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-27
 * 
 * Summary:
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
 * 1 is the smallest ugly number.
 * Let x_1, x_2, ..., x_n be the first n ugly numbers, where x_i < x_(i+1).
 * Then x_(n+1) = x_a * 2, x_b * 3, or x_c * 5, where 1 <= a, b, c <= n.
 * And a, b and c are the smallest numbers s.t. x_a * 2 > x_n, x_b * 3  > x_n, 
 * and x_c * 5 > x_n.
 * To find x_(n+1), we first find the smallest a, b and c s.t. x_a * 2 > x_n, 
 * x_b * 3  > x_n, and x_c * 5 > x_n. Then we take the min among x_a * 2, x_b * 
 * 3, x_c * 5 as x_(n+1).
 * To find x_(n+1), we need to find x_1 through x_n first. We could solve it 
 * using bottom-up dynamic programming.
 * 
 * 丑数是质因数只包含2、3、5的正整数（包括1）。
 * 除了1以外，其他丑数都是由更小的丑数乘上2、3、5得到的。
 * 那么，第(n+1)个丑数是前n个丑数中的某一个乘上2、3或5得到的，并且大于第n个丑数的最小
 * 丑数。
 * 我们先分别找出乘上2、3和5后大于第n个丑数的最小丑数。
 * 然后取这3个丑数分别乘上2、3和5后的最小值作为第(n+1)个丑数。
 * 为获得第(n+1)个丑数，我们就需要计算前n个丑数。我们可以利用自底向上的动态规划来完成。
 * 
 * Acknowledgement: This solution is inspired by the solution on https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
 * 该解法受了 https://leetcode-cn.com/problems/chou-shu-lcof/solution/mian-shi-ti-49-chou-shu-dong-tai-gui-hua-qing-xi-t/ 的启发。
 ******************************************************************************/

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugly_nums(n);
        ugly_nums[0] = 1; // 1 is the smallest ugly number.
                          // 1是最小的丑数。
        int a = 0; // The smallest a s.t. ugly_nums[a] * 2 > ugly_nums[i].
                   // a是最小的数，使得ugly_nums[a] * 2 > ugly_nums[i].
        int b = 0; // The smallest b s.t. ugly_nums[b] * 3 > ugly_nums[i].
                   // b是最小的数，使得ugly_nums[b] * 3 > ugly_nums[i].
        int c = 0; // The smallest c s.t. ugly_nums[c] * 5 > ugly_nums[i].
                   // c是最小的数，使得ugly_nums[c] * 5 > ugly_nums[i].
        
        // Find the first n ugly numbers.
        // 找出最小的n个丑数。
        for (int i = 0; i < n - 1; i++)
        {
            // Find the smallest a s.t. ugly_nums[a] * 2 > ugly_nums[i].
            // 找到最小的a，使得ugly_nums[a] * 2 > ugly_nums[i].
            while(ugly_nums[a] * 2 <= ugly_nums[i]) a++;

            // Find the smallest b s.t. ugly_nums[b] * 3 > ugly_nums[i].
            // 找到最小的b，使得ugly_nums[b] * 3 > ugly_nums[i].
            while(ugly_nums[b] * 3 <= ugly_nums[i]) b++;

            // Find the smallest c s.t. ugly_nums[c] * 5 > ugly_nums[i].
            // 找到最小的c，使得ugly_nums[c] * 5 > ugly_nums[i].
            while(ugly_nums[c] * 5 <= ugly_nums[i]) c++;

            ugly_nums[i + 1] = min(min(ugly_nums[a] * 2, ugly_nums[b] * 3), 
                                   ugly_nums[c] * 5);
        }

        return ugly_nums[n - 1];
    }
};
