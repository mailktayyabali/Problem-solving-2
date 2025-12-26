#include <iostream>
using namespace std;

// Function to check if an edge exists
bool isEdge(int adjMatrix[][5], int u, int v) {
    return adjMatrix[u][v] == 1;
}

int main() {
    int vertices = 5;

    int adjMatrix[5][5] = {0};

    // Sample edges (undirected graph)
    adjMatrix[0][1] = 1;
    adjMatrix[1][0] = 1;

    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;

    adjMatrix[3][4] = 1;
    adjMatrix[4][3] = 1;

    int u, v;
    cout << "Enter two vertices to check edge: ";
    cin >> u >> v;

    if (isEdge(adjMatrix, u, v))
        cout << "Edge exists between " << u << " and " << v << endl;
    else
        cout << "No edge exists between " << u << " and " << v << endl;

    return 0;
}
