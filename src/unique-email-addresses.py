import collections


class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        email_dict = collections.defaultdict(set)
        for email in emails:
            email_dict[email.split('@')[1]].add(email.split('@')[0].replace('.', '').split('+')[0])

        return sum(len(value) for value in email_dict.values())


solution = Solution()
print(solution.numUniqueEmails(
    ["test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com"]))
