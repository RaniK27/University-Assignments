#include<bits/stdc++.h>
using namespace std;

class Traversal
{
    public:
    void dfs(int idx, vector<vector<int>> &graph, int vis[])
    {
        cout << idx << " ";
        vis[idx] = true;
        int n = graph[idx].size();
        
        for(int i = 0; i < n; i++)
        {
            if(graph[idx][i] == 1 && vis[i] == 0)
            {
                dfs(i, graph, vis);
            }
        }
    }

    void bfs(vector<vector<int>> & graph, int vis[], queue<int> &q)
    {
        if(q.empty())
            return;
        int node = q.front();
        q.pop();
        cout << node << " ";
        int n = graph[node].size();
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
            {
                vis[i] = true;
                q.push(i);
            }
        }
        bfs(graph, vis, q);
    }  
};



int main()
{ 
    int n, e;
    Traversal t; 
    cout <<"Please enter the number of nodes in graph: ";
    cin >> n; 
    cout <<"\nPlease enter the of edges in graph: ";
    cin>> e;
    vector<vector<int>> graph(n, vector<int>(n, 0))
    for(int i = 0; i < e; i++)
    {
        int u, v;
        cout << "Enter source and destination nodde: ";
        cin >> u >> v;
        //unidirectional graph
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    cout << "\nAdjacency Matrix: \n";
    cout << "        ";
    for(int i = 0; i <n ; i++)
        cout << i << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "node " << i << ": ";
        for(int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    
    int choice;
    
    do
    {
        cout <<"\n1.DFS\n2.BFS\n3.Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch(choice)
        {
            case 1:
                {int start;
                cout << "Enter start node: ";
                int vis1[n] = {0};
                cin >> start;
                cout << "\nDFS of the graph: ";
                t.dfs(start, graph, vis1);
                break;}
                
            case 2:
                {int start;
                cout << "Enter start node: ";
                cin >> start;
                int vis2[n] = {0};
                queue<int> q;
                q.push(start);
                vis2[start] = 1;
                cout << "\nBFS of the graph: ";
                t.bfs(graph, vis2, q);
                break;}
            
            case 3:
                exit(0);  
            default:
                break;
        }
    }while(choice != 3);
    
    return 0;
}
