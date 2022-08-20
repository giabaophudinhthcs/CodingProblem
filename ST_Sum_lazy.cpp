#include <bits/stdc++.h>
using namespace std;

const int nMax = 4e6 + 40;

class ST_Sum_lazy{
	public:
		int tree[nMax];
		int lazy[nMax] = {0};
		void updateUtil(int ss, int se, int l, int r, int x, int si);
		void update(int n, int l, int r, int x);
		int sumUtil(int ss, int se, int l, int r, int si);
		int sum(int n, int l, int r);
		void initTree(int arr[], int ss, int se, int si);
    	void print();
};

void ST_Sum_lazy::print(){
    for (int i = 0; i < 9; ++i){
        cout << this->tree[i] << " ";
    }
    cout << "\n";
}

void ST_Sum_lazy::updateUtil(int ss, int se, int l, int r, int x, int si){
	// Step 1:
	if (this->lazy[si] != 0){
		this->tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se){
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	
	// Step 2:
	// Case 1:
	if (ss > se || se < l || ss > r) return;
	
	// Case 2:
	if (ss >= l && se <= r){
		this->tree[si] += (se - ss + 1) * x;
		if (ss != se){
			lazy[2 * si + 1] += x;
			lazy[2 * si + 2] += x;
		}
	}
	
	// Case 3:
	int sm = ss + (se - ss) / 2;
	this->updateUtil(ss, sm, l, r, x, 2 * si + 1);
	this->updateUtil(sm + 1, se, l, r, x, 2 * si + 2);
	tree[si] = tree[2 * si + 1] + tree[2 * si + 2];
}

void ST_Sum_lazy::update(int n, int l, int r, int x){
	updateUtil(0, n - 1, l, r, x, 0);
}

int ST_Sum_lazy::sumUtil(int ss, int se, int l, int r, int si){
	if (this->lazy[si] != 0){
		this->tree[si] += (se - ss + 1) * lazy[si];
		if (ss != se){
			lazy[2 * si + 1] += lazy[si];
			lazy[2 * si + 2] += lazy[si];
		}
		lazy[si] = 0;
	}
	
	if (ss > se || ss > qe || se < qs) return 0;
	
	if (se <= r && l <= ss) return this->tree[si];
	
	int sm = ss + (se - ss) / 2;
	return this->sumUtil(ss, sm, l, r, 2 * si + 1) + this->sumUtil(sm + 1, se, l, r, 2 * si + 2);
}

int ST_Sum_lazy::sum(int n, int l, int r){
	if (l < 0 || r < 0 || l > n - 1 || r > n - 1 || l > r){
		cout << "Invalid input!\n";
		return -1;
	}
	return this->sumUtil(0, n - 1, l, r, 0);
}

void ST_Sum_lazy::initTree(int arr[], int ss, int se, int si){
	if (ss == se){
		this->tree[si] = arr[ss];
		return;
	}
	int sm = ss + (se - ss) / 2;
	this->initTree(arr, ss, sm, 2 * si + 1);
	this->initTree(arr, sm + 1, se, 2 * si + 2);
	this->tree[si] = this->tree[2 * si + 1] + this->tree[2 * si + 2];
}

int main(){
	// Driver code
}
