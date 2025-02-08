class NumberContainers {
public:
    unordered_map<int, int>mp1;
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp2;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mp1[index] = number;
        mp2[number].push(index);
    }
    
    int find(int number) {
        if(!mp2.count(number))
            return -1;
        auto &pq = mp2[number];
        while(!pq.empty()){
            int ind = pq.top();
            if(mp1[ind] == number)
                return ind;
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */