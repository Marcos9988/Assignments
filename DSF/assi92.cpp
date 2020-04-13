#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

class graph
{
    int V, E;
    vector<pair<int, ipair>> edge;
public:
    graph(int a, int b)
    {
        V = a;
        E = b;
    }
    void addedge(int u, int v, int w)
    {
        edge.push_back({w, {u, v}});
    }
    int krushkal();
};
class disjoint
{
    int *rank, *parent;
    int n;
public:
    disjoint(int m)
    {
        n = m;
        parent = new int[m+1];
        rank = new int[m+1];
        for(int i = 0; i <= n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if(u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if(rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;
        if(rank[x] == rank[y])
            rank[y]++;
    }
};
int graph::krushkal()
{
    int mst = 0;
    sort(edge.begin(), edge.end());
    disjoint ds(V);
    vector<pair<int , ipair>> :: iterator itr;
    for(itr = edge.begin(); itr != edge.end(); itr++)
    {
        int u = itr->second.first;
        int v = itr->second.second;

        int setu = ds.find(u);
        int setv = ds.find(v);
        if(setu != setv)
        {
            cout<<"\t"<<u<<" - "<<v<<"\t"<<itr->first<<endl;
            mst += itr->first;
            ds. merge(setu, setv);
        }
    }
    return mst;
}
int main()
{
    int v, e;
    cout<<"\n\tEnter the No. of Vertices and edges:-\t";
    cin>>v>>e;
    graph g(v, e);
    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cout<<"\n\tEnter Edge between the vertices:-\t";
        cin>>u>>v;
        cout<<"\n\tEnter the weight of the edge:-\t";
        cin>>w;
        g.addedge(u, v, w);
    }
    cout<<"\n\tEdges of MST are:-\t"<<endl;
    int cost = g.krushkal();
    cout<<"\n\tWeight of MST is:-\t"<<cost;
}