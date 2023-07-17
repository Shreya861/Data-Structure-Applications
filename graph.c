

#include <stdio.h>
#define size 4
main() 
{
  int adjMatrix[size][size];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 2, 0);
  addEdge(adjMatrix, 2, 3);

  printAdjMatrix(adjMatrix);
}


void init(int arr[][size]) 
{
  int i, j;
  for (i = 0; i < size; i++)
  {
    for (j = 0; j < size; j++)
    {
      arr[i][j] = 0;
    }
  }
}

void addEdge(int arr[][size], int i, int j) 
{
  arr[i][j] = 1;
  arr[j][i] = 1;
}

void printAdjMatrix(int arr[][size])
 {
  int i, j;

  for (i = 0; i < size; i++) 
  {
    printf("%d: ", i);
    for (j = 0; j < size; j++)
    {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}
