class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> m = set<string>(wordDict.begin(), wordDict.end());
        vector<bool>  dp = vector<bool>(s.length()+1, false);

        int minLen = INT_MAX;
        int maxLen = 0;

        for (string t : wordDict) {
            int len = t.length();
            minLen = minLen < len ? minLen : len; 
            maxLen = max(len, maxLen);
        }

        dp[0] = true;

        for (int i = minLen; i <= s.length(); i++)
        {
            for (int j = max(0, i - maxLen); j < i; j++)
            {
                if (dp[j] && m.find(s.substr(j, i - j)) != m.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
