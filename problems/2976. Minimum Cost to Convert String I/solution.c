#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INF 1000000000000000LL

long long minimumCost(char* source, char* target, char* original, int originalSize, char* changed, int changedSize, int* cost, int costSize) {
    // Distance matrix: dist[i][j] = min cost to convert char i -> j
    long long dist[26][26];

    // Initialize distances
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    // Fill direct conversion costs
    // originalSize == changedSize == costSize (guaranteed by LeetCode)
    for (int i = 0; i < originalSize; i++) {
        int u = original[i] - 'a';
        int v = changed[i] - 'a';

        if (cost[i] < dist[u][v]) {
            dist[u][v] = cost[i];
        }
    }

    // Floyd–Warshall algorithm (all-pairs shortest path)
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Calculate total cost to convert source -> target
    long long totalCost = 0;
    int len = strlen(source);

    for (int i = 0; i < len; i++) {
        int s = source[i] - 'a';
        int t = target[i] - 'a';

        if (dist[s][t] == INF) {
            return -1;   // Conversion impossible
        }

        totalCost += dist[s][t];
    }

    return totalCost;
}
