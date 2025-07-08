
//In this we used Linear search. we can also use binary search
// Time complexity:O(n² × k)-with linear search and with binary search we'll get O(n* k * log n)
//space complexity:  O(n × k)

class Solution {
public:
int n;
vector<vector<int>> t;// memoising 
int solve(vector<vector<int>>& events, int idx, int k){
    if(idx >= n || k==0){
        return 0;//as we cannot attend any events
    }

    if(t[idx][k] != -1)
    return t[idx][k];

      //defining values for all the three things present in events[start,end,value]
    int start = events[idx][0];
    int end = events[idx][1];
    int value = events[idx][2];

     // if we skip an event 
    int skip= solve(events, idx+1,k);

    //if we take the events
    int j=idx+1;
    for(;j<n;j++){
        if(events[j][0] >events[idx][1])//to compare the current event start with the end day
        break;
    }

    int take = value+solve(events,j, k-1);
    return t[idx][k] = max(skip,take);

}
    int maxValue(vector<vector<int>>& events, int k) {
        // sort the events on the basis of start day
        sort(begin(events),end(events));

        n=events.size();
        t.resize(n+1, vector<int>(k+1, -1));
        return solve(events,0,k);

    }
};
