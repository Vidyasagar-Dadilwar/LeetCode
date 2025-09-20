class Router {
public:
    int size;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> counts;
    queue<long long> q;
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key = ((long long)source << 40) | ((long long)destination << 20) | timestamp;

        if(packets.find(key) != packets.end())
            return false;
        
        if((int)packets.size() >= size)
            forwardPacket();
        
        packets[key] = {source, destination, timestamp};
        q.push(key);
        counts[destination].push_back(timestamp);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(packets.empty())
            return {};
        long long key = q.front();
        q.pop();
        vector<int> packet = packets[key];
        packets.erase(key);

        int dest = packet[1];
        counts[dest].erase(counts[dest].begin());
        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = counts.find(destination);
        if(it == counts.end() || it->second.empty())
            return 0;
        vector<int>& list = it->second;
        int lb = (int)(lower_bound(list.begin(), list.end(), startTime) - list.begin());
        int ub = (int)(upper_bound(list.begin(), list.end(), endTime) - list.begin());
        return ub - lb;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */