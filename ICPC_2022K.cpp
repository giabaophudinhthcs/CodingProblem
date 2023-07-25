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

class Point{
	public:
		int x, y;
		
		bool operator<(Point o){
			return (this->x * o.y < this->y * o.x);
		}
};

int n, cnt = 0, X = -1e6, Y = -1e6;
Point P[nMax];
map<ii, int> m;

int Gcd(int gx, int gy){
	return ((!gy) ? gx : Gcd(gy, gx % gy));
}

void gen(){
	FOR(a, 1, 3000){
		FOR(b, 1, 3000){
			if (Gcd(a, b) == 1){
				int C = a * a + b * b, c;
				c = sqrt(C);
				if (c * c == C){
					cnt++;
					P[cnt].x = a;
					P[cnt].y = b;
				}
			}
		}
	}
	sort(P + 1, P + cnt + 1);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	gen();
	cin >> n;
	cout << "YES\n" << X << " " << Y << "\n";
	FOR(k, 1, n - 2){
		X += P[k].x;
		Y += P[k].y;
		cout << X << " " << Y << "\n";
	}
	cout << X << " -1000000\n";
	return 0;
}
