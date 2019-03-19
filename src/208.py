class TrieNode:
    def __init__(self):
        self.prefix, self.count, self.nextNodes = 0, 0, {}


class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.tree = TrieNode()

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        arr = list(word)
        cur_node = self.tree
        for i in range(0, len(arr)):
            if cur_node.nextNodes.get(arr[i]):
                cur_node = cur_node.nextNodes[arr[i]]
            else:
                cur_node.nextNodes[arr[i]] = TrieNode()
                cur_node = cur_node.nextNodes[arr[i]]
            cur_node.prefix += 1
        cur_node.count += 1

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        arr = list(word)
        cur_node = self.tree
        for i in range(0, len(arr)):
            if cur_node.nextNodes.get(arr[i]):
                cur_node = cur_node.nextNodes[arr[i]]
            else:
                return False
        return cur_node and cur_node.count > 0

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        arr = list(prefix)
        cur_node = self.tree
        for i in range(0, len(arr)):
            if cur_node.nextNodes.get(arr[i]):
                cur_node = cur_node.nextNodes[arr[i]]
            else:
                return False
        return cur_node and cur_node.prefix > 0


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


trie = Trie()

print(trie.insert("apple"))
print(trie.search("apple"))
print(trie.search("app"))
print(trie.startsWith("app"))
print(trie.insert("app"))
print(trie.search("app"))
