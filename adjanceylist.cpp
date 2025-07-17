#include <iostream>
using namespace std;

class Graph {
private:
    int V;
    int adjMatrix[100][100]; 

public:
    
    Graph(int vertices) {
        V = vertices;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adjMatrix[i][j] = 0;
    }

    
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    void removeEdge(int u, int v) {
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main() {
    Graph g(5); 

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    }
