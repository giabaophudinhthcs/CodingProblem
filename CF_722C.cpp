// Link: https://codeforces.com/contest/722/problem/C

#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int nMax = 1e6 + 10;
const ll MOD = 1e9 + 7;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;

class DSU{
    public:
        int par[nMax];
        int sz[nMax];
        ll val[nMax];
        
        void make_set(int v, ll x[]){
            par[v] = v;
            sz[v] = 1;
            val[v] = x[v];
        }
        
        int find(int v){
            return v == par[v] ? v : par[v] = find(par[v]);
        }
        
        void Union(int s, int t) {
            s = find(s);
            t = find(t);
            if (s != t) {
                if (sz[s] < sz[t]) swap(s, t);
                par[t] = s;
                sz[s] += sz[t];
                val[s] += val[t];
            } 
        }
};

int n, p[nMax], mark[nMax];
ll a[nMax], ans = -ooll, res[nMax];
DSU check;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	FOR(x, 1, n) cin >> a[x];
	FOR(x, 1, n) cin >> p[x];
	FOR(x, 1, n) check.make_set(x, a);
	FORD(x, n, 1){
	    mark[p[x]] = 1;
	    if (p[x] > 1 && mark[p[x] - 1]) check.Union(p[x], p[x] - 1);
	    if (p[x] < n && mark[p[x] + 1]) check.Union(p[x], p[x] + 1);
	    ans = max(ans, check.val[check.find(p[x])]);
	    res[x - 1] = ans;
	}
	FOR(x, 1, n) cout << res[x] << "\n";
	return 0;
}
