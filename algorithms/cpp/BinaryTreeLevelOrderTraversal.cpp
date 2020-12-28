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
 * We use a modified BFS algorithm to record values on each level respectively. 
 * Values on each have to be store in a independent array. So, we use an even 
 * level queue and an odd level queue to store nodes on the current level and 
 * on the next level respectively.
 * If the current level is even, we pop nodes in even level queue one by one. 
 * For each node, we append its value to value array for this level and append 
 * its children to odd level queue.
 * If the current level is odd, we do the similar thing.
 * 
 * 利用BFS分别记录每一层从左到右各节点的值。
 * 由于每一层的值要各自保存在单独的数组中，这里我需要用到两个队列，偶数层队列和奇数层队
 * 列，分别存储这一层的结点和下一层的结点。
 * 若当前行为偶数行，则这一层的结点保存再偶数层队列中。每当从偶数层队列中取出队首节点，
 * 就把它的值记录在本层数值最后，并将其子节点放到奇数层队列末尾。
 * 若当前行为奇数行，同理。
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result; // Tree node values in level order.
        if (root == NULL)
        {
            return result;
        }
        queue<TreeNode *> nodes[2]; // nodes[0]: nodes on even level. 
                                    // nodes[1]: nodes on odd level. 
        TreeNode *curr = NULL;
        int is_odd = 0; // 0 is for even level and 1 is for odd level. 
        nodes[is_odd].push(root);
        while(true)
        {
            vector<int> values; // Values on this level.

            // Go through each node on this level.
            while(!nodes[is_odd].empty())
            {
                curr = nodes[is_odd].front();
                
                values.push_back(curr->val);

                // Add children to the queue for next level.
                if (curr->left != NULL)
                {
                    nodes[(is_odd + 1) % 2].push(curr->left);
                }
                if (curr->right != NULL)
                {
                    nodes[(is_odd + 1) % 2].push(curr->right);
                }

                nodes[is_odd].pop();
            }

            // If no value on this level, stop.
            if (values.empty())
            {
                break;
            }
            else
            {
                result.push_back(values);
            }

            // Go to next level.
            is_odd = (is_odd + 1) % 2;
        }
        return result;
    }
};
