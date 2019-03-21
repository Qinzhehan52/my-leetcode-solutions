class Solution:
    def escapeGhosts(self, ghosts, target) -> bool:
        """
        :type ghosts: List[List[int]]
        :type target: List[int]
        :rtype: bool
        """
        for ghost in ghosts:
            if self.distance(ghost, target) <= abs(target[0]) + abs(target[1]):
                return False
        return True

    def distance(self, pos, target):
        """
        :type pos: List[int]
        :type target: List[int]
        :rtype: int
        """
        return abs(pos[0] - target[0]) + abs(pos[1] - target[1])


print(Solution().escapeGhosts([[1, 0], [0, 3], [2, 0]], [1, 0]))
