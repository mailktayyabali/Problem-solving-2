#include <iostream>
using namespace std;
int main() {
    const int V = 5;   // Number of vertices
    const int E = 4;   // Number of edges

    int adjMatrix[V][V] = {0}; // Initialize all elements to 0

    int u, v;

    cout << "Enter " << E << " edges (vertex pairs between 0 and 4):\n";

    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
