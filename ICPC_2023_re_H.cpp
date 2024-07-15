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
// const auto seed = chrono::steady_clock::now().time_since_epoch().count();

int t, n, S, cnt = 0, Id[300], a[5005][5005];
bool can;
string s, r = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

class Hash{
	public:
		int cnt;
		ll Code;
		
		void init(){
			this->cnt = 0;
			this->Code = 0LL;
		}
		
		void add(int v){
			this->cnt += v;
			this->Code = (3 * this->Code + (v + 1)) % MOD;
		}
};

Hash h[5005];

void check(){
	FOR(col, 0, n - 1){
		int row1 = -1, row2 = -1;
		FOR(row, 0, n - 1){
			if (a[row][col] == 0){
				if (row1 < 0) row1 = row;
				else if (h[row1].cnt != h[row].cnt || h[row1].Code != h[row].Code){
					row2 = row;
					FOR(col2, 0, n - 1){
						if (a[row1][col2] != a[row2][col2]){
							cout << "YES\n" << row1 + 1 << " " << col + 1 << " " << row2 + 1 << " " << col2 + 1 << "\n";
							return;
						}
					}
				}
			}
		}
	}
	
	cout << "NO\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	FOR(x, 0, 63) Id[r[x]] = x;
	
	cin >> t;
	while (t--){
		cin >> n >> s;
		
		FOR(x, 0, n - 1) h[x].init();
		
		int S = int(s.len());
		FOR(x, 0, S - 1){
			int d = Id[s[x]];
			
			FOR(k, 0, 5){
				int i = x * 6 + k;
				if (i >= n * n) break;
				a[i / n][i % n] = (d >> k) & 1;
				h[i / n].add(a[i / n][i % n]);
			}
		}
		
		check();
	}
	
	return 0;
}
