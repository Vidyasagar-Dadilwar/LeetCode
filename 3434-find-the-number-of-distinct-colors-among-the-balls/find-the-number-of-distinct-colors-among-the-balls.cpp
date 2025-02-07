class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> m1;   
        unordered_map<int,int> m2;  
        vector<int> result;                 

        for(auto& arr : queries){
            int ball = arr[0];
            int currColor = arr[1];

            if(m1.find(ball) != m1.end()){
                int prevColor = m1[ball];
                m2[prevColor]--;        
                if(m2[prevColor] == 0)  
                    m2.erase(prevColor);
            }
            m1[ball] = currColor;    
            m2[currColor]++;        
            result.push_back(m2.size());
        }
        m1.clear();
        m2.clear();
        return result;
    }
};