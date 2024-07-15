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

int n, types[55][6], cnt, L[6], R[6];
ll dp[51][16][16][16][16][16], res = 0LL;
string s;

int Get_type(){
	if (s == "dp") return 1;
	if (s == "graph") return 2;
	if (s == "mathgeo") return 3;
	if (s == "ds") return 4;
	if (s == "adhoc") return 5;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	FOR(x, 1, n){
		types[x][1] = types[x][2] = types[x][3] = types[x][4] = types[x][5] = 0;
		
		cin >> cnt;
		FOR(y, 1, cnt){
			cin >> s;
			types[x][Get_type()] = 1;
		}
	}
	
	FOR(x, 1, 5) cin >> L[x] >> R[x];
	
	dp[0][0][0][0][0][0] = 1;
	
	FOR(prop, 1, n){
		FOR(DP, 0, 15){
			FOR(GRAPH, 0, 15){
				FOR(MATHGEO, 0, 15){
					FOR(DS, 0, 15){
						FOR(ADHOC, 0, 15){
							dp[prop][DP][GRAPH][MATHGEO][DS][ADHOC] = dp[prop - 1][DP][GRAPH][MATHGEO][DS][ADHOC];
							if (DP >= types[prop][1] && GRAPH >= types[prop][2] && MATHGEO >= types[prop][3] && DS >= types[prop][4] && ADHOC >= types[prop][5]) dp[prop][DP][GRAPH][MATHGEO][DS][ADHOC] += dp[prop - 1][DP - types[prop][1]][GRAPH - types[prop][2]][MATHGEO - types[prop][3]][DS - types[prop][4]][ADHOC - types[prop][5]];
						}
					}
				}
			}
		}
	}
	
	FOR(DP, L[1], R[1]){
		FOR(GRAPH, L[2], R[2]){
			FOR(MATHGEO, L[3], R[3]){
				FOR(DS, L[4], R[4]){
					FOR(ADHOC, L[5], R[5]) res += dp[n][DP][GRAPH][MATHGEO][DS][ADHOC];
				}
			}
		}
	}
	
	if (L[1] + L[2] + L[3] + L[4] + L[5] == 0) res--;
	
	cout << res;
	
	return 0;
}
