#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

void genTestCase(vector<int>& v, int k);
void genTestCase1(vector<int>& v);
void genTestCase2(vector<int>& v);
void genTestCase3(vector<int>& v);
void genTestCase4(vector<int>& v);

bool check(vector<int>& v, int& errind);

void printFirstKNum(vector<int>&v, int k);

void quickSort(vector<int>& v, int left, int right);
int partition(vector<int>& v, int left, int right);
int main() {
	vector<int> v;
	for (int i = 1; i < 5; i++) {
		cout << "Case #" << i << ":" << endl;
		cout << "Before sort:" << endl;
		genTestCase(v, i);
		printFirstKNum(v, 20);

		cout << "After sort:" << endl;
		unsigned long long startTime = (unsigned long long)clock();
		quickSort(v, 0, v.size()-1);
		unsigned long long endTime = (unsigned long long)clock();
		printFirstKNum(v, 20);
		cout << "Sort time:" << (endTime - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
		int errind;
		if (!check(v, errind)) {
			cout << "Error happened!!!\t" << "error index:" << errind << endl;
			cout << v[errind - 1] << "\t" << v[errind] << endl;
		}
		else {
			cout << "Check passed!" << endl;
		}
		cout << endl;
	}
}

void quickSort(vector<int>& v, int left, int right) {
	if (left <= right) {
		int pivot = partition(v, left, right);
		quickSort(v, left, pivot - 1);
		quickSort(v, pivot + 1, right);
	}
}

int partition(vector<int>& v, int left, int right) {
	// random select
	srand(unsigned int(time(NULL)));
	int length = right - left + 1;
	int ind = rand() % length + left;
	// swap to the last one
	swap(v[ind], v[right]);

	int selection = v[right];
	int small = left;
	for (int i = left; i < right; i++) {
		if (v[i] < selection) {
			if (small != i)
				swap(v[small], v[i]);
			small++;
		}
	}

	swap(v[small], v[right]);

	return small;
}


// 1,2 fucntional test
// 3 edge test
// 4 special input test
void genTestCase(vector<int>& v, int k) {
	v.clear();
	switch (k) {
	case 1:
		genTestCase1(v);
		break;
	case 2:
		genTestCase2(v);
		break;
	case 3:
		genTestCase3(v);
		break;
	case 4:
		genTestCase4(v);
		break;
	default:
		genTestCase4(v);
	}

	return;
}

// functional test, small
void genTestCase1(vector<int>& v) {
	int count = 100;
	int max = 50;
	int min = 1;
	int range = max - min + 1;
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < count; i++) {
		int next = rand() % range + min;
		v.push_back(next);
	}
	return;
}

// functional test, large
void genTestCase2(vector<int>& v) {
	int count = 10000;
	int max = 1000;
	int min = 1;
	int range = max - min + 1;
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < count; i++) {
		int next = rand() % range + min;
		v.push_back(next);
	}
	return;
}

// functional test, edge
void genTestCase3(vector<int>& v) {
	int count = 100;
	int number = 5;
	for (int i = 0; i < count; i++) {
		v.push_back(number);
	}
	return;
}

// special test
void genTestCase4(vector<int>& v) {
	return;
}

bool check(vector<int>& v, int& errind) {
	bool sorted = true;
	errind = -1;
	int len = v.size();
	for (int i = 1; i < len; i++) {
		if (v[i] < v[i - 1]) {
			sorted = false;
			errind = i;
			break;
		}
	}

	return sorted;
}

void printFirstKNum(vector<int>&v, int k) {
	for (int i = 0; i < k && i<v.size(); i++) {
		cout << v[i] << "\t";
		if ((i + 1) % 10 == 0) {
			cout << endl;
		}
	}

	return;
}