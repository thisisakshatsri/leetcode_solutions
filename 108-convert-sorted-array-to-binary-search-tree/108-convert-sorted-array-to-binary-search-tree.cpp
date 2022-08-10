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
    TreeNode *bst(vector<int> v, int left, int right) {
        if(left > right) return NULL;
        if(left <= right) {
            int mid = left + (right - left) / 2;
            TreeNode* root = new TreeNode(v[mid]);
            root->left = bst(v, left, mid-1);
            root->right = bst(v, mid+1, right);
            return root;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        TreeNode* ans = bst(nums, left, right);
        return ans;
    }
};