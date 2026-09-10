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
    pair<int,int> dfs(TreeNode* node,int& count) {
        if (!node) return {0, 0};
        auto [ls, lc] = dfs(node->left,count);
        auto [rs, rc] = dfs(node->right,count);
        int sum = ls + rs + node->val;
        int cnt = lc + rc + 1;
        if (sum / cnt == node->val) count++;
        return {sum, cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count; 
    }
};