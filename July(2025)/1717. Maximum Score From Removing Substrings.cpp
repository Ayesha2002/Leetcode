class Solution {
public:
    string removeSubstr(string &s, string &matchStr){
        stack<char> st;

        for(char &ch : s){
            if(ch == matchStr[1] && !st.empty() && st.top() == matchStr[0]){
                st.pop(); // remove the pair
            } else {
                st.push(ch); // keep it
            }
        }

        string temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }

    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxString = (x >= y) ? "ab" : "ba";
        string minString = (x >= y) ? "ba" : "ab";

        string temp_first = removeSubstr(s, maxString);
        int l = temp_first.length();
        int charRemoved = n - l;
        score += (charRemoved / 2) * max(x, y);

        string temp_second = removeSubstr(temp_first, minString);
        charRemoved = l - temp_second.length();
        score += (charRemoved / 2) * min(x, y);

        return score;
    }
};
