//
//  main.cpp
//  Dijkstra
//
//  Created by Diana Ovechkina on 22.05.2022.
//


#include <iostream>
using namespace std;

const int N = 9;

// поиск вершины с минимальным расстоянием из вершин, не отмеченных как кратчайшие
int minDistance(int dist[], bool markedVertices[])
{
    int min = INT_MAX;
    int min_index = 0;

    for (int i = 0; i < N; i++)
        if (markedVertices[i] == false && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }

    return min_index;
}

void printDist(int dist[], int P[])
{
    cout << "Вершина \t Расстояние из начальной вершины " << endl;
    for (int i = 0; i < N; i++) {
        cout << i << " \t\t\t\t" << dist[i] << endl;
    }
    cout << endl;
    for (int j = N - 1; j > 0; j--) {
        int k = j;
        cout << "Кратчайший путь для  " << j << " вершины: ";
        while (j != -1) {
            cout << j << " ";
            j = P[j];
        }
        j = k;
    
        cout << endl;
    }

}


void dijkstra(int graph[N][N])
{
    int dist[N]; // массив с кратчайшими расстояниями

    bool markedVertices[N]; // массив, отвечающий, за то что кратчайшее расстояние из i вершины найдено
    int P[N];

    for (int i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        markedVertices[i] = false;
        P[i] = 0;
    }

    dist[0] = 0;// начальная вершина имеет расстояние = 0
    P[0] = -1;

    for (int count = 0; count < N - 1; count++) {
        int u = minDistance(dist, markedVertices); // вершина с минмальным расстоянием и не отмечена как проверенная

        for (int v = 0; v < N; v++) {
            // если вершина не отмечена и в матрице не 0 и расстояние из мин u + из графа [u][v] < расстояния v
            if (!markedVertices[v] && graph[u][v] != 0 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                P[v] = u;
            }
        }
        markedVertices[u] = true; // помечаем, что для u вершины окончен поиск кратчайшего пути

    }
    printDist(dist, P);
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << "Овечкина Диана Алексеевна" << endl;
    cout << "ВШКМиС, 15.11Д-МО11/20б" << endl;
    cout << "Жадные Алгоритмы" << endl;
    cout << "Реализация алгоритма Дейкстры" << endl << endl;
    int graph[N][N] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph);

    cout << endl;
    return 0;
}

