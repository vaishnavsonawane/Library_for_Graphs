#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <queue>
#include<iostream>
#define INFINITY 9999
using namespace std;


using namespace std;
class Graph
{
    protected:
        
        int numOfNodes;
        
        vector<vector<pair<int,long long>>> adjacencyList;
        void dfsHelper(int source, vector<int> &nodesDiscovered, vector<bool> &vis);
        

    public:
        Graph(int nodes)
        {
            numOfNodes = nodes;
            adjacencyList = vector<vector<pair<int,long long>>>(nodes+1);
        }
        virtual void addEdge(int u, int v, long long weight) = 0;
        virtual bool isCyclic() = 0;
        vector<int> breadthFirstTraversal(int source);
        vector<int> depthFirstTraversal(int source);
        
        void shortestPath(int startnode);
        void shortestPath(int startnode,int destination);  //Dijkstras
        
        int getNumberOfNodes()
        {
            return numOfNodes;
        }

        void printGraph()
        {
            cout<<"Printing Graph:"<< endl;
            for(int i=1;i<adjacencyList.size();i++)
            {
                cout<<i<<" --->";
                for(int j=0;j<adjacencyList[i].size();j++)
                {
                    cout<<"  ( "<<adjacencyList[i][j].first<<","<<adjacencyList[i][j].second<<")";
                }
                cout<<endl;
            }
            cout<<endl;
        }
   
};

vector<int> Graph::breadthFirstTraversal(int source)
{
    vector<int> nodesDiscovered;
    queue<int> nodesToExplore;
    vector<bool> visited(numOfNodes+1, 0);

    nodesToExplore.push(source);
    visited[source] = true;

    while(!nodesToExplore.empty())
    {
       int explore = nodesToExplore.front();
       nodesToExplore.pop();
       nodesDiscovered.push_back(explore);

       for(pair<int,long long> neighbours : adjacencyList[explore])
       {
           int neighbour = neighbours.first;
           if(!visited[neighbour])
           {
               visited[neighbour] = 1;
               nodesToExplore.push(neighbour);
           }
       }
    }
    return nodesDiscovered;
}

void Graph::dfsHelper(int source,vector<int> &nodesDiscovered, vector<bool> &vis)
{
    vis[source] = 1;
    nodesDiscovered.push_back(source);

    for(pair<int,long long> neighbours : adjacencyList[source])
       {
           int neighbour = neighbours.first;
           if(!vis[neighbour])
           {
               dfsHelper(neighbour, nodesDiscovered, vis);
           }
       }
}

vector<int> Graph::depthFirstTraversal(int source)
{
      vector<int> nodesDiscovered;
      vector<bool> vis(numOfNodes + 1, 0);
      dfsHelper(source, nodesDiscovered, vis);
      return nodesDiscovered;
}



void Graph::shortestPath(int startnode) {
   startnode--;
   int n=numOfNodes; 
   int G[numOfNodes][numOfNodes], cost[numOfNodes][numOfNodes],distance[numOfNodes],pred[numOfNodes];
   int visited[numOfNodes],count,mindistance,nextnode,i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++ )
         G[i][j]=0;


    for(i=1;i<adjacencyList.size();i++)
        {       
            for(j=0;j<adjacencyList[i].size();j++)
            {
                G[i-1][adjacencyList[i][j].first-1] = adjacencyList[i][j].second;     
            }          
        }
        

   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   count=1;
   while(count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   cout<<endl;
   cout<<"Source node is "<<startnode+1;
   for(i=0;i<n;i++)
   if(i!=startnode) {
    if(distance[i]==INFINITY)
    {
      cout<<"\nDistance of node"<<i+1<<"= Infinity"; 
      cout<<"\nNO path available";
      continue; 
    }    
      cout<<"\nDistance of node"<<i+1<<"="<<distance[i];
      cout<<"\nPath="<<i+1;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j+1;
      }while(j!=startnode);
   }
cout<<endl;
cout<<endl;

}



void Graph::shortestPath(int startnode, int destination) {
   startnode--;
   int n=numOfNodes; 
   int G[numOfNodes][numOfNodes], cost[numOfNodes][numOfNodes],distance[numOfNodes],pred[numOfNodes];
   int visited[numOfNodes],count,mindistance,nextnode,i,j;
    
    for(i=0;i<n;i++)
        for(j=0;j<n;j++ )
         G[i][j]=0;


    for(i=1;i<adjacencyList.size();i++)
        {       
            for(j=0;j<adjacencyList[i].size();j++)
            {
                G[i-1][adjacencyList[i][j].first-1] = adjacencyList[i][j].second;     
            }          
        }
        

   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
   if(G[i][j]==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=G[i][j];
   for(i=0;i<n;i++) {
      distance[i]=cost[startnode][i];
      pred[i]=startnode;
      visited[i]=0;
   }
   distance[startnode]=0;
   visited[startnode]=1;
   count=1;
   while(count<n-1) {
      mindistance=INFINITY;
      for(i=0;i<n;i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<n;i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }
   cout<<endl;
   cout<<"Source node is "<<startnode+1;
   
   i=destination-1;
   if(i!=startnode) {
    if(distance[i]==INFINITY)
    {
      cout<<"\nDistance of node"<<i+1<<"= Infinity"; 
      cout<<"\nNO path available";
       
    }
    else{    
      cout<<"\nDistance of node"<<i+1<<"="<<distance[i];
      cout<<"\nPath="<<i+1;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j+1;
      }while(j!=startnode);}
   }
cout<<endl;
cout<<endl;

}

#endif // GRAPH_H