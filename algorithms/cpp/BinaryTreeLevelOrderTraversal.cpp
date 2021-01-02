/*******************************************************************************
 * Problem: 102. Binary Tree Level Order Traversal
 * https://leetcode.com/problems/binary-tree-level-order-traversal/
 * 问题：102. 二叉树的层序遍历
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 * 剑指 Offer 32 - II. 从上到下打印二叉树 II
 * https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-27
 * 
 * Summary:
 * We use modified BFS to record values in each level respectively.
 * We use only one queue for all nodes. For each level, we record n as the 
 * number of nodes in the next level. When processing the next level, we only 
 * pop the first n nodes such that we only process nodes in the current level 
 * and won't touch nodes in the next level.
 * 
 * Pseudocode:
 * 1. Push root to the queue and set n, number of nodes in current level, to 1.
 * 2. While queue is not empty:
 *  (1) Pop the first n nodes. For each node:
 *      a. Record its value.
 *      b. Push non-null left and right child to the queue, and increase m, the 
 *         number of non-null children in current level.
 *  (2) Append values in the current level to the result.
 *  (3) Set n, number of nodes in current level, to m, the number of non-null 
 *      children in current level.
 * 
 * 用改进的BFS分别记录每一层从左到右各节点的值。
 * 用一个队列保存所有节点。在处理每一行节点时，记录下一行的节点数n，即当前行的非空子节
 * 点数。在处理下一行时，只处理队首的n个节点。这样，在处理每一行时，只会处理当前行的结
 * 点，而不会处理到下一行的结点。
 * 
 * 具体算法：
 * 1.将根节点放入队列，记当前行节点数为n=1。
 * 2.当队列不为空：
 *  (1)依次取出队列的前n个节点。对于每个节点：
 *      a.记录当前节点的值。
 *      b.依次将非空左子节点和非空右子节点放入队列，并统计当前行非空子节点总数。
 *  (2)将当前行的值并入结果。
 *  (3)将当前行非空子节点总数作为下一行的节点数。
 * 3.输出结果
 ******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int> > result;
        if (root == NULL)
        {
            return result;
        }

        TreeNode *curr; // Node is currently being processed.
                        // 当前处理的节点。
        queue<TreeNode *> q; // Node queue for BFS.
                             // 广搜队列。
        int curr_width; // Number of nodes in the current level.
                        // 当前行的节点数。
        int next_width; // Number of nodes in the next level.
                        // 下一行的节点数。
        
        // Push root node.
        // 将根节点加入队列。
        q.push(root);
        curr_width = 1;

        // BFS.
        // 广搜。
        while (!q.empty())
        {
            vector<int> values; // Values in the current level.
                                // 当前行的值。
            next_width = 0;

            // Only pop nodes in the current level.
            // 只从队列中取出当前行的节点。
            for (int i = 0; i < curr_width; i++)
            {
                curr = q.front();

                values.push_back(curr->val);

                // Only push non-null children.
                // 只将非空子节点加入队列。
                if (curr->left != NULL)
                {
                    q.push(curr->left);
                    next_width++;
                }
                if (curr->right != NULL)
                {
                    q.push(curr->right);
                    next_width++;
                }

                q.pop();
            }

            result.push_back(values);

            // Go to next level. 
            curr_width = next_width;
        }
        return result;
    }
};
