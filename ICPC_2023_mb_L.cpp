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

const int nMax = 5e6 + 10;
const int mMax = 3e3 + 30;
const ll MOD = 998244353;
const ll MODLL = 1e18 + 7;
const int oo = 2e9 + 10;
const ll ooll = 2e18 + 10;
const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int Gcd(ll X, ll Y){
	return ((Y == 0) ? X : Gcd(Y, X % Y));
}

ll Phi[nMax], res = 0LL;
int A, B, p[nMax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> A >> B;
	FOR(x, 1, 5e6){
	    Phi[x] = x;
	    p[x] = 1;
	}
	FOR(x, 2, 5e6){
		if (p[x]){
		    Phi[x] -= Phi[x] / x;
			for (int y = x + x; y <= 5e6; y += x){
			    p[y] = 0;
				Phi[y] -= Phi[y] / x;
			}
		}
	}
	FOR(x, 1, B){
		int d = Gcd(A, x);
		ll g = Phi[A] / Phi[d];
		g = (g * Phi[x]) % MOD;
		g = (g * d) % MOD;
		res = (res + g) % MOD;
	}
	cout << res;
	return 0;
}
