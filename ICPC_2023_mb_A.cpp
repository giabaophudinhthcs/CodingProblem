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

ll fib[90], n;
int t;
map<ll, int> h[90];

int solve(ll N, int P){
	if (N == 1LL) return 1;
	if (h[P].count(N)) return h[P][N];
	
	int res = 0LL;
	FOR(x, P, 87){
		if (N < fib[x]) break;
		if (N % fib[x] == 0LL){
			ll tmp = N;
			while (tmp % fib[x] == 0LL){
				tmp /= fib[x];
				res += solve(tmp, x + 1);
			}
		}
	}
	
	return h[P][N] = res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	fib[0] = fib[1] = 1;
	FOR(x, 2, 87) fib[x] = fib[x - 1] + fib[x - 2];
	cin >> t;
	while (t--){
		cin >> n;
		cout << solve(n, 2) << "\n";
	}
	return 0;
}
