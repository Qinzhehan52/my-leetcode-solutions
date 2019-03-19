import itertools


class Solution(object):
    def largestTimeFromDigits(self, A):
        """
                :type A: List[int]
                :rtype: str
        """
        ans = -1
        for h1, h2, m1, m2 in itertools.permutations(A):
            hours = 10 * h1 + h2
            mins = 10 * m1 + m2
            time = 60 * hours + mins
            if 0 <= hours < 24 and 0 <= mins < 60 and time > ans:
                ans = time

        return "{:02}:{:02}".format(*divmod(ans, 60)) if ans >= 0 else ""


solution = Solution()
print(solution.largestTimeFromDigits([2, 4, 5, 9]))
