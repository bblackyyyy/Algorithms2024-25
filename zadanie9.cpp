#include <iostream>
#include <string>
#include <iomanip>


#define t 10000
#define kk 1000

using namespace  std;
string s256 = "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";



//long long int counting_sort(long long int *A, long long int *B, long long int n, long long int min, long long int max) {
//
//    long long int range = max - min + 1;      //implementacja z wykladu modyfikowana range
//                                    // dla ulepszenia pamieci
//
//
//    long long int *C = new long long int[range] ;
//
//    for(long long int i = 0; i < range; i++) {
//        C[i] = 0;
//    }
//
//
//    for(long long int j = 0; j < n; j++) {
//        C[A[j] - min] += 1;
//    }
//
//    C[0] -= 1;
//
//    for(long long int i = 1; i < range; i++) {
//        C[i] += C[i - 1] ;
//    }
//
//    for(long long int j = n - 1; j >= 0; j--) {
//        long long int current = A[j];
//
//        long long int index = C[current - min];
//        B[index] = current;
//        C[current - min] -= 1;
//    }
//
//
//    delete[] C;
//
//    return 0;
//}

//nie dziala -  przekracza zakres  zmiennej i jest zle jezeli 10^9 to 10^9 * 10^4 = 10^13 i odwrotnie

//void quickSortRecursive(float *arr, int size) {
//
//
//    int i =  0;
//    int j = size - 1;
//
//    float pivot = arr[size / 2];
//
//    while (i <= j) {
//
//        while (arr[i] < pivot) {
//            i++;
//        }
//
//        while (arr[j] > pivot) {
//            j--;
//        }
//        if (i <= j) {
//
//            float temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp ;
//
//
//
//            i++;
//            j--;
//        }
//    }
//
//    if (j > 0) {
//        quickSortRecursive(arr, j + 1);
//    }
//
//    if (i < size) {
//        quickSortRecursive(&arr[i], size - i);
//    }
//}










//void InsertSort( float* arr,  int n) {
//    float temp;
//    for (unsigned int i=1; i<n; i++) {
//        temp = arr[i];
//        int j = i -1;
//        for(j; j>=0 && arr[j] > temp;j--){ // z wykladu przerobione z wykozystaniem for
//            arr[j+1] = arr[j]; // optymizowany
//        }
//        arr[j + 1] = temp;
//    }
//
//}



//void bucketSort(float *arr, int n,float maxi, float minn) {
//
//
//
//    const int MAX_ELEMENTS_PER_BUCKET = 2;
//
//
//    float** buckets = new float*[kk];
//    int* bucketSizes = new int[kk]();
//
//
//    for (int i = 0; i < kk; i++) {
//        buckets[i] = new float[MAX_ELEMENTS_PER_BUCKET];
//        bucketSizes[i] = 0;
//    }
//
//
//
//    float range = (maxi - minn) / kk;
//
//
//    if (range == 0) {
//        range = 0.0f;
//    }
//
//
//    for (int i = 0; i < n; i++) {
//        int bucketIndex = (arr[i] - minn) / range;
//
//        if (bucketIndex == kk) {
//            bucketIndex--;
//        }
//
//
//        if (bucketSizes[bucketIndex] < MAX_ELEMENTS_PER_BUCKET) {
//            buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
//            bucketSizes[bucketIndex]++;
//        }
//    }
//
//
//    for (int i = 0; i < kk; i++) {
//        //InsertSort(buckets[i], bucketSizes[i]);
//        if(bucketSizes[i] > 2){
//            quickSortRecursive(buckets[i], bucketSizes[i]);
//            //merge_sort(buckets[i], 0, bucketSizes[i] - 1);
//        }
//        else{
//            continue;
//        }
//    }
//
//
//    int index = 0;
//    for (int i = 0; i < kk; i++) {
//        for (int j = 0; j < bucketSizes[i]; j++) {
//            arr[index++] = buckets[i][j];
//        }
//    }
//
//
//    for (int i = 0; i < kk; i++) {
//        delete[] buckets[i];
//    }
//    delete[] buckets;
//    delete[] bucketSizes;
//}
//nie dziala - za duzy czas dzialania w 7 i 9 testach jezeli mozna byloby zrobic z uzyciem
//algirithn sort to byloby szybciej
struct Node {
    long data;
    Node* next;





    Node(long val){
        data = val;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(long val) {
        Node* newNode = new Node(val);
        if (!tail) {

            head = newNode;

            tail= newNode;
        } else {


            tail->next =  newNode;
            tail =  newNode;
        }
    }

    void append(LinkedList& other) {
        if (!other.head){
            return;
        }
        if (!head) {
            head =    other.head;


            tail = other.tail;
        } else {
            tail->next = other.head;
            tail = other.tail;
        }
        other.head = other.tail = nullptr;
    }

    ~LinkedList() {

        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current ;



            current = nextNode;
        }
    }
};

void floatRadixSort(float in[], int size) {
    long* arr = new long[size];
    long* arr2 = new long[size];
    int* bucket = new int[2048];

    for (int i = 0; i < size; i++)
        arr[i] = *(long*)&in[i];

    for (int shift = 0; shift < 22; shift += 11)
    {
        for (int i = 0; i <= 0x7ff; i++)
            bucket[i] = 0;

        for (int i = 0; i < size; i++)
            bucket[arr[i] >> shift & 0x7ff]++;

        for (int i = 0x7ff; i > 0; i--)
            bucket[i - 1] += bucket[i];

        for (int i = size - 1; i >= 0; i--)
            arr2[--bucket[arr[i] >> shift & 0x7ff]] = arr[i];

        long* tmp = arr;
        arr = arr2;
        arr2 = tmp;
    }

    for (int i = 0; i <= 0x1ff; i++)
        bucket[i] = 0;

    for (int i = 0; i < size; i++)
        bucket[arr[i] >> 22 & 0x1ff]++;

    for (int i = 0x1ff; i > 0; i--)
        bucket[i - 1] += bucket[i];

    for (int i = size - 1; i >= 0; i--)
        arr2[--bucket[arr[i] >> 22 & 0x1ff]] = arr[i];

    bucket[0] = 0;
    bucket[1] = 0;

    for (int i = 0; i < size; i++)
        bucket[arr2[i] >> 31 & 1]++;

    bool p;
    int b;

    for (int i = size - 1; i >= 0; i--)
    {
        p = arr2[i] >> 31 & 1;
        b = --bucket[p];
        in[b - p * (b + b - size + 1)] = *(float*)&arr2[i];
    }

    delete[] arr;
    delete[] arr2;
    delete[] bucket;


}





int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);


    unsigned long long int n;
    cin >> n;
    float * arr = new float[n];
    float * out_arr = new float[n];


    float c;
//     long long int minn = 0;


    float  maxi = 0;
    float minn = t;

    long long int k;
    for(int i =0; i<n; i++){
        cin>>c;
        arr[i] = c;
        if (arr[i]>maxi){
            maxi = arr[i];
        }
        else if(arr[i]< minn ){
            minn = arr[i];
        }

        out_arr[i]  =0;
        k++;

    }
    

    float res = 0;
//    counting_sort(arr, n, min, maxi);
//bucketSort(arr, n);
    // bucketSort(arr, n,maxi, minn);
    //quickSortRecursive(arr,n);
    floatRadixSort(arr, n);


    // for(int i =0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    for(int i =1; i<n; i++){
        if(res < arr[i-1] -arr[i]){
            res = arr[i-1] - arr[i];
        }
        //cout<<fixed<< setprecision(4)<<arr[i]/t<< " " ;
    }
    cout << fixed << setprecision(4) << (float)res << "\n";
//cout<<endl<<min/t << " " <<  maxi/t;

//    long long int res = countingSortInPlace(arr, n, maxi);
//
//    cout << fixed << setprecision(4) << (float)res/t << endl;
    //cout<<res;
    k += kk;


    delete[] arr;
    arr= nullptr;

    delete[] out_arr;
    out_arr = nullptr;

    return 0;
}
