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

int x, n, p[25], a[25], cnt = 0;
ll mem[nMax][25];

ll dp(int val, int i){
	if (mem[val][i] != -1) return mem[val][i];
	
	mem[val][i] = dp(val, i - 1);
	if (val >= a[i]) mem[val][i] += dp(val - a[i], i);
	
	return mem[val][i];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> x >> n;
	FOR(i, 1, n) cin >> p[i];
	
	sort(p + 1, p + n + 1);
	FOR(i, 1, n){
		if (i == 1){
			a[++cnt] = p[1];
			continue;
		}
		
		if (p[i] > p[i - 1]) a[++cnt] = p[i];
	}
	
	FOR(i, 0, x){
		FOR(j, 2, n) mem[i][j] = -1;
	}
	
	FOR(i, 0, x) mem[i][0] = (i == 0);
	FOR(i, 0, x) mem[i][1] = (i % a[1] == 0);
	
	cout << dp(x, cnt);
	
	return 0;
}
