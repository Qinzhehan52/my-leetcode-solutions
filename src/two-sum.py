class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        nums_map = {}
        for i in range(0, len(nums)):
            nums_map[nums[i]] = i
            pass

        for k in nums_map.keys():
            try:
                res = nums_map[target - k]
                if res != nums_map[k]:
                    return [nums_map[k], res]
            except KeyError:
                continue


solution = Solution()
print(solution.twoSum([3, 2, 4], 6))
