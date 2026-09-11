class Solution {
public:
    int totalNumbers(vector<int>& d) {
        set<int> s;
        int n = d.size();

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++) {
                    if(i==j || j==k || i==k) continue;
                    if(d[i]==0 || d[k]%2!=0) continue;

                    s.insert(d[i]*100+d[j]*10+d[k]);
                }

        return s.size();
    }
};