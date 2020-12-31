/*******************************************************************************
 * Problem: 518. Coin Change 2
 * https://leetcode.com/problems/coin-change-2/
 * 问题：518. 零钱兑换 II
 * https://leetcode-cn.com/problems/coin-change-2/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-30
 * 
 * Summary:
 * Solve by dynamic programming.
 * Let dp[n] be the number of coin combinations for amount n.
 * Base case: 
 *  Amount 0 has only one combination, i.e. no coin. dp[0] = 1.
 * Recursive case: 
 *  Assume m is the largest denomination in coin combination. 
 *  Then the number of combinations using coins no larger than m is dp[n - m].
 *  Sum up dp[n - m] for all possible m's. We can get dp[n].
 * 用动态规划处理。
 * 假设总金额n有dp[n]中组合。
 * 基本情况：
 *  总金额为0时，只有一种组合，即没有硬币。dp[0] = 1
 * 递归情况：
 *  假设组合中硬币的最大面额是m。
 *  那么，面额不大于m的硬币组合总数为dp[n - m]。
 *  对所有可能的m的情况进行加和，就能得到dp[n]。
 ******************************************************************************/

class Solution
{
public:
    int change(int amount, vector<int>& coins)
    {
        // combinations[n] is number of coin combinations for amount n.
        // combinations[n]是总金额为n的硬币组合总数。
        vector<int> combinations(amount + 1, 0);
        
        // Base Case: Amount 0 has only one combination, i.e. no coin.
        // 基本情况：总金额为0时，只有一种组合，即没有硬币。
        combinations[0] = 1;

        // Solve it bottom-up.
        // 自底向上处理。
        int coin_type_num = coins.size();
        // coins[coin] is the largest denomination in the combination.
        // 面额为coins[coin]的硬币是组合中面额最大的硬币。
        for (int coin = 0; coin < coin_type_num; coin++)
        {
            for (int n = 0; n <= amount; n++)
            {
                if (n >= coins[coin])
                {
                    // Use one coin of coins[coin].
                    combinations[n] += combinations[n - coins[coin]];
                }
            }
        }
        
        return combinations[amount];
    }
};
