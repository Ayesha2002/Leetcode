class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        
        //strore the conflictingof each
        vector<vector<long long>>mp(n+1);
        for(auto conf:conflictingPairs)
        {
            int u=max(conf[1],conf[0]);
            int v=min(conf[1],conf[0]);
            mp[u].push_back(v);
        }
        
        
        int maxi=0,smaxi=0;
        vector<long long> maxExtra(n + 1, 0);
        long long valid=0;
        for(int i=1;i<=n;i++)
        {
           
           for(int ele:mp[i])
           {
               if(ele>=maxi)
                {
                    smaxi=maxi;
                    maxi=ele;
                }
                else if(ele>smaxi)
                {
                    smaxi=ele;
                }
           }
            valid+=i-maxi;
            maxExtra[maxi] += (maxi - smaxi);    
        }
        valid+= *max_element(maxExtra.begin(), maxExtra.end());
        return valid;
    }
};
