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

int t, n, x, y, dx[6], dy[6];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	dx[0] = dx[3] = 0;
	dx[1] = dx[2] = 1;
	dx[5] = dx[4] = -1;
	
	dy[2] = dy[5] = 0;
	dy[0] = dy[1] = 1;
	dy[3] = dy[4] = -1;
	
	cin >> t;
	while (t--){
		cout << "YES\n";
		cin >> n;
		cout << 7 * n << "\n";
		FOR(p, 1, n){
			cin >> x >> y;
			cout << x << " " << y << " " << 3 << "\n";
			FOR(D, 0, 5) cout << x + dx[D] << " " << y + dy[D] << " " << 2 << "\n";
		}
	}
	return 0;
}
