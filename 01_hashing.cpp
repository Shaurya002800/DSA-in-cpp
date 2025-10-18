#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "enter size of array: ";
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int has[13] = {0};
    for(int i = 0; i < n; i++){
        has[arr[i]]++;
    }
    int q ;
    cout << "enter number of search: ";
    cin >> q;
    for(int i = 0; i < q; i++){
        int s;
    cout << "enter a number to know the frequency: ";
        cin >> s;
        cout << s <<" came "<<has[s] << " times in the array"<<endl;
        // cout << has[i]<<" ";
    }
}






//CHARACTER HASHING 

// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     string s;
//     cout << "enter a string: ";
//     cin >> s;


//     // when all are lower case character
//     int has[26] = {0};                      // can also 256 (which contains upper case letters)
//     for(int i = 0; i < sizeof(s); i++){
//         has[s[i] - 'a']++;                     // if we take 256 no need to subtract 'a'
//     }

//     int q;
//     cin >> q;
//     while (q--){
//         char c;
//         cin >> c;
//         cout << has[c - 'a'] <<""<< endl;  
//     }
// }





  
// HASHING USING MAP  (stores all the values in sorted manner)  and its time complexity is log(n)

// #include <iostream>
// #include <string>
// #include <map>
// using namespace std;

// int main(){
//     int n ;
//     cout << "enter a number: ";
//     cin >> n;

//     int arr[n];
                      
//     for(int i = 0; i < n; i++){      
//         cin >> arr[i];           
//     }
//     //pre-compute
//     map< int,  int> mpp;
//     for(int i = 0; i < n; i++){
//         mpp[arr[i]]++;
//     }

//     //iterate in the map
//     for(auto it : mpp){
//         cout << it.first << " -> " << it.second << endl;
//     }


//     int q;
//     cin >> q;
//     while (q--){
//         int number;
//         cin >> number;
//         //fetch
//         cout << mpp[number] <<endl;

//     }
// }




// UNORDERED MAPPING (no order, can change order and depends on compiler) and time complexity is o(1) both average and best &  in very2 rare case its o(n)

// #include <iostream>
// #include <string>
// #include <unordered_map>
// using namespace std;

// int main(){
//     int n ;
//     cout << "enter a number: ";
//     cin >> n;

//     int arr[n];
                      
//     for(int i = 0; i < n; i++){      
//         cin >> arr[i];           
//     }
//     //pre-compute
//     unordered_map< int,  int> mpp;
//     for(int i = 0; i < n; i++){
//         mpp[arr[i]]++;
//     }

//     //iterate in the map
//     for(auto it : mpp){
//         cout << it.first << " -> " << it.second << endl;
//     }


//     int q;
//     cin >> q;
//     while (q--){
//         int number;
//         cin >> number;
//         //fetch
//         cout << mpp[number] <<endl;

//     }
// }




// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cout << "enter the size of array: ";
//     cin >> n;
//     int arr[n];
//     for(int  i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     unordered_map<int, int> k;
//     for(int i = 0; i < n; i++){
//         k[arr[i]]++;
//     }
//     int maxx = 0;
//     int minn = 1;

//     for(int i = 0; i < n; i++){
//         maxx = max(maxx, k[arr[i]]);
//         minn = min(minn, k[arr[i]]);
//     }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j <= i; j++){
    //         if(k[i] > k[j]){
    //             int tem = k[i];
    //             k[i] = k[j];
    //             k[j] = tem;
    //         }
    //     }
    // }
    // // cout << k[0] << "has maximum frequency of "<<maxx<<endl;
    // cout << k[n-1] << "has minimum frequency of "<<minn<<endl;
//     for(int i = 0; i < n; i++){
//         if ( maxx == arr[i]){
//             cout << arr[i] << "has maximum frequency of "<<maxx<<endl;
            
//         } if( minn == arr[i]){
//             cout << arr[i] << "has minimum frequency of "<<minn<<endl;
    
//         }
//     }
// }


// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cout << "enter the size of the array: ";
//     cin >> n;
//     int arr[n];  
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }


//     for(int i = n - 1; i >= 0; i--){
//         for(int j = 0; j < i - 1 - i; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//             }
//         }
//     }
//     // for(int i = 0; i < n-1; i++){
//     //     for(int j = 0; j < n - 1 - i; j++){
//     //         if(arr[j] > arr[j+1]){
//     //             int temp = arr[j];
//     //             arr[j] = arr[j+1];
//     //             arr[j+1] = temp;
//     //         }
//     //     }
//     // }


//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0; 
// }