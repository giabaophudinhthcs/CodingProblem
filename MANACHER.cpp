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

int n, calc[nMax], l = 1, r = 0, res = 0;
string s, t;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n >> s;
	s = " " + s;
	t = " ";
	
	FOR(x, 1, 2 * n + 1){
	    if (x & 1) t += '.';
	    else t += s[x >> 1];
	}
	
	FOR(x, 1, (2 * n + 1)){
	    if (x > r) calc[x] = 0;
	    else calc[x] = min(r - x, calc[l + r - x]);
	    
	    while (x - calc[x] - 1 > 0 && x + calc[x] + 1 <= 2 * n + 1 && t[x - calc[x] - 1] == t[x + calc[x] + 1]) calc[x]++;
	    
	    if (calc[x] + x > r){
	        l = x - calc[x];
	        r = x + calc[x];
	    }
	}
	
	FOR(x, 1, 2 * n + 1) res = max(res, calc[x]);
	cout << res;
	
	return 0;
}
