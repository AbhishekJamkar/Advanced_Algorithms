#include <bits/stdc++.h>
using namespace std;

void karger(int graph[4][4], vector<pair<int, int>> &edges, map<pair<int, int>, bool> &visited)
{
    map<pair<int, int>, bool> visitedEdge;
    int graph1[4][4];
    int count = 0;

    int randomNumber = rand() % 4;
    cout << "choosen edge " << edges[randomNumber].first << " " << edges[randomNumber].second << endl;
    int u = edges[randomNumber].first;
    int v = edges[randomNumber].second;

    if(visitedEdge[{u, v}] == false)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                count = 0;
                if(i == u && j == v)
                {
                    graph1[i][j] = graph1[j][i] = 0;
                }
                else if(i == u || i == v)
                {
                    if(graph[u][j] > 0)
                    {
                        count += graph[u][j];
                    }
                    if(graph[v][j] > 0)
                    {
                        count += graph[v][j];
                    }
                    graph1[u][j] = graph1[v][j] = count;
                }
                else if(j == u || j == v)
                {
                    if(graph[u][i] > 0)
                    {
                        count += graph[u][i];
                    }
                    if(graph[v][i] > 0)
                    {
                        count += graph[v][i];
                    }
                    graph1[i][u] = graph1[i][v] = count;
                }
                else
                {
                    graph1[i][j] = graph[i][j];
                }
            }
        }
        visitedEdge[{edges[randomNumber].first, edges[randomNumber].second}] = true;
    }

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i >= j)
            {
                graph1[i][j] = graph1[j][i];
            }
        }
    }

    int graph2[4][4];
    int row = 0, col = 0;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(i != v && j != v)
            {
                graph2[row++][col++] = graph1[i][j];
            }
        }
    }
    
}
int main()
{
    int graph[4][4] = {{0, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 0, 1}, {1, 1, 1, 0}} ;
    vector<pair<int, int>> edges;
    map<pair<int, int>, bool> visited;
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(graph[i][j] == 1 && visited[{i, j}] == false && visited[{j, i}] == false)
            {
                edges.push_back({i, j});
                visited[{i, j}] = true;
                visited[{j, i}] = true;
            }
        }
    }
    srand( time(NULL) );
    for(auto pairit : edges)
    {
        cout << "Edge : " << pairit.first << " " << pairit.second << endl;
    }

    karger(graph, edges, visited);
    
    
}

