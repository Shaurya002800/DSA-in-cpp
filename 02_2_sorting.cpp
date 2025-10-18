//MERGE SORT


#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    int left = low;
    int right = mid + 1;
    vector<int> temp;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i - low];
    }
}

void mergeSorting(vector<int> &arr, int low, int high){
    if(low >= high) return;
    int mid = (low + high) / 2;
    
    mergeSorting(arr, low, mid);
    mergeSorting(arr, mid + 1, high);
    merge(arr, low, mid, high);
}


int main(){
    int n;
    cout << "enter the size of array: ";
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    mergeSorting(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
}





//QUICK SORT               Time complexity is o(nlogn) and space complexity is o(n)


#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    qs(arr, 0, n - 1);

    for(auto it : arr){
        cout << it << " ";
    }
}