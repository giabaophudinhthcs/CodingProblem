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

double a, h, res;

double n(double t){
	return (6.0 * (a - 1) * t * t) / (1.0 * h) + (7.0 - 8.0 * a) * (1.0 * t) + (2.0 * a - 1.0) * (1.0 * h);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> h;
	a /= 100.0;
	
	if (a == 0.0 && a == 0.5) res = (h * 2.0) / 3.0;
	else if (a == 1.0) res = (5.0 * h) / 6.0;
	else{
		res = max((5.0 * a * h) / 6.0, (h * 2.0) / 3.0);
		double i = (1.0 * h * (8.0 * a - 7.0)) / (12.0 * a - 12.0);
		
		if (i > h / 3.0) res = max(res, n(h / 3.0));
		else if (i < h / 6.0) res = max(res, n(h / 6.0));
		else res = max(res, n(i));
	}
	
	res *= 100.0;
	cout << fixed << setprecision(10) << res;
	return 0;
}
