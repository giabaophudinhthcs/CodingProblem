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
const ll MOD = 987654321;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

ll n, x, y, z, t, g = 1, res = 0LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	x = n;
	y = n - 3;
	if (!(x & 1)) x >>= 1;
	else y >>= 1;
	x %= MOD;
	y %= MOD;
	res = (res + (x * y) % MOD) % MOD;
	x = n;
	y = n - 1;
	z = x - 2;
	t = x - 3;
	
	if (!(x & 3)) x >>= 2;
	else if (!(y & 3)) y >>= 2;
	else if (!(z & 3)) z >>= 2;
	else t >>= 2;
	
	if (!(x & 1)) x >>= 1;
	else if (!(y & 1)) y >>= 1;
	else if (!(z & 1)) z >>= 1;
	else t >>= 1;
	
	if (!(x % 3)) x /= 3;
	else if (!(y % 3)) y /= 3;
	else if (!(z % 3)) z /= 3;
	else t /= 3;
	
	x %= MOD;
	g = (g * x) % MOD;
	y %= MOD;
	g = (g * y) % MOD;
	z %= MOD;
	g = (g * z) % MOD;
	t %= MOD;
	g = (g * t) % MOD;
	
	res = (res + g + 1) % MOD;
	
	cout << res;
	return 0;
}
