#include<bits/stdc++.h>
using namespace std;
const int V=6;

int min_dist(int dist[], bool visited[], int n)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) 
    {
        if (visited[v] == false && dist[v] < min) 
            min = dist[v], min_index = v;
    }
    return min_index;
}

int print_MST(int from[], int cost[V][V], int n)
{
    int minCost = 0;
    for (int i = 1; i < n; i++) 
    {
		int y = from[i];
		minCost += cost[i][y];
    }
	return minCost;
}


void find_MST(int cost[V][V], int n)
{
    int from[n], dist[n], final[n];
    bool visited[n];

    for (int i = 0; i< n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[0] = 0;
    from[0] = -1;
    for (int x = 0; x < n - 1; x++)
    {
        int u = min_dist(dist, visited, n);
        visited[u] = true;
        for (int v = 0; v < n; v++)
        {
            if (cost[u][v] && visited[v] == false && cost[u][v] < dist[v])
            {
                from[v] = u;
                dist[v] = cost[u][v];
            }
        }
        u = min_dist(dist, visited, n);
        cout<<endl;
        cout<<"\t"<<from[u]<<" - "<<u<<"\t"<<cost[u][from[u]]<<endl;
    }
	cout<<"\tcost is:-"<<print_MST(from, cost, n)<<endl;
}

int main()
{
    int n, arr[V][V], m = 1, a, b, cost,src;
    cout<<"\n\tEnter the No. of vertices:\t";
    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = 0;

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
    find_MST(arr,n);
    return 0;
}