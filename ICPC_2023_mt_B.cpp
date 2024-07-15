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

int n, a[105], q, pos[nMax], au, av, Len;
ll dp[105][105][105];

int Gcd(int X, int Y){
	return ((!Y) ? X : Gcd(Y, X % Y));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	FOR(x, 1, 1e5) pos[x] = -1;
	cin >> n;
	FOR(x, 1, n){
		cin >> a[x];
		dp[x][x][0] = 1;
	}
	sort(a + 1, a + n + 1);
	FOR(x, 1, n){
		if (pos[a[x]] == -1) pos[a[x]] = x;
	}
	
	FOR(x, 1, n){
		FOR(y, x, n){
			FOR(l, 0, n - 1){
				ll v = dp[x][y][l];
				if (v == 0) continue;
				
				FOR(z, y + 1, n){
					if (Gcd(a[y], a[z]) == 1) dp[x][z][l + 1] = (dp[x][z][l + 1] + v) % 2023;
				}
			}
		}
	}
	
	cin >> q;
	FOR(test, 1, q){
		cin >> au >> av >> Len;
		int u = pos[au];
		int v = pos[av];
		cout << dp[u][v][Len] << "\n";
	}
	return 0;
}
