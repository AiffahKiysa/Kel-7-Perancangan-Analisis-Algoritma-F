#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
  
typedef pair<int, int> iPair;

void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void shortestPath(vector<pair<int,int> > adj[], int V, int src)
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

    vector<int> dist(V, INF);

    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
  
        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            
            //printf("v %d u %d dist[v] %d dist[u] %d weight %d\n", v, u, dist[v], dist[u], weight);
            if (dist[v] > dist[u] + weight)
            {
               //printf("updating\n");
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                //printf("updated v %d u %d dist[v] %d dist[u] %d weight %d\n", v, u, dist[v], dist[u], weight);
            }
        }
    }

    for (int i = 0; i < V; i++)
        (dist[i] == INF)? cout << "-1" << endl : cout << dist[i] << endl;
}

int main()
{
    int n, m;
    int a, b, dist;

    scanf("%d %d", &n, &m);
    vector<iPair> adj[n];
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &dist);
        addEdge(adj, a-1, b-1, dist);
    }
  
    shortestPath(adj, n, 0);
  
    return 0;
}