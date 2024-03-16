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

class Edge{
	public:
		int u, v;
};

class Ver{
	public:
		int v, d;
		
		bool operator<(Ver O){
			return (this->d < O.d);
		}
};

map<int, int> mark;
int n, m, s, dist[10005], res = 0;
vi adj[10005];
vector<Edge> E;
queue<int> q;
Ver T[10005];
vi tracing[10005];
ll cnt[10005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s;
	
	FOR(x, 1, n){
		cnt[x] = 0;
		T[x].v = x;
		T[x].d = -1;
	}
	
	FOR(x, 1, m){
		int U, V;
		cin >> U >> V;
		
		if (!mark[(U - 1) * n + V]){
			mark[(U - 1) * n + V] = 1;
			E.pb({U, V});
			adj[U].pb(V);
			tracing[V].pb(U);
		}
	}
	
	q.push(s);
	T[s].d = 0;
	cnt[s] = 1;
	
	while (!q.empty()){
		int U = q.front();
		q.pop();
		
		for (auto V: adj[U]){
			if (T[V].d == -1){
				q.push(V);
				T[V].d = T[U].d + 1;
			}
		}
	}
	
	sort(T + 1, T + n + 1);
	FOR(x, 1, n) dist[T[x].v] = T[x].d;
	
	FOR(V, 1, n){
		for (auto U: tracing[T[V].v]){
			cnt[T[V].v] += cnt[U] * (dist[U] + 1 == T[V].d);
			cnt[T[V].v] = min(cnt[T[V].v], 1LL * oo);
		}
		
		res += (cnt[T[V].v] >= 2);
	}
	
	cout << res;
	
	return 0;
}
