"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    # n叉数的层序遍历
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        if root == None:
            return []
        temp = []
        temp.append(root)
        res = []
        while len(temp) > 0:
            res.append(list(map(lambda x: x.val, filter(lambda x: x != None,temp))))
            temp2 = []
            for node in temp:
                temp2.extend(node.children)
            temp = temp2
        return res