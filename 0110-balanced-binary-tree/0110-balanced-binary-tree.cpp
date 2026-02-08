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
    
int DFS(TreeNode*root){
    if(root==NULL){
      return 0;
    }
   int lh=DFS(root->left);
   if(lh==-1)return -1;
   int rh=DFS(root->right);
if(rh==-1)return -1;
   if(abs(rh-lh)>1)return -1;
   return max(lh,rh)+1;
//  if(abs(rh-lh)>1)return -1;
// return true;

}
    bool isBalanced(TreeNode* root) {
        // return DFS(root)==-1?false:true;
        if(DFS(root)!=-1)return true;
        else return false;
    }
};