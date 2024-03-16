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

int n, v, c = 0, dp[nMax], res = 0, k = 0, m = 1;
map<int, int> p;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	while (1){
		k += m;
		if (k > 1e8) break;
		p[k] = m;
		m++;
	}
	
	cin >> n;
	FOR(x, 1, n){
		cin >> v;
		
		if (!p[v]) dp[x] = 0;
		else{
			if ((!p[c]) || (p[c] > p[v])) dp[x] = 1;
			else dp[x] = dp[x - 1] + 1;
		}
		
		res = max(res, dp[x]);
		c = v;
	}
	
	cout << res;
	
	return 0;
}
