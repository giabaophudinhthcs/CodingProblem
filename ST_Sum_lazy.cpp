#include <bits/stdc++.h>
using namespace std;

const int nMax = 4e6 + 40;

class ST_Sum{
	public:
		int tree[nMax];
		int lazy[nMax];
		void updateUtil(int stStart, int stEnd, int s, int e, int val, int si);
		void update(int arr[], int n, int s, int e, int val);
		int sumUtil(int stStart, int stEnd, int qStart, int qEnd, int si);
		int sum(int n, int qStart, int qEnd);
		void initTree(int arr[], int stStart, int stEnd, int si);
    	void print();
};

void ST_Sum::print(){
    for (int i = 0; i < 9; ++i){
        cout << this->tree[i] << " ";
    }
    cout << "\n";
}

void ST_Sum::updateUtil(int stStart, int stEnd, int s, int e, int val, int si){
	// ??
}

void ST_Sum::update(int arr[], int n, int i, int val){
	// ??
}

int ST_Sum::sumUtil(int stStart, int stEnd, int qStart, int qEnd, int si){
	// ??
}

int ST_Sum::sum(int n, int qStart, int qEnd){
	// ??
}

void ST_Sum::initTree(int arr[], int stStart, int stEnd, int si){
	if (stStart == stEnd){
		this->tree[si] = arr[stStart];
		return;
	}
	int stMid = stStart + (stEnd - stStart) / 2;
	this->initTree(arr, stStart, stMid, 2 * si + 1);
	this->initTree(arr, stMid + 1, stEnd, 2 * si + 2);
	this->tree[si] = this->tree[2 * si + 1] + this->tree[2 * si + 2];
}

int main(){
	// Driver code
}
