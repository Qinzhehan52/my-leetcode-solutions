/**
 * Definition for a binary tree node.
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }

        bool left = isValidBST(root->left) && checkLeft(root);
        bool right = isValidBST(root->right) && checkRight(root);

        return left && right;
    }

    bool checkLeft(TreeNode *root) {

        return root->left == NULL || root->val > maxElem(root->left);
    }

    bool checkRight(TreeNode *root) {
        return root->right == NULL || root->val < minElem(root->right);
    }

    int maxElem(TreeNode *root) {
        if (root == NULL) {
            return INT_MIN;
        }

        int max_elem = root->val;
        max_elem = max(max_elem, maxElem(root->left));
        max_elem = max(max_elem, maxElem(root->right));

        return max_elem;
    }

    int minElem(TreeNode *root) {
        if (root == NULL) {
            return INT_MAX;
        }

        int min_elem = root->val;
        min_elem = min(min_elem, minElem(root->left));
        min_elem = min(min_elem, minElem(root->right));

        return min_elem;
    }
};


void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode *root = stringToTreeNode(line);

        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}