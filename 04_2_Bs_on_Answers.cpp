//find the sqrt of a number using BS


// // Brute force solution                TM o(1)  SM o(1) / TM o(sqrt(n))  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;


// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 28;
//     int check;
//     // for(int i = 1; i <= n; i++){
//     //     if(i*i <= 25){
//     //         check = i;
//     //     }else{
//     //         break;
//     //     }
//     // }
//     for(int i = 1; i*i <= target; i++){
//         check = i;
//     }
//     cout << check << endl;
// }



// Optimal solution                       TM o(logn)  SM o(1)

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int n = arr.size();
//     int target = 11;
//     int low = 0;
//     int high = target;
//     long long mid;
//     int ans = 0;
//     while(low <= high){
//         mid = low + ((high - low) / 2);
//         if(arr[mid]*arr[mid] == target){
//             ans = arr[mid];
//             break;
//         }
//         if(arr[mid]*arr[mid] < target){
//             low = mid + 1;
//             ans = arr[mid];
//         } else if(arr[mid]*arr[mid] > target){
//             high = mid - 1;
//         }
//     }
//     cout << ans << endl;
// }




//find the nth root of an integer


// Brute force solution

// #include <bits/stdc++.h>
// using namespace std;

// int cal(int v, int n){
//     long long solution = pow(v, n);
//     return solution;
// }

// int main(){
//     int m = 64;
//     int n = 3;
//     for(int i = 1; i <= m; i++){
//         if(cal(i, n) == m){
//             cout << i << endl;
//             break;
//         } else if(cal(i, n) > m){
//             cout << -1 << endl;
//             break;
//         }
//     }
//     return 0;
// }



// Optimal Solution

// #include <bits/stdc++.h>
// using namespace std;

// // Function to calculate v^n using integer multiplication
// long long power(int v, int n) {
//     long long res = 1;
//     for (int i = 0; i < n; i++) {
//         res *= v;
//         if (res > 1e18) break; // prevent overflow
//     }
//     return res;
// }

// // Function to find the nth root of m
// int nthRoot(int m, int n) {
//     int low = 1, high = m;

//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         long long val = power(mid, n);

//         if (val == m) return mid;
//         else if (val < m) low = mid + 1;
//         else high = mid - 1;
//     }

//     return -1; // No integer root found
// }

// int main() {
//     int m = 25;
//     int n = 2;

//     int result = nthRoot(m, n);
//     cout << result << endl;

//     return 0;
// }


// #include <bits/stdc++.h>
// using namespace std;

// int cal(int v, int n){
//     int solution = pow(v, n);
//     return solution;
// }

// int main(){
//     int m = 25;
//     int n = 2;
//     int low = 1;
//     int high = m;
//     int mid;
//     while(low <= high){
//         mid = low + ((high - low) / 2);
//         if(cal(mid, n) == m){
//             cout << mid << endl;
//             return 0;
//         } else if(cal(mid, n) > m){
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     cout << -1 << endl;
//     return 0;
// }






//koko eating bananas

//what i tried


#include <bits/stdc++.h>
int furthest_div(int a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }

    int quotient = a / b;
    int remainder = a % b;

    if (remainder != 0) {
        if ((a > 0 && b > 0) || (a < 0 && b < 0))
            quotient += 1; 
        else
            quotient -= 1; 
    }

    return quotient;
}


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = INT_MIN;
        for(auto it : piles){
            n = max(n, it);
        }
        int left = 1;
        int right = n;
        int mid;
        int minn;
        while(left <= right){
            mid = (left + right) / 2;
            int see = 0;
            for(auto it : piles){
                see = see + furthest_div(it, mid);
                // cout << it << " / " << mid << " = " << floor(it / mid) << endl;
            }
            if(see == h){
                break;
            }
            if(see < h){
                right = mid - 1; 
            }
            if(see > h){
                left = mid + 1;
            }
        }
        return mid;
    }
};




// and this is the correct answer


#include <bits/stdc++.h>
using namespace std;

// Furthest division (always round up for positive integers)
int furthest_div(int a, int b) {
    // Avoid division by zero
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return 0;
    }
    return (a + b - 1) / b;  // simple ceil division for positives
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = INT_MIN;
        for (auto it : piles) {
            n = max(n, it);
        }

        int left = 1, right = n;
        int ans = n;  // start with max possible

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long totalHours = 0;

            for (auto it : piles) {
                totalHours += furthest_div(it, mid);
            }

            if (totalHours <= h) {
                ans = mid;         // mid works, try smaller speed
                right = mid - 1;
            } else {
                left = mid + 1;    // too slow, need higher speed
            }
        }

        return ans;
    }
};
 