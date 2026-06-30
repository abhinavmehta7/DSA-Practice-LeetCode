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
    void solve(TreeNode* node,bool& ans,long long min,long long max){
        if(!node || !ans) return;
        if(node->val <= min || node->val >= max){
            ans=false;
            return;
        }
        solve(node->right,ans,node->val,max);
        solve(node->left,ans,min,node->val);
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        solve(root,ans,LLONG_MIN,LLONG_MAX);
        return ans;
    }
};