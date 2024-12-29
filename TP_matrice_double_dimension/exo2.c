#include <stdio.h>
#include <stdbool.h>


//Déplacements valides du plateau
int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

//Vérifie si une cellule (x, y) est une cellule valide ou non visitée
bool isValid(int x, int y, int N, int board[N][N], bool visited[N][N]) {
    return (x >= 0) && (x < N) &&
           (y >= 0) && (y < N) &&
           (board[x][y] == 0 && !visited[x][y]);
}

//Fonction DFS pour trouver le chemin le plus long
int findLongestPath(int x, int y, int N, int board[N][N], bool visited[N][N]) {
    visited[x][y] = true; //Marquer la cellule comme visitée
    int max = 0;

    //Parcourir les 4 cellules adjacentes
    for (int i = 0; i < 4; i++) {
        if (isValid(x + dx[i], y + dy[i], N, board, visited)) {
            int path = 1 + findLongestPath(x + dx[i], y + dy[i], N, board, visited);
            if (path > max) {
                max = path;
            }
        }
    }
    visited[x][y] = false; //Marquer la cellule comme non visitée
    return max;
}

//Trouver le chemin le plus long sur le plateau
int getLonguestPath(int N, int board[N][N]) {
    int maxPath = 0; 
    bool visited[N][N]; // Initialiser le tableau des visites
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                int path = findLongestPath(i, j, N, board, visited);
                if (path > maxPath) {
                    maxPath = path;
                }
            }
        }
    }
    return maxPath;
}

int main() {
    int N = 5; // Taille du plateau
    int board[5][5] = {
        {1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0}
    };

    printf("Le chemin le plus long est : %d\n", getLonguestPath(N, board));
    return 0;
}