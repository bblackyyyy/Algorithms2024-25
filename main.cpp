#include <iostream>
#include <vector>
//#include <cmath>


using namespace std;

struct Rab {
    unsigned short int C;
    unsigned short int K;
    int zero =0; //C / K + 1;

    // int res = 0;

};

unsigned long int calc( vector<Rab>& arr, int day) {
    unsigned long int blend = 0;
    for (int j = 0; j < arr.size(); j++) {
        int terms = min(day, arr[j].zero);
        if (terms > 0) {
            int last_term = arr[j].C - (terms - 1) * arr[j].K;
            blend += ((unsigned long int)terms * (arr[j].C + last_term)) / 2;
        }
    }
    return blend;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned short int t;
    cin >> t;

    while (t--) {
        unsigned int n, d, m;
        cin >> n >> d >> m;

        vector<Rab> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].C >> arr[i].K;
            arr[i].zero = (arr[i].C / arr[i].K) + 1; //ceil or floor mozna nie korzystac
        }

        unsigned long int res = 0;
        for (int i = 0; i < d; i++) {
            int day;
            cin >> day;

            unsigned long int blend = calc( arr, day);

            cout << blend << " ";
            if (blend >= m) {
                res++;
            }
        }
        cout << '\n' << res << '\n';
    }

    return 0;
}
//count
//for(.........){
//    cin a,b,c
//    for(........)
//        cin struct....
//
//}