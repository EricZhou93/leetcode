/*******************************************************************************
 * Problem: 1046. Last Stone Weight
 * https://leetcode.com/problems/last-stone-weight/
 * 问题：1046. 最后一块石头的重量
 * https://leetcode-cn.com/problems/last-stone-weight/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-29
 * 
 * Summary:
 * Store all the stones with a max priority queue. 
 * Case 1: If queue is empty, return 0.
 * Case 2: If queue has only one stone, return the weight of the stone. 
 * Case 3: If queue has more than one stones, pop 2 stones and push their 
 * weight difference. Even if we push 0 to the queue, it does not affect the 
 * result.
 * 用优先队列保存所有石头，最重的石头先出。
 * 情况1：队列空了，则返回0。
 * 情况2：队列中只有一块石头，则返回那块石头的重量。
 * 情况3：取出两块石头，则将两块重量的差值放入队列。即使放入队列中的差值为0，也不影响最
 * 终结果。
 ******************************************************************************/

class Solution
{
public:
    int lastStoneWeight(vector<int>& stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        int larger = 0;
        int smaller = 0;
        while(!pq.empty())
        {
            larger = pq.top();
            pq.pop();

            if (pq.empty())
            {
                break;
            }
            smaller = pq.top();
            pq.pop();

            pq.push(larger - smaller);
        }
        return larger;
    }
};
