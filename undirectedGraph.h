#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "Graph.h"


class UndirectedGraph : public Graph
{
    private:
        void detectCycle(int src, vector<int> &parent, vector<bool> &visited, bool &cycle);
        int minKey(int key[], bool mstSet[]); 

    public:
        UndirectedGraph(int nodes) : Graph(nodes)
        {

        }

        virtual bool isCyclic();

        virtual void addEdge(int u, int v, long long w = 1)
        {
            adjacencyList[u].push_back({v, w});
            adjacencyList[v].push_back({u, w});
        }

        void findMST();

};

bool UndirectedGraph::isCyclic()
{
    if(numOfNodes <= 1)
        return false;
    vector<int> parent(numOfNodes + 1);
    vector<bool> visited(numOfNodes + 1, 0);
    bool cycle = 0;
    parent[1] = 1;
    detectCycle(1, parent, visited, cycle);
    return cycle;
}

void UndirectedGraph::
    detectCycle(int source, vector<int> &parent, vector<bool> &visited, bool &cycle)
{
   if(cycle)
      return;
   visited[source] = 1;
   for(auto neighbours : adjacencyList[source])
   {
       int neighbour = neighbours.first;
       if(visited[neighbour] && parent[source] != neighbour)
       {
          cycle = 1;
          return;
       }
       else if(!visited[neighbour])
       {
           parent[neighbour] = source;
           detectCycle(neighbour, parent, visited, cycle);
       }
   }
}

  

void UndirectedGraph:: findMST() 
{ 
    int V=numOfNodes;
    int graph[V][V];
    int INT_MAX=2147483647;

    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++ )
         graph[i][j]=0;
    

    for(int i=1;i<adjacencyList.size();i++)
        {       
            for(int j=0;j<adjacencyList[i].size();j++)
            {
                graph[i-1][adjacencyList[i][j].first-1] = adjacencyList[i][j].second;     
            }          
        }
    int parent[V];   
    int key[V]; 
    bool mstSet[V]; 
  
    for (int i = 0; i < V; i++) 
        key[i] = INT_MAX, mstSet[i] = false; 
  
    key[0] = 0; 
    parent[0] = -1; 
  
    for (int count = 0; count < V - 1; count++)
    {    
        int u = minKey(key, mstSet); 
  
        mstSet[u] = true; 
  
        for (int v = 0; v < V; v++) 
  

            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v]; 
    } 
    cout<<endl;
    cout<<"root node is 1"<<endl;
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]+1<<" - "<<i+1<<" \t"<<graph[i][parent[i]]<<" \n";
    cout<<endl;
} 
int UndirectedGraph:: minKey(int key[], bool mstSet[])  // helper function.
{ 
    int INT_MAX=2147483647;
    int min = INT_MAX, min_index; 
    int V=numOfNodes;
    for (int v = 0; v < V; v++) 
        if (mstSet[v] == false && key[v] < min) 
            min = key[v], min_index = v; 
  
    return min_index; 
}


#endif 