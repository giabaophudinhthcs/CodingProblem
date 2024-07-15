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
typedef unsigned long long ull;
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

int n, m, dist[nMax], trace[nMax];
vi adj[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n >> m;
	
	FOR(x, 1, n) dist[x] = trace[x] = -1;
	
	dist[1] = trace[1] = 0;
	
	FOR(x, 1, m){
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	queue<int> q;
	
	q.push(1);
	
	while (!q.empty()){
		int s = q.front();
		q.pop();
		
		for (auto t: adj[s]){
			if (dist[t] == -1){
				dist[t] = dist[s] + 1;
				trace[t] = s;
				q.push(t);
			}
		}
	}
	
	stack<int> St;
	
	if (dist[n] == -1) cout << "IMPOSSIBLE";
	else{
		cout << dist[n] + 1 << "\n";
		
		int v = n;
		while (v){
			St.push(v);
			v = trace[v];
		}
		
		while (!St.empty()){
			cout << St.top() << " ";
			St.pop();
		}
	}
	
	return 0;
}
