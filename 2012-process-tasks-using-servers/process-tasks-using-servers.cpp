
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> available;

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;

        for (int i = 0; i < servers.size(); i++) {
            available.push({servers[i], i});
        }

        vector<int> answer;
        long long time = 0;

        for (int i = 0; i < tasks.size(); i++) {
            time = max(time, (long long)i);

            while (!busy.empty() && busy.top()[0] <= time) {
                available.push({busy.top()[1], busy.top()[2]});
                busy.pop();
            }

            if (available.empty()) {
                time = busy.top()[0];

                while (!busy.empty() && busy.top()[0] <= time) {
                    available.push({busy.top()[1], busy.top()[2]});
                    busy.pop();
                }
            }

            auto server = available.top();
            available.pop();

            answer.push_back(server.second);

            busy.push({
                time + tasks[i],
                server.first,
                server.second
            });
        }

        return answer;
    }
};
