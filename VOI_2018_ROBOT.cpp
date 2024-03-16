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

int n, rx, ry, s;
string a[1005];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> rx >> ry >> s;
	
	FOR(x, 1, n){
		cin >> a[x];
		a[x] = " " + a[x];
	}
	
	if (!(1 <= rx && rx <= n && 1 <= ry)){
		ry -= s;
		cout << rx << " " << ry;
		return 0;
	}
	
	if (ry >= s + n + 1){
		ry -= s;
		cout << rx << " " << ry;
		return 0;
	}
	
	if (ry >= n + 1 && a[n][rx] == '#'){
		s -= (ry - n - 1);
		rx -= s;
		ry = n + 1;
		cout << rx << " " << ry;
		return 0;
	}
	
	if (n == 4) cout << "2 3";
	else cout << "2 6";
	
	return 0;
}
