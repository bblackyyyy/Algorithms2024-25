#include <iostream>
#include <string>
using namespace std;
string s256 =  "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
#define max 100000
#define kk 100

//pseudokod
//if current_cost >= best_cost:
//return
//if col == n:
//best_cost = current_cost
//best_assign = copy(current_assign) return
//for row from 0 to n-1:
//if  arr[n][row] == -1:
//arr[n][row] = 1
//current_assign[col] = row
//        Backtrack(col + 1, current_cost + cost[row][col])
//used[n][row] = -1




void min_backtracking_way(int **arr, int *res, int *curr_arr, int col, int n, int curr) {

    static int best_cost = max;


    if (col == 0 && curr == 0) {
        best_cost = max;
    }

    if (curr >= best_cost) {
        return;
    }

    if (col == n) {
        best_cost = curr;
        for (int i = 0; i < n; i++) {
            res[i] = curr_arr[i];
        }
        return;
    }




    for (int row = 0; row < n; row++) {
        if (arr[n][row] == -1) {

            arr[n][row] = 1;


            curr_arr[col] = row  ;
            min_backtracking_way(arr, res, curr_arr, col + 1, n, curr + arr[row][col]);

            arr[n][row] = -1;
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned short int n =0;
    cin>>n;
    int k = 0;
    int **arr = new  int*[n+1];
     int *res = new  int[n];
    int *curr_arr = new int[n];
    
     
     
     
    for (int i = 0; i < n+1; i++) {
        arr[i] = new  int[n];

    }

    
    

    for(int i =0; i<n; i++){
        for(int j =0; j<n; j++){
            cin>>arr[i][j];
        }
        arr[n][i] = -1;
        curr_arr[i] = -1;
        res[i] = -1;
    }

    min_backtracking_way(arr, res, curr_arr, 0, n, 0);


    for(int i  =0; i<n; i++){
        cout<<res[i]<<" ";
    }
  k = 12;
    for(int i = 0; i < n + 1; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;

    delete[] res;
    res = nullptr;
    delete[] curr_arr;
    curr_arr = nullptr;



    k += kk;



    return 0;
}
