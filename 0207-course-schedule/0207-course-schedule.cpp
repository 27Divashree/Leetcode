class Solution {
public:
    bool DFS(int src,vector<bool>& rec,vector<int> adj[],vector<bool>& vis)
    {
        vis[src] = true;
        rec[src] = true;
        
        for(int &u:adj[src])
        {
            if(vis[u]==false)
            {
                if(DFS(u,rec,adj,vis))
                    return true;
            }
            else if(rec[u])
                return true;
        }
        rec[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        //visited array
        vector<bool> vis(numCourses,false);
        vector<bool> rec(numCourses,false);
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==false)
            {
                if(DFS(i,rec,adj,vis))
                    return false;
            }
        }

        return true;
    }
};