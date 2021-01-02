/*******************************************************************************
 * Problem: 611. Valid Triangle Number
 * https://leetcode.com/problems/valid-triangle-number/
 * 问题：611. 有效三角形的个数
 * https://leetcode-cn.com/problems/valid-triangle-number/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-01
 * 
 * Summary:
 * Assume 0 <= a <= b <= c can form a valid triangle, then a + b > c. 
 * Solution:
 * Sort edges in ascending order.
 * For i < j, find the largest k s.t. nums[i] + nums[j] > nums[k]. Then, each 
 * edge of nums[j+1:k+1] can form a valid triangle with nums[i] and nums[j].
 * For each i, if j increases, k cannot decrease. Thus, we could search k from 
 * the k of the last round. Then, j and k move at most twice the length of nums 
 * for each i. Thus, time complexity is O(n^2).
 * 
 * 假设0 < a <= b <= c三条边能构成三角形，则 a + b < c.
 * 解法：
 * 对边升序排序。
 * 对于i < j，找出最大的k，使得nums[i] + nums[j] > nums[k]。那么，nums[j+1:k+1]的每
 * 一条边都能与nums[i]和nums[j]构成三角形。
 * 当i不变，j=j+1时，k不可能减小。因此，可以从上一轮的k开始找最大的k。这样，当i不变
 * 时，j和k最多移动2倍nums的长度。这样就使得时间复杂度为O(n^2)。
 ******************************************************************************/

class Solution
{
public:
    int triangleNumber(vector<int>& nums)
    {
        int count = 0;
        int i, j, k;

        sort(nums.begin(), nums.end());

        // Find the first non-zero edge.
        // 找到第一条非0边。
        int len = nums.size();
        i = 0;
        while (i < len && nums[i] == 0)
        {
            i++;
        }

        // Find the largest k s.t. nums[i] + nums[j] > nums[k].
        // 找出最大的k，使得 nums[i] + nums[j] > nums[k]。
        for (; i < len - 2; i++)
        {
            k = i + 2;
            for (j = i + 1; j < len - 1; j++)
            {
                while (k < len && (nums[i] + nums[j] > nums[k])) k++;
                count += k - 1 - j;
            }
        }

        return count;
    }
};
