/* P1: Flags for Mine Sweeper */

#include <stdio.h>
#include <stdlib.h>

void sweeper (char **map, int row, int col, char **ans){
    int count;

    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            count = 0;
            if ( *(*(map + i) + j) == '*')
                *(*(ans + i - 1) + j - 1) = 'F';
            else{
                if (map[i-1][j-1] == '*') count++;
                if (map[i-1][j] == '*') count++;
                if (map[i-1][j+1] == '*') count++;
                if (map[i][j-1] == '*') count++;
                if (map[i][j+1] == '*') count++;
                if (map[i+1][j-1] == '*') count++;
                if (map[i+1][j] == '*') count++;
                if (map[i+1][j+1] == '*') count++;
                
                ans[i-1][j-1] = count == 0 ? '-' : '0' + count;
            }
        }
    }
    
}

char **initMatrix(int row, int col){
    char **matrix = (char**)malloc(sizeof(char*) * row);
    
    if (matrix == NULL) {
        printf("Error:No space!\n");
        exit(0);
    }

    for (int i = 0; i < row; i++) {
        matrix[i] = (char*)malloc(sizeof(char) * col);
        if (matrix[i] == NULL) {
            printf("Error:No space!\n");
            exit(0);
        }
    }

    return matrix;
}

void freeMatrix(char **matrix, int row) {
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}

int main () {
    int m, n; // m:row  n:column 
    scanf("%d %d", &m, &n);

    //initialize Map matrix
    char **map = initMatrix(m + 2, n + 2); //in, add extra rows

    for (int j = 0; j <= n+1; j++) {
        map[0][j] = '.';
        map[m+1][j] = '.';
    }
    
    for (int i = 1; i <= m; i++) {
        map[i][0] = '.';
        scanf("%s\n", *(map + i) + 1);
        map[i][n+1] = '.';
    }

    //initialize ans matrix
    char **ans = initMatrix(m, n); //out

    //Calculate
    sweeper( map, m, n, ans );

    //Output
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%c", ans[i][j]);
        printf("\n");
    }
    
    //free
    freeMatrix(map, m + 2);
    freeMatrix(ans, m);

    return 0;
}