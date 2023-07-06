// Shortest Path with Dijkstra's Algorithm

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

class Node{
	public:
		int u;
		ll cost;
		
		bool operator<(Node other) const {
			return (this->cost > other.cost);
		}
};

int n, m;
ll dist[nMax];
vector<Node> adj[nMax];
priority_queue<Node> pq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	memset(dist, ooll, sizeof(dist));
	dist[0] = 0LL;
	pq.push({0, 0LL});
	FOR(p, 1, m){
		int x, y;
		ll c;
		cin >> x >> y >> c;
		adj[x].pb({y, c});
	}
	while (!pq.empty()){
		Node t = pq.top();
		pq.pop();
		for (auto s: adj[t.u]){
			if (dist[s.u] > dist[t.u] + s.cost){
				dist[s.u] = dist[t.u] + s.cost;
				pq.push({s.u, dist[s.u]});
			}
		}
	}
	FOR(x, 0, n - 1){
		cout << 0 << " -> " << x << ": ";
		if (dist[x] >= oo) cout << "(No way)\n";
		else cout << dist[x] << "\n";
	}
	return 0;
}
