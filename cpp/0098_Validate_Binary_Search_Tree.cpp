#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
// #include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* lb, TreeNode* hb) {
        if (!root) return true;

        if (lb && root->val <= lb->val) return false;

        if (hb && root->val >= hb->val) return false;

        return helper(root->left, lb, root) && helper(root->right, root, hb);
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }
};

/*
class Solution {
public:
    int last_val;
    bool set;

    bool dfs(TreeNode* root) {
        if (root->left) {
            if (!dfs(root->left)) return false;
        }

        if (last_val >= root->val) {
            if (set)
                return false;
        }
        last_val = root->val;
        set = true;

        if (root->right) {
            if (!dfs(root->right)) return false;
        }

        return true;
    }

    bool isValidBST(TreeNode* root) {
        last_val = numeric_limits<int>::min();
        set = false;

        return dfs(root);
    }
};
*/

int main(int argc, char *argv[]) {

    return 0;
}
