#include <iostream>
#include <list>
#include <forward_list>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <string>
#include <vector>
#define kk 10


using namespace std;
string s256 = "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
string NO = "BRAK DANYCH";

struct  elem{
    unsigned int val;
    bool has_odd_prime =0 ;

    elem(){
        val = 0;
        has_odd_prime = 0;
    }

    elem(unsigned int val){
        this->val = val;
        has_odd_prime = 0;
    }

};







bool check_prime(unsigned int n){
////    int count = 0;
////    if(v % 2 == 0){
////        count++;
////        while( v % 2 ==0){
////            v/=2;
////        }
////    }
////
////
////    if(v > 1){
////        count++;
////    }
////
////
////    for(int i =3; i*i <= v; i+=2){
////        if(v % i == 0){
////            count++;
////            while(v % i == 0){
////                v/=i;
////            }
////        }
////    }
////
////
////    return  count%2 == 0 ;
//
//
    int count =  0;

//    if (n % 2 == 0) {
//        count++;
//        while (n % 2 == 0) {
//            n /= 2;
//
//
//           }
//    }
//
    if ((n & 1) == 0 ){
        count++;
        while ((n & 1) == 0){
            n /= 2;
        }
    }

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {


            count++;
            while (n % i == 0) {



                n /= i;
            }
          }
      }


    if (n > 1) {

        count++;
    }


    return count % 2 == 0;






}

//bool isPrime(unsigned int n) {
//    if (n < 2){
//        return 0;
//    }
//    for (unsigned int i = 2; i * i <= n; i++) {
//        if (n % i == 0)
//            return 0;
//    }
//    return 1;
//}

//bool check_prime(unsigned int n) {
//    int count = 0;
//    if (n < 2) {
//        return 1;
//
//    }
//    int limit = (int)(sqrt(n)) + 1;
//    char *isPrime = (char *)malloc(limit * sizeof(char));
//    if (isPrime == NULL) {
//        printf("Memory allocation failed.\n");
//        return 0;
//    }
//    wmemset(reinterpret_cast<wchar_t *>(isPrime), 1, limit);
//    if (limit > 0) {
//        isPrime[0] = 0;
//    }
//    if (limit > 1){
//        isPrime[1] = 0;
//        }
//    for (int i = 2; i * i < limit; i++) {
//        if (isPrime[i]) {
//            for (int j = i * i; j < limit; j += i)
//                isPrime[j] = 0;
//        }
//    }
//    for (int i = 2; i < limit; i++) {
//        if (isPrime[i] && (n % i == 0)) {
//            count++;
//            while (n % i == 0)
//                n /= i;
//        }
//    }
//    if (n > 1) {
//        count++;
//    }
//    free(isPrime);
//    return (count % 2 == 0);
//}



//
//
//bool check_prime(unsigned int n) {
//    int count = 0;
//
//    for (unsigned int i = 2; i <= n; i++) {   // nie dziala za duzo czasu
//
//
//        if (n % i == 0 && isPrime(i)) {
//            count++;
//        }
//    }
//    //return count;
//    if(count %2 != 0 ){
//        return 0;
//    }
//
//
//
//    else{
//        return 1;
//    }
//}


int insertionsort(vector< unsigned int> &n, int lc, int rc)
{
    int i;
    int j;
    for (i = lc+1; i <= rc; ++i) {
        int tmp = n[i];
        for (j = i - 1; j >= lc; --j) {
            if (tmp < n[j])
                n[j+1] = n[j];
            else
                break;
        }
        n[j+1] = tmp;
    }
    return (lc+rc)/2;
}



int median_m5(vector< unsigned int> &n, int lc, int rc)
{
    if (rc-lc+1 <= 5) {
        return insertionsort(n, lc, rc);
    }

    int mc = lc - 1;
    int tmp;
    for (; rc-lc+1 >= 5; lc += 5)
    {
        tmp = median_m5(n, lc, lc+4);
        swap(n[++mc], n[tmp]);
    }



    if (lc != rc)
    {
        tmp = median_m5(n, lc, rc);
        swap(n[++mc], n[tmp]);
    }



    return median_m5(n, lc, mc);
}





int quickselect(vector<unsigned int> &n, int lc, int rc, int k)
{
    int pidx = median_m5(n, lc, rc);

    int pivot = n[pidx];




    swap(n[pidx], n[rc]);


    int i = lc-1;
    int j = rc;
    while (i < j) {





        while (++i <= rc && n[i] < pivot) { ;
        }
        while (--j >= lc && n[j] > pivot){
            ;}





        if (i < j){
            swap(n[i], n[j]);
        }
    }
    swap(n[i], n[rc]);
    if (i == k-1) {
        return pivot;
    }
    else if (i < k-1) {
        return quickselect(n, i + 1, rc, k);
    }
    else {
        return quickselect(n, lc, i - 1, k);
    }
}












int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    unsigned int t =0;
    unsigned int n =0;
    unsigned int kj = 0;
    elem *arr1 = new elem[10];



     cin>>t;
     //cout<<check_prime(t) << endl;

    vector<int> res;
    res.resize(t);
     for(int j =0; j<t; j++){
         cin>>n;
         kj+=kk;
         int mid = 0;
          //forward_list <unsigned int> arr;
          vector<unsigned int> arr;

         for(int i =0; i<n; i++){
                kj+=kk;
                unsigned int val = 0;
                cin>>val;
                if(check_prime(val)){
                    arr.emplace_back(val);
                }





         }
         cin>>mid;

        // res[j] =  bfprt(arr, )
        if(arr.size()  <= mid  ){
            res[j] = -1;
        }


        if(arr.size() > mid){
            res[j] = quickselect(arr, 0, arr.size()-1, mid+1);
        }












     }





    for(int i=0;i<t;i++){
        if(res[i] == -1){
            cout<< NO << '\n';
        }


        else{
            cout<<res[i]<<'\n';
        }
        //cout<<res[i]<<endl;
    }

    delete[] arr1;
    arr1  = nullptr;
    return 0;
}
