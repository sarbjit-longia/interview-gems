//
//  dijkstra.h
//  Algorithms
//
//  Created by Sarbjit Singh on 5/16/16.
//  Copyright © 2016 Sarbjit Singh. All rights reserved.
//

#ifndef dijkstra_h
#define dijkstra_h

#define MAX_VERTEX	50
#define MAX_DEGREE	50

#include <queue>

class Dijkstra
{
public:
	Dijkstra()
	{
		memset(cost, 1000000, sizeof(int) * MAX_VERTEX);
		memset(parent, -1, sizeof(int) * MAX_VERTEX);
	}
	
	void InsertEdge(int x, int y, int weight, bool directed = true)
	{
		g_.edges[x][g_.degree[x]] = y;
		g_.degree[x]++;
		g_.weight[x][y] = weight;
		
		if(!directed)
		{
			InsertEdge(y, x, weight, true);
		}
		else
		{
			g_.nedges++;
		}
	}
	
	void solve(int s)
	{
		q_.push(s);
		memset(discovered, false, sizeof(bool) * MAX_VERTEX);
		memset(processed, false, sizeof(bool) * MAX_VERTEX);
		
		discovered[s] = true;
		
		while(q_.empty() == false)
		{
			int v = q_.front();
			q_.pop();
			processVertex(v);
			
			// Now process all the edges this node is connected to
			for(int i = 0; i < g_.degree[v]; i++)
			{
				int c = g_.edges[v][i];
				if(discovered[c]) continue;
				
				discovered[c] = true;
				
				if(cost[v] + g_.weight[v][c] < cost[c])
				{
					cost[c] = cost[v] + g_.weight[v][c];
					parent[c] = v;
				}
			}
		}
		
	}
	
	void processVertex(int v)
	{
		std::cout<<"Processing vertex:"<<v<<"\n";
		processed[v] = true;
	}
	
	void processEdge(int x, int y)
	{
		std::cout<<"Processing edge: "<<x<<", "<<y<<"\n";
	}
	
private:
	typedef struct graph_
	{
		int edges[MAX_VERTEX][MAX_DEGREE];
		int degree[MAX_VERTEX];
		int weight[MAX_VERTEX][MAX_DEGREE];
		int nedges;
	}graph;
	
	graph g_;
	int cost[MAX_VERTEX];
	int parent[MAX_VERTEX];
	std::queue<int>	q_;
	bool discovered[MAX_VERTEX];
	bool processed[MAX_VERTEX];
};

#endif /* dijkstra_h */
