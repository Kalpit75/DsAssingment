#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int dirGraph();
int undirGraph();
int readGraph(int adjMat[50][50], int n);

int main() {
    int option;

    do {
        printf("\n A Program to represent a Graph by using an Adjacency Matrix method \n ");
        printf("\n 1. Directed Graph ");
        printf("\n 2. Un-Directed Graph ");
        printf("\n 3. Exit ");
        printf("\n\n Select a proper option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                dirGraph();
                break;
            case 2:
                undirGraph();
                break;
            case 3:
                exit(0);
        }
    } while (1);

    return 0;
}

// Function to represent a directed graph
int dirGraph() {
    int adjMat[50][50];
    int n, indeg, outdeg, i, j;

    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);

    readGraph(adjMat, n);

    printf("\n Vertex \t InDegree \t OutDegree \t TotalDegree ");

    for (i = 1; i <= n; i++) {
        indeg = outdeg = 0;

        for (j = 1; j <= n; j++)
            if (adjMat[j][i] == 1)
                indeg++;

        for (j = 1; j <= n; j++)
            if (adjMat[i][j] == 1)
                outdeg++;

        printf("\n\n %5d\t\t\t%d\t\t%d\t\t%d\n\n", i, indeg, outdeg, indeg + outdeg);
    }

    return 0;
}

// Function to represent an undirected graph
int undirGraph() {
    int adjMat[50][50];
    int deg, i, j, n;

    printf("\n How Many Vertices ? : ");
    scanf("%d", &n);

    readGraph(adjMat, n);

    printf("\n Vertex \t Degree ");

    for (i = 1; i <= n; i++) {
        deg = 0;

        for (j = 1; j <= n; j++)
            if (adjMat[i][j] == 1)
                deg++;

        printf("\n\n %5d \t\t %d\n\n", i, deg);
    }

    return 0;
}

// Function to read the graph
int readGraph(int adjMat[50][50], int n) {
    int i, j;
    char reply;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                adjMat[i][j] = 0;
                continue;
            }

            printf("\n Vertices %d & %d are Adjacent ? (Y/N) :", i, j);

            while (getchar() != '\n');  // Consume extra characters in the input buffer

            scanf("%c", &reply);

            if (reply == 'y' || reply == 'Y')
                adjMat[i][j] = 1;
            else
                adjMat[i][j] = 0;
        }
    }

    return 0;
}
