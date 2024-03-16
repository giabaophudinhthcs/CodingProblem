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

int n, k, a[505][505], R1[505][505], R2[505][505], X1[3], Y1[3], X2[3], Y2[3];
queue<ii> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	X1[0] = 0;
	Y1[0] = 1;
	X1[1] = 1;
	Y1[1] = 0;
	X1[2] = 1;
	Y1[2] = 1;
	
	X2[0] = 0;
	Y2[0] = -1;
	X2[1] = 1;
	Y2[1] = 0;
	X2[2] = 1;
	Y2[2] = -1;	
	
	cin >> n >> k;
	
	FOR(x, 1, n){
		FOR(y, 1, n){
			a[x][y] = 0;
			R1[x][y] = R2[x][y] = -1;
		}
	}
	
	FOR(x, 1, k){
		int u, v;
		cin >> u >> v;
		a[u][v] = 1;
	}
	
	R1[1][1] = 0;
	q.push({1, 1});
	
	while (!q.empty()){
		ii S = q.front();
		q.pop();
		
		FOR(t, 0, 2){
			if (!a[S.ff + X1[t]][S.ss + Y1[t]] && R1[S.ff + X1[t]][S.ss + Y1[t]] == -1){
				R1[S.ff + X1[t]][S.ss + Y1[t]] = R1[S.ff][S.ss] + 1;
				q.push({S.ff + X1[t], S.ss + Y1[t]});
			}
		}
	}
	
	R2[1][n] = 0;
	q.push({1, n});
	
	while (!q.empty()){
		ii S = q.front();
		q.pop();
		
		FOR(t, 0, 2){
			if (!a[S.ff + X2[t]][S.ss + Y2[t]] && R1[S.ff + X1[t]][S.ss + Y1[t]] == -1){
				R1[S.ff + X1[t]][S.ss + Y1[t]] = R1[S.ff][S.ss] + 1;
				q.push({S.ff + X1[t], S.ss + Y1[t]});
			}
		}
	}
	
	return 0;
}
