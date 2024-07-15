#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i <= b ; ++i)
#define FORD(i, a, b) for(int i = a; i >= b ; --i)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pb push_back
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

class Coor{
	public:
		int X, Y;
};

int c, a, dirX[4], dirY[4];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	// left
	dirX[0] = 0;
	dirY[0] = -2;
	
	// up
	dirX[1] = -1;
	dirY[1] = -1;
	
	// down
	dirX[2] = 1;
	dirY[2] = -1;
	
	// stay
	dirX[3] = 0;
	dirY[3] = -1;
		
	cin >> c >> a;
	queue<Coor> q;
	string s[c];
	int d[c][a];
	FOR(x, 0, c - 1){
		FOR(y, 0, a - 1) d[x][y] = -1;
	}
	FOR(x, 0, c - 1) cin >> s[x];
	d[0][0] = 0;
	q.push({0, 0});
	while (!q.empty()){
		Coor v = q.front();
		q.pop();
		if (v.X == c - 1){
			cout << d[v.X][v.Y] + 1;
			return 0;
		}
		FOR(t, 0, 2){
			Coor u;
			u.X = v.X + dirX[t];
			u.Y = (v.Y + dirY[t] + a) % a;
			
			if (u.X < 0) continue;
			
			if (s[u.X][u.Y] == '.' && s[u.X][(u.Y + 1) % a] == '.' && d[u.X][u.Y] == -1){
				d[u.X][u.Y] = d[v.X][v.Y] + 1;
				q.push(u);
			}
		}
		
		Coor u;
		u.X = v.X + dirX[3];
		u.Y = (v.Y + dirY[3] + a) % a;
		
		if (u.X >= 0 && s[u.X][u.Y] == '.' && d[u.X][u.Y] == -1){
			d[u.X][u.Y] = d[v.X][v.Y] + 1;
			q.push(u);
		}
	}
	cout << -1;
	return 0;
}
