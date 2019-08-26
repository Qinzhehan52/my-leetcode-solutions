class Solution:
    def replaceWords(self, dictionary, sentence):
        """
        :type dictionary: list[str]
        :type sentence: str
        :rtype: str
        """
        words = sentence.split()
        for i in range(0, len(words)):
            for root in dictionary:
                if self.is_root(words[i], root):
                    words[i] = root
                    break
        return ' '.join(words)

    def is_root(self, word, root):
        """
        :type word: str
        :type root: str
        :rtype: str
        """
        return word[:len(root)] == root


print(Solution().replaceWords(["ca", "cat", "bat", "rat"], "the cattle was rattled by the battery"))
