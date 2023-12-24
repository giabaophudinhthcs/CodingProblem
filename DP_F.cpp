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

string s, t, res = "";
int n, m, dp[mMax][mMax], posX, posY;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	posX = n = int(s.len());
	posY = m = int(t.len());
	s = " " + s;
	t = " " + t;
	FOR(x, 1, n){
		FOR(y, 1, m){
			if (s[x] == t[y]) dp[x][y] = dp[x - 1][y - 1] + 1;
			else dp[x][y] = max(dp[x - 1][y], dp[x][y - 1]);
		}
	}
	while (posX >= 1 && posY >= 1){
		if (s[posX] == t[posY]){
			res = s[posX] + res;
			posX--;
			posY--;
		}else{
			if (dp[posX][posY] == dp[posX - 1][posY]) posX--;
			else posY--;
		}
	}
	cout << res;
	return 0;
}
