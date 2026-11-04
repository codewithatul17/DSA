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
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* build(vector<int>& preorder,
                    int inStart, int inEnd) {

        if (inStart > inEnd) {
            return nullptr;
        }

        // Get root from preorder
        int rootValue = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootValue);

        // Find root position in inorder
        int mid = mp[rootValue];

        // Build left subtree
        root->left = build(preorder, inStart, mid - 1);

        // Build right subtree
        root->right = build(preorder, mid + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder,
                        vector<int>& inorder) {

        int n = inorder.size();

        // Store inorder values and indices
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }

        return build(preorder, 0, n - 1);
    }
};