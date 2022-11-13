#include <bits/stdc++.h>

const int noOfVertices = 6;

int getMinimumDistance(int distArr[], bool verticesSelected[])
{
    int minDist = INT_MAX, min_index;
    for (int v = 0; v < noOfVertices; v++)
        if (verticesSelected[v] == false && distArr[v] <= minDist)
        {
            minDist = distArr[v], min_index = v;
        }
    return min_index;
}

void display(int distArr[], int n, int sourceVertex)
{
    printf("Distance of Vertex from Source %d: \n", sourceVertex);
    for (int i = 0; i < noOfVertices; i++)
        printf("%d %d\n", i, distArr[i]);
}

void dijkstra(int graph[noOfVertices][noOfVertices], int sourceVertex)
{
    int distArr[noOfVertices];
    bool verticesSelected[noOfVertices];
    for (int i = 0; i < noOfVertices; i++)
    {
        distArr[i] = INT_MAX, verticesSelected[i] = false;
    }

    distArr[sourceVertex] = 0;
    for (int count = 0; count < noOfVertices - 1; count++)
    {
        int u = getMinimumDistance(distArr, verticesSelected);
        verticesSelected[u] = true;
        for (int v = 0; v < noOfVertices; v++)
        {
            if (!verticesSelected[v] && graph[u][v] && distArr[u] != INT_MAX &&
                distArr[u] + graph[u][v] < distArr[v])
            {
                distArr[v] = distArr[u] + graph[u][v];
            }
        }
    }
    display(distArr, noOfVertices, sourceVertex);
}
int main()
{
    int graph[noOfVertices][noOfVertices] = {{0, 2, 0, 0, 8, 0},
                                             {0, 0, 1, 0, 0, 0},
                                             {0, 0, 0, 0, 4, 5},
                                             {1, 0, 0, 0, 0, 0},
                                             {0, 3, 0, 1, 0, 7},
                                             {0, 0, 0, 0, 0, 0}};
    dijkstra(graph, 0);
    return 0;
}