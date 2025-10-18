// BS on 1D array

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
//     int n = arr.size();
//     int target = 6;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == target){
//             cout << "found the number " << target << " at index " << i;
//             break; 
//         }
//     }
// }



//Optimal solution                             TM o(logn)  SM o(1)

#include <bits/stdc++.h>
using namespace std;

void search(vector<int> arr, int n, int target){
    int low = 0;
    int high = n - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            cout << "found the number " << target << " at index " << mid;
            return;
        } else if(arr[mid] <  target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Number " << target << " not found." << endl;
}


int main(){
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int n = arr.size();
    int target = 6;
    search(arr, n, target);
    return 0;
}



//Optimal solution with recursion                      TM o(logn)  SM o(logn) 

// #include <bits/stdc++.h>
// using namespace std;

// void search(vector<int> arr, int low, int high, int target){
//     if(low > high){
//         cout << "Number " << target << " not found." << endl;
//         return;
//     }
//     int mid = (low + high) / 2;
//     if(arr[mid] == target){
//         cout << "found the number " << target << " at index " << mid;
//         return;
//     } else if(arr[mid] > target){
//         return search(arr, low, mid - 1, target);
//     } else {
//         return search(arr, mid + 1, high, target);
//     }
// }


// int main(){
//     vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
//     int n = arr.size();
//     int target = 6;
//     int low = 0;
//     int high = n - 1;
//     search(arr, low, high, target);
//     return 0;
// }





// Lower Bond and Upper bond

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 5, 8, 15, 19};
//     int n = arr.size();
//     int target = 20;
//     for(int i = 0; i < n; i++){
//         if(arr[i] >= target){
//             cout << "lower bound of " << target << " is " << "at index " << i << endl;
//             return 0;
//         }
//     }
//     cout << "lower bound of " << target << " is " << "at index " << n << endl;
//     return 0;
// }




// Lower bond                          TM o(logn)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {3, 5, 8, 15, 19};

//     int n = arr.size();
//     int target = 18;
//     int left = 0; 
//     int right = n - 1;
//     int res = right;
//     while(left < right){
//         int mid = left + (right - left) / 2;
//         if(arr[mid] >= target){
//             res = mid;
//             right = mid - 1;
//         } 
//         else{
//             left = mid + 1;
//         }
//     }
//     cout << arr[res];
//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;




// Upper bond

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 5, 8, 15, 19};

//     int n = arr.size();
//     int target = 18;
//     int left = 0; 
//     int right = n - 1;
//     int res = right;
//     while(left < right){
//         int mid = left + (right - left) / 2;
//         if(arr[mid] > target){
//             res = mid;
//             right = mid - 1;
//         } 
//         else{
//             left = mid + 1;
//         }
//     }
//     cout << arr[res];
//     return 0;
// }




//Find the first and last occurrence of x


// Brute force

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
//     int n = arr.size();
//     int x = 1;
//     int first = -1;
//     int last = -1;
//     for(int i = 0; i < n; i++){
//         if(arr[i] == x && first == -1){
//             first = i;
//             last = i;
//         } else if(arr[i] == x){
//             last = i;
//         }
//     }
//     cout << "first occurrence: " << first << endl;
//     cout << "last occurrence: " << last << endl;
// }



//Optimal Solution                  TM o(logn)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
//     int n = arr.size();
//     int x = 1;
//     int mid;
//     int low = 0;
//     int high = n - 1;
//     int first = -1;
//     while(low <= high){
//         mid = (low + high) / 2;
//         if(arr[mid] == x){
//             high = mid - 1;
//             first = mid;
//         }
//         else if(arr[mid] > x){
//             high = mid - 1;
//         }
//         else {
//             low = mid + 1;
//         }
//     } 
//     int last = -1;
//     int low1 = 0;
//     int high1 = n - 1;
//     while(low1 <= high1){
//         mid = (low1 + high1) / 2;
//         if(arr[mid] == x){
//             low1 = mid + 1;
//             last = mid;
//         }
//         else if(arr[mid] < x){
//             low1 = mid + 1;
//         }
//         else{
//             high1 = mid - 1;
//         }
//     } 
//     cout << first << endl;
//     cout << last << endl;
// }





// Search in rotated sorted array 1


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
//     int n = arr.size();
//     int target = 10;
//     int low = 0;
//     int high = n - 1;
//     int mid;
//     while(low <= high){
//         mid = (low + high) / 2;
//         if(arr[mid] == target){
//             cout << "Taregt found at index: " << mid << endl;
//             return 0;
//         }
        
//         if(arr[low] <= arr[mid]){
//             if(arr[low] <= target && target < arr[mid]){
//                 high = mid - 1;
//             }
//             else {
//                 low = mid + 1;
//             }
//         }
//         else{
//             if(arr[mid] < target && target <= arr[high]){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//     }
//     cout << "Target not found" << endl;
// }




// Search Element in Rotated Sorted Array 2                       TM o(logn) best/average case o(n) in worst case  SM

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
//     int n = arr.size();
//     int target = 3;
//     int high = n - 1;
//     int low = 0;
//     int mid;
//     while(low <= high){
//         mid = low + ((high - low) / 2);
//         if(arr[mid] == target){
//             cout << "Found at index: " << mid << endl;
//             return 0;
//         }
//         if(arr[mid] == arr[low] && arr[mid] == arr[high]){
//             low = low + 1;
//             high = high - 1;
//             continue;
//         }
//         if(arr[low] <= arr[mid]){
//             if(arr[low] <= target && arr[mid] > target){
//                 high = mid - 1;
//             } else{
//                 low = mid + 1;
//             }
//         }
//         else {
//             if(arr[mid] < target && arr[high] >= target){
//                 low = mid + 1;
//             } else{
//                 high = mid - 1;
//             }
//         }
//     }
// }




//Brute force solution            TM o(n)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
//     int n = arr.size();
//     int minn = INT_MAX;
//     for(int i = 0; i < n; i++){
//         minn = min(minn, arr[i]);
//     }
//     cout << minn << endl;
//     return 0;
// }




//Optimal solution   

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
//     int n = arr.size();
//     int low = 0;
//     int high = n - 1;
//     int mid;
//     int minn = INT_MAX;
//     while(low <= high){
//         mid = low + (high - low) / 2;
//         if(arr[low] <= arr[mid]){
//             minn = min(minn, low);
//             low = mid + 1;
//         }
//         else{
//             minn = min(minn, arr[mid]);
//             high = mid - 1;
//         }
//     }
//     cout << minn << endl;
//     return 0;
// }






// Find out how many times has an array been rotated.                TM o(logn)  SM o(1)


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {3, 4, 5, 1, 2};
//     int n = arr.size();
//     int low = 0;
//     int high = n - 1;
//     int mid;
//     int minn = INT_MAX;
//     int ans;
//     while(low <= high){
//         mid = low + ((high - low) / 2);
//         if(arr[low] <= arr[high]){
//             if(arr[low] < minn){
//                 minn = arr[low];
//                 ans = low;
//             }
//         }
//         if(arr[low] <= arr[mid]){
//             if(arr[low] < minn){
//                 minn = arr[low];
//                 ans = low;
//             }
//             low = mid + 1;
//         } else {
//             if(arr[mid] < minn){
//                 minn = arr[mid];
//                 ans = mid;
//             }
//             high = mid - 1;
//         }
//     }
//     cout << ans;
// }







//single element in sorted Array


//Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
//     int n = arr.size();
//     if(arr[0] != arr[1]){
//         cout << arr[0] << endl;
//         return 0;
//     }
//     if(arr[n - 1] != arr[n - 2]){
//             cout << arr[n - 1];
//             return 0; 
//     }
//     for(int i = 0; i < n; i++){
//         if(arr[i] != arr[i + 1] && arr[i] != arr[i - 1]){
//             cout << arr[i] << endl;
//             return 0;
//         }
//     }
//     return 0;
// }



//Optimal Solution

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
//     int n = arr.size();

//     if (arr[0] != arr[1]) {
//         cout << arr[0] << endl;
//         return 0;
//     }
//     if (arr[n - 1] != arr[n - 2]) {
//         cout << arr[n - 1] << endl;
//         return 0;
//     }

//     int low = 1, high = n - 2;

//     while (low <= high) {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1]) {
//             cout << arr[mid] << endl;
//             return 0;
//         }

//         if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
//             (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }

//     return 0;
// }





//Find Peak Element


//Optimal Solution                     TM o(logn)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
//     int n = arr.size();
//     if(n == 1){
//         cout << 0 << endl;
//         return 0;
//     }
//     if(arr[0] > arr[1]){
//         cout << 0 << endl;
//         return 0;
//     }
//     if(arr[n - 1] > arr[n - 2]){
//         cout << n - 1 << endl;
//         return 0;
//     }
//     int low = 1;
//     int high = n - 2;
//     int mid;
//     while(low <= high){
//         mid = low + ((high - low) / 2);
//         if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
//             cout << mid << endl;
//             return 0;
//         }
//         else if(arr[mid] > arr[mid - 1]){
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return 0;
// }