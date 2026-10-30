
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> g(n);

        for(auto &e : edges)
            g[e[0]].push_back({e[1], e[2]});

        vector<vector<long long>> d(n, vector<long long>(k+1, LLONG_MAX));

        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        d[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {
            auto [cost, u, cnt] = pq.top();
            pq.pop();

            if(cost != d[u][cnt]) continue;

            if(u == n-1) return cost;

            for(auto [v, w] : g[u]) {
                int c = (labels[u] == labels[v]) ? cnt+1 : 1;

                if(c > k) continue;

                if(cost + w < d[v][c]) {
                    d[v][c] = cost + w;
                    pq.push({cost+w, v, c});
                }
            }
        }

        return -1;
    }
};
