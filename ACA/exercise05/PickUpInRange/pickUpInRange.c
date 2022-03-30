/*example:
in:
4 1 10
4 1 -2 0 3
5 2 -4 2 1 8
4 0 0 10 0
3 0 18 0

first line:
    1st : number of rows
    2st and 3st : range

each line 1st number: number of elements of this row

out:
[1, 3]
[2, 1, 8]
[10]
[]
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void pickUpInRange (int **a, int row, int x, int y, int **ans){
    int count;
    int tmp[MAX];

    for (int i = 0; i < row; i++) {
        int size = a[i][0];
        count = 0;
        for (int j = 1; j <= size; j++)
            if (x <= a[i][j] && a[i][j] <= y)
                tmp[count++] = a[i][j];

        ans[i] = (int*)malloc(sizeof(int) * (count + 1));
        if (ans[i] ==NULL) {
            printf("Error:No space!\n");
            exit(0);
        }

        ans[i][0] = count;
        for (int j = 1; j <= count; j++) {
            ans[i][j] = tmp[j - 1];
        }
    }

}

void freeMatrix(int **matrix, int row) {
    for (int i = 0; i < row; i++)
        free(matrix[i]);
    free(matrix);
}

int main () {
    int row, x, y;
    scanf("%d %d %d",&row, &x, &y);

    int **a = (int**)malloc(sizeof(int*) * row);
    if (a == NULL) {
        printf("Error:No space!\n");
        exit(0);
    }

    for (int i = 0; i < row; i++) {
        int size;
        scanf("%d", &size);
        a[i] = (int*)malloc(sizeof(int) * (size + 1));
        if (a[i] == NULL) {
            printf("Error:No space!\n");
            exit(0);
        }

        a[i][0] = size;

        for (int j = 1; j <= size; j++)
            scanf(" %d", *(a + i) + j);
    }

    int **ans = (int**)malloc(sizeof(int*) * row);

    pickUpInRange(a, row, x, y, ans);

    for (int i = 0; i < row; i++) {
        int size = ans[i][0];
        printf("[");
        if ( size != 0 )
            printf("%d", ans[i][1]);
        
        for (int j = 2; j <= size; j++)
            printf(", %d",ans[i][j]);
        printf("]\n");
    }

    freeMatrix(a, row);
    freeMatrix(ans, row);

    return 0;
}