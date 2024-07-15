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

int a, b, c, d;
vi N;

/*
x % a = 0
x % b != 0
c % x = 0
d % x != 0
*/

bool Is_Good(int p){
	return ((p % a == 0) && (p % b != 0) && (c % p == 0) && (d % p != 0));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	for (int n = 1; n * n <= c; n++){
		if (c % n == 0){
			N.pb(n);
			if (n * n < c) N.pb(c / n);
		}
	}
	sort(all(N));
	for (auto n: N){
		if (Is_Good(n)){
			cout << n;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
