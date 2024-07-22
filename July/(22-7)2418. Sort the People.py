class Solution:
    def sortPeople(self, names: list[str], heights: list[int]) -> list[str]:
      
        # Combine names and heights into a list of tuples and sort by height in descending order
      #zip() is used to map the values in python
        combined = sorted(zip(heights, names), reverse=True)
        
        # Extract and return the sorted names
        return [name for height, name in combined]
