// Link: https://oj.vnoi.info/problem/fc027_gears

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class point{
    public:
        ll x;
        ll y;
        void inp(){
            cin >> this->x >> this->y;
        }
};

class circle{
    public:
        point center;
        ll r;
        void inp(){
            this->center.inp();
            cin >> this->r;
        }
};

ll gcd(ll x, ll y){
    if (!x) return y;
    return gcd(y % x, x);
}

class fraction{
    public:
    ll tu;
    ll mau;
    
    void init(){
        this->tu = 1LL;
        this->mau = 1LL;
    }
    
    void simplify(){
        ll d = gcd(this->tu, this->mau);
        this->tu /= d;
        this->mau /= d;
    }
    
    fraction operator *(fraction x){
        fraction ans;
        ans.init();
        this->simplify();
        x.simplify();
        ans.tu = this->tu * x.tu;
        ans.mau = this->mau * x.mau;
        ans.simplify();
        return ans;
    }
};

ll sqr(ll a){
    return a * a;
}

ll sqr_dist(point A, point B){
    return sqr(A.x - B.x) + sqr(A.y - B.y);
}

bool isTangent(circle a, circle b){
    return (sqr_dist(a.center, b.center) == sqr(a.r + b.r));
}

int n, cnt = 0;
circle t[1010];
vector<int> adj[1010];
int dir[1010], par[1010], path[1010];
queue<int> q;
stack<int> e;
fraction ans;

bool isBipartite(){
    int s = 1;
    q.push(s);
    dir[s] = 1;
    par[s] = 1;
    while (!q.empty()){
        int t = q.front();
        q.pop();
        for (auto x: adj[t]){
            if (!dir[x]){
                q.push(x);
                dir[x] = dir[t] * (-1);
                par[x] = t;
            }else{
                if (dir[x] == dir[t]) return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans.init();
    cin >> n;
    if (n == 1){
        cout << "1 1";
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        t[i].inp();
        dir[i] = 0;
    }
    for (int i = 1; i < n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (isTangent(t[i], t[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    if (!isBipartite()){
        cout << -1;
        return 0;
    }
    if (!dir[n]){
        cout << 0;
        return 0;
    }
    int a = n;
    while (a != 1){
        e.push(a);
        a = par[a];
    }
    e.push(1);
    while (!e.empty()){
        cnt++;
        path[cnt] = e.top();
        e.pop();
    }
    for (int x = 1; x < cnt; ++x){
        fraction z;
        z.init();
        z.tu = t[path[x]].r;
        z.mau = t[path[x + 1]].r;
        z.simplify();
        ans = ans * z;
    }
    if (dir[n] == 1) cout << ans.mau << " " << ans.tu;
    else cout << ans.mau << " " << (-1) * ans.tu;
    return 0;
}
