/*******************************************************************************
 * Problem: 881. Boats to Save People
 * https://leetcode.com/problems/boats-to-save-people/
 * 问题：881. 救生艇
 * https://leetcode-cn.com/problems/boats-to-save-people/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-06
 * 
 * Summary:
 * Greedy algorithm.
 * Try to put 2 people on 1 boat. 
 * Try to pair the heaviest person with another and put them on 1 boat. 
 * Then lighter people are easier to pair on 1 boat.
 * 
 * Find the heaviest and the lightest people not on boat， until all people are 
 * on boats:
 * If the heaviest and the lightest people are not overweight, put them 
 * together on 1 boat. 
 * If not, put the heaviest one on boat alone.
 * 
 * 思路：
 * 贪心算法。
 * 尽量让每艘船坐两个人。
 * 尽可能让最重的人和其他人两人坐一艘船。这样剩下的更轻的人更容易做到两人一艘船。
 * 
 * 找未上船的人中最轻的和最重的配对，直至所有人都已上船：
 * 若不超重，则两人一艘；若超重，则最重的人单独坐一艘。
 ******************************************************************************/

class Solution
{
public:
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(), people.end());
        int left = 0; // The lightest person not on boat.
                      // 指向未上船的人中最轻的。
        int right = people.size() - 1; // The heaviest person not on boat.
                                       // 指向未上船的人中最重的。
        int nboat = 0;
        while(left <= right)
        {
            // Pair the heaviest and the lightest people.
            // 最轻的和最重的配对。
            if (people[left] + people[right] <= limit)
            {
                left++;
            }
            right--;
            nboat++;
        }
        return nboat;
    }
};
