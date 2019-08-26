class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans, i, j, charset = 0, 0, 0, set()
        while i < len(s) and j < (len(s)):
            if s[j] not in charset:
                charset.add(s[j])
                j += 1
                ans = max(ans, j - i)
            else:
                charset.remove(s[i])
                i += 1
        return ans
