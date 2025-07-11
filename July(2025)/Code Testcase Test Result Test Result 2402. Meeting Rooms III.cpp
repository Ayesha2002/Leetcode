//Used min heaps
//Time complexity: O(m log n)
//Space complexity: O(n)


class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); // Sort meetings by start time

        vector<int> count(n, 0); // Booking counts
        priority_queue<int, vector<int>, greater<>> free; // Free rooms
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy; // (end_time, room)

        // Initially, all rooms are free
        for (int i = 0; i < n; ++i) {
            free.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            // Free up rooms that have finished before the current meeting starts
            while (!busy.empty() && busy.top().first <= start) {
                free.push(busy.top().second);
                busy.pop();
            }

            if (!free.empty()) {
                // Use the smallest-index free room
                int room = free.top(); free.pop();
                busy.emplace(end, room);
                count[room]++;
            } else {
                // No room is free, delay the meeting
                auto [available_time, room] = busy.top(); busy.pop();
                long long new_end = available_time + (end - start);
                busy.emplace(new_end, room);
                count[room]++;
            }
        }

        // Find room with the maximum bookings
        int max_room = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[max_room]) {
                max_room = i;
            }
        }

        return max_room;
    }
};
