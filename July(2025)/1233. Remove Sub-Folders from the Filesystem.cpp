//Time complexity: O(n * L^2)
//Space complexity:O(n*L)

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for(string currfolder :folder){
            bool issubfolder=false;
            string tempfolder = currfolder;
            while(!currfolder.empty()){
                size_t position = currfolder.find_last_of('/');

                currfolder = currfolder.substr(0,position);

                if(st.find(currfolder) != st.end()){
                    issubfolder = true;
                    break;

                }
            }

            if(!issubfolder){
                result.push_back(tempfolder);
            }
        }
        return result;
    }
};
