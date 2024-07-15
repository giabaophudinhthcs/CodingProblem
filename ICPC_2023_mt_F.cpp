#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define len length

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<string> vs;

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

class Node{
	public:
		int v;
		ll Ones, Multi;
};

int n, anc[nMax][20], L[nMax], dist[nMax];
ll f[nMax], res = 0LL;
vi adj[nMax];
vector<Node> cost[nMax];

void LOG_TRICK_LORD(){
	L[1] = 0;
	FOR(x, 2, 1e6) L[x] = L[x >> 1] + 1;
}

void dfs_calc_ancestor(int s, int par_s){
	if (par_s == -1) dist[s] = 0;
	else dist[s] = dist[par_s] + 1;
	
	anc[s][0] = par_s;
	
	for (auto t: adj[s]){
		if (t != par_s) dfs_calc_ancestor(t, s);
	}
}

void calc_ancestor(){
	FOR(k, 1, L[n]){
		FOR(s, 1, n) anc[s][k] = anc[anc[s][k - 1]][k - 1];
	}
}

int K_jump(int s, int step){
	int res = s;
	for (int k = 0; (1 << k) <= step; ++k){
		if ((step >> k) & 1) res = anc[res][k];
	}
	return res;
}

int lca(int s, int t){
	int S, T;
	S = s;
	T = t;
	if (dist[S] > dist[T]) swap(S, T);
	
	if (dist[S] < dist[T]) T = K_jump(T, dist[T] - dist[S]);
	
	if (S == T) return T;
	
	FORD(k, L[dist[S]], 0){
		if (anc[S][k] != anc[T][k]){
			S = anc[S][k];
			T = anc[T][k];
		}
	}
	
	return anc[S][0];
}

void dfs_cost(int s, int par_s){
	for (auto NN: cost[s]){
		if (NN.v != par_s){
			dfs_cost(NN.v, s);
			f[s] += f[NN.v];
			res += min(NN.Multi, f[NN.v] * NN.Ones);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LOG_TRICK_LORD();
	cin >> n;
	FOR(x, 1, n - 1){
		int a, b, cO, cM;
		Node N;
		cin >> a >> b >> cO >> cM;
		adj[a].pb(b);
		adj[b].pb(a);
		N.v = b;
		N.Ones = cO;
		N.Multi = cM;
		cost[a].pb(N);
		N.v = a;
		cost[b].pb(N);
	}
	dfs_calc_ancestor(1, -1);
	calc_ancestor();
	
	FOR(x, 1, n) f[x] = 0;
	FOR(x, 1, n - 1){
		int V = lca(x, x + 1);
		f[x]++;
		f[x + 1]++;
		f[V] -= 2;
	}
	
	dfs_cost(1, -1);
	
	cout << res;	
	return 0;
}
