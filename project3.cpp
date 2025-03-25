/*
 * CSC-301
 * project3.cpp
 * Spring 2025
 *
 * Partner 1:
 * Partner 2:
 * Date:
 */

#include "project3.hpp"

using namespace std;

/* We are assuming that the order of the rates follows the order of the labels. 
   We decided to */

/*
 * createAdjacencyMatrix
 */
vector<double> createAdjacencyMatrix(vector<double> &rates, 
                                     vector<string> &currencies) {
    double n_rates = rates.size();
    vector<double> adjMatrix(n_rates);

    // Set adjacency values to be the -1 * the log of the rates
    for (double i = 0; i < n_rates; i++){
        double logRate = -1 * log10(rates[i]);
        adjMatrix[i] = logRate;
    }

    return adjMatrix;
}

/*
 * detectArbitrage
 */
vector<int> detectArbitrage(vector<double> &adjMatrix, 
                            vector<string> &currencies, 
                            double tol) {

    // Get the number of vertices and initialize the dist and prev values.
    int n = currencies.size();
    vector<double> distances( n, numeric_limits<double>::infinity() );
    vector<int> previous( n, -1 );
    
    // Run |V| - 1 iterations of Bellman-Ford, taking the tol value into account
    for(int h = 0; h < n -1; h++){
        // Bellman-Ford is these two inner for loops:
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // r * j + i or r * i + j
                if (distances[j] > distances[i] + adjMatrix[n * j + i] + tol){
                    // update neighbor's distance to the smaller value
                    distances[j] = distances[i] + adjMatrix[n * j + i];
                    // update neighbor's previous to the current vertex
                    previous[j] = i; 

                }    //   vector<int> cycle = sub(&maybe_cycle[loop_start],&maybe_cycle[loop_end]);
            }
        }
    }

                            }

    // Run extra iteraion of Bellman-Ford, and see if anything changes!
    int changed_vertex = -1;
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                // r * j + i or r * i + j
                if (distances[j] > distances[i] + adjMatrix[n * j + i] + tol){
                    // update changed_vertex to the neighbor we are about to update
                    changed_vertex = j;
                    // update neighbor's distance to the smaller value
                    distances[j] = distances[i] + adjMatrix[n * j + i];
                    // update neighbor's previous to the current vertex
                    previous[j] = i; 

                }
            }
    }

    // find the cycle, if there was a changed vertex
    if(changed_vertex > 0){
        vector<int> maybe_cycle;
        bool no_repeats = true; 
        int cur = changed_vertex;
        maybe_cycle.push_back(cur);
        int loop_start = -1;
        int loop_end = -1;
        while(no_repeats){
            cur = previous[cur];
            for(int elt : maybe_cycle){
                if(cur == elt){
                    //loop_start = elt;
                    //loop_end = cur;
                    no_repeats = false;
                }
            }

            maybe_cycle.push_back(cur);

    // Get negative loop from the elements in between (including) repeated elements


    // Return the cycle.
        return cycle;
    }

    vector<int> no_cycles = [-1];
    // Return [-1] if there is no cycle.
    return no_cycles;
}   