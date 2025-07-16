//Time complexity:O(n)
//Space Complexity:O(1)

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int countEven=0;
        int countOdd=0;
        int alt=1;

        for(int &num:nums){
            if(num %2==0){
                countEven++;
            }else{
                countOdd++;
            }
        }

        int parity=nums[0]%2;
        for(int i=1;i<nums.size();i++){
            int currParity=nums[i]%2;
            if(currParity != parity){
                alt++;
                parity= currParity;
            }
        }

        return max({countEven,countOdd,alt});
    }
};
