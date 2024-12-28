#include <stdio.h>
#include <stdbool.h>

#define ROW 5
#define COL 5


//Déplacements possibles dans les 8 directions
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

//Vérifie si une cellule (x, y) est une cellule valide ou non visitée
bool isSafe(int m[ROW][COL], int row, int col, bool visited[ROW][COL]) {
    return (row >= 0) && (row < ROW) && 
           (col >= 0) && (col < COL) && 
           (m[row][col] == 1 && !visited[row][col]);
}

//Fonction DFS pour explorer une île
void DFS(int m[ROW][COL], bool visited[ROW][COL], int row, int col) {
    //Marquer la cellule comme visitée
    visited[row][col] = true;

    //Parcourir les 8 cellules adjacentes
    for (int k = 0; k < 8; k++) {
        //Si la cellule est valide et non visitée
        if (isSafe(m, row + dx[k], col + dy[k], visited)) {
            //Explorer l'île
            DFS(m, visited, row + dx[k], col + dy[k]);
        }
    }
}

//Compte le nombre d'îles dans la matrice
int countIslands(int m[ROW][COL]) {
    bool visited[ROW][COL] = {false};
    int count = 0;

    for (int i = 0; i < ROW;i++){
        for (int j = 0; j < COL; j++){
            if (m[i][j] ==1 && !visited[i][j]) {
                DFS(m, visited, i, j);
                count++;
            }
        }
    }
    return count;
}

int main() {
    int matrix[ROW][COL] = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };
    int cont = countIslands(matrix);
    printf("Nombre d'îles : %d\n", cont);
    return 0;
}