# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def __init__(self):
        self.tree = None

    def bstFromPreorder(self, preorder):
        """
        :type preorder: List[int]
        :rtype TreeNode
        """
        if len(preorder) < 0:
            return None
        self.tree = TreeNode(preorder[0])
        for x in preorder:
            self.insert(self.tree, x)
        return self.tree

    def insert(self, node, elem):
        """
        :type node: TreeNode
        :type elem: int
        :rtype None
        """
        if elem < node.val:
            if not node.left:
                node.left = TreeNode(elem)
            else:
                self.insert(node.left, elem)
            return
        if elem > node.val:
            if not node.right:
                node.right = TreeNode(elem)
            else:
                self.insert(node.right, elem)
            return


Solution().bstFromPreorder([8, 5, 1, 7, 10, 12])
