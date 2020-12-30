/*******************************************************************************
 * Problem: 57. Insert Interval
 * https://leetcode.com/problems/insert-interval/
 * 问题：57. 插入区间
 * https://leetcode-cn.com/problems/insert-interval/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-29
 * 
 * Summary:
 * Given 2 intervals [a, b] and [c, d]. 
 * If they do not overlap, [a, b] is on the left or right side of [c, d], i.e. 
 * b < c or a > d. 
 * If they overlap, then c <= a <= d or c <= b <= d. 
 * Given a set of non-overlapping intervals and a new interval, 
 * we first find out interval on the left and right side of the new interval, 
 * then merge the new intervals and intervals that it overlaps with.
 * The left bound of the merged interval is the smaller one between the left 
 * bounds of the new interval and the left-most overlaping interval.
 * The right bound of the merged interval is the larger one between the right 
 * bounds of the new interval and the right-most overlapping interval. Since 
 * the overlapping intervals do not overlap with each other, an interval on the 
 * right side has larger right bound.
 * 给定两个区间[a, b]和[c, d]。
 * 若无重叠，则[a, b]在[c, d]左侧或右侧，即b < c或a > d。
 * 若有重叠，则c <= a <= d或者c <= b <= d。
 * 根据给定的无重叠区间和插入区间，先分别确定插入区间左右侧的无重叠区间，然后合并插入区
 * 间与重叠区间。
 * 合并重叠的区间时，合并后区间的左端应该是插入区间左端和最左侧重叠区间左端的最小值。
 * 由于给定的一系列区间不重叠，右侧区间的右端一定更大。合并区间的右端应该是插入区间右端
 * 和最右侧重叠区间右端的最小值。
 ******************************************************************************/

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, 
                               vector<int>& newInterval)
    {
        // If the set of non-overlapping intervals is empty, insert the new 
        // interval directly.
        // 无重叠区间为空，直接插入新区间。
        vector<vector<int>> result;
        if (intervals.size() == 0)
        {
            result.push_back(newInterval);
            return result;
        }

        // Count non-overlapping intervals on the left side of the new one.
        // 计算左侧未重叠的区间数量。
        int len = intervals.size();
        int left = 0;
        while(left < len && newInterval[0] > intervals[left][1])
        {
            left++;
        }

        // Count non-overlapping intervals on the right side of the new one.
        // 计算右侧未重叠的区间数量。
        int right = 0;
        while(right < len && newInterval[1] < intervals[len - 1 - right][0])
        {
            right++;
        }

        // Copy non-overlapping intervals on the left side of the new one.
        // 左侧未重叠区间。
        for (int i = 0; i < left; i++)
        {
            result.push_back(intervals[i]);
        }
        // The new interval does not overlap with others.
        // 新区间与其他区间无重叠。
        if (left + right == len)
        {
            result.push_back(newInterval);
        }
        // The new interval overlaps with others.
        // 新区间与其他区间有重叠。
        else
        {
            vector<int> toInsert(2);
            toInsert[0] = min(newInterval[0], intervals[left][0]);
            toInsert[1] = max(newInterval[1], intervals[len - 1 - right][1]);
            result.push_back(toInsert);
        }
        // Copy non-overlapping intervals on the right side of the new one.
        // 右侧未重叠区间。
        for (int i = len - right; i < len; i++)
        {
            result.push_back(intervals[i]);
        }
        return result;
    }
};
