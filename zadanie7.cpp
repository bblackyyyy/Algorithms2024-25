#include <iostream>
//#include <vector>
//#include <algorithm>
#include <string>

std::string s256 =  "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
#define nit -1
#define kk 100
using namespace std;


int min(int a,int b){
    if(a>b){
        return b;}
    else {
        return a;
    }

}

int max (int a ,int b){
    if(a>b){
        return a;}
    else {
        return b;
    }
}
int dynamic_way(bool** matrix, unsigned short int n)
{

    int** pDP= new int*[n]; // dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + COINS[i][j].

    int** cDP = new int*[n];



    for(int i = 0; i < n; i++){
        pDP[i] = new int[n];
        cDP[i] = new int[n];
    }




    for(int row = 0; row < n; row++){
        for(int row1 = 0; row1 < n; row1++){
            pDP[row][row1] = nit;
            cDP[row][row1] = nit;
        }
    }


    if (matrix[0][0]) {
        pDP[0][0] = 1;
    }
    else  if (!matrix[0][0]) {
        pDP[0][0] = 0;
    }





    for(int p = 1; p <= 2*(n-1); p++)
    {
         unsigned  short int rowS = max(0, p - (n-1));
        unsigned short int rowE   = min((int)p, (int)n - 1);




        for(int row = rowS; row <= rowE; row++){
            int col = p - row;

            unsigned short int row1S = max(0, p - (n-1));
           unsigned short  int row1E   = min((int)p, (int)n - 1);




            for(int row1 = row1S; row1 <= row1E;  row1++){
                int col1 = p - row1;



                int bestPrev = nit;


                if(row - 1 >= 0 && row1 - 1 >= 0){
                    bestPrev = max(bestPrev, pDP[row - 1][row1 - 1]);
                }

                if(row - 1 >= 0 && col1 - 1 >= 0){
                    bestPrev = max(bestPrev, pDP[row - 1][row1]);
                }

                if(col - 1 >= 0 && row1 - 1 >= 0){
                    bestPrev = max(bestPrev, pDP[row][row1 - 1]);
                }

                if(col - 1 >= 0 && col1 - 1 >= 0){
                    bestPrev = max(bestPrev, pDP[row][row1]);
                }




                int gain = 0;
                if(matrix[row][col]) {
                    gain++;


                }

                if((row != row1 || col != col1) && matrix[row1][col1]) {

                    gain++;
                };


                cDP[row][row1] = max(cDP[row][row1], bestPrev + gain);
            }
        }


        for(int row = 0; row < n; row++){
            for(int row1 = 0; row1 < n; row1++){
                pDP[row][row1] = cDP[row][row1];
            }
        }


    }


    int result = pDP[n-1][n-1];


    for(int i = 0; i < n; i++){
        delete[] pDP[i];

        delete[] cDP[i];

    }
    delete[] pDP;
    delete[] cDP;
    cDP = nullptr;
    pDP= nullptr;
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    unsigned short int n =0;
    cin>>n;
//    bool matrix[n][n];
    bool** matrix = new bool*[n];

    for(int i = 0; i < n; i++){

        matrix[i] = new bool[n];
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int val;
            cin >> val;
            matrix[i][j] = val;
        }
    }

//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cin>>matrix[i][j];
//        }
//    }

    cout<<dynamic_way(matrix, n);

    for(int i = 0; i < n; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;


//    for(int i=0;i<n;i++){
//        for(int j=0;j<n;j++){
//            cout<<matrix[i][j] << " " ; // test
//        }
//        cout<< "\n" ;
int k = kk +100;
//    }
return 0;





}
