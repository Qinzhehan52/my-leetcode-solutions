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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0) return NULL;
        int idx = 0;
        while (inorder[idx] != preorder[0]) idx++;

        int l_size = idx;
        int r_size = inorder.size() - idx - 1;

        vector<int> l_pre, l_in, r_pre, r_in;

        l_pre.assign(preorder.begin(), preorder.begin() + l_size);
        l_in.assign(inorder.begin(), inorder.begin() + l_size);
//        for (int i = 0; i < l_size; ++i) {
//            l_pre.push_back(preorder[i + 1]);
//            l_in.push_back(inorder[i]);
//        }
        r_pre.assign(preorder.begin() + l_size + 1, preorder.begin() + l_size + r_size);
        r_in.assign(inorder.begin() + l_size + 1, inorder.begin() + l_size + r_size);
//        for (int i = 0; i < r_size; ++i) {
//            r_pre.push_back(preorder[l_size + i + 1]);
//            r_in.push_back(inorder[l_size + i + 1]);
//        }

        TreeNode *root = new TreeNode(preorder[0]);
        root->left = buildTree(l_pre, l_in);
        root->right = buildTree(r_pre, r_in);

        return root;
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) {
        return "[]";
    }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> preorder = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> inorder = stringToIntegerVector(line);

        TreeNode *ret = Solution().buildTree(preorder, inorder);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}