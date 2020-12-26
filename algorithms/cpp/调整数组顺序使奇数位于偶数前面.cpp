/*******************************************************************************
 * Problem: https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * 问题：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-26
 * 
 * Summary:
 * 参考快速排序算法的思想，利用两个左右两个指针寻找最左侧的偶数和最右侧的奇数并交换。
 * 左指针从左向右找最左侧的偶数，直到触及右指针。
 * 右指针从右向左找最右侧的奇数，直到触及左指针。
 * 若最左侧偶数在最右侧奇数的左侧，则交换，并继续上述步骤。
 * 若左指针已触及右指针，则结束。
 ******************************************************************************/

class Solution {
public:
    vector<int> exchange(vector<int>& nums)
    {
        int left = 0; // Index of the left-most even number.
                      // 最左侧奇数的下标。
        int right = nums.size() - 1; // Index of the right-most odd number.
                                     // 最右侧奇数的下标。
        int tmp; // Temp variable for swapping.
                 // 用于交换的临时变量。

        while(left < right)
        {
            // Find the left-most even number from left to right, until it 
            // reaches the right pointer.
            // 从左向右找最左侧偶数，直至触及右指针。
            while(left < right && nums[left] % 2 == 1)
            {
                left++;
            }

            // Find the right-most odd number from right to left, until it 
            // reaches the left pointer.
            // 从右向左找最右侧奇数，直至触及左指针。
            while(left < right && nums[right] % 2 == 0)
            {
                right--;
            }

            // If the left-most even number is on the left side of the 
            // right-most odd number, swap them.
            // If the left pointer has reached the right pointer, do nothing.
            // 如果最左侧偶数在最右侧奇数的左边，则交换。
            // 如果左指针已经触及右指针，则不操作。
            if (left < right)
            {
                tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }

        return nums;
    }
};
