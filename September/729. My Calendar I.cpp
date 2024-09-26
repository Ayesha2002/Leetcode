class MyCalendar {
public:
    unordered_map<int, int> um;
    MyCalendar() {
        // no need to do anything
    }
    
    bool book(int x, int y) {
        for(auto& val : um) {
            int a = val.first, b = val.second;

            if(!(y <= a || x >= b)) {
                return false;
            }
        }

        // If no overlap is found, book the interval
        um[x] = y;
        return true;
    }
};
