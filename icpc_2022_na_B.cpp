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

int n, m, k;
string s[305];
unordered_set<string> T;

string Major(int X, int Y, int Z){
	string res = "";
	
	FOR(pos, 0, m - 1){
		int cnt = (s[X][pos] == '1') + (s[Y][pos] == '1') + (s[Z][pos] == '1');
		if (cnt >= 2) res += "1";
		else res += "0";
	}
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	
	FOR(x, 1, n){
		cin >> s[x];
		T.insert(s[x]);
	}
	
	FOR(x, 1, n - 2){
		FOR(y, x + 1, n - 1){
			FOR(z, y + 1, n){
				string r = Major(x, y, z);
				
				if (T.find(r) == T.end()){
					cout << "NO";
					return 0;
				}
			}
		}
	}
	
	cout << "YES";
	return 0;
}
