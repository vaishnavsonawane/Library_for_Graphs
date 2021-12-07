#include<iostream>
#include "Graph.h"
#include "undirectedGraph.h"
#include "DirectedGraph.h"
using namespace std;
int main()
{
  
    UndirectedGraph g1(9);

    DirectedGraph g2(7);

    g1.addEdge(1,9,4);
    g1.addEdge(9,7,8);
    g1.addEdge(1,2,8);
    g1.addEdge(1,7,11);
    g1.addEdge(7,6,1);
    g1.addEdge(7,8,7);
    g1.addEdge(2,8,2);
    g1.addEdge(8,6,6);
    g1.addEdge(2,3,7);
    g1.addEdge(2,5,4);
    g1.addEdge(6,5,2);
    g1.addEdge(3,5,14);
    g1.addEdge(3,4,9);
    g1.addEdge(5,4,10);

    g2.addEdge(1,4,5);
    g2.addEdge(1,2,3);
    g2.addEdge(3,1,2);
    g2.addEdge(3,4,3);
    g2.addEdge(4,3,1);
    g2.addEdge(2,3,8);
    g2.addEdge(1,5,4);
    g2.addEdge(5,7,3);
    g2.addEdge(7,6,5);
    g2.addEdge(6,5,1);

    g1.printGraph();
    g2.printGraph();

    cout<<"\n"<<g1.getNumberOfNodes()<<endl;
    cout<<g2.getNumberOfNodes()<<endl;

    cout<<g1.isCyclic()<<endl;
    cout<<g2.isCyclic()<<endl;

    vector<int>bfs = g2.breadthFirstTraversal(1);
    for(int i=0;i<bfs.size();i++)
    {
        cout<<bfs[i]<<" ";
    }
    cout<<endl;
    
    vector<int>dfs = g2.depthFirstTraversal(1);
    for(int i=0;i<dfs.size();i++)
    {
        cout<<dfs[i]<<" ";
    }
    cout<<endl;

    g2.shortestPath(1);
    g2.shortestPath(1,3);
    g1.shortestPath(8);

    vector<vector<int>> scc = g2.getStronglyConnectedComponents();
    cout<<"scc"<<endl;
    for(int i=0;i<scc.size();i++)
    {
        for(int j=0;j<scc[i].size();j++ )
        {
            cout<<scc[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    g1.findMST();





}

