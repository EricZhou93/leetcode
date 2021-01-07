/*******************************************************************************
 * Problem: 75. Sort Colors
 * https://leetcode.com/problems/sort-colors/
 * 问题：75. 颜色分类
 * https://leetcode-cn.com/problems/sort-colors/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-06
 * 
 * Summary:
 * We use 3 pointers to partition the array into 4 parts, which are sorted 0s, 
 * sorted 1s, unsorted numbers and sorted 2s.
 * Pointer i points to the next slot of the right-most sorted 0. 
 * Pointer j points to the next slot of the right-most sorted 1. 
 * Pointer k points to the previous slot of the left-most sorted 2. 
 * 
 * If no more than 1 number, no need to sort.
 * If there are more than 1 number:
 *  Case 1: j points to 0.
 *      Swap numbers pointed by i and j.
 *      Right shift i and j for 1 slot.
 *      It is equivalent to move the 0 to the left of i and right shift all the 
 *      sorted 1s by 1 slot.
 *  Case 2: j points to 1.
 *      Right shift j for 1 slot.
 *      It is equivalent to move the 1 to the left of j.
 *  Case 3: j points to 2.
 *      Swap numbers pointed by j and k.
 *      Left shift k.
 *      It is equivalent to move the 2 to the right of k.
 * 
 * 思路：
 * 用3个指针将数组分成4段，从左到右分别为：排序好的0、排序好的1、未排序的数字和排序好的
 * 2。
 * 指针i指向最右侧排序好的0。
 * 指针j指向最右侧排序好的1。
 * 指针k指向最左侧排序好的2。
 * 指针j和k之间的部分就是未排序的数字。
 * 
 * 若不超过一个数字，则无需排序。
 * 若有多个数字，i和j初始化指向第一个数字，k初始化指向最后一个数字。
 * 当j尚未到k右侧：
 *  情况1：j指向0。
 *      交换i和j指向的数字，并且i和j都右移一位。
 *      这样相当于将这个0移动到i左侧，i和j之间排序好的1整体右移一位。
 *  情况2：j指向1。
 *      j右移一位。
 *      这样相当于将这个1移动到j左侧。
 *  情况3：j指向2。
 *      交换j和k指向的数字，并且k左移一位。
 *      这样相当于将这个2移动到j右侧。
 ******************************************************************************/

class Solution
{
public:
    void sortColors(vector<int>& nums)
    {
        int i = 0; // Next slot of the right-most sorted 0. 
                   // 最右侧排序好的0的后一位。
        int j = 0; // Next slot of the right-most sorted 1. 
                   // 最右侧排序好的1的后一位。
        int k = nums.size() - 1; // Previous slot of the left-most sorted 2. 
                                 // 最左侧排序号的2的前一位。
        
        // If there is no more than 1 number, no need to sort.
        // 若不超过一个数字，则不用排序。
        if (k <= 0)
        {
            return;
        }

        // Sort.
        // 排序。
        while (j <= k)
        {
            if (nums[j] == 1)
            {
                j++;
            }
            else if (nums[j] == 0)
            {
                swap(nums[i], nums[j]);
                i++;
                j++;
            }
            else // (nums[j] == 2)
            {
                swap(nums[j], nums[k]);
                k--;
            }
        }
    }

private:
    // Swap 2 variables.
    // 交换两个变量值。
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
