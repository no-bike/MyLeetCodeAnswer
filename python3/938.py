# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
        sum = 0
        def Dfs(node:Optional[TreeNode])->None:
            nonlocal sum
            if node is None:
               return
            if node.val < low:
                Dfs(node.right)
            if(node.val > high):
                Dfs(node.left)
            if node.val >= low and node.val <= high:
               sum += node.val
               Dfs(node.left)
               Dfs(node.right)
        Dfs(root)
        return sum