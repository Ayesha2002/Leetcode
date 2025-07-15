//Time complexity:O(n)
//Space complexity:O(1)

class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3){
            return false;
        }

        bool Vowel = false;
        bool Consonant= false;

        for(char ch: word){
            if (isalpha(ch)){
                ch = tolower(ch);
                if(ch == 'a' ||ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ){
                    Vowel= true;
                }else{
                    Consonant= true;
                }
            }else if(!isdigit(ch)){
                return false;
            }
        }
        return Vowel && Consonant;
    }
};
