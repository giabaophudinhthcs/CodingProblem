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
int color[nMax], v, e;

bool bfs_bipartite(){
	int a = 1;
	queue<int> q;
	q.pu(a);
	color[a] = 1;
	while (!q.em()){
		int u = q.ft();
		q.po();
		for (int i = 0; i < ke[u].se(); ++i){
			int v = ke[u][i];
			if (!color[v]){
				if (color[u] == 1) color[v] = 2;
				else color[v] = 1;
			}else{
				if (color[v] == color[u]) return false;
			}
		}
	}
	return true;
}

int main(){
	memset(color, 0, sizeof(color));
	cin >> v >> e;
	for (int i = 0; i < e; ++i){
		int x, y;
		cin >> x >> y;
		ke[x].pub(y);
		ke[y].pub(x);
	}
	if (bfs_bipartite()) cout << "It's bipartite graph";
	else cout << "It isn't bipartite graph";
}
