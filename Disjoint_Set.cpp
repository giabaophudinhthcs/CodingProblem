#include <bits/stdc++.h>

using namespace std;

const int nMax = 1e4 + 10;

class DSU{
    public:
    	int parent[nMax];
        int sz[nMax];
    
    	void make(int v){
            this->parent[v] = v;
            sz[v] = 1;
        }
    
    	int find(int v){
            return (v == this->parent[v]) ? v : this->parent[v] = this->find(this->parent[v]);
        }
    
    	void combine(int x, int y){
            x = this->find(x);
            y = this->find(y);
            if (x != y){
                if (sz[x] < sz[y]) swap(x, y);
                this->parent[y] = x;
                sz[x] += sz[y];
            }
        }
};

DSU test;

int main(){
    int x, y, z, q;
    for (int i = 1; i <= nMax; ++i) test.make(i);
    cin >> q;
    for (int i = 1; i <= q; ++i){
        cin >> x >> y >> z;
        x = test.find(x);
        y = test.find(y);
        if (z == 1){
            if (x != y) test.combine(x, y);
        }else cout << ((x == y) ? 1 : 0) << "\n";
    }
}
