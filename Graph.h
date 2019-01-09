//
//  Graph.h
//  Algorithms
//
//  Created by Sarbjit Singh on 4/23/16.
//  Copyright © 2016 Sarbjit Singh. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#define MAX_DEGREE	50
#define MAX_VERTEX	100

#include <queue>
#include <iostream>
#include <stack>

using namespace std;

typedef struct graph_t_
{
	int edges[MAX_VERTEX][MAX_DEGREE];
	int degree[MAX_VERTEX];
	int num_vertex;
	int num_edges;
}graph_t;

class Graph
{
public:
	Graph()
	{
		memset(&graph_, 0, sizeof(graph_));
		memset(parent, -1, sizeof(int) * MAX_VERTEX);
	}
	
	void InsertEdge(int x, int y, bool directed = true)
	{
		graph_.edges[x][graph_.degree[x]] = y;
		graph_.degree[x]++;
		graph_.num_vertex++;
		
		if(!directed)
		{
			InsertEdge(y, x);
		}
		else
		{
			graph_.num_edges++;
		}
	}
	
	void bfs(int start)
	{
		q.push(start);
		discovered[start] = true;
		
		while(!q.empty())
		{
			int v = q.front();
			q.pop();
			processed[v] = true;
			
			process_vertex(v);
			for(int i = 0 ; i < graph_.degree[v]; i++)
			{
				if(discovered[graph_.edges[v][i]] == false)
				{
					discovered[graph_.edges[v][i]] = true;
					q.push(graph_.edges[v][i]);
					parent[graph_.edges[v][i]] = v;
				}
			}
		}
	}
	
	void dfs(int start)
	{
		s.push(start);
		discovered[start] = true;
		
		while(!s.empty())
		{
			int v = s.top();
			s.pop();

			processed[v] = true;
			
			process_vertex(v);
			for(int i = 0 ; i < graph_.degree[v]; i++)
			{
				if(discovered[graph_.edges[v][i]] == false)
				{
					discovered[graph_.edges[v][i]] = true;
					s.push(graph_.edges[v][i]);
					parent[graph_.edges[v][i]] = v;
				}
			}
		}
	}
	
	void process_vertex(int v)
	{
		cout<<"Proessing vertex: " <<v <<"\n";
	}
	
private:
	graph_t		graph_;
	bool		processed[MAX_VERTEX];
	bool		discovered[MAX_VERTEX];
	int			parent[MAX_VERTEX];
	std::queue<int>	q;
	std::stack<int>	s;
	
};


#endif /* Graph_h */
