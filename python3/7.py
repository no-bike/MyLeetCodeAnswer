class Solution:
    def reverse(self, x: int) -> int:
        if x < 0:
            y = int('-'+str(x)[:0:-1])
        else:
            y = int(str(x)[::-1])
        return y if y<=2147483647 and y>=-2147483648 else 0