# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p, q, l3 = l1, l2, ListNode(0)
        res = l3
        while p and q:
            x, y = int((p.val + q.val + l3.val) / 10), (p.val + q.val + l3.val) % 10
            l3.val = y
            l3.next = ListNode(x)
            p, q, l3 = p.next, q.next, l3.next

        while p:
            l3.val += p.val
            l3.val, l3.next = int(l3.val % 10), ListNode(int(l3.val / 10))
            l3, p = l3.next, p.next

        while q:
            l3.val += q.val
            l3.val, l3.next = int(l3.val % 10), ListNode(int(l3.val / 10))
            l3, q = l3.next, q.next

        if l3.val == 0:
            node = res
            while node.next != l3:
                node = node.next
            node.next = None
        return res


l_1 = ListNode(1)
l_2 = ListNode(9)
l_2.next = ListNode(9)

solution = Solution()
l4 = solution.addTwoNumbers(l_1, l_2)
while l4 is not None:
    print(l4.val)
    l4 = l4.next