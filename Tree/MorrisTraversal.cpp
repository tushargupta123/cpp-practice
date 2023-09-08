// it is tree traversal technique that takes O(n) time and  O(1) space

vector<int> getInorder(TreeNode *root){
    vector<int> res;
    TreeNode *curr = root;
    while(curr){
        if(!curr->left){
            res.push_back(curr->val);
            curr=curr->right;
        }else{
            TreeNode *prev = curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            if(!prev->right){
                prev->right=curr;
                curr=curr->left;
            }else{
                prev->right=NULL;
                res.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return res;
}