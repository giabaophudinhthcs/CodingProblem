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

class Sudoku{
	public:
		int v[9][9], cell = 0;
		
		void init(){
			FOR(x, 0, 8){
				string s;
				cin >> s;
				FOR(y, 0, 8){
				    v[x][y] = s[y] - '0';
				    cell += (v[x][y] != 0);
				}
			}
		}
		
		void out(){
			FOR(x, 0, 8){
				FOR(y, 0, 8) cout << this->v[x][y];
				cout << "\n";
			}
		}
};

Sudoku P, J;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	P.cell = 81; // NO NEED
	FOR(x, 0, 8){
		FOR(y, 0, 8) P.v[x][y] = (y + int(x / 3) + 3 * (x % 3)) % 9 + 1;
	}
	
	J.init();
	
	// JUST AVAILABLE FOR (J.cell <= 2)
	if (J.cell == 0) P.out();
	else if (J.cell == 1){
		// ???
	}else if (J.cell == 2){
		// ???
	}else cout << "ERROR! INVALID INPUT!";
	
	return 0;
}
