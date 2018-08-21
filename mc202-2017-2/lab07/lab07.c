#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_matrix(char **M, int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", M[i][j]);
        }
        printf("\n");
    }
}

int find_path(char **M, char **map, int rows, int cols, int i_start, int j_start, int i_end, int j_end) {
    /* review index */
    if (i_start < 0 || i_start >= rows || j_start < 0 || j_start >= cols) return 0;
    /* review if possible walk  */
    if (M[i_start][j_start] == 'X') return 0;

    /* Backtrack mark */
    M[i_start][j_start] = 'X';
    map[i_start][j_start] = '*';

    /* if start == end  finish */
    if (i_start == i_end && j_start == j_end) return 1;

    /* left */
    if (find_path(M, map, rows, cols, i_start, j_start-1, i_end, j_end) == 1) return 1;
    /* up */
    if (find_path(M, map, rows, cols, i_start - 1, j_start, i_end, j_end) == 1) return 1;
    /* right */
    if (find_path(M, map, rows, cols, i_start, j_start + 1, i_end, j_end) == 1) return 1;
    /* down */
    if (find_path(M, map, rows, cols, i_start + 1, j_start, i_end, j_end) == 1) return 1;


    /* Backtrack unmark */
    M[i_start][j_start] = 'O';
    map[i_start][j_start] = ' ';

    return 0;
}

int main(int argc, char const *argv[]) {
    int rows, cols, i_start, j_start, i_end, j_end, i;

    char **M, **map;

    scanf("%d %d %d %d %d %d", &rows, &cols, &i_start, &j_start, &i_end, &j_end);

    M = (char **)malloc(rows * sizeof(char *));
    map = (char **)malloc(rows * sizeof(char *));
    for (i = 0; i < rows; i++) {
        M[i] = (char *)malloc((cols + 1) * sizeof(char));
        map[i] = (char *)malloc(cols * sizeof(char));

        memset(map[i], ' ', cols);

        scanf("%s", M[i]);

    }

    find_path(M, map, rows, cols, i_start, j_start, i_end, j_end);

    print_matrix(map, rows, cols);

    for (i = 0; i < rows; i++) {
        free(M[i]);
        free(map[i]);
    }
    free(M);
    free(map);

    return 0;
}
