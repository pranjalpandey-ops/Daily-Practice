class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        set<int> s(a.begin(), a.end()), r;
        
        for(int x : b)
            if(s.count(x))
                r.insert(x);
        
        return vector<int>(r.begin(), r.end());
    }
};