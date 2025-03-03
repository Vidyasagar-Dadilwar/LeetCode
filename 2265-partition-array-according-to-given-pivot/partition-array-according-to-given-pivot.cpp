class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> l, e, g;
        for(auto i: nums){
            if(i<pivot)
                l.push_back(i);
            else if(i == pivot)
                e.push_back(i);
            else if(i > pivot)
                g.push_back(i);
        }
        for(auto i: e)
            l.push_back(i);
        for(auto i: g)
            l.push_back(i);

        e.clear();g.clear();
        return l;
    }
};