class Solution:
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        stack = []
        for char in S:
            if char == ')' and len(stack) > 0 and stack[-1] == '(':
                stack.pop()
            else:
                stack.append(char)
        return len(stack)


solution = Solution()
print(solution.minAddToMakeValid(""))
