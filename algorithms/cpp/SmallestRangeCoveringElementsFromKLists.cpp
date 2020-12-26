
/*******************************************************************************
 * Problem: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
 * 问题：https://leetcode-cn.com/problems/smallest-range-covering-elements-from-k-lists/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-25
 * 
 * Summary:
 * This problem is equivalent to find a selection for exact one number in 
 * each list such that max - min is the smallest.
 * 该问题等效于，从每一个列表中选一个数字，使得选中的数字的最大值和最小值的差值最小。
 * 
 * Firstly, we select the first number in each list and init the range with 
 * the min and max in this selection. 
 * Then, we replace the minimal number in the selection with the next distinct 
 * number in its list, until the minimal number is the last number in its list. 
 * 首先，我们选择每个列表中的第一个数字。
 * 然后，将选中的最小数字用同列表的下一个不同数字替换，直到选中的最小数字是它所在列表的
 * 最后一个。
 * 
 * Since all lists are in non-decreasing order, for each replacement of the 
 * minimal number, it is replaced with a larger number. So, the range 
 * right-shifts a little bit for time. 
 * 由于所有列表示非递减排列，每次选中的最小数字会被一个更大的数字替换。因此，每次区间都
 * 会向右移动一点。
 * 
 * For each right-shift, the range contains at least one number in each list 
 * and it is as small as possible. So, we traverse all possible smallest 
 * ranges. 
 * 每次右移，区间都包含每个列表的数字，且区间尽可能小。因此，我们能遍历所有可能的最小区
 * 间。
 * 
 * Once the minimal number in selection is the last number in its list, this 
 * minimal number must remain in selection and any update of other numbers can 
 * only make that number larger and make the range larger. So, we stop here. 
 * 当选中的最小数字是其列表的最后一个数字时，继续右移区间必须保证该数字仍在区间内，而其
 * 他数字只可能被更大的数字替换，而区间也只可能变得更大。因此，我们到此为止，不再右移。
 ******************************************************************************/

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int nlist = nums.size(); // Total number of lists.
                                 // 列表总数。
        std::vector<int> range; // Currently smallest range.
                                // 当前最小区间。
        std::multimap<int, int> included; // Number-list pairs included in 
            // range. Each list has exact one number included.
            // 包含在区间内的数字-列表对。每个列表都有一个数字被包含。
        std::vector<int> indices; // Indices of included numbers in their lists.
                                  // 被包含数字的列表。
        
        // Include the first number in each list.
        // 包含每个列表的第一个数字。
        for (int i = 0; i < nlist; i++)
        {
            included.insert(std::pair<int, int>(nums[i][0], i));
            indices.push_back(0);
        }
        // Init range.
        // 初始化区间。
        auto min = included.begin();
        auto max = included.rbegin();
        range.push_back(min->first);
        range.push_back(max->first);
        
        // Replace the minimal number included with the next number in its list.
        // 将选中的最小数字用同列表中的下一个不同数字替换。
        int min_list = min->second; // List of the minimal included number.
                                    // 选中的最小数字所在的列表。
        while(indices[min_list] < nums[min_list].size() - 1)
        {
            // Replace the smallest included number to the next distinct number 
            // in its list.
            // 将选中的最小数字用同列表中的下一个不同数字替换。
            while(indices[min_list] < nums[min_list].size() - 1 && nums[min_list][indices[min_list]] == min->first)
            {
                indices[min_list]++;
            }
            included.erase(min);
            included.insert(std::pair<int, int>(nums[min_list][indices[min_list]], min_list));
            
            // Update range.
            // 更新区间
            min = included.begin();
            min_list = min->second;
            max = included.rbegin();
            if (max->first - min->first < range[1] - range[0])
            {
                range[0] = min->first;
                range[1] = max->first;
            }
        }
        
        return range;
    }
};
