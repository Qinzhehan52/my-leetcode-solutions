class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> M;

        for (char c : s) M[c]++;

        int ans = 0;

        for (auto it = M.begin(); it != M.end(); it++) ans += it->second / 2 * 2;

        return ans < s.length() ? ans + 1 : ans;
    }
};
