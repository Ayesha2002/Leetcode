class Solution:
    def minimumDeletions(self, s: str) -> int:
        a_right =0
        for c in s :
            a_right += 1 if c=="a" else 0

        b_left =0
        res=len(s)
        for i,c in enumerate(s):
            if c == "a":
                a_right -=1
            res=min(res,b_left + a_right)
            if c=="b":
                b_left +=1
        return res         

        
