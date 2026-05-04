#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int u[m], v[m], w[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
    }

    int src;
    scanf("%d", &src);

    long long dist[n];
    for (int i = 0; i < n; i++) dist[i] = LLONG_MAX;
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (dist[u[j]] != LLONG_MAX && dist[u[j]] + w[j] < dist[v[j]]) {
                dist[v[j]] = dist[u[j]] + w[j];
            }
        }
    }

    for (int j = 0; j < m; j++) {
        if (dist[u[j]] != LLONG_MAX && dist[u[j]] + w[j] < dist[v[j]]) {
            printf("NEGATIVE CYCLE\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == LLONG_MAX) printf("INF ");
        else printf("%lld ", dist[i]);
    }
    printf("\n");

    return 0;
}
