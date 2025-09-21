#include <vector>
#include <array>
#include <algorithm>
#include <iostream>

typedef std::vector<int> vector;
typedef std::array<int,10> array;
// research all sorting in cpp
// try all sorting in cpp


void display(const array ar) {
	for (int x : ar) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}


void BubbleSort(array& ar) {

	/*
		BAD for large data set
		DECENT for small data set

		time comp: O(N^2)
	*/

	for (int i = 0; i < ar.size() - 1; ++i) {
		for (int j = 0; j < ar.size() - 1 - i; ++j) {
			if (ar[j] > ar[j + 1]) {
				int temp = ar[j + 1];
				ar[j + 1] = ar[j];
				ar[j] = temp;
			}
		}
	}

}


void InsertionSort(array& ar) {

	/*
		BAD for Large data set
		DECENT for small data set
		(better than bubble sort as it takes lesser steps)

		time comp: O(N^2)
		best case: O(N)
	*/


	for (int i = 1; i < ar.size(); ++i) {
		int temp = ar[i];
		int j = i - 1;

		while (j >= 0 && temp < ar[j]) {
			ar[j + 1] = ar[j];
			--j;
		}
		ar[j + 1] = temp;
	}
}



void SelectionSort(array& ar) {

	/*
		BAD for large data set
		DECENT for small data set

		time comp : O(N^2)
	*/

	for (int i = 0; i < ar.size() - 1; ++i) {
		int min = i;

		for (int j = i + 1; j < ar.size(); ++j) {
			if (ar[min] > ar[j]) {
				min = j;
			}
		}
		int temp = ar[i];
		ar[i] = ar[min];
		ar[min] = temp;
	}
}

class QuickSort {
	/*
		BEST for large data set
		BAD for small data set

		time comp : O(N log N)
		worst time comp: O(N^2)			(nearly sorted array case)
	*/

protected:
	int partition(array& ar, int low, int high) {						// helper function for QuickSort

		int pivot = ar[high];

		int i = low;

		for (int j = low; j <= high; ++j) {
			if (ar[j] < pivot) {
				std::swap(ar[i], ar[j]);
				++i;
			}
		}

		std::swap(ar[i], ar[high]);
		return i;
	}

public:
	void sort(array& ar, int low, int high) {
		if (high <= low) {
			return;
		}

		int pivot = partition(ar, low, high);
		sort(ar, low, pivot - 1);
		sort(ar, pivot + 1, high);
	}
};

class RandomizedQuickSort : public QuickSort {
	/*
		
		BEST for large data set
		BAD for small data set

		average time comp : O(N log N)
		worst time comp: O(N log N)
		space comp: O(N)	
	
	*/
	int partition(array& ar, int low, int high) {
		srand(time(NULL));
		int r = low + (rand() % (high - low));
		std::swap(ar[r], ar[high]);

		int pivot = ar[high];

		int i = low;

		for (int j = low; j <= high; ++j) {
			if (ar[j] < pivot) {
				std::swap(ar[i], ar[j]);
				++i;
			}
		}

		std::swap(ar[i], ar[high]);
		return i;
	}
};



class MergeSort {
	/*
		GOOD for large data set 
		BAD for small data set

		time comp: O(N log N)
		space comp: O(N)
	*/

	void merge(vector& ar, int s, int m, int e) {

		vector v1 = {ar.begin() + s, ar.begin() + m + 1};
		vector v2 = {ar.begin() + m + 1, ar.begin() + e + 1};

		int i = s, l = 0, r = 0;

		while (l < v1.size() && r < v2.size()) {
			if (v1[l] < v2[r]) {
				ar[i] = v1[l++];
			}
			else {
				ar[i] = v2[r++];
			}
			++i;
		}

		while (l < v1.size()) {
			ar[i++] = v1[l++];
		}
		while (r < v2.size()) {
			ar[i++] = v2[r++];
		}
	}

public:
	void sort(vector& ar, int s, int e) {
		if (e - s + 1 <= 1) return; 

		int m = (s + e) / 2;

		sort(ar, s, m);
		sort(ar, m + 1, e);
		merge(ar, s, m, e);
	}
};




void countingSort(int n, int a[]){
	/*
		time comp: O(n)

		ONLY USE WHEN repetative ELEMENTS PRESENT
	*/

    //frequency array setup

    int k = 0;
    for (int i = 0; i < n; ++i){
        if (a[i] > k){
            k = a[i];
        }
    }

    int frequency[k+1];

    for (int i = 0; i < n; ++i){
        frequency[a[i]-1] += 1;
    }

    for (int i = 1; i < k; ++i){
        frequency[i] = frequency[i-1] + frequency[i];
    }

    // third (sorted) array creation
    int t[n];

    for (int i = n-1; i >= 0; --i){
        t[frequency[a[i]-1]-1] = a[i];
        frequency[a[i]-1] -= 1;
    }
}


class heap{
    public:
    
    void heapify(int ar[], int n,int i){
        int la = i;
        int l = (2*i) + 1;
        int r = (2 * i) + 2;
        
        if (l < n && ar[la] < ar[l]){
            la = l;
        }
        if (r < n && ar[la] < ar[r]){
            la = r;
        }
        
        if (la != i ){
            std::swap(ar[i],ar[la]);
            heapify(ar,n,la);
        }
    }
    
    void sort(int ar[], int n){
        for (int i = (n/2) - 1; i >= 0; --i){
            heapify(ar,n,i);
        }
        
        for (int i = n - 1; i > 0; --i){
            std::swap(ar[0],ar[i]);
            
            heapify(ar,i,0);
        }
    }
};


void bucketSort(vector& v){

	vector freq(*std::max_element(v.begin(), v.end()) + 1, 0); 

	for(int i : v) freq[i] += 1;

	v.clear();

	for(int i = 0; i < freq.size(); ++i){
		for(int j = 0; j < freq[i]; ++j) v.push_back(i);
	}
}



int main() {

	array ar{ 100,3,45,7,8,4,2,21,56,7 };
	BubbleSort(ar);
	display(ar);

	ar = { 100,3,45,7,8,4,2,21,56,7 };
	InsertionSort(ar);
	display(ar);

	ar = { 100,3,45,7,8,4,2,21,56,7 };
	SelectionSort(ar);
	display(ar);

	ar = { 100,3,45,7,8,4,2,21,56,7 };
	QuickSort qsort;
	qsort.sort(ar, 0, ar.size() - 1);
	display(ar);

	ar = { 100,3,45,7,8,4,2,21,56,7 };
	RandomizedQuickSort rqsort;
	rqsort.sort(ar, 0, ar.size() - 1);
	display(ar);

	vector AR { 100,3,45,7,8,4,2,21,56,7 };
	MergeSort msort;
	msort.sort(AR, 0, AR.size());
	display(ar);

	// count
	int a[4] {4,3,2,1};
	countingSort(4,a);
	for(int x: a){
        std::cout << x << " ";
    }   std::cout << '\n';

    
    int arr[5]{5,4,3,2,1};
    heap Heap;
    Heap.sort(arr,(sizeof(a)/sizeof(a[0])));
    for(int x : arr){ 
        std::cout << x << " ";
    }   std::cout << '\n';
	
	// radix
	// shell
	

	// bucket

	vector bucketVec {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	bucketSort(bucketVec);
	std::cout << "\n";
	for(int i : bucketVec) std::cout << i << " ";
	std::cout << "\n";

	return 0;
}
