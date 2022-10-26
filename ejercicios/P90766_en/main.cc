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


void found(const gridGraph& g, visitedGraph& visited, int x, int y, int& t) {
    if (visited[x][y] or g[x][y] == 'X') // Ya se ha visitado esta casilla o es pared
        return;

   if (g[x][y] == 't') // Tesoro encontrado
        ++t;    
 
    visited[x][y] = true;

    found(g, visited, x, y + 1, t);
    found(g, visited, x, y - 1, t);
    found(g, visited, x + 1, y, t);
    found(g, visited, x - 1, y, t); 
}


int main() {
    int n, m;
    cin >> n >> m;

    gridGraph g = read_grid_graph(n, m);
    visitedGraph v(n + 2, vector<bool>(m + 2, false));
   
    int t = 0;

    cin >> n >> m;

    found(g, v, n, m, t);
    
    cout << t << endl;
}
