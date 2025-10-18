// In interview firest give give brute then better than optimal solution of the given solution



// This is brute solution (Sorting) 

// #include <iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     // cin >> n;
//     int arr[n] ={3, 2, 1, 5, 2};
//     // for(int i = 0; i < n; i++) {
//     //     cin >> arr[n];
//     // }
//     for(int i = 0; i < 1; i++){
//         for(int j = 0; j < n - 1; j++){
//             if( arr[j] > arr[j + 1]){
//                 swap(arr[j], arr[j + 1]);
//             }
//             // cout << arr[j]<<" ";
//         }
//     }
//     cout << arr[n - 1];
// }




// Optimal soluion

// #include <iostream>
// using namespace std;

// int main(){
//     int n = 5;
//     // cin >> n;
//     int arr[n] ={3, 2, 1, 5, 2};
//     int nums[n - 1];
//     // for(int i = 0; i < n; i++) {
//     //     cin >> arr[n];
//     // }
//     int maxNum = arr[0];
//     for(int i = 0; i < n; i++){
//         if(arr[i] > maxNum){
//             maxNum = arr[i];
//         }
//     }
    
    
//     cout << maxNum;
// }




/*****************************/

// brute solution is sorting than finding second largest number  time com o(nlogn + n)


// thoda kam better se



// #include <iostream>
// using namespace std;

// int main(){
//     int n = 6;
//     // cin >> n;
//     int arr[n] ={1, 2, 4, 7, 7, 5};
//     int nums[n];
//     // for(int i = 0; i < n; i++) {
//     //     cin >> arr[n];
//     // }
//     int maxNum = arr[0];
//     for(int i = 0; i < n; i++){
//         if(arr[i] > maxNum){
//             maxNum = arr[i];
//         }
//     }
//     for(int i = 0; i < n; i++){
//         if(arr[i] == maxNum){
//             continue;
//         }
//         else{
//             nums[i] = arr[i];
//         }
//     }
//     int max = nums[0];
//     for(int i = 0; i < n; i++){
//         if(nums[i] > max){
//             max = nums[i];
//         }
//     }
    
    
//     cout << max;
// }





// Better code    time complexity is o(2n)


// #include <iostream>
// using namespace std;

// int main(){
//     int n = 6;
//     // cin >> n;
//     int arr[n] ={1, 2, 4, 7, 7, 5};
//     // for(int i = 0; i < n; i++) {
//     //     cin >> arr[n];
//     // }
//     int maxNum = arr[0];
//     for(int i = 0; i < n; i++){
//         if(arr[i] > maxNum){
//             maxNum = arr[i];
//         }
//     }
//     int secMax = -1;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > secMax && arr[i] < maxNum){
//             secMax = arr[i];
//         }
//     }
//     cout << secMax;
// }




// Optimal code         time complexity is o(n)



// #include <iostream>
// using namespace std;

// int main(){
//     int n = 6;
//     // cin >> n;
//     int arr[n] ={1, 2, 4, 7, 7, 5};
//     int nums[n];
//     // for(int i = 0; i < n; i++) {
//     //     cin >> arr[n];
//     // }
//     int max = arr[0] ;
//     int secMax = -1;
//     for(int i = 0; i < n; i++){
//         if(arr[i] > max ){
//             secMax = max;
//             max = arr[i];
//         } else if(arr[i] > secMax && arr[i] < max){
//             secMax = arr[i];
//         }
//     }
//     cout << max << endl;
//     cout << secMax << endl;
// }





/*************************/



// array is sorted or not           TM o(n)

// #include <iostream>
// using namespace std;

// int main(){
//     int arr[] = {1, 2, 1, 3, 4};
//     int n = 5;
//     int check;
//     for(int i = 0; i < n - 1; i++){
//         if(arr[i] <= arr[i + 1]){        }

//         else{
//             check = 0;
//             break;
//         }
//     }
//     if(check == 0){
//         cout << "false";
//     }
//     else{
//         cout << "true";
//     }
// }






/**************************************/



// Remove duplicates in-place from sorted array

// Brute so lution           TM o(nlogn + n), SC o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[6] = {1, 1, 2, 2, 3, 3};
//     set<int> st;
//     for(int i = 0; i < 6; i++){
//         st.insert(arr[i]);
//     }
//     int index = 0 ;
//     for(auto it : st){
//         arr[index++] = it;
//     }
//     for(int i = 0; i < index; i++){
//         cout << arr[i] << " ";
//     }
// }




//Optimal solution         TM o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n = 6;
//     int arr[n] = {1, 1, 2, 2, 3, 3};
//     int i = 0;
//     for(int j = 1; j < n; j++){
//         if(arr[j] != arr[i]){
//             arr[i + 1] = arr[j];
//             i++;
//         }
//     }
//     cout << i + 1 << endl;
//     for(int j = 0; j < i + 1; j++){
//         cout << arr[j] << " ";
//     }
// }







// left Rotate the array by one place


// Optimal Solution           TM o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();

//     int temp = arr[0];
//     for(int i = 1; i < n; i++){
//         arr[i - 1] = arr[i];
//     }
//     arr[n - 1] = temp;
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }









// Left rotate the array by D places


//Brute solution    TM o(n)   SM o(d)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     int n = arr.size();
//     int d;
//     cin >> d;
//     d = d % n;
//     vector<int> temp;
//     for(int i = 0; i < d; i++){
//         temp.push_back(arr[i]);
//     }
//     for(int i = d; i < n; i++){
//         arr[i - d] = arr[i];
//     }
//     for(int i = n - d; i < n; i++){
//         arr[i] = temp[i - (n - d)];
//     }
//     for(auto it : arr){
//         cout << it <<" "; 
//     }

//     return 0;
// }



// Optimal Solution            TM o(2n)  SM(1)

// #include <bits/stdc++.h>     
// using namespace std;


// int main(){
//     // vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
//     int n = 7;
//     int arr[n] = {1, 2, 3, 4, 5, 6, 7};
//     int d; 
//     cin >> d;

//     reverse(arr, arr + d);
//     reverse(arr + d, arr + n);
//     reverse(arr, arr + n);

//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }





//move all zeros to the end of the array           TM  o(n)  extra space SM o(n)
 
// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
//     int n = arr.size();
//     vector<int> temp; 
//     for(int i = 0; i < n; i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }
//     for(int i = 0; i < n; i++){
//         if(arr[i] == 0){
//             temp.push_back(arr[i]);
//         }
//     }
//     int i = 0;
//     for(auto it : temp){
//         arr[i++] = it;
//     }

//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }


//     return 0;
// }




//Optimal solution         TM o(n)     SM o(1)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
//     int n = arr.size();
//     int j ;
//     for(int i = 0; i < n; i++){
//         if (arr[i] == 0){
//             j = i;
//             break;
//         }
//     }
//     for (int i = j + 1; i < n; i++){
//         if( arr[i] != 0){
//             swap(arr[i], arr[j]);
//             j++;
//         }
//     }
    
//     for(auto it : arr){
//         cout << it << " ";
//     }

//     return 0;
// }





// Linear search

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {6, 7, 8, 4, 1};
//     int n = arr.size();
//     int num;
//     cin >> num;
//     for(int i =  0; i < n; i++){
//         if (arr[i] == num){
//             cout << i;
//             break;
//         }
//     }
//     return 0;
// }







// Union of two sorted arrays


// Brute solution         TM o(n1logn + n2logn)  + o(n1 + n2)   SM o(n1 + n2) o(n1 + n2)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr1 = {1, 1, 2, 3, 4, 5};
//     int n1 = arr1.size();
//     vector<int> arr2 = {2, 3, 4, 4, 5, 6};
//     int n2 = arr2.size();
//     set<int> temp;
//     for(int i = 0; i < n1; i++){
//         temp.insert(arr1[i]);
//         temp.insert(arr2[i]);
//     }
//     int unionn[temp.size()];
//     // cout << temp.size();
//     int i = 0;
//     for(auto it : temp){
//         unionn[i++] = it ;
//     }
//     for(int i = 0; i < temp.size(); i++){
//         cout << unionn[i] << " ";
//     }
//     return 0;
// }





//Optimal Solution                                 TM o(n1 + n2)   SM o(n1 + n2)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr1 = {1, 1, 2, 3, 4, 5};
//     vector<int> arr2 = {2, 3, 4, 4, 5, 6};
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     vector<int> uni;
//     int i = 0;
//     int j = 0;
//     while(i < n1 && j < n2){
//         if (arr1[i] <= arr2[j]){
//             if (uni.size() == 0 || uni.back() != arr1[i]){
//                 uni.push_back(arr1[i]);
//             }
//             i++;
//         }
//         if (arr2[j] < arr1[i]){
//             if (uni.size() == 0 || uni.back() != arr2[j]){
//                 uni.push_back(arr2[j]);
//             }
//             j++;
//         }
//     }
//     while(i < n1){
//         if (uni.size() == 0 || uni.back() != arr1[i]){
//             uni.push_back(arr1[i]);
//         }
//         i++;
//     }
//     while(j < n2){
//         if (uni.size() == 0 || uni.back() != arr2[j]){
//             uni.push_back(arr2[j]);
//         }
//         j++;
//     }
//     for(auto it : uni){
//         cout << it << " ";
//     }
//     return 0;
// }










// Intersection of two sorted array   



// Optimal Solution                       TM  o(n1 + n2)   SM o(kl)

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr1 = {1, 2, 2, 3, 3, 4, 5, 6};
//     vector<int> arr2 = {2, 3, 3, 5, 6, 6, 7};
//     int n1 = arr1.size();
//     int n2 = arr2.size();
//     int i = 0;
//     int j = 0;
//     vector<int> inter;
//     while(i < n1 && j < n2){
//         if(arr1[i] == arr2[j]){
//             inter.push_back(arr1[i]);
//             i++;
//             j++;
//         }
//         else if(arr1[i] < arr2[j]){
//             i++;
//         }
//         else{
//             j++;
//         }
//     } 
//     for(auto it : inter){
//         cout << it << " ";
//     }
//     return 0;
// }






// missing number           TM o(n x n)     SM  o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 4, 5};
//     int n = arr.size();
//     int check = 0;
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j < n - 1; j++){
//             if (i == arr[j]){
//                 check = 1;
//                 break;
//             }else{
//                 check = 0;
//             }
//         }
//         if (check == 0){
//             cout << i;
//             break;
//         }
//     }
//     return 0;
// }



// Better solution                 TM o(n) + o(n)           SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 4, 5};
//     int n = arr.size();
//     int tem[n + 1] = {0};
//     for(int i = 0; i < n; i++){
//         tem[arr[i]] = 1;
//     }
//     // for(auto it : tem){
//     //     cout << it << " ";
//     // }
//     for(int i = 1; i < n + 1; i++){
//         if(tem[i] == 0){
//             cout << i;
//             break;
//         }
//     }
//     return 0;
// }





// Optimal solution  1.0           TM  o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 4, 5};
//     int n = arr.size();
//     int sum = 0;
//     for(int i = 0; i < n; i++){
//         sum = sum + arr[i];
    
//     }
//     cout << (n + 1)*(n + 2)/2 - sum;
//     return 0;
// }




// Optimal solution  2.0           TM  o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 4, 5};
//     int n = arr.size();
//     int X1 = 0;
//     int X2 = 0;
//     for(int i = 0; i < n; i++){
//         X1 = X1 ^ arr[i];
//         X2 = X2 ^ (i + 1);
//     } 
//     X2 = X2 ^ (n + 1);
//     cout << X1 ^ X2;
//     return 0;
// }





// Maximum Consecutive  Ones


// Optimal solution solution         TM o(n)  SM o(1)
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 0, 1, 1, 1, 0, 1, 1};
//     int n = arr.size();
//     int count = 0;
//     int maxx = 0;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == 1){
//             count++;
//             maxx = max(maxx, count);
//         } else{
//             count = 0;
//         }
//     }
//     cout << maxx;

//     return 0;
// }








// Find the number that appaers once, and the others twice



// Better solution           TM o(n)   SM o(n)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 2, 3, 3, 3, 4, 4};
//     int n = arr.size();
//     vector<int> temp(n, 0);
//     for(int i = 0; i < n; i++){
//         temp[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++){
//         if( temp[i] == 1){
//             cout << i;
//             break;
//         }
//     }

//     return 0;
// }





// Optimal soluion                TM  o(n)     SM o(1)
 

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 2, 3, 3, 3, 4, 4};
//     int n = arr.size();
//     int X = 0;
//     for(int i = 0; i < n; i++){
//         X = X^arr[i];
//     }
//     cout << X;
//     return 0;
// }





// longest subarray with sum k(positive)


// Brute soluion           tM o(n ^ 2)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     int n = arr.size();
//     int len = 0;
//     int k = 3;
//     for(int i = 0; i < n; i++){
//         int s = 0;
//         for(int j = i; j < n; j++){
//             s = s + arr[j];
//             if (s == k) {
//                 len = max(len, j - i + 1);
//             }
//         }
//     }
//     cout << len;
//     return 0;
// }





// Better soluion                 TM o(nlogn) with ordered map and o(n) with unordered map  SM o(n)

// (optimal solution when array contains only positive and zeros elements)




// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     int n = arr.size();
//     int k = 3;
//     map<long long, int> preSumMap;
//     long long sum = 0; 
//     int maxLen = 0;
//     for(int i = 0; i < n; i++){
//         sum = sum + arr[i];
//         if(sum == k) {
//             maxLen = max(maxLen, i + 1);
//         }
//         long long rem = sum - k;
//         if(preSumMap.find(rem) != preSumMap.end()){
//             int len = i - preSumMap[rem];
//             maxLen = max(maxLen, len);
//         }
//         if(preSumMap.find(sum) == preSumMap.end()){          // this handles case of zero
//         preSumMap[sum] = i;
//         }
//     } 
//     cout<< maxLen;
//     return 0;
// }




// Optimal solution4                TM  o(2n)   SM  o(1)


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
//     int n = arr.size();
//     int k = 6;
//     int left = 0 , right = 0;
//     long long sum = arr[0];
//     int maxLen = 0;
//     while(right < n){
//         while(left <= right && sum > k){
//             sum -= arr[left];
//             left++;
//         }
//         if(sum == k){
//             maxLen = max(maxLen, right - left + 1);
//         }
//         right++;
//         if(right < n) {
//             sum += arr[right];
//         }
//     }
//     cout << maxLen;

//     return 0;
// }