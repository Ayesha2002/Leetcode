//Time complexity:O(n)
//Space complexity:O(1)
//Use of bit manipulation

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result=0;

        while(head){
            result = (result<<1) | (head->val);
            head= head->next;
        }
        return result;

    }
};
