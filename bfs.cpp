#include <bits/stdc++.h>

#define pub push_back
#define pu push
#define em empty
#define po pop
#define ft front
#define se size

using namespace std;

const int nMax = 1e3 + 3;

vector<int> ke[nMax];
int dist[nMax], v, e;

void bfs(){
	int a = 1;
	queue<int> q;
	q.pu(a);
	dist[a] = 1;
	while (!q.em()){
		int u = q.ft();
		q.po();
		for (int i = 0; i < ke[u].se(); ++i){
			int v = ke[u][i];
			if (!dist[v]){
				dist[v] = dist[u] + 1;
				q.pu(v);
			}
		}
	}
}

int main(){
	cin >> v >> e;
	for (int i = 0; i < e; ++i){
		int x, y;
		cin >> x >> y;
		ke[x].pub(y);
		ke[y].pub(x);
	}
	bfs();
	for (int i = 1; i <= v; ++i){
		cout << "1 -> " << i << ": " << dist[i] - 1 << "\n";
	}
}
