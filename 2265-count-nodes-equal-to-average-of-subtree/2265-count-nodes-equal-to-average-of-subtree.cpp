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
    int val(TreeNode* node){
        if(!node) return 0;
        return val(node->left)+val(node->right)+node->val;
    }
    int size(TreeNode* node){
        if(!node->left && !node->right) return 1;
        else if(node->left && !node->right) return size(node->left)+1;
        else if(!node->left && node->right) return size(node->right)+1;
        else return size(node->left) + size(node->right) + 1;
    }
    void dfs(TreeNode* node,int& count){
        if(!node) return;
        int average=val(node)/size(node);
        if(average==node->val) count++;
        dfs(node->left,count);
        dfs(node->right,count);
        return ;
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        dfs(root,count);
        return count; 
    }
};