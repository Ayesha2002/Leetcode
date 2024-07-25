class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
       
        min_val = min(nums)
        max_val = max(nums)
        
       
        count_range = max_val - min_val + 1
        count = [0] * count_range
        
       
        for num in nums:
            count[num - min_val] += 1
        
        
        sorted_nums = []
        for i in range(count_range):
            sorted_nums.extend([i + min_val] * count[i])
        
        return sorted_nums
