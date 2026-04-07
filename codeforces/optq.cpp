#include <bits/stdc++.h>
using namespace std;

// ---------- INSERTION SORT ----------
void insertionSort(vector<int>& a, int l, int r) {
    for (int i = l + 1; i <= r; i++) {
        int key = a[i], j = i - 1;
        while (j >= l && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// ---------- MEDIAN OF THREE ----------
int median3(vector<int>& a, int l, int r) {
    int m = (l + r) / 2;

    if (a[l] > a[m]) swap(a[l], a[m]);
    if (a[l] > a[r]) swap(a[l], a[r]);
    if (a[m] > a[r]) swap(a[m], a[r]);

    swap(a[m], a[r - 1]);
    return a[r - 1];
}

// ---------- PARTITION ----------
int partition(vector<int>& a, int l, int r) {
    int pivot = median3(a, l, r);
    int i = l, j = r - 1;

    while (true) {
        while (a[++i] < pivot);
        while (a[--j] > pivot);
        if (i >= j) break;
        swap(a[i], a[j]);
    }
    swap(a[i], a[r - 1]);
    return i;
}

// ---------- HEAPSORT FALLBACK ----------
void heapify(vector<int>& a, int n, int i, int offset) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < n && a[offset + l] > a[offset + largest]) largest = l;
    if (r < n && a[offset + r] > a[offset + largest]) largest = r;

    if (largest != i) {
        swap(a[offset + i], a[offset + largest]);
        heapify(a, n, largest, offset);
    }
}

void heapSort(vector<int>& a, int l, int r) {
    int n = r - l + 1;

    for (int i = n/2 - 1; i >= 0; i--)
        heapify(a, n, i, l);

    for (int i = n-1; i > 0; i--) {
        swap(a[l], a[l + i]);
        heapify(a, i, 0, l);
    }
}

// ---------- INTROSORT CORE ----------
void introsortUtil(vector<int>& a, int l, int r, int depthLimit) {
    while (r - l > 16) {

        if (depthLimit == 0) {
            heapSort(a, l, r);
            return;
        }

        depthLimit--;

        int p = partition(a, l, r);

        // recurse on smaller side
        if (p - l < r - p) {
            introsortUtil(a, l, p - 1, depthLimit);
            l = p + 1;
        } else {
            introsortUtil(a, p + 1, r, depthLimit);
            r = p - 1;
        }
    }

    insertionSort(a, l, r);
}

// ---------- ENTRY ----------
void introSort(vector<int>& a) {
    int depthLimit = 2 * log(a.size());
    introsortUtil(a, 0, a.size() - 1, depthLimit);
}


long long benchmark(vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();

    introSort(arr);

    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::microseconds>(end - start).count();


}



vector<int> sortedArray(int n) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    return a;
}


vector<int> reverseArray(int n) {
    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = n - i;
    return a;
}



vector<int> nearlySorted(int n) {
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    for (int i = 0; i < n/100; i++) {
        swap(a[rand()%n], a[rand()%n]);
    }
    return a;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> sizes = {10000, 100000, 1000000};

    for (int n : sizes) {
        cout << "\nSize: " << n << "\n";


     auto   test = sortedArray(n);
        cout << "Sorted: " << benchmark(test) << " us\n";

       auto  test = reverseArray(n);
        cout << "Reverse: " << benchmark(test) << " us\n";


      auto  test = nearlySorted(n);
        cout << "Nearly Sorted: " << benchmark(test) << " us\n";
    }
}






























