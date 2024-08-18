class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>>minHeap;
        minHeap.push(1);
        unordered_set<long long>st;
        long long uglyNo = 1;

        while(st.size()<n){
            auto temp = minHeap.top();
            minHeap.pop();
            if(st.find(temp)==st.end()){
                st.insert(temp);
                minHeap.push(temp*2);
                minHeap.push(temp*3);
                minHeap.push(temp*5);
                uglyNo = temp;
            }
        }
        return uglyNo;
    }
};