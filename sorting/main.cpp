//
//  main.cpp
//  Algorithms
//
//  Created by Sarbjit Singh on 4/23/16.
//  Copyright © 2016 Sarbjit Singh. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "dijkstra.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	//std::cout << "Hello, World!\n";
	
	Graph g;
	g.InsertEdge(0, 1);
	g.InsertEdge(0, 2);
	g.InsertEdge(2, 3);
	g.InsertEdge(3, 4);
	g.InsertEdge(4, 5);
	g.InsertEdge(2, 5);
	
	//g.bfs(0);
	g.dfs(0);

	
	Dijkstra d;
	d.InsertEdge(0, 1);
	d.InsertEdge(0, 2);
	d.InsertEdge(2, 3);
	d.InsertEdge(3, 4);
	d.InsertEdge(4, 5);
	d.InsertEdge(2, 5);
	
	d.solve(2);

	
    return 0;
}
