class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        sum_n = 0
        if len(A) == 0:
            return sum_n

        for j in range(0, len(A[0])):
            flag = False
            for i in range(0, len(A) - 1):
                if A[i][j] > A[i + 1][j]:
                    flag = True
            if flag:
                sum_n += 1
        return sum_n


a = ["cba", "daf", "ghi"]
solution = Solution()
print(solution.minDeletionSize(["zyx", "wvu", "tsr"]))
