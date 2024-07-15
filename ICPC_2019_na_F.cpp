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

int nA, nB, nC, a, b, c, cnt[3][30000005], dp[6005][6005];
ll A, B, C, res = 0LL;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> nA >> nB >> nC;
	
	FOR(x, 1, nA){
		cin >> a;
		cnt[0][a]++;
	}
	
	FOR(x, 1, nB){
		cin >> b;
		cnt[1][b]++;
	}
	
	FOR(x, 1, nC){
		cin >> c;
		cnt[2][c]++;
	}
	
	FOR(m, 1, 6000){
		FOR(n, 1, 6000){
			if (m % n == 0 || n % m == 0) dp[m][n] = min(m, n);
			else{
				if (m < n) dp[m][n] = dp[m][n % m];
				else dp[m][n] = dp[m % n][n];
			}
		}
	}
	
	FOR(m, 1, 6000){
		FOR(n, 1, 6000){
			if (m >= n && dp[m][n] == 1 && (m % 2 == 0 || n % 2 == 0) && (m*m + n*n <= 3e7)){
				a = m*m - n*n;
				b = 2*m*n;
				c = m*m + n*n;
				
				int Cnt = 0;
				for (int mC = c; mC <= 1e7; mC += c) Cnt += cnt[2][mC];
				
				if (Cnt){
					int AA = a, BB = b, CC = c;
					while (CC <= 1e7){
						A = cnt[0][AA];
						B = cnt[1][BB];
						C = cnt[2][CC];
						res += A * B * C;
					}
				}
			}
		}
	}
	
	cout << res;
	
	return 0;
}
