#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> gridGraph;
typedef vector<vector<bool>> visitedGraph;


gridGraph read_grid_graph(int x, int y) {
    // Para añadir la "muralla" que impida salir de la zona
    gridGraph g(x + 2, vector<char>(y + 2, 'X'));

    for (int i = 1; i < x + 1; ++i) {
        for (int j = 1; j < y + 1; ++j) {
            // Yendo elemento a elemento dejando la muralla
            cin >> g[i][j];
        }
    }

    return g;
}


bool found(const gridGraph& g, visitedGraph& visited, int x, int y) {
    if (visited[x][y]) // Ya se ha visitado esta casilla
        return false;

    if (g[x][y] == 't') // Tesoro encontrado
        return true;
    if (g[x][y] == 'X') // Estamos en pared
        return false;
 
    visited[x][y] = true;

    if (found(g, visited, x, y + 1) or found(g, visited, x, y - 1) or
        found(g, visited, x + 1, y) or found(g, visited, x - 1, y))
        return true;

    return false;
}


int main() {
    int n, m;
    cin >> n >> m;

    gridGraph g = read_grid_graph(n, m);
    visitedGraph v(n + 2, vector<bool>(m + 2, false));
    
    cin >> n >> m;

    if (found(g, v, n, m))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
