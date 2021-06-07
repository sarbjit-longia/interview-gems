// https://leetcode.com/problems/evaluate-division/
// Very good question that uses BFS for evaluation equation



class Solution {
public:

    struct Node{
        string destination;
        double weight;

        Node(string destination, double weight){
            this->destination = destination;
            this->weight = weight;
        }

    };

    // Storing Graph of vertex_1 -> [ {vertex_2, weight}, ...  ]
    unordered_map<string, vector<Node>> adjList;

    //BFS Search
    double evaluate(string source, string destination){

        unordered_map<string, bool> visited;
        queue<pair<string, double>> vertexQueue;

        //Adding source to our queue
        vertexQueue.push({source, 1.0});

        //Core BFS Logic
        while(!vertexQueue.empty()){

            pair<string, double> topVertex = vertexQueue.front();
            vertexQueue.pop();

            //Check Neighbours
            for(Node edge:adjList[topVertex.first]){

                if(!visited[edge.destination]){
                    visited[edge.destination] = true;

                    if(edge.destination==destination) // If we reach destination, return the weight.
                        return topVertex.second*edge.weight;


                    vertexQueue.push({edge.destination, topVertex.second*edge.weight});

                }

            }

        }
        // Even after BFS, if we can't locate/reach destination, return -1.0d
        return -1.0;

    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        vector<double> solution;


        //Creating graph of division
        for(int index = 0; index<equations.size(); index++){

            string source = equations[index][0];
            string destination = equations[index][1];
            double weight = values[index];


            adjList[source].push_back(Node(destination, weight));
            adjList[destination].push_back(Node(source, 1/weight));

        }

        for(vector<string> query:queries){

            string source = query[0];
            string destination = query[1];

            //Calling evaluate BFS on each source and destination from queries
            solution.push_back(evaluate(source, destination));

        }

        return solution;

    }
};
