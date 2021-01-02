/*******************************************************************************
 * Problem: 94. Binary Tree Inorder Traversal
 * https://leetcode.com/problems/binary-tree-inorder-traversal/
 * 问题：94. 二叉树的中序遍历
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-01
 * 
 * Summary:
 * Inorder traversal: left subtree > current node > right subtree.
 * 
 * Recursive solution:
 * Base case: If the current node is empty, return.
 * Recursive case: If the current node is not empty, recursively process the 
 * left child, then process the current node, and the recursively process the 
 * right child.
 * 
 * Iterative solution:
 * We use stack to simulate recursion.
 * 1. Simulate recursively processing left subtree: If the current node is not 
 * empty, push it to stack and set its left child as the new current node. 
 * Repeat until the current node is empty.
 * 2. Simulate processing the current node: Pop a node from the stack, set it 
 * as the current node and process it.
 * 3. Simulate recursively processing the right subtree: Set the right child as 
 * the new current node.
 * Repeat step 1-3 until both stack and the current node is empty.
 * 
 * 二叉树的中序遍历：左子树 > 当前节点 > 右子树
 * 
 * 递归解法：
 * 基本情况：若当前结点为空，则结束。
 * 递归情况：若当前结点不为空，先递归处理左子节点，再处理当前节点，最后递归处理右子节
 * 点。
 * 
 * 迭代解法：
 * 利用栈来模拟递归。
 * 1. 模拟递归处理左子树：若当前节点非空，则放入栈中，将左子节点作为新的当前节点。循环
 * 直至当前节点为空。
 * 2. 模拟处理当前节点：从栈中取出结点作为当前节点，并处理。
 * 3. 模拟递归处理右子树：将右子节点作为新的当前节点。
 * 重复1-3步，直至栈和当前节点都为空。
 ******************************************************************************/

// Recursive solution:
// 递归解法：
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
private:
    void inorderTraversal(TreeNode* curr, vector<int> &result)
    {
        // Base case:
        // 基本情况：
        if (curr == NULL)
        {
            return;
        }

        // Recursive case:
        // 递归情况：
        inorderTraversal(curr->left, result);
        result.push_back(curr->val);
        inorderTraversal(curr->right, result);
        return;
    }
};

// Iterative solution:
// 迭代解法：
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode *> stk; // Stack used to simulate recursion.
                               // 用于模拟递归的栈。
        TreeNode *curr = root;

        while (!stk.empty() || curr != NULL)
        {
            // Simulate recursively processing the left subtree and find the 
            // left-most node.
            // 模拟递归处理左子树，找到最左侧的子节点。
            while (curr != NULL)
            {
                stk.push(curr); // All nodes in stack are non-null.
                                // 栈内节点都是非空的。
                curr = curr->left;
            }
            curr = stk.top();
            stk.pop();

            // Process the current node.
            // 处理当前结点。
            result.push_back(curr->val);

            // Simulate recursively processing the right subtree.
            // 模拟递归处理右子树。
            curr = curr->right;
        }

        return result;
    }
};
