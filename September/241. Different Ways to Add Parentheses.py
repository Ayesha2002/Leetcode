class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        
        def helper(expr):
            result = []
            for i, char in enumerate(expr):
                if char in "+-*":
                    left = helper(expr[:i])
                    right = helper(expr[i+1:])
                    
                    for l in left:
                        for r in right:
                            if char == '+':
                                result.append(l + r)
                            elif char == '-':
                                result.append(l - r)
                            else:
                                result.append(l * r)
            
            if not result:
                result.append(int(expr))
            
            return result
        
        return helper(expression)
