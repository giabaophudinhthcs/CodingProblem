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

string s;
int digit[20], n, p[150];
ll dp[20][3][150][150], res = 0LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 0, 135) p[x] = 1;
	p[0] = p[1] = 0;
	for (int x = 2; x * x <= 135; ++x){
		if (p[x]){
			for (int y = x * x; y <= 135; y += x) p[y] = 0;
		}
	}
	cin >> s;
	n = int(s.len());
	FOR(d, 1, n) digit[d] = int(s[d - 1] - '0');
	dp[n + 1][0][0][0] = 1;
	
	FORD(d, n + 1, 1){
		FOR(rem, 0, 2){
			FOR(sx, 0, 135){
				FOR(sy, 0, 135){
					
					ll val = dp[d][rem][sx][sy];
					if (!val) continue;
					
					FOR(dx, 0, 9){
						FOR(dy, 0, 9){
							int t = dx + dy * 2 + rem;
							if (digit[d - 1] == t % 10) dp[d - 1][t / 10][sx + dx][sy + dy] += val;
						}
					}
				}
			}
		}
	}
	
	FOR(sx, 0, 135){
		FOR(sy, 0, 135){
			if (p[sx] && p[sy]){
			    res += dp[0][0][sx][sy];
			}
		}
	}
	
	cout << res;
	return 0;
}
