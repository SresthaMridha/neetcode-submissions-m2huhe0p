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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        queue<TreeNode*> q;
        string s = "";

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!node){
                s = s + "N" + ",";
                continue;
            }

            s = s + to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }

        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals;
        string temp = "";

        for(auto c: data){
            if(c==','){
                vals.push_back(temp);
                temp = "";
            }
            else{
                temp +=c;
            }
        }

        if(vals[0]=="N") return NULL;

        TreeNode* root  = new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;     
        q.push(root);

        int i = 1;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(vals[i]!="N"){
                node->left = new TreeNode(stoi(vals[i]));
                q.push(node->left);
            }

            i++;

            if(vals[i]!="N"){
                node->right = new TreeNode(stoi(vals[i]));
                q.push(node->right);
            }

            i++;
        } 
        return root;
    }
};
