#include<bits/stdc++.h>
using namespace std;

int parent[10];
int find(int x)
{
    while(parent[x] != x)
        x = parent[x];
    return x;
}

void cycle(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void krushkal(int cost[][10], int vertex)
{
    int mincost = 0;
    for(int i = 0; i < vertex; i++)
        parent[i] = i;

    int edgecount = 0;
    while (edgecount < vertex - 1)
    {
        int mini = INT_MAX, a = -1, b = -1;
        for(int i = 0; i < vertex; i++)
            for(int j = 0; j < vertex; j++)
            {
                if(find(i) != find(j) && cost[i][j] < mini)
                {
                    mini = cost[i][j];
                    a = i, b=j;
                }
            }
        cycle(a,b);
        cout<<"\tEDGES: "<<a<<" - "<<b<<" COST: "<<mini<<endl;
        edgecount++;
        mincost += mini;
    }
    cout<<"\n\tMINIMUM COST IS:\t"<<mincost<<endl;
}

int main()
{
    int n, arr[10][10], m = 1, a, b, cost,src;
    cout<<"\n\tEnter the No. of vertices:\t";
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = INT_MAX;

    while(m)
    { 
        cout<<"\n\tEnter the Vertices B/w which Edge is Present:\t";
        cin>>a>>b;
        cout<<"\n\tEnter the Weight of Edge:\t";
        cin>>cost;
        arr[a][b]=cost;
        arr[b][a]=cost;
        cout<<"\n\tWant to Continue(1) else(0)\t";
        cin>>m;
    }
    krushkal(arr,n);
    return 0;
}