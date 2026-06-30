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
    void attach(TreeNode* node,TreeNode* temp){
        if(!node->right) node->right=temp;
        else attach(node->right,temp);
    }
    void search(TreeNode* node,int key){
        if(!node) return;
        if(node->left && node->left->val==key){
            //detach
            if(node->left->left && node->left->right){
                TreeNode* temp=node->left->right;
                node->left=node->left->left;
                attach(node->left,temp);
            }
            else node->left=node->left->left?node->left->left:node->left->right;
        }
        else if(node->right && node->right->val==key){
            //detach
            if(node->right->left && node->right->right){
                TreeNode* temp=node->right->right;
                node->right=node->right->left;
                attach(node->right,temp);
            }
            else node->right=node->right->left?node->right->left:node->right->right;
        }
        else{
            if(node->val<key) search(node->right,key);
            else search(node->left,key);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if (root->val == key) {
        TreeNode* dummy = new TreeNode(0);
        dummy->left = root;
        search(dummy, key);
        TreeNode* newRoot = dummy->left;
        delete dummy;
        return newRoot;
       }
    search(root, key);
    return root;
    }
};