#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int display(int dist[],int n, int par[])
{
	cout<<"Vertex \t\t Distance \tParent\n";
	for (int i=1; i<=n; i++)
		cout<<i<<" \t\t "<<dist[i]<<" \t\t "<<par[i]<<endl;
}
int minDistance(int dist[], bool visited[],int n)
{
    int min=INT_MAX,min_index;
    for (int v=0; v<n; v++)
    {
        if (visited[v]==false && dist[v]<=min)
            min=dist[v], min_index=v;
    }
    return min_index;
}
void dijisktra(int v[N][N],int s,int n)
{
    int dist[n], par[n];
    bool visited[n]={0};
    dist[s]=0;
    for(int i = 1; i <= n; i++)
    {
        if(i != s) 
            dist[i] = INT_MAX;
    }
    for(int count = 1; count < n; count++)
    {
        int u = minDistance(dist, visited, n);
        visited[u] = true;
        for(int i = 1; i <= n; i++)
        {
            if (!visited[i] && v[u][i] && dist[u] != INT_MAX && dist[u] + v[u][i] < dist[i])
                {
                    dist[i] = dist[u] + v[u][i];
                    par[i] = u;
                }
        }
    }
    display(dist, n, par);
}
int main()
{
    int n, arr[N][N], m = 1, a, b, cost,src;
    cout<<"\n\tEnter the No. of vertices:\t";
    cin>>n;
    for(int i = 1; i <= n+1; i++)
        for(int j = 1; j <= n+1; j++)
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
    cout<<"\n\tCost matrix is :\t";
    for(int i = 1;i <= n + 1; i++)
    {
        cout<<"\n";
        for(int j = 1;j <= n+1; j++)
            cout<<"\t"<<arr[i][j];
    }
    cout<<"\n\tFrom WHere you want to find the minimum dstance:\t";
    cin>>src;
    dijisktra(arr,src,n+1);
	return 0;
}