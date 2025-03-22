// M1:递归

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/maximum-depth-of-binary-tree/solutions/349250/er-cha-shu-de-zui-da-shen-du-by-leetcode-solution/
来源：力扣（LeetCode）

// M2：迭代

class Solution {
public:
    int maxDepth(TreeNode* root) {
        stack<TreeNode*> st;
        int max = 0;
        int cur = 0;
        TreeNode* curr = root;
        TreeNode* tmp = root;
        if (!root) {
            return 0;
        }
        else {
            st.push(root);
            cur++;
            root->val = -100;
        }

        while (!st.empty()) {
            curr = st.top();
            tmp = curr;

            if (curr->left && curr->left->val != -100) {
                st.push(curr->left);
                curr = curr->left;
                curr->val = -100;
                cur++;
            }

            else if (curr->right && curr->right->val != -100) {
                st.push(curr->right);
                curr = curr->right;
                curr->val = -100;
                cur++;
            }
            if (max < cur) {
                max = cur;
            }
            if (!st.empty()) {
                curr = st.top();
            }
            if (tmp == curr) {
                st.pop();
                cur--;
            }
        }
    return max;
    }
}
;
