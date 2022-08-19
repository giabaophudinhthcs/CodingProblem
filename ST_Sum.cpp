#include <bits/stdc++.h>
using namespace std;

const int nMax = 4e6 + 40;

class ST_Sum{
	public:
		int tree[nMax];
		void updateUtil(int stStart, int stEnd, int i, int val, int si);
		void update(int arr[], int n, int i, int val);
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

void ST_Sum::updateUtil(int stStart, int stEnd, int i, int val, int si){
	if (i < stStart || i > stEnd) return;
	this->tree[si] += val;
	if (stStart != stEnd){
		int stMid = stStart + (stEnd - stStart) / 2;
		this->updateUtil(stStart, stMid, i, val, 2 * si + 1);
		this->updateUtil(stMid + 1, stEnd, i, val, 2 * si + 2);
	}
}

void ST_Sum::update(int arr[], int n, int i, int val){
	if (i < 0 || i > n - 1){
		cout << "Invalid input!\n";
		return;
	}
	arr[i] += val;
	this->updateUtil(0, n - 1, i, val, 0);
}

int ST_Sum::sumUtil(int stStart, int stEnd, int qStart, int qEnd, int si){
	if (stEnd < qStart || qEnd < stStart) return 0;
	if (stEnd <= qEnd && qStart <= stStart) return this->tree[si];
	int stMid = stStart + (stEnd - stStart) / 2;
	return this->sumUtil(stStart, stMid, qStart, qEnd, 2 * si + 1) + this->sumUtil(stMid + 1, stEnd, qStart, qEnd, 2 * si + 2);
}

int ST_Sum::sum(int n, int qStart, int qEnd){
	if (qStart < 0 || qEnd < 0 || qStart > n - 1 || qEnd > n - 1 || qStart > qEnd){
		cout << "Invalid input!\n";
		return -1;
	}
	return this->sumUtil(0, n - 1, qStart, qEnd, 0);
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
