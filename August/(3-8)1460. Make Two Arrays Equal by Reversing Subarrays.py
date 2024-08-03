class Solution(object):
    def canBeEqual(self, target, arr):
        """
        :type target: List[int]
        :type arr: List[int]
        :rtype: bool
        """
        for i in target:
            if i not in arr:
                return False
            else:
                arr.remove(i)
        return True            

OR

class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return Counter(target)== Counter(arr)
        
        
