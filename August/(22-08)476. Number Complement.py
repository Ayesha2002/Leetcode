//Time complexity = O(1)
//Space complexity = O(1)

class Solution:
    def findComplement(self, num: int) -> int:
        bit_length = num.bit_length() // find the length of the number
        
        mask = (1 << bit_length) - 1 // bitwise operation to shift the 1 on to the left side and subtract 1 from the number
        
        return num ^ mask // performing the XOR operation to swap (1 with 0) and (0 with 1)
