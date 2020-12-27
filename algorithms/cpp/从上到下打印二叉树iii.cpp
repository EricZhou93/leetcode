/*******************************************************************************
 * Problem: https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * 问题：https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-27
 * 
 * Summary:
 * We use a modified BFS to solve this problem.
 * We use 2 stacks to store nodes on an even level and an odd level 
 * respectively. When we pop nodes from a stack, we must pop them in a reverse 
 * order to the one for pushing them.
 * Assume the current level is even. We go through each node from left to right 
 * and push their children (on odd level) to stack from left to right as well. 
 * When we work on the next level, an odd level, we pop nodes from stack in 
 * exact right-to-left order.
 * Similarly, assume the current level is odd. We go through each node from 
 * right to left and push their children (on even level) to stack from right to 
 * left as well. When we work on the next level, an even level, we pop nodes 
 * from stack in exact left-to-right order.
 * Thus, we can print even levels from left to right and print odd levels from 
 * right to left.
 * 该算法的核心是广度搜索。但是由于奇数行和偶数行的打印顺序相反，所以要对广搜进行改进。
 * 这里我们用两个堆分别保存偶数行和奇数行的结点。这样每次从堆中取出结点一定与放入顺序相
 * 反。
 * 假如当前在偶数行，我们从左到右遍历每个结点，同时也从左到右把下一行（奇数行）结点放入
 * 堆中。当要处理奇数行时，我们需要倒序从堆中取出结点，正好是从右到左遍历每个结点。
 * 同理，假如当前在奇数行，我们从右到左遍历每个结点，同时也从右到左把下一行（偶数行）结
 * 点放入堆中。当要处理偶数行时，我们倒序从堆中取出结点，正好是从左到右遍历每个结点。
 * 这样正好符合奇数行和偶数行打印顺序相反的要求。
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
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        TreeNode* curr = root; // Current tree node.
                               // 当前节点。
        std::stack<TreeNode*> even_nodes; // Tree nodes on an even level.
                                          // 偶数层节点。
        std::stack<TreeNode*> odd_nodes; // Tree nodes on an odd level.
                                         // 奇数层节点。
        bool is_even = true; // Whether the current level is an even level.
                             // 当前是否为偶数层。

        even_nodes.push(curr);
        while(true)
        {
            vector<int> values; // Values on the current level.
                                // 当前层的数值。
            while(is_even && !even_nodes.empty())
            {
                curr = even_nodes.top();
                values.push_back(curr->val);
                if (curr->left != NULL)
                {
                    odd_nodes.push(curr->left);
                }
                if (curr->right != NULL)
                {
                    odd_nodes.push(curr->right);
                }
                even_nodes.pop();
            }
            while(!is_even && !odd_nodes.empty())
            {
                curr = odd_nodes.top();
                values.push_back(curr->val);
                if (curr->right != NULL)
                {
                    even_nodes.push(curr->right);
                }
                if (curr->left != NULL)
                {
                    even_nodes.push(curr->left);
                }
                odd_nodes.pop();
            }
            is_even = !is_even;
            if (!values.empty())
            {
                result.push_back(values);
            }
            else
            {
                break;
            }
        }
        
        return result;
    }
};