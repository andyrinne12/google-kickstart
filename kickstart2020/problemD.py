import sys


sys.stdin = open("input.txt")


class Node:
    def __init__(self):
        self.children = {}
        self.count = 1


class Trie:
    def __init__(self):
        self.roots = {}

    def addString(self, s):
        if(not s[0] in self.roots.keys()):
            root = Node()
        else:
            root = self.roots[s[0]]
            root.count += 1
        self._addString(root, s, 1)

        self.roots[s[0]] = root

    def _addString(self, root, s, ind):
        if(ind >= len(s)):
            return

        letter = s[ind]

        if(not letter in root.children.keys()):
            child = Node()
        else:
            child = root.children[letter]
            child.count += 1
        self._addString(child, s, ind + 1)

        root.children[letter] = child


def solve(root, ans, K):
    ans[0] += root.count // K
    for child in root.children.values():
        solve(child, ans, K)


testCases = int(input())

for testCase in range(1, testCases + 1):
    line = input().split()
    N = int(line[0])
    K = int(line[1])

    trie = Trie()

    for _ in range(N):
        trie.addString(input().strip())

    ans = [0]

    for root in trie.roots.values():
        solve(root, ans, K)

    print("CASE #{}: {}".format(testCase, ans[0]))
