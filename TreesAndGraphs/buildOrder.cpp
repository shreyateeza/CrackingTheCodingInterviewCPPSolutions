// https://leetcode.com/problems/course-schedule-ii/solutions/6222344/kahn-s-algorithm-bfs-topological-sorting-approach/ 

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses], indegree(numCourses, 0), result;
        queue<int> q;
        int count = 0;
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            count++; 
            result.push_back(temp);
            for(int i=0; i<adj[temp].size(); i++){
                if(--indegree[adj[temp][i]] == 0) q.push(adj[temp][i]);
            }
        }
        if(numCourses == count) return result;
        return {};        
    }
};