typedef vector<vector<int>> graph;
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraphs(numCourses, prerequisites);
        vector<int> indegrees = computeIndegrees(g);
        queue<int> q;
        vector<int> orders;
        for(int i=0;i<numCourses;i++){
            if(indegrees[i]==0) q.push(i);
        }
        int count =0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            orders.push_back(v);
            count++;
            for(int u:g[v]){
                if(!(--indegrees[u])) q.push(u);
            }
        }
        if(count>=numCourses) return orders;
        else return {};
    }
private:
    graph buildGraphs(int numCourses, vector<pair<int,int>>& prerequisites){
        graph g(numCourses);
        for(auto p:prerequisites){
            g[p.second].push_back(p.first);
        }
        return g;
    }

    vector<int> computeIndegrees(graph& g){
        vector<int> degrees(g.size(),0);
        for(auto adj:g){
            for(int v:adj){
                degrees[v]++;
            }
        }
        return degrees;
    }