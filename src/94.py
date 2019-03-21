# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root: TreeNode) -> list:
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        arr = []
        if root:
            arr += self.inorderTraversal(root.left)
            arr.append(root.val)
            arr += self.inorderTraversal(root.right)
        return arr

    def inorderTraversal_1(self, root: TreeNode) -> list:
        """
        递归法
        :type root: TreeNode
        :rtype: List[int]
        """
        arr = []
        if root:
            arr += self.inorderTraversal(root.left)
            arr.append(root.val)
            arr += self.inorderTraversal(root.right)
        return arr

    def inorderTraversal_2(self, root: TreeNode) -> list:
        """
        迭代法
        :type root: TreeNode
        :rtype: List[int]
        """
        cur, arr, stack = root, [], []
        while cur or len(stack) > 0:
            if cur:
                stack.append(cur)
                cur = cur.left
            else:
                cur = stack.pop()
                arr.append(cur.val)
                cur = cur.right
        return arr
