// Two sum


// Brute force solution               TM o(n^2)        SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int n = arr.size();
//     int check = 0;
//     int target = 100;
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] + arr[j] == target){
//                 cout << i << ", " << j;
//                 check = 1;
//                 break;
//             }
//         }
//         if (check == 1){
//             break;
//         }
//     }
//     if(check == 0){
//         cout << "kuch nhi mila";
//     }
// }






//Better soltuion             TM o(nlogn) when ordered map/ o(n) when unordered map but worst case in this is o(n^2)   SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int n = arr.size();
//     int target = 14;
//     map<int, int> temp;
//     for(int i = 0; i < n; i++){
//         int more = target - arr[i];
//         if(temp.find(more) != temp.end()){       //“If the element more exists in the map temp... then do something.”
//             cout << i << " " << temp[more] ; 
//             return 0;
//         }
//         temp[arr[i]] = i;
//     }

//     cout << "kuch nhi mila";
// }



// Optimal solution (where using map is not allowed)  
// SHOULD BE SORTED                                          TM o(n) + o(nlogn) o(1)
// we are not making another array but distorting the main one, if we make another array then space complexity will be o(n)


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 6, 5, 8, 11};
//     int n = arr.size();
//     int target = 14;
 
//     sort(arr.begin(), arr.end());              // V.V.IMP
//     int low = 0, high = n - 1;
//     while (low < high) {
//         int sum = arr[low] + arr[high];
//         if (sum == target) {
//             cout << low << ", " << high;
//             return 0;
//         } else if (sum < target) {
//             low++;
//         } else {
//             high--;
//         }
//     }

//     cout << "kuch nhi mila";
// }







// sort an array of 0's, 1's and 2's



// Brute/better force soltuion          TM o(2n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
//     int n = arr.size();
//     int count0 = 0;
//     int count1 = 0;
//     int count2 = 0;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == 0){
//             count0++;
//         } else if(arr[i] == 1){
//             count1++;
//         } else if(arr[i] == 2){
//             count2++;
//         }
//     }
//     for(int i = 0; i < count0; i++){
//         arr[i] = 0;
//     }
//     for(int i = count0; i < count0 + count1; i++){
//         arr[i] = 1;
//     }
//     for(int i = count0 + count1; i < n; i++){
//         arr[i] = 2;
//     }

//     for(auto it : arr){
//         cout << it << " ";
//     }
// }







//Optimal solution 
// Dutch National Flag Algorithm            TM o(n)  SM o(1)                  <----------------------  

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
//     int n = arr.size();
//     int low = 0;
//     int mid = 0;
//     int high = n - 1;
//     while(mid <= high){
//         if(arr[mid] == 0){
//             swap(arr[low], arr[mid]);
//             mid++;
//             low++;
//         } else if(arr[mid] == 1){
//             mid++;
//         }
//         else{
//             swap(arr[mid], arr[high]);
//             high--;
//         }
//     }
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }






// Majority element (> n/2 times)



// Brute force solution           TM o(n^2)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
//     int n = arr.size();
//     int ye = n/2;
//     for(int i = 0; i < n; i++){
//         int count = 1;
//         for(int j = i + 1; j < n; j++){
//             if(arr[i] == arr[j]){
//                 count++;
//             }
//         }
//         if(count > ye){
//             cout << arr[i] << " ";
//             break;
//         }
//     }
//     return 0;
// }





//Better solution                      TM o(n)  SM o(n)    ,    TM o(nlogn) + o(n) with ordered map

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 2, 3, 3, 1, 2, 2};
//     int n = arr.size();
//     int ye = n / 2;
//     unordered_map<int, int> freq;

//     for (int i = 0; i < n; i++) {
//         freq[arr[i]]++;
//     }

//     for (auto it : freq) {
//         if (it.second > ye) {
//             cout << it.first;
//             return 0;
//         }
//     }

//     cout << "kuch nhi h n se bada";
// }






//Optimal solution
// Moore’s Voting Algorithm                 TM o(n)    SM o(1)  <----------------

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
//     int n = arr.size();
//     int ye = n / 2;
//     int cnt = 0;
//     int el;
//     for(int i = 0; i < n; i++){
//         if(cnt == 0){
//             cnt = 1;
//             el = arr[i];
//         }
//         else if(arr[i] == el){
//             cnt++;
//         }else{
//             cnt--;
//         }
//     }
//     int cnt1 = 0;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == el){
//             cnt1++;
//         }
//     }
//     if(cnt1 > n/2){
//         cout << el;
//     }
//     return 0;
// }






// Maximum subarray sum  


// Brute force solution            TM o(n^3)   SM o(1)
  
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int temp = INT_MIN;
//     vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = arr.size();
//     for(int i = 0; i < n; i++){
//         for(int j = i; j < n; j++){
//             int sum = 0;
//             for(int k = i; k <= j; k++){
//                 sum += arr[k];
//             }
//             temp = max(sum, temp);
//         }
//     }
//     cout << temp << endl;
//     return 0;  
// } 





//Better solution             TM o(n^2)     SM o(1)
 
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = arr.size();
//     int maxSum = INT_MIN;
//     for(int i = 0; i < n; i++){
//         int sum = 0;
//         for(int j = i; j < n; j++){
//             sum  += arr[j];
//             maxSum = max(maxSum, sum);
//         }
//     }
//     cout << maxSum << endl;
//     return 0;  
// } 




// Optimal soltuion           
//Kadane's Algorithm          TM o(n)   SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
//     int n = arr.size();
//     int sum = 0;
//     int maxSum = INT_MIN;
//     int start = 0; 
//     int end = 0;
//     // int sum = arr[0];
//     // int maxSum = arr[0];
//     for(int i = 0; i < n; i++){
//         if(sum == 0) start = i;
//         sum += arr[i];
//         if(sum < 0){
//             sum = 0;
//         }
//         if(sum > maxSum) {
//             maxSum = sum;
//             end = i;
//         }
//         // sum = max(arr[i], sum + arr[i]);
//         // maxSum = max(maxSum, sum);
//     }   
//     cout << "max sum array is from " << start << " to " << end << " with sum: " << maxSum << endl; 
//     return 0;  
// } 






//Best time to buy or sell  stock


//Brute force solution           TM o(n^2)   SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {7, 1, 5, 3, 6, 4};
//     int n = arr.size();
//     int maxProfit = 0;
//     int buy;
//     int sell;
//     for(int i = 0; i < n; i++){
//         int subs;
//         for(int j = i + 1; j < n; j++){
//             subs = arr[j] - arr[i];
//             if(subs > maxProfit){
//                 maxProfit = subs;
//                 buy = i;
//                 sell = j;
//             }
//         }
//     }
//     cout << arr[sell] << " - " << arr[buy] << " = " << maxProfit; 
//     return 0;  
// } 




//Optimal solution            TM o(n)    SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {5, 7, 1, 5, 3, 6, 4};
//     int n = arr.size();
//     int mini = arr[0];
//     int maxProfit = 0;
//     for(int i = 1; i < n; i++){
//         maxProfit = max(arr[i] - mini, maxProfit);
//         mini = min(mini, arr[i]);
//     }
//     cout << maxProfit;
//     return 0;  
// } 




// Rearrange array elements by sign

// Optimal solution          TM o(n) + o(min(pos, neg)) + o(left overs)   SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 1, -2, -5, 2, -4};
//     int n = arr.size();
//     vector<int> pos, neg;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > 0){
//             pos.push_back(arr[i]);
//         }
//         else{
//             neg.push_back(arr[i]);
//         }
//     }
//     if(pos.size() > neg.size()){
//         for(int i = 0; i < neg.size(); i++){
//            arr[2 * i] = pos[i];
//            arr[2 * i + 1] = neg[i]; 
//         }
//         for(int i = neg.size(); i < pos.size(); i++){
//             arr[i * 2] = pos[i];
//         }
//     }
//     else {
//         for(int i = 0; i < pos.size(); i++){
//            arr[2 * i] = pos[i];
//            arr[2 * i + 1] = neg[i]; 
//         }  
//         for(int i = pos.size(); i < neg.size(); i++){
//             arr[i * 2] = pos[i];
//         }
//     }
//     for(auto it : arr){
//         cout << it << " "; 
//     }
//     return 0;  
// } 






//Next permutation

// Brute force solution  
// steps => generate all sorted 
//          then do a linear search             (recursion)
//          then find the next index




// Optimal solution 1.0


// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> arr = {3, 1, 2} ;
//     int n = arr.size();
//     next_permutation(arr.begin(), arr.end());                // only possible in c++
//     for(auto it : arr){
//         cout << it << " ";
//     }
// }



// Optimal solution 2.0                            TM o(n)  SM o(1)


// #include <bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
//     int n = arr.size();
//     int index = -1;
//     for(int i = n - 2; i >= 0; i--){
//         if(arr[i] < arr[i + 1]){
//             index = i;
//             break;
//         }
//     }
//     if (index == -1) {
//         reverse(arr.begin(), arr.end());
//     } else{
//         for(int i = n - 1; i > index; i--){
//             if(arr[index] < arr[i]){
//                 swap(arr[index], arr[i]);
//                 break;
//             }
//         }
//         reverse(arr.begin() + index + 1, arr.end());
//     }
//     for(auto it : arr){
//         cout << it << " ";
//     }
// }








// Leaders in array


// Brute force solution             TM o(n^2)   SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {10, 22, 12, 3, 0, 6};
//     int n = arr.size();
//     vector<int> temp;
//     for(int i = 0; i < n; i++){
//         int check = 1;
//         for(int  j = i + 1; j < n; j++){
//             if(arr[i] < arr[j]){
//                 check = 0;
//             }
//         }if (check == 1){
//             temp.push_back(arr[i]);
//         }
//     }
//     for(auto it : temp){
//         cout<< it << " ";
//     }
// }



// Optimal solution        TM  o(n)   SM  o(n)


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {10, 22, 12, 3, 0, 6};
//     int n = arr.size();
//     vector<int> temp;
//     int maxi = INT_MIN;

//     for(int i = n - 1; i >= 0; i--){
//         maxi = max(maxi, arr[i]);
//         if(maxi == arr[i]){
//             temp.push_back(maxi);
//         }
//     }
//     reverse(temp.begin(), temp.end());
//     for(auto it : temp){
//         cout<< it << " ";
//     }
//     return 0;
// }









// Longest consecutive Sequence 


// Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 2, 3};
//     int n = arr.size();
//     int maxCount = 1;
//     for(int i = 0; i < n; i++){
//         int count = 1;
//         int temp = arr[i];
//         for(int j = 0; j < n; j++){
//             for(int k = 0; k < n; k++){
//                 if(temp + 1 == arr[k]){
//                     count++;
//                     temp = temp + 1;
//                 }
//             }
//         }
//         maxCount = max(maxCount, count);
//     }
//     cout << maxCount << endl;
// }




// #include <bits/stdc++.h>            tM o(n^2) SM o(1)
// using namespace std;

// int main(){
//     vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1}; 
//     int n = arr.size();
//     int maxCount = 1;
//     for(int i = 0; i < n; i++){
//         int count = 1; 
//         int temp = arr[i];
//         while (find(arr.begin(), arr.end(), temp + 1) != arr.end()){    //find(start, end, value) , If not found: returns arr.end()
//             count++;
//             temp++;
//         }
//         maxCount = max(maxCount, count);
//     }
//     cout << maxCount << endl;

// }




//better Solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {100, 102, 100, 101, 101, 3, 2, 3, 2, 1, 1, 1, 2, 4}; 
//     int n = arr.size();
//     // sort(arr.begin(), arr.end());
//     set<int> arr1;
//     for(int i = 0; i < n; i++){
//         arr1.insert(arr[i]);
//     }
//     int count = 0;
//     int maxCount = 1;
//     for(int i = 0; i < n; i++){
//         if(find(arr1.begin(), arr1.end(), i + 1) != arr1.end()){
//             count++;
//         }
//         else if(find(arr1.begin(), arr1.end(), i + 1) == arr1.end()){
//             count = 0;
//         }
//         maxCount = max(maxCount, count);
//     }
//     cout << maxCount << endl;
//     return 0;
// }



// #include <bits/stdc++.h>                             TM o(nlogn)  SM o(1)
// using namespace std;

// int main(){
//     vector<int> arr= {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}; 
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     int count = 0;
//     int maxCount = 1;
//     int lastSmall = INT_MIN;
//     for(int i = 0; i < n; i++){
//         if(lastSmall == arr[i] - 1){
//             count++;
//             lastSmall = arr[i];
//         }else if (arr[i] != lastSmall){
//             count = 1; 
//             lastSmall = arr[i];
//         }
//         maxCount = max(maxCount, count);
//     }
//     cout << maxCount << endl;
//     return 0;
// }



// Optimal solution               TM o(n)   SM o(n)

// #include <bits/stdc++.h>                            
// using namespace std;

// int main(){
//     vector<int> arr= {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2}; 
//     int n = arr.size();
//     unordered_set<int> arr1;
//     for(int i = 0; i < n; i++){
//         arr1.insert(arr[i]);
//     }
    
//     int maxCount = 1;
//     for(auto it : arr1){
//         if(arr1.find(it - 1) == arr1.end()){
//             int count = 1;
//             int x = it;
//             while(arr1.find(x + 1) != arr1.end()){
//                 x++;
//                 count++;
//             }
//             maxCount = max(maxCount, count);
//         }
//     }
//     cout << maxCount;
//     return 0;
// }






// Set amtrix zero


// Brute force solution                       TM o((nxm)x(nxm)+(nxm))

// #include <bits/stdc++.h>
// using namespace std;

// // Define markRow and markCol outside main
// void markRow(vector<vector<int>> &arr, int row) {
//     int n = arr[0].size();
//     for (int j = 0; j < n; j++) {
//         if (arr[row][j] != 0)
//             arr[row][j] = -1;
//     }
// }

// void markCol(vector<vector<int>> &arr, int col) {
//     int m = arr.size();
//     for (int i = 0; i < m; i++) {
//         if (arr[i][col] != 0)
//             arr[i][col] = -1;
//     }
// }

// int main() {
//     vector<vector<int>> arr = {
//         {1, 1, 1, 1},
//         {1, 0, 0, 1},
//         {1, 1, 0, 1},
//         {1, 1, 1, 1}
//     };

//     int m = arr.size();
//     int n = arr[0].size();

//     // Step 1: Mark rows and cols for cells containing 0
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (arr[i][j] == 0) {
//                 markRow(arr, i);
//                 markCol(arr, j);
//             }
//         }
//     }

//     // Step 2: Replace all -1 with 0
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (arr[i][j] == -1)
//                 arr[i][j] = 0;
//         }
//     }

//     // Output the final matrix
//     for (auto row : arr) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }




// Optimal Solution                   TM o(n^2)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<vector<int>> arr = {
//         {1, 1, 1, 1},
//         {1, 0, 0, 1},
//         {1, 1, 0, 1},
//         {1, 1, 1, 1}
//     };

//     int n = arr.size();
//     int m = arr[0].size();
//     int col0 = 1;

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (arr[i][j] == 0) {
//                 arr[i][0] = 0;
//                 if( j != 0){
//                     arr[0][j] = 0;
//                 }
//                 else col0 = 0;
//             }
//         }
//     }
//     for(int i = 1; i < n; i++){
//         for(int j = 1; j < n; j++){
//             if(arr[i][j] != 0){
//                 if(arr[0][j] == 0 || arr[i][0] == 0){
//                     arr[i][j] = 0;
//                 }
//             }
//         }
//     }
//     if(arr[0][0] == 0){
//         for(int j = 0; j < m; j++){
//             arr[0][j] = 0;
//         }
//     }
//     if(col0 == 0){
//         for(int i = 0; i < n; i++){
//             arr[i][0] = 0;
//         }
//     }


//     for (auto row : arr) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }






// Rotate Image 90 degree


// //BRute force solution                    TM o(n^2)  SM o(n^2)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<vector<int>> arr = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12},
//         {13, 14, 15, 16}
//     };
//     int n = arr.size();
//     int m = arr[0].size();
//     int arr1[n][m];
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             arr1[j][n - 1 - i] = arr[i][j];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             cout << arr1[i][j] << " ";
//         }
//         cout << endl;
//     }
// }



//Optimal solution                TM o(n/2 * n/2)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<vector<int>> arr = {
//         {1, 2, 3, 4},
//         {5, 6, 7, 8},
//         {9, 10, 11, 12},
//         {13, 14, 15, 16}
//     };
//     int n = arr.size();
//     int m = arr[0].size();
//     for(int i = 0; i < n; i++){
//         for(int j = i + 1; j < m; j++){
//             swap(arr[i][j], arr[j][i]);
//         }
//     }
//     for(int i = 0; i < n; i++){
//         reverse(arr[i].begin(), arr[i].end());
//     }
//     for (auto row : arr) {
//         for (auto val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }

// }







// Spiral Matrix


// Optimal Solution          TM o(nxm)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<vector<int>> arr = {
//         {1, 2, 3, 4, 5, 6},
//         {20, 21, 22, 23, 24, 7},
//         {19, 32, 33, 34, 25, 8},
//         {18, 31, 36, 35, 26, 9},
//         {17, 30, 29, 28, 27, 10},
//         {16, 15, 14, 13, 12 ,11}
//     };
//     int n = arr.size();
//     int m = arr[0].size();
//     int top = 0;
//     int bottom = n - 1;
//     int left = 0;
//     int right = n - 1;
//     while(top <= bottom && left <= right){
//         for(int i = left; i <= right; i++){
//             cout << arr[top][i] << " ";
//         }
//         top++;
//         for(int i = top; i <= bottom; i++){
//             cout << arr[i][right] << " ";
//         }
//         right--;
//         if(top <= bottom){
//             for(int i = right; i >= left; i--){
//                 cout << arr[bottom][i] << " ";
//             }
//             bottom--;
//         }
//         if(left <= right){
//             for(int i = bottom; i >= top; i--){
//                 cout << arr[i][left] << " ";
//             }
//             left++;
//         }
//     }

// }





// Number of subarray with sum K  




// Better solution         TM o(n^2)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
//     int n = arr.size();
//     int k = 3;
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         int sum = 0;                
//         for(int j = i; j < n; j++){
//             sum = sum + arr[j];
//             // cout << sum << " ";
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     cout << count << endl;
// }





// Optimal solution  

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
//     int n = arr.size();
//     unordered_map<int, int> temp;
//     temp[0] = 1;
//     int k = 3;
//     int preSum = 0;
//     int count = 0;
//     for(int i = 0; i < n; i++){
//         preSum += arr[i];
//         int remove = preSum - k;
//         count += temp[remove];
//         temp[preSum] += 1;
//     }
//     cout << count;
// }