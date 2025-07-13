//Time complexity: O(mlog m +n log n)
//Space complexity:O(1)

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(begin(players), end(players));
        sort(begin(trainers), end(trainers));

        int m=players.size();
        int n=trainers.size();

        int count=0;
        int i=0;
        int j=0;

        while(i<m && j<n){
            if(players[i] <= trainers[j]){
                i++;
                count++;
            }
            j++;
        }
        return count;

    }
};
