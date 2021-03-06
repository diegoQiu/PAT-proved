#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 505;
const int INF = 1000000000;
int N, M, st, ed;
int hands[maxn];
int G[maxn][maxn];
bool vis[maxn];
int path;
int d[maxn],w[maxn],num[maxn];

int hand;
void dijkstra(int s) {
	fill(d, d + N, INF);
	d[s] = 0;
	memset(num, 0, sizeof(num));
	memset(w, 0, sizeof(w));
	w[s] = hands[s];
	num[s] = 1;
	for (int i = 0; i < N; i++) {
		int u = -1, MIN = INF;
		for (int j = 0; j < N; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1)
			return;
		vis[u] = true;
		for (int v = 0; v < N; v++) {
			if (vis[v] == false && G[u][v] != INF) {
				if (d[v] > d[u] + G[u][v]) {
					d[v] = d[u] + G[u][v];
					w[v] = w[u] + hands[v];
					num[v] = num[u];
				}
				else if (d[v] == d[u] + G[u][v]) {
					if (w[v] < w[u] + hands[v]) {
						w[v] = w[u] + hands[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main() {
	cin >> N >> M >> st >> ed;
	fill(G[0], G[0] + maxn * maxn, INF);
	for (int i = 0; i < N; i++) {
		scanf("%d", &hands[i]);
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &G[a][b]);
		G[b][a] = G[a][b];
	}
	dijkstra(st);
	cout << num[ed] << " "<<w[ed] << endl;
	return 0;
}