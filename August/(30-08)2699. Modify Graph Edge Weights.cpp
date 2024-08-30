class Solution {
public:
    int dijkstra(int source, int destination, vector<vector<pair<int, int>>> &adj){
        vector<int> dist(adj.size(), INT_MAX);
        dist[source] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // {dist, node}
        pq.push({0, source});
        while (!pq.empty()){
            auto front = pq.top(); 
            pq.pop(); 
            int node = front.second;
            // int currdist = front.first; 
            for (auto it: adj[node]){
                int neigh = it.first; 
                int nwt = it.second; 
                if (dist[node] + nwt < dist[neigh]){
                    dist[neigh] = dist[node] + nwt; 
                    pq.push({dist[neigh], neigh});
                }
            }
        }
        return dist[destination];
    }

    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        // first we will find the distance b/w source and destination without considering the negative edges
        // if the distance comes out to be less than target then return empty list
        // else now we will pick negative edges 1 by one and add it to the graph and apply shortest distance algo (dijkstra) and find the shortest distance if it comes out to be less than target than just update the value of the edge picked and do it for all the edges 
        // agar abhi tak nhi mila toh return empty list 

        // main intuition or though process was that: we should first not consider the negative edges and add them one by one

        vector<vector<pair<int, int>>> adj(n); 
        for (auto it: edges){
            int wt = it[2]; 
            if (wt == -1) continue; 
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        // now apply dijkstra
        int shortestPath = dijkstra(source, destination, adj);
        if (shortestPath < target){
            return {};
        }
        if (shortestPath == target){
            for (int i = 0; i<edges.size(); i++){
                int wt = edges[i][2];
                if (wt == -1){
                    edges[i][2] = 1e9; 
                }
            }
            return edges; 
        }

        for (int i = 0; i<edges.size(); i++){
            int wt = edges[i][2];
            if (wt == -1){
                edges[i][2] = 1;
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back({v, 1});
                adj[v].push_back({u, 1}); 
                int shortestPath = dijkstra(source, destination, adj);
                if (shortestPath <= target){
                    edges[i][2] += (target - shortestPath);
                    for (int j = 0; j<edges.size(); j++){
                        int wt = edges[j][2];
                        if (wt == -1){
                            edges[j][2] = 1e9; 
                        }
                    }
                    return edges;
                }
            }
        }

        return {};

    }
};
