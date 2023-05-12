#include <iostream>
#include <chrono>
#include <iomanip>

#include "prim.h"
#include "kruskal.h"

using namespace std;

void functions(void (*f)(int), int target) {
    auto start_timer = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    f(target);

    auto end_timer = chrono::high_resolution_clock::now();

    double time_taken =
            chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

    time_taken *= 1e-9;
    cout << " " << time_taken << setprecision(4) << endl;
}

int main() {
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
    }

//    int graph[V][V] = { {0, 2, 0},
//                        {2, 0, 8},
//                        {0, 8, 0} };

//    int graph[V][V] = { {0, 1, 5, 0, 8},
//                        {1, 0, 7, 3, 0},
//                        {5, 7, 0, 11, 3},
//                        {0, 3, 11, 0, 6},
//                        {8, 0, 3, 6, 0} };

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


    cout << "PRIM" << endl;
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        primMST(graph);

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
        cout << " " << time_taken << setprecision(4) << endl;
    }

    Graph g(V);
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0)
                g.addEdge(i, j, graph[i][j]);
        }
    }

    cout << "KRUSKAL" << endl;
    {
        auto start_timer = chrono::high_resolution_clock::now();
        ios_base::sync_with_stdio(false);

        g.kruskals_mst();

        auto end_timer = chrono::high_resolution_clock::now();

        double time_taken =
                chrono::duration_cast<chrono::nanoseconds>(end_timer - start_timer).count();

        time_taken *= 1e-9;
        cout << " " << time_taken << setprecision(4) << endl;
    }
}