#include <bits/stdc++.h>

using namespace std;

const int nMax = 1e4 + 10;

class DSU{
    public:
    	int parent[nMax];
    	void make(int x);
    	int find(int v);
    	void combine(int x, int y);
};

void DSU::make(int x){
    this->parent[x] = x;
}

int DSU::find(int x){
    return (x == this->parent[x]) ? x : this->find(this->parent[x]);
}

void DSU::combine(int x, int y){
    this->parent[this->find(y)] = this->find(x);
}

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
