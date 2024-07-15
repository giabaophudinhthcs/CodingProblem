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

int n, m, v, mark[9];
vi S(8);
map<vi, ll> R[105];

ll DP(int pos, vi& C){
	if (pos == n + 1) return 1LL;
	
	if (R[pos].count(C)) return R[pos][C];
	
	ll res = 0LL;
	FOR(V, 0, 7){
		if (mark[V] && C[V] == V){
			vi N(8);
			FOR(x, 0, 7) N[x] = min(C[x] + 1, x);
			N[V] = 0;
			res += DP(pos + 1, N);
			res %= MOD;
		}
	}
	
	return R[pos][C] = res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	FOR(x, 0, 7){
		mark[x] = 0;
		S[x] = x;
	}
	FOR(x, 1, m){
		cin >> v;
		mark[v - 1] = 1;
	}
	
	cout << DP(1, S);
	return 0;
}
