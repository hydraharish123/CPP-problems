// https://leetcode.com/problems/swim-in-rising-water/
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() ; 
        DisjointSet ds(n*n);

        vector<vector<int>> position(n*n);
        for(int row = 0 ; row<n ; row++){
            for(int col = 0 ; col<n ; col++){
                position[grid[row][col]] = {row,col};
            }
        }

        int drow[] = {-1,0,1,0};
        int dcol[] = {0,-1,0,1};

        for(int time = 0 ; time < n*n ; time++){
            int r = position[time][0];
            int c = position[time][1];

            for(int i = 0 ; i<4 ; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && grid[nrow][ncol] <= time){
                    ds.unionBySize(grid[r][c], grid[nrow][ncol]);
                }
            }

            if(ds.findUPar(grid[0][0]) == ds.findUPar(grid[n-1][n-1]))
                return time;
        }

        return -1;
    }
};