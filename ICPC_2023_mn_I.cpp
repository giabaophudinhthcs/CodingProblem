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

int n, L[5005], cnt[5005];
ll P2[5005], dp[5005], res = 0LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	P2[0] = 1LL;
	FOR(x, 1, 5000){
		P2[x] = (P2[x - 1] << 1LL) % MOD;
		dp[x] = 0LL;
	}
	dp[0] = 1;
	cin >> n;
	FOR(x, 1, n) cin >> L[x];
	sort(L + 1, L + n + 1);
	FOR(x, 1, n){
		if (x >= 3){
			res += (((P2[x - 1] - x) % MOD) + MOD) % MOD;
			FOR(v, 1, L[x]){
				res = (res + cnt[v] - dp[v]) % MOD;
				res = (res + MOD) % MOD;
			}
		}
		cnt[L[x]]++;
		FORD(v, 5000, L[x]) dp[v] = (dp[v] + dp[v - L[x]]) % MOD;
	}
	cout << res;
	return 0;
}
