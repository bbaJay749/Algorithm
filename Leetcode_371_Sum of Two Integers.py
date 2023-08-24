

class Solution:

    def getSum(self, a: int, b: int) -> int:
        mask = 0xFFFFFFFF  # set limitation up to 32-bit

        # a is sum, b is carry
        while b:
            a, b = (a ^ b), ((a & b) << 1)
            a, b = a & mask, b & mask

        # if a < 0, return 2's complement
        return a if a <= 0x7FFFFFFF else ~(a ^ mask)
