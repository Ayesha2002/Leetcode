class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> c;
        for(int i=1;i<=n;i++){
            string tmp= to_string(i);// converts int to str
            c.push_back(tmp);
        }
        sort(c.begin(), c.end());
        vector<int> ans;
        for(auto val:c){
            ans.push_back(stoi(val));// converts str to int
        }
        return ans;
        
    }
};
