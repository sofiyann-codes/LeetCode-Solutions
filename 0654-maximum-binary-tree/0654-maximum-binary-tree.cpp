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
    TreeNode* findnode(vector<int>& nums, int s, int e)
    {
        if(s>e) return NULL;
        int idx = s;
        int maxi = nums[s];
        for(int i=s+1;i<=e;i++)
        {
            if(nums[i]>maxi)
            {
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* temp = new TreeNode(maxi);
        temp->left = findnode(nums, s, idx-1);
        temp->right = findnode(nums, idx+1, e);
        return temp; 
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int n = nums.size();
        int idx=0;
        int maxi=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>maxi)
            {
                maxi = nums[i];
                idx = i;
            }
        }
        TreeNode* root = new TreeNode(maxi);
        root->left = findnode(nums,0,idx-1);
        root->right = findnode(nums,idx+1,n-1); 
        return root;
    }
};