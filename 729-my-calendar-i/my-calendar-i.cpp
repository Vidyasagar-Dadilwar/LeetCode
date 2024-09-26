class MyCalendar {
public:
    unordered_map<int, int> calender;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto it=calender.begin(); it!=calender.end(); it++){
            if(it->first < end && it->second > start){
                return false;
            }
        }
        calender[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */