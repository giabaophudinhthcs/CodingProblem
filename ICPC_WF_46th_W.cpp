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

int r[6];

void Ask(int a, int b, int c, int i){
	cout << a << " " << b << " " << c << endl;
	cin >> r[i];
}

void Answer(int la, int lb, int lc){
	cout << la << " " << lb << " " << lc << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// freopen("NAME.INP", "r", stdin);
	// freopen("NAME.OUT", "w", stdout);
	
	Ask(1, 0, 0, 1);
	Ask(0, 1, 0, 2);
	Ask(0, 0, 1, 3);
	Ask(1, 1, 1, 4);
	Ask(1, 2, 3, 5);
	
	if (r[1] + r[2] + r[3] == r[4]) Answer(r[1], r[2], r[3]);
	else if (r[1] + 2 * r[2] + 3 * r[3] == r[5]) Answer(r[1], r[2], r[3]);
	else if (r[5] - r[4] == r[2] + 2 * r[3]) Answer(r[4] - r[2] - r[3], r[2], r[3]);
	else if (r[5] - 2 * r[4] == r[3] - r[1]) Answer(r[1], r[4] - r[1] - r[3], r[3]);
	else Answer(r[1], r[2], r[4] - r[1] - r[2]);
	
	return 0;
}
