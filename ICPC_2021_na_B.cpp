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

int R, C, d[4], res = 0;
string s[53];
char Letter[4];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> R >> C;
	FOR(r, 1, R){
		cin >> s[r];
		s[r] = " " + s[r];
	}
	
	FOR(r, 1, R >> 1){
		FOR(c, 1, C >> 1){
			int dist = 500;
			
			Letter[0] = s[r][c];
			Letter[1] = s[r][C + 1 - c];
			Letter[2] = s[R + 1 - r][c];
			Letter[3] = s[R + 1 - r][C + 1 - c];
			
			for (char x = 'A'; x <= 'Z'; ++x){
				d[0] = abs(int(Letter[0] - x));
				d[1] = abs(int(Letter[1] - x));
				d[2] = abs(int(Letter[2] - x));
				d[3] = abs(int(Letter[3] - x));
				
				d[0] = min(d[0], 26 - d[0]);
				d[1] = min(d[1], 26 - d[1]);
				d[2] = min(d[2], 26 - d[2]);
				d[3] = min(d[3], 26 - d[3]);
				
				dist = min(dist, d[0] + d[1] + d[2] + d[3]);
			}
			
			res += dist;
		}
	}
	
	if (R & 1){
		int pos = (R + 1) >> 1;
		
		FOR(c, 1, C >> 1){
			int dist = 500;
			
			Letter[0] = s[pos][c];
			Letter[1] = s[pos][C + 1 - c];
			
			for (char x = 'A'; x <= 'Z'; ++x){
				d[0] = abs(int(Letter[0] - x));
				d[1] = abs(int(Letter[1] - x));
				
				d[0] = min(d[0], 26 - d[0]);
				d[1] = min(d[1], 26 - d[1]);
				
				dist = min(dist, d[0] + d[1]);
			}
			
			res += dist;
		}
	}
	
	if (C & 1){
		int pos = (C + 1) >> 1;
		
		FOR(r, 1, R >> 1){
			int dist = 500;
			
			Letter[0] = s[r][pos];
			Letter[1] = s[R + 1 - r][pos];
			
			for (char x = 'A'; x <= 'Z'; ++x){
				d[0] = abs(int(Letter[0] - x));
				d[1] = abs(int(Letter[1] - x));
				
				d[0] = min(d[0], 26 - d[0]);
				d[1] = min(d[1], 26 - d[1]);
				
				dist = min(dist, d[0] + d[1]);
			}
			
			res += dist;
		}
	}
	
	cout << res;
	
	return 0;
}
