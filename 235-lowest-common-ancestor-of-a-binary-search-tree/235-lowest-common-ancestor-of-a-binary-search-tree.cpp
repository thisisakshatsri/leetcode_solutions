/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //Approach: BST have the property is the left->value will be smaller than root->value and the right->value is strictly greater than the roo->value. We can use this property such that if both p->val and q->val is smaller than root, we go to the left and if the p->val and q->val is greater than the root then, we go to the right. And, where both condition doesn't satisfied we're sure that's the intersection point and that node will be Lowest Common Ancestor of p and q  
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *temp = root;   
        
        if(temp == nullptr) return nullptr;
        
        while(temp != NULL) {
            if(temp->val > p->val && temp->val > q->val)
                temp = temp->left;
            else if(temp->val < p->val && temp->val < q->val)
                temp = temp->right;
            else return temp;
        }
        return nullptr;
    }
};