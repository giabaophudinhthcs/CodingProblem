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

int m, n, res, u, v, uv, vu, dist, G;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	FOR(p, 1, m - 1){
		cout << p << ' ' << p + 1 << endl;
	}
	res = m - 1;
	
	mt19937 g(seed);
	FOR(Q, 1, 150){
	    G = g();
	    G = abs(G);
	    u = (G % (n - 1)) + 1;
	    v = (G % (n - u)) + u + 1;
	    
	    cout << "distance " << u << ' ' << v << endl;
	    cin >> dist;
	    
	    cout << "subtree " << u << ' ' << v << endl;
	    cin >> uv;
	    
	    cout << "subtree " << v << ' ' << u << endl;
	    cin >> vu;
	    
	    res = max(res, uv + vu - dist);
	}
	cout << "! " << res << endl;
	return 0;
}
