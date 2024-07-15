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

int test, n, p, q, dp[15][15];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> test;
	while (test--){
		cin >> n >> p >> q;
		if ((p >= n || q >= n) && abs(p - q) >= 2){
			FOR(x, 0, 12){
				FOR(y, 0, 12) dp[x][y] = 0;
			}
			dp[0][0] = 1;
			FOR(x, 0, 10){
				FOR(y, 0, 10){
					if ((x >= n || y >= n) && abs(x - y) >= 2) continue;
					else{
						dp[x + 1][y] += dp[x][y];
						dp[x][y + 1] += dp[x][y];
					}
				}
			}
			cout << dp[p][q] << "\n";
		}else cout << "0\n";
	}
	return 0;
}
