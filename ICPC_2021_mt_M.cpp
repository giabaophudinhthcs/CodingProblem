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

const int nMax = 1e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

ll F[nMax], res = 0LL;
int n, m, vis[nMax];
vi adj[nMax];

ll club_val(int s){
	vis[s] = 1;
	int cnt = 1;
	queue<int> q;
	q.push(s);
	while (!q.empty()){
		int u = q.front();
		q.pop();
		for (auto v: adj[u]){
			if (!vis[v]){
				vis[v] = 1;
				q.push(v);
				cnt++;
			}
		}
	}
	return F[cnt];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(vis, 0, sizeof(vis));
	F[0] = F[1] = F[2] = 0LL;
	F[3] = 6LL;
	FOR(x, 4, 1e5) F[x] = (F[x - 1] * x) % MOD;
	cin >> n >> m;
	FOR(x, 1, m){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	FOR(x, 0, n - 1){
		if (!vis[x]) res = (res + club_val(x)) % MOD;
	}
	cout << res;
	return 0;
}
