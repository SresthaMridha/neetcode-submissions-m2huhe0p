class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool> &visited, vector<bool> &visitedpath){

        //turn both vsisited and visisted path to true
        visited[node] = true;
        visitedpath[node] = true;

        for(auto x: adj[node]){
            if(!visited[x]){
                if(dfs(x, adj, visited, visitedpath)){
                    return true;
                }
            }
            else if(visitedpath[x]){
                return true;
            }
        }

        visitedpath[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create graph
        vector<vector<int>> adj(numCourses);
        for(auto x: prerequisites){
            int course = x[0];
            int prereq = x[1];

            adj[prereq].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> visitedpath(numCourses, false);

        for(int  i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfs(i, adj, visited, visitedpath)){
                    return false;
                }
            }
        }
        return true;

    }
};
