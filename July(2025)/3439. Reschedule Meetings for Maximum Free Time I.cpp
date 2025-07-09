//Sliding Window problem
//Time complexity:O(nlogn)
//Space complexity:O(n)

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeArray;

        int n = startTime.size();
        if (n == 0) return eventTime; // no events = all time is free

        // Sort events by start time in case they're unsorted
        vector<pair<int, int>> events(n);
        for (int i = 0; i < n; i++) {
            events[i] = {startTime[i], endTime[i]};
        }
        sort(events.begin(), events.end());

        // Free time before the first event
        freeArray.push_back(events[0].first);

        // Free time between consecutive events
        for (int i = 1; i < n; i++) {
            int gap = events[i].first - events[i - 1].second;
            freeArray.push_back(max(0, gap)); // avoid negative gaps
        }

        // Free time after the last event
        freeArray.push_back(eventTime - events[n - 1].second);

        // Sliding window to sum any (k+1) free intervals
        int maxSum = 0, currSum = 0;
        int i = 0, j = 0, m = freeArray.size();

        while (j < m) {
            currSum += freeArray[j];
            if (j - i + 1 > k + 1) {
                currSum -= freeArray[i];
                i++;
            }
            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
};
