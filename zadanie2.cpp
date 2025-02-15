#include <iostream>
#include <string>
using namespace std;
string s256 =  "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
//Vladyslav Meroniuk
struct c {
    unsigned long long int waga;
    unsigned  long long int sum;
    string name;
};

//void shellSort(c arr[], int n) {
//    for (int gap = n / 2; gap > 0; gap /= 2) {
//        for (int i = gap; i < n; i++) {
//            c temp = arr[i];
//            int j;
//            for (  j = i; j >= gap && (arr[j - gap].waga > temp.waga ); j -= gap) {
//                arr[j] = arr[j - gap];
//            }
//            arr[j] = temp; // zle
//        }
//    }
//}

//void InsertSort(int tab[], unsigned int n){
//    int pom;
//
//    for (unsigned int i=1; i<n; i++){
//        unsigned int j = i-1;
//        if (tab[i] <tab[i - 1]){
//            pom=tab[i];
//            for (j=i-1; (j>0) && (tab[j] >pom);j-) tab[j + 1]=tab[j]; // z wykladu
//            tab[j + 1]=pom;
//        }
//    }
//    return;
//}
void InsertSort(c arr[], unsigned int n) {
    c temp;
    for (unsigned int i=1; i<n; i++) {
        temp = arr[i];
        int j = i -1;
        for(j; j>=0 && arr[j].waga > temp.waga;j--){ // z wykladu przerobione z wykozystaniem for
            arr[j+1] = arr[j]; // optymizowany
        }
        arr[j + 1] = temp;
    }

}








//void fun(c arr[] , int n){
//    c temp;
//    for(int i  =0; i< n; i++){
//        int j = i-1;
//        temp = arr[i];
//        for(j; j>=0 && arr[j].waga > temp.waga;j--){//prosty do testowania
//            arr[j+1] = arr[j];
//        }
//        arr[j+1] = temp;
//    }
//
//}
//void BubbleSort (c tab [], unsigned int n) {
//    for (unsigned int i = n - 1; i > 0; i--) {
//        for (unsigned int j = 0; j < i; j++) {
//            if (tab[j].waga > tab[j + 1].waga) { // zawolno
//                swap(tab[j], tab[j + 1]);
//            }
//        }
//    }
//}



//mozna wykorzystywac tylko Stabilne sortowania
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned short int t;

    cin>> t;
    cin.ignore();
    while(t--) {
        int n;
        cin >> n;
        c *arr = new c[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i].name >> arr[i].waga;
        }
        //shellSort(arr, n); // nie dziala bo nie stabilne
        InsertSort(arr, n);
        //BubbleSort(arr, n);
        //fun(arr,n);
        unsigned long long  int toten = 0;
                unsigned long long int  currentMass = 0;
                for (int i = 0; i < n; i++) {
                    toten += currentMass + arr[i].waga;
                    currentMass += arr[i].waga;
                }

        cout<< toten << '\n';
        for(int i = 0; i<n; i++){
            cout << arr[i].name << " ";
        }
        cout<<'\n';
        delete[] arr;
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
