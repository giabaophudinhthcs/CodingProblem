// Minimum Spanning Tree with Kruskal Algorithm

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

class DSU{
    public:
    	int parent[10010];
        int sz[10010];
    
    	void make(int v){
            this->parent[v] = v;
            sz[v] = 1;
        }
    
    	int find(int v){
            return (v == this->parent[v]) ? v : this->parent[v] = this->find(this->parent[v]);
        }
    
    	void combine(int x, int y){
            x = this->find(x);
            y = this->find(y);
            if (x != y){
                if (sz[x] < sz[y]) swap(x, y);
                this->parent[y] = x;
                sz[x] += sz[y];
            }
        }
};

class edge{
	public:
		int u;
		int v;
		int w;
		
		bool operator<(edge e){
			return (this->w < e.w);
		}
		
		void inp(){
			cin >> this->u >> this->v >> this->w;
		}
};

DSU test;
edge E[20010];
int n, m, min_weight = 0;
vector<edge> MST;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 1, 10000) test.make(x);
	cin >> n >> m;
	FOR(x, 1, m) E[x].inp();
	sort(E + 1, E + m + 1);
	FOR(x, 1, m){
		int p = E[x].u, q = E[x].v;
		if (test.find(p) != test.find(q)){
			MST.pb(E[x]);
			test.combine(p, q);
		}
	}
	for (auto e: MST) min_weight += e.w;
	cout << min_weight;
	return 0;
}
