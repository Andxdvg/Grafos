#include <iostream>
#include <cstring> // Para inicializar arreglos con memset

using namespace std;

const int MAX = 100; // Máximo número de nodos que puede tener el grafo

class Grafo {
private:
    int adj[MAX][MAX]; // Matriz de adyacencia para almacenar las conexiones
    int V;             // Número de nodos (vértices)

public:
    // Constructor: inicializa el grafo con un número de nodos
    Grafo(int vertices) {
        V = vertices;
        memset(adj, 0, sizeof(adj)); // Inicializamos la matriz con ceros (sin conexiones)
    }

    // Método para agregar una conexión (arista) entre dos nodos
    void agregarArista(int u, int v) {
        adj[u][v] = 1; // Conexión de u a v
        adj[v][u] = 1; // Conexión de v a u (porque es un grafo no dirigido)
    }

    // Método para mostrar la matriz de adyacencia
    void mostrarGrafo() {
        cout << "Matriz de adyacencia:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Método para realizar una búsqueda en profundidad (DFS)
    void DFS(int inicio) {
        bool visitado[MAX]; // Arreglo para marcar los nodos visitados
        memset(visitado, false, sizeof(visitado)); // Inicializamos todos los nodos como no visitados
        int pila[MAX]; // Usamos un arreglo como pila
        int tope = -1; // La pila está vacía al inicio

        // Empujamos el nodo inicial a la pila
        pila[++tope] = inicio;

        cout << "Recorrido DFS: ";
        while (tope >= 0) {
            int nodo = pila[tope--]; // Sacamos el nodo del tope de la pila

            if (!visitado[nodo]) {
                cout << nodo << " "; // Visitamos el nodo
                visitado[nodo] = true;
            }

            // Agregamos los vecinos no visitados a la pila
            for (int i = V - 1; i >= 0; i--) {
                if (adj[nodo][i] == 1 && !visitado[i]) {
                    pila[++tope] = i;
                }
            }
        }
        cout << endl;
    }

    // Método para realizar una búsqueda en amplitud (BFS)
    void BFS(int inicio) {
        bool visitado[MAX]; // Arreglo para marcar los nodos visitados
        memset(visitado, false, sizeof(visitado)); // Inicializamos todos los nodos como no visitados
        int cola[MAX]; // Usamos un arreglo como cola
        int frente = 0, final = 0; // La cola está vacía al inicio

        // Encolamos el nodo inicial
        cola[final++] = inicio;
        visitado[inicio] = true;

        cout << "Recorrido BFS: ";
        while (frente < final) {
            int nodo = cola[frente++]; // Sacamos el nodo del frente de la cola
            cout << nodo << " "; // Visitamos el nodo

            // Agregamos los vecinos no visitados a la cola
            for (int i = 0; i < V; i++) {
                if (adj[nodo][i] == 1 && !visitado[i]) {
                    cola[final++] = i;
                    visitado[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Creamos un grafo con 7 nodos (numerados del 0 al 6)
    Grafo grafo(7);

    // Agregamos conexiones (aristas) entre los nodos
    grafo.agregarArista(0, 1);
    grafo.agregarArista(0, 2);
    grafo.agregarArista(1, 3);
    grafo.agregarArista(1, 4);
    grafo.agregarArista(2, 5);
    grafo.agregarArista(2, 6);

    // Mostramos la matriz de adyacencia
    grafo.mostrarGrafo();

    // Realizamos los recorridos
    cout << endl;
    grafo.DFS(0); // Búsqueda en profundidad desde el nodo 0
    grafo.BFS(0); // Búsqueda en amplitud desde el nodo 0

    return 0;
}