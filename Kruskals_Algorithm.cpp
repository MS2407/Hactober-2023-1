class DSU{
    public:
    vector<int> parent,rank;
    int n;
    DSU(int _n){
        n = _n;

        parent.resize(n,0);
        rank.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    void unionn(int u,int v){
        int parent_u = findParent(u);
        int parent_v = findParent(v);

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        else{
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }

    }
};
