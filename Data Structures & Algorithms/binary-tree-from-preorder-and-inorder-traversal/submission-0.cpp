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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return nullptr;

        int rootval = preorder[0];
        TreeNode* root = new TreeNode(rootval);
        
        int mid = 0;
        while(inorder[mid]!=rootval){
            mid++;
        }

        vector<int> leftinorder(inorder.begin(),inorder.begin()+mid);
        vector<int> rightinorder(inorder.begin()+mid+1,inorder.end());

        vector<int> leftpreorder(preorder.begin()+1,preorder.begin()+1+mid);
        vector<int> rightpreorder(preorder.begin()+1+mid,preorder.end());

        root->left = buildTree(leftpreorder,leftinorder);
        root->right = buildTree(rightpreorder,rightinorder);

        return root;
    }
};
