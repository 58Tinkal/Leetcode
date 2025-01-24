class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>indegree(numCourses,0);
        queue<int>q;
        int S = 0;
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i])  indegree[it]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0)  q.push(i);
        }
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            S++;
            for(auto itt:adj[it]){
                indegree[itt]--;
                if(indegree[itt] == 0) q.push(itt);
            }
        }
        if(S == numCourses) return true;
        return false;
    }
};