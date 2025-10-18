// SELECTION SORT

#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cout << "enter the size of the array: ";
    cin >> n;
    int arr[n];  
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n-1; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(arr[j] < arr[mini]){
                mini =j;
            }
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0; 
}


 
// BUBBLE SORTING                 avg and worst timme complexity is o(n^2)   and best is o(n)

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
//     int didswap =0; 

//     for(int i = n - 1; i >= 0; i--){
//         for(int j = 0; j < i; j++){
//             if(arr[j] > arr[j+1]){
//                 int temp = arr[j];
//                 arr[j] = arr[j+1];
//                 arr[j+1] = temp;
//                 didswap = 1;
//             }
//         }
//         if(didswap == 0){
//             break;
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




// INSERTION SORT      time complexity for best case is o(n) , and worst, average case is o(n^2)


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

//     for(int i = 0; i < n - 1; i++){
//         int j = i;
//         while(j > 0 && arr[j - 1] > arr[j]){
//             int temp = arr[j - 1];
//             arr[j - 1] = arr[j];
//             arr[j] = temp;
//             j--;

//         }
//     }

//     for(int i = 0; i < n; i++){
//         cout << arr[i] << " ";
//     }
//     return 0; 
// }





