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

int n, q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	cin >> n;
	
	int s1[n + 1][n + 1], s2[n + 1][n + 1];
	
	FOR(x, 0, n){
		FOR(y, 0, n) s1[x][y] = s2[x][y] = 0;
	}
	
	FOR(x, 1, n){
		FOR(y, 1, n){
			int v;
			cin >> v;
			s1[x][y] = s1[x - 1][y] + s1[x][y - 1] - s1[x - 1][y - 1];
			s2[x][y] = s2[x - 1][y] + s2[x][y - 1] - s2[x - 1][y - 1];
			
			if ((x + y) & 1) s1[x][y] += v;
			else s2[x][y] += v;
		}
	}
	
	cin >> q;
	while (q--){
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		
		int S1 = s1[i2][j2] - s1[i1 - 1][j2] - s1[i2][j1 - 1] + s1[i1 - 1][j1 - 1];
		int S2 = s2[i2][j2] - s2[i1 - 1][j2] - s2[i2][j1 - 1] + s2[i1 - 1][j1 - 1];
		cout << abs(S1 - S2) << "\n";
	}
	
	return 0;
}
