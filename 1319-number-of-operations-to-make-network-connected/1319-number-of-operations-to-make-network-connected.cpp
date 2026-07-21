class Solution {
    vector<int> parent,size;
    void DisjointSet(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findpar(parent[node]);
    }
    bool find(int u, int v) {
        return findpar(u)==findpar(v);
    }
    void unionBySize(int u, int v) {
        int ultu=findpar(u),ultv=findpar(v);
        if(ultu==ultv) return;
        if (size[ultu] < size[ultv]) {
            parent[ultu] = ultv;
            size[ultv] += size[ultu]; 
        } 
        else {
            parent[ultv] = ultu;
            size[ultu] += size[ultv]; 
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        DisjointSet(n);
        for(int i=0;i<connections.size();i++){
            unionBySize(connections[i][0],connections[i][1]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(findpar(i) == i) count++;
        }
        return count-1;
    }
};