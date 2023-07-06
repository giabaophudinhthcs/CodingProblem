#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e5 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int n, LG[nMax], q, x, y, par[nMax], dist[nMax], anc[nMax][20];
vi adj[nMax];

void genLG(){
	LG[0] = -1;
	FOR(v, 1, nMax) LG[v] = LG[v >> 1] + 1;
}

void bfs(){
	queue<int> q;
	q.push(1);
	par[1] = -1;
	dist[1] = 0;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for (auto v: adj[s]){
			if (dist[v] == -1){
				par[v] = s;
				dist[v] = dist[s] + 1;
				q.push(v);
				FOR(k, 0, LG[dist[v]]){
			        if (!k) anc[v][k] = par[v];
			        else anc[v][k] = anc[anc[v][k - 1]][k - 1];
		        }
			}
		}
	}
}

int jump(int p, int Len){
	int P = p;
	if (!Len) return p;
	FOR(step, 0, LG[Len]){
		if ((Len >> step) & 1) P = anc[P][step];
	}
	return P;
}

int lca(int s, int t){
	int S = s, T = t;
	if (dist[S] < dist[T]) swap(S, T);
	S = jump(S, dist[S] - dist[T]);
	if (S == T) return S;
	int Len = LG[dist[S]];
	FORD(v, Len, 0){
		if (anc[S][v] != anc[T][v]){
			S = anc[S][v];
			T = anc[T][v];
		}
	}
	return anc[S][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	genLG();
	cin >> n;
	FOR(k, 1, n - 1){
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	memset(par, -1, sizeof(par));
	memset(dist, -1, sizeof(dist));
	memset(anc, -1, sizeof(anc));
	bfs();
	cin >> q;
	FOR(k, 1, q){
		cin >> x >> y;
		cout << lca(x, y) << "\n";
	}
	return 0;
}
