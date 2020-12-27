/*******************************************************************************
 * Problem: 226. Invert Binary Tree
 * https://leetcode.com/problems/invert-binary-tree/
 * 问题：226. 翻转二叉树
 * https://leetcode-cn.com/problems/invert-binary-tree/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-26
 * 
 * Summary:
 * The key is recursion.
 * Base case: 
 *     If the tree is empty, then return the given root.
 * Recursive case: 
 *     Recursively invert left tree and right tree respectively. 
 *     Set the inverted left tree as the new right tree. 
 *     Set the inverted right tree as the new left tree.
 * 利用递归思想处理二叉树问题。
 * 基本情况：
 *     若二叉树为空，即root==NULL，则返回root。
 * 递归情况：
 *     分别递归翻转左子树和右子树。
 *     将翻转的左子树作为新的右子树。
 *     将翻转的右子树作为新的左子树。
 ******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root)
    {
        // Base case:
        if (root == NULL)
        {
            return NULL;
        }
        
        // Recursive case:
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
};
