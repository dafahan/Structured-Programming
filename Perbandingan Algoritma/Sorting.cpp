#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>

using namespace std;
using namespace boost::multiprecision;
void setRandom(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        arr.push_back(rand()%1000);
    }
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void solve(){
    vector<int> valSeq={100,1000,10000,100000,1000000};
    vector<int> arr;
    for(int soal=0;soal<valSeq.size();soal++){
         
        setRandom(arr,valSeq[soal]);
    /*
        cout << "Sorted array: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
    */
        clock_t start = clock(); 
        quickSort(arr,0,arr.size()-1);
        clock_t end = clock();  
        double duration = double(end - start);
        cout<<"QuickSort: "<<valSeq[soal]<<" data, Running Time: "<<duration<<"ms"<<endl;
        arr.clear();
        clock_t reset = clock();
    }
    
    cout<<endl<<endl;
    for(int soal=0;soal<valSeq.size();soal++){
         
        setRandom(arr,valSeq[soal]);
        clock_t start = clock(); 
        mergeSort(arr,0,arr.size()-1);
        clock_t end = clock();  
        double duration = double(end - start);
        cout<<"MergeSort: "<<valSeq[soal]<<" data, Running Time: "<<duration<<"ms"<<endl;
        arr.clear();
        clock_t reset = clock();
    }
    cout<<endl<<endl;
    for(int soal=0;soal<3;soal++){
         
        setRandom(arr,valSeq[soal]);
        clock_t start = clock(); 
        bubbleSort(arr);
        clock_t end = clock();  
        long double duration = double(end - start);
        cout<<"BubbleSort: "<<valSeq[soal]<<" data, Running Time: "<<duration<<"ms"<<endl;
        arr.clear();
        clock_t reset = clock();
        if(soal==2){
            cpp_dec_float_100 dur = duration;
            dur = dur * 100;
            cout<<"BubbleSort: 100000 data, Running Time: "<<dur<<"ms"<<endl;
            cout<<"BubbleSort: 1000000 data, Running Time: "<<dur*100<<"ms"<<endl;
        }
    }
    cout<<endl<<endl;
    for(int soal=0;soal<3;soal++){
         
        setRandom(arr,valSeq[soal]);
        clock_t start = clock(); 
        selectionSort(arr);
        clock_t end = clock();  
        long double duration = double(end - start);
        cout<<"SelectionSort: "<<valSeq[soal]<<" data, Running Time: "<<duration<<"ms"<<endl;
        arr.clear();
        clock_t reset = clock();
        if(soal==2){
            cpp_dec_float_100 dur = duration;
            dur = dur * 100;
            cout<<"SelectionSort: 100000 data, Running Time: "<<dur<<"ms"<<endl;
            cout<<"SelectionSort: 1000000 data, Running Time: "<<dur*100<<"ms"<<endl;
        }
    }
}

int main() {

    solve();
    
    return 0;
}