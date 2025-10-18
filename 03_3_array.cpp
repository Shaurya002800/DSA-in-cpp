// Pascal Triangle


//Give R&C, print the element at that place

// r-1(combination)c-1

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n = 6;
//     for(int i = 1; i <= n; i++){
//         vector<int> temp;
//         temp.push_back(1);
//         int ele = 1;
//         for(int j = 1; j < i; j++){
//             ele = (ele * (i - j)) / j;
//             temp.push_back(ele);
//         }
//         for(int it : temp){
//             cout << it << " ";
//         }
//         cout << endl;
//     } 
// }







//Majority Element [> n/3 times]


//Better solution     

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
//     int n = arr.size();
//     for(int i = 0; i < n; i++){
//         int count = 1;
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }
//         if(count > n/3){
//             cout << arr[i] << " " << count << endl;
//         }
//     }

//     return 0; 
// }





//Majority Element [> n/3 times]


//Better solution     

// #include <bits/stdc++.h>         //TM o(n)  SM o(n)
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
//     int n = arr.size();
//     map<int, int> temp;
//     for(int i = 0; i < n; i++){
//         temp[arr[i]]++;
//     }
//     for(auto it : temp){
//         if(it.second > n/3){
//             cout << it.first << " ";
//         }
//     }
//     return 0; 
// }




// Optimal Solution

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 1, 1, 1, 3, 2, 2, 2};
//     int n = arr.size();

//     int count1 = 0, count2 = 0;
//     int ele1 = INT_MIN, ele2 = INT_MIN;

//     // Phase 1: Find potential candidates
//     for(int i = 0; i < n; i++) {
//         if(ele1 == arr[i]) {
//             count1++;
//         }
//         else if(ele2 == arr[i]) {
//             count2++;
//         }
//         else if(count1 == 0) {
//             ele1 = arr[i];
//             count1 = 1;
//         }
//         else if(count2 == 0) {
//             ele2 = arr[i];
//             count2 = 1;
//         }
//         else {
//             count1--;
//             count2--;
//         }
//     }

//     // Phase 2: Verify the actual frequencies
//     count1 = count2 = 0;
//     for(int i = 0; i < n; i++) {
//         if(arr[i] == ele1) count1++;
//         else if(arr[i] == ele2) count2++;
//     }

//     if(count1 > n / 3) cout << ele1 << " ";
//     if(count2 > n / 3) cout << ele2 << " ";

//     return 0;
// }






// 3 SUM



//Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {-1, 0, 1, 2, -1, -4};
//     int n = arr.size();
//     set<vector<int>> ans;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 if(arr[i] + arr[j] + arr[k] == 0){
//                     vector<int> temp = {arr[i], arr[j], arr[k]};
//                         sort(temp.begin(), temp.end());
//                     ans.insert(temp);
//                 }
//             }
//         }
//     }
//     for(auto it : ans) {
//         for(int x : it) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }






// Better Solution        TM o(n^2logn)  SM o(n + k*3)



// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {-1, 0, 1, 2, -1, -4};
//     int n = arr.size();
//     set<vector<int>> temp;
//     for(int i = 0; i < n - 2; i++){
//         set<int> hat;
//         for(int j = i + 1; j < n; j++){
//             int rem = -(arr[i] + arr[j]);
//             if(hat.find(rem) != hat.end()){
//                 vector<int> noob = {arr[i], arr[j], rem};
//                 sort(noob.begin(), noob.end());
//                 temp.insert(noob); 
//             } 
//             hat.insert(arr[j]);
//         }
//     }
//     for(auto it : temp) {
//         for(int x : it) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




// Optimal solution


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {-2, -2, -2, -1, -1, -1, 0, 0, 0, 2, 2, 2, 2};
//     int n = arr.size();
//     vector<vector<int>> result;
//     sort(arr.begin(), arr.end());
//     for (int i = 0; i < n - 2; i++) {
//         if (i > 0 && arr[i] == arr[i - 1]) continue;

//         int j = i + 1;
//         int k = n - 1;

//         while (j < k) {
//             int sum = arr[i] + arr[j] + arr[k];
//             if (sum == 0) {
//                 result.push_back({arr[i], arr[j], arr[k]});
//                 j++;
//                 k--;
//                 while (j < k && arr[j] == arr[j - 1]) j++;
//                 while (j < k && arr[k] == arr[k + 1]) k--;
//             }
//             else if (sum < 0) {
//                 j++;
//             }
//             else {
//                 k--;
//             }
//         }
//     }
//     for (auto triplet : result) {
//         for (int num : triplet) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }






// 4 SUM 


// Brute force solution

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 0, -1, 0, -2, 2};
//     int n = arr.size();
//     int target = 0;
    // set<vector<int>> ans;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             for(int k = j + 1; k < n; k++){
//                 for(int l = k + 1; l < n; l++){
//                     int sum = arr[i] + arr[j] + arr[k] + arr[l];
//                     if(sum == target){
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end());
//                         ans.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     for(auto it : ans) {
//         for(int x : it) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }



//Better solution

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 0, -1, 0, -2, 2};
//     int n = arr.size();
//     int target = 0;
//     set<vector<int>> ans;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             set<int> check;
//             for(int k = j + 1; k < n; k++){
//                 int rem = target - (arr[i] + arr[j] + arr[k]);
//                 if(check.find(rem) != check.end()){
//                     vector<int> temp = {arr[i], arr[j], arr[k], rem};
//                     sort(temp.begin(), temp.end());
//                     ans.insert(temp);
//                 }else{
//                     check.insert(arr[k]);
//                 }
//             }
//         }
//     }
//     for(auto it : ans) {
//         for(int x : it) {
//             cout << x << " ";
//         }
//         cout << endl;
//     }
// }




// //Optimal solution           TM o(n^3) SM (k)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 0, -1, 0, -2, 2};
//     int n = arr.size();
//     int target = 0;
//     set<vector<int>> ans;
//     sort(arr.begin(), arr.end());
//     for(int i = 0; i < n; i++){
//         if(i > 0 && arr[i] == arr[i - 1]) continue;
//         for(int j = i + 1; j < n; j++){
//             if(j > i + 1 && arr[j] == arr[j - 1]) continue;
//             int k = j + 1;
//             int l = n - 1;
//             while(k < l){
//                 int sum = arr[i] + arr[j] + arr[k] + arr[l];
//                 if(sum == 0){
//                     cout << arr[i] << " " << arr[j] << " " << arr[k] << " " << arr[l] << "\n";
//                     k++;
//                     l--;
//                     while(arr[k] == arr[k - 1]) j++;
//                     while(arr[l] == arr[l + 1]) l--;
//                 }
//                 else if(sum < 0){
//                     k++;
//                 } else {
//                     l--;
//                 }
//             }
//         }
//     }
//     return 0;
// }






// Largest subarray with 0 sum



//Brute force solution            TM o(n^2)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
//     int n = arr.size();
//     int target = 0;
//     int maxLen = 1;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         int count = 0;
//         for(int j = i; j < n; j++){
//             sum = sum + arr[j];
//             if(sum == target){
//                 maxLen = max(maxLen, j - i + 1);
//             }
//         }
//     }
//     cout << maxLen << endl; 
//     return 0;
// }





//Otpimal solution      TM o(n)  SM o(n)



// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
//     int n = arr.size();
//     int target = 0;
//     unordered_map<int, int> hash;
//     int maxi = 0;
//     int sum = 0;
//     for(int i = 0; i < n; i++){
//         sum += arr[i];
//         if(sum == 0){
//             maxi = i + 1;
//         }
//         else{
//             if(hash.find(sum) != hash.end()){
//                 maxi = max(maxi, i - hash[sum]);
//             }
//             else {
//                 hash[sum] = i;
//             }
//         }
//     }
//     for(auto it : hash){
//         cout << it.first << " -> " << it.second << endl;
//     }
//     // cout << maxi << endl;
//     return 0;
// }






// count subarrays with XOR as k



 // Brute force solution   (same as better solution only the third for loop will be included form i to k)


//Better solution                            TM o(n^2)  SM o(1)
 
// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int n = arr.size();
//     int target = 6;
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         int xorr = 0;
//         for(int j = i; j < n; j++){
//             xorr = xorr ^ arr[j];
//             if(xorr == target){
//                 count++;
//             } 
//         }
//     }
//     cout << count << endl;
//     return 0;
// }




// Optimal solution

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {4, 2, 2, 6, 4};
//     int n = arr.size();
//     int target = 6;
//     map<int, int> temp;
//     int xorr = 0;
//     temp[xorr]++;
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         xorr ^= arr[i];
//         int x = xorr ^ target;
//         cnt += temp[x];
//         temp[xorr]++;
//     }
//     cout << cnt << endl;
//     return 0;
// }







//merge 2 sorted arrays without extra space


//Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {0, 2, 6, 8, 9};
//     int n1 = arr1.size(); 
//     int n2 = arr2.size(); 
//     set<int> ans;
//     for(int i = 0; i < n1 + n2; i++){
//         if(i < n1){
//             ans.insert(arr1[i]);
//         }
//         else if(i >= n1){
//             ans.insert(arr2[i - n1]);
//         }
//     }
//     for(auto it : ans){
//         cout << it << " ";
//     }
// }



// Better solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {0, 2, 6, 8, 9};
//     int n1 = arr1.size(); 
//     int n2 = arr2.size(); 
//     int i = 0;
//     int j = 0;
//     int index = 0;
//     int ans[n1 + n2];
//     while(i < n1 && j < n2){
//         if(arr1[i] <= arr2[j]){
//             ans[index] = arr1[i];
//             i++, index++;
//         }
//         else {
//             ans[index] = arr2[j];
//             j++, index++;
//         }
//     }
//     while(i < n1){
//         ans[index++] = arr1[i++];
//     }
//     while(j < n2){
//         ans[index++] = arr2[j++];
//     }


//     for(int k = 0; k < n1 + n2; k++){
//         cout << ans[k] << " ";
//     }
// }



// Better but bit difficult


// #include <bits/stdc++.h>
// using namespace std;

//  int main(){
//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {0, 2, 6, 8, 9};
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     int i = n1 - 1;
//     int j = 0;
//     while(i >= 0 && j < n2){
//         if(arr1[i] > arr2[j]){
//             swap(arr1[i], arr2[j]);
//             i--, j++;
//         }else {
//             break;
//         }
//     }
//     for(auto it : arr1){
//         cout << it << " ";
//     }
//  }




//optimal solution                // NHI HUAAAAAAAAAAAAAAAAAAAAAAAA

// #include <bits/stdc++.h>
// using namespace std;

// void swapIfGreater(int &a, int &b) {
//     if (a > b) swap(a, b);
// }

// int nextGap(int gap) {
//     if (gap <= 1) return 0;
//     return (gap / 2) + (gap % 2);
// }

// int main() {
//     int arr1[] = {1, 3, 5, 7};
//     int arr2[] = {0, 2, 6, 8, 9};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);

//     int gap = nextGap(n1 + n2);
//     while (gap > 0) {
//         // Compare elements in arr1
//         for (int i = 0; i + gap < n1; i++) {
//             swapIfGreater(arr1[i], arr1[i + gap]);
//         }

//         // Compare elements between arr1 and arr2
//         int i = (gap > n1) ? 0 : n1 - gap;
//         int j = gap > n1 ? gap - n1 : 0;

//         for (; i < n1 && j < n2; i++, j++) {
//             swapIfGreater(arr1[i], arr2[j]);
//         }

//         // Compare elements in arr2
//         for (int j = 0; j + gap < n2; j++) {
//             swapIfGreater(arr2[j], arr2[j + gap]);
//         }

//         gap = nextGap(gap);
//     }

//     cout << "arr1: ";
//     for (int i = 0; i < n1; i++) cout << arr1[i] << " ";
//     cout << "\narr2: ";
//     for (int i = 0; i < n2; i++) cout << arr2[i] << " ";
// }







// Find the missing and reapting number



// Brute Force solution


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr ={4, 3, 6, 2, 5, 5};
//     int n = arr.size();
//     map<int, int> temp;
//     for (int i = 1; i < n + 1; i++) {
//         temp[i] = 0;
//     }
//     for(int i = 0; i < n; i++){
//         temp[arr[i]]++;
//     }
//     for(auto it : temp){ 
//         if (it.second == 2){
//             cout << it.first << " "; 
//         }
//         if(it.second == 0){
//             cout << it.first << " ";
//         }
//     }
// }






// Find the missing and reapting number



// Brute force solution


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {4, 3, 1, 2, 5, 1};
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     int repeating = -1, missing = -1;

//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i] == arr[i + 1]) {
//             repeating = arr[i];
//         } else if (arr[i + 1] - arr[i] > 1) {
//             missing = arr[i] + 1;
//         }
//     }

//     // Handle missing = n case
//     if (missing == -1) {
//         int expectedSum = n * (n + 1) / 2;
//         int actualSum = accumulate(arr.begin(), arr.end(), 0) - repeating;
//         missing = expectedSum - actualSum;
//     }

//     cout << "Repeating: " << repeating << ", Missing: " << missing << endl;

//     return 0;
// }




// Optimal Solution             TM o(n)   SM o(1)


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr ={4, 3, 1, 2, 5, 1};
//     int n = arr.size();
//     int s1 = 0;
//     int s2 = 0;
//     int s1n = n * (n + 1) / 2;
//     int s2n = (n * (n + 1) * (2 * n + 1)) / 6;
//     for(int i = 0; i < n; i++){
//         s1 += arr[i];
//         s2 += (arr[i] * arr[i]);
//     }
//     int val1 = s1n - s1;
//     int val2 = s2n - s2;
//     val2 = val2 / val1;
//     int x = (val1 + val2) / 2;
//     int y = x - val1;
//     cout << x << " " << y;
//     return 0;
// }






// Count Conversion


// Brute force Solution                      TM o(n^2)  SM o(1)


// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {5, 3, 2, 4, 1};
//     int n = arr.size();
//     int cnt = 0;
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] > arr[j]){
//                 // cout << arr[i] << ", " << arr[j] << endl;
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt;
//     return 0;
// }



//Optimal Solution             TM o(nlogn)  SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int merge(vector<int> &arr, int low, int mid, int high){
//     int left = low;
//     int right = mid + 1;
//     vector<int> temp;
//     int cnt = 0;

//     while( left <= mid && right <= high){
//         if(arr[left] < arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         } else{
//             cnt += (mid - left + 1);
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i = low; i <= high; i++){
//         arr[i] = temp[i - low];
//     }
//     return cnt;
// }

// int mergeSorting(vector<int> &arr, int low, int high){
//     int cnt = 0;
//     if(low >= high) return cnt;
//     int mid = (low + high) / 2;
    
//     cnt += mergeSorting(arr, low, mid);
//     cnt += mergeSorting(arr, mid + 1, high);
//     cnt += merge(arr, low, mid, high);
//     return cnt; 
// }


// int main(){
//     vector<int> arr = {5, 3, 2, 4, 1};
//     int n = arr.size();
//     cout << mergeSorting(arr, 0, n - 1);

// }



// Reverse Pair



//Brute force solution             TM o(n^2)  SM o(1)

// #include <bits/stdc++.h> 
// using namespace std;

// int main(){
//     vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
//     int n = arr.size();
//     int cnt = 0;
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] > (arr[j] * 2)){
//                 // cout << arr[i] << ", " << arr[j] << endl;
//                 cnt++;
//             }
//         }
//     } 
//     cout << cnt;
// }



// Optimal solution

// int cnt = 0;
// #include <bits/stdc++.h>
// using namespace std;


// int merge(vector<int>& arr, int low, int mid, int high){
//     int cnt = 0;                                                  // IMPORTANT SECTION
//     int rightt = mid + 1;
//     for(int i = low; i <= mid; i++){
//         while(rightt <= high && arr[i] > 2 * arr[rightt]){
//             rightt++;
//         }
//         cnt += (rightt  - (mid + 1));
//     }
//     int left = low;
//     int right = mid + 1;    
//     vector<int> temp;

//     while(left <= mid && right <= high){
//         if(arr[left] <= arr[right]) {
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else {
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left <= mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right <= high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i = low; i <= high; i++) {
//         arr[i] = temp[i - low];
//     }
//     return cnt;
// }

// int mergeSorting(vector<int>& arr, int low, int high){
//     if (low >= high) return 0;

//     int mid = (low + high) / 2;
//     int cnt = 0;
//     cnt += mergeSorting(arr, low, mid);
//     cnt += mergeSorting(arr, mid + 1, high);
//     cnt += merge(arr, low, mid, high);
//     return cnt;
// }

// int main(){
//     vector<int> arr = {40, 25, 19, 12, 9, 6, 2};
//     int n = arr.size();
//     cout << mergeSorting(arr, 0, n - 1);
//     return 0 ;
// }






// Maximum product subarray


// Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 3, -2, 4};
//     int n = arr.size();
//     int maxPro = INT_MIN;
//     for(int i = 0; i < n; i++){
//         int pro = 1;
//         for(int j = i; j < n; j++){
//             pro *= arr[j];
//             maxPro = max(maxPro, pro);
//         }
//     }
//     cout << maxPro;
// }


 
//Optimal solution                       TM o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 3, -2, 4, -5};
//     int n = arr.size();
//     int preffix = 1;
//     int suffix = 1;
//     int maxPro = INT_MIN;
//     for(int i = 0; i < n; i++){
//         if(preffix == 0) preffix = 1;
//         if(suffix == 0) suffix = 1;
//         preffix *= arr[i];
//         suffix *= arr[n - i - 1];
//         maxPro = max(maxPro, max(preffix, suffix));
//     }
//     cout << maxPro;
//     return 0;
// }