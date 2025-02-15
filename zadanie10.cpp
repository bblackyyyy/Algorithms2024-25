#include <iostream>
//#include<vector>
#include <string>
#define ROW 2
#define m_heap  -100000

using namespace std;
string s256 = "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
//struct date{
//    int price;
//    int percent;
//
//
//    date(int p, int per){
//        price = p;
//        percent = per;
//    }
//};

////void add(vector<vector <long long int > > v, long long int price, long long int percent){
////    vector<long long int> temp;
////    temp.push_back(price);
////    temp.push_back(percent);
////    v.push_back(temp);
////}
//
//void heapify(vector<long long>& vec, int n, int i) {
//    int largest = i;
//    int left   = 2 * i + 1;
//    int right  = 2 * i + 2;
//
//
//    if (left < n && vec[left] >  vec[largest]) {
//        largest = left;
//    }
//
//    if (right < n && vec[ right] > vec[largest]) {
//        largest = right;
//    }
//
//
//    if (largest != i) {
//        swap(vec[i], vec[largest]);
//        heapify(vec, n, largest);
//    }
//}
//
//
//void heapSort(vector<long long>& vec) {
//    int n = vec.size();
//
//
//    for (int i = n / 2 - 1; i >= 0; --i) {
//        heapify(vec, n, i);
//    }
//
//
//    for (int i = n - 1; i > 0; --i) {
//
//
//        swap(vec[0], vec[i]);
//        heapify(vec, i, 0);
//    }
//}

struct Heap {
    int size ;

    int count;
    int* array;

};




Heap* createHeap(int size ) {
    Heap* h = new Heap;
    h->size  = size ;
    h->count = 0;

    h->array = new int[size ];
    return h;
}



int getParent(Heap* h, int i) {
    if (i <= 0 || i >= h->count){
        return -1;
    } else{
    return (i - 1) / 2;
    }
}




int getLeftChild(Heap* h, int i) {
    int left = 2*i + 1;
    if(left>= h->count){
        return -1;
    }
    else{
     return left;
    }
}







int getRightChild(Heap* h, int i) {
    int right = 2*i + 2;
    if(right>= h->count){
        return -1;
    }
    else{
        return right;
    }
}




void maxHeapify(Heap* h, int i) {


    int left = getLeftChild(h, i);
    int right = getRightChild(h, i);
    int largest = i;

    if (left != -1 && h->array[left] > h->array[largest]) {
        largest = left;
    }
    if (right != -1 && h->array[right] > h->array[largest]) {
        largest = right;
    }


    if (largest != i) {
        int temp = h->array[i];
        h->array[i] = h->array[largest];
        h->array[largest] = temp;
        maxHeapify(h, largest);
    }

}

void resizeHeap(Heap* h) {
    int newCapacity = 2 * h->size ;
    int* newArray = new int[newCapacity];
    for (int i = 0; i < h->count; i++) {
        newArray[i] = h->array[i];
    }
    delete[] h->array;
    h->array = newArray;
    h->size  = newCapacity;
}


void heapIncreaseKey(Heap* h, int i, int key) {
    if (i < 0 || i >= h->count) return;
    if (key < h->array[i]) {

        return;
    }
    h->array[i] = key;


    while (i > 0) {
        int parentIdx = getParent(h, i);
        if (parentIdx == -1) {
            break;
        }
        if (h->array[parentIdx] < h->array[i]) {
            int temp = h->array[parentIdx];
            h->array[parentIdx] = h->array[i];
            h->array[i] = temp;
            i = parentIdx;
        } else {
            break;
        }
    }
}

void HeapInsert(Heap* h, int key) {
    if (h->count == h->size ) {
        resizeHeap(h);
    }
    h->count++;

    h->array[h->count - 1] = m_heap;
    heapIncreaseKey(h, h->count - 1, key);
}

int heapExtractMax(Heap* h) {
    if (!h || h->count < 1) {
        return m_heap;
    }
    int maxVal = h->array[0];
    h->array[0] = h->array[h->count - 1];
    h->count--;


    maxHeapify(h, 0);



    return maxVal;
}

void destroyHeap(Heap* h) {

        delete[] h->array;
        delete h;

}






int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    unsigned short int n =0;
    unsigned short int kl =0;
   // long long  int price =0;

    //vector<date> v;
    //vector<date> v;
    char c;




    cin>>n;

    long long *arr = new long long[ROW];

    while(n--){
        kl++;
        Heap* prices = createHeap(1);
        Heap* taxes  = createHeap(1);

        unsigned int o = 0;
        cin>>o;
        arr[0] = 0;
        arr[1] = 0;
        //v.resize(o);
        for(int i =0; i<o; i++){



            cin>>c;
            switch (c){
                case 'a' :
                    int p, t;
                    p =0;
                    t =0;
                    cin>>p>>t;

                    HeapInsert(prices, p);
                    HeapInsert(taxes, -t);
                    break;





                case 'p':
                    //heapSort(arr[0]);
                    int pc =0;
                    cin>>pc;
//                    if(arr[0][0] + price <= 0){
//                        arr[0][0]  =1;
//                    }
//                    else{
//                        arr[0][0] += price;
//                    }
//                    heapSort(arr[0]);
                    if (prices->count > 0) {
                        int largestPrice = heapExtractMax(prices);
                        int newPrice = largestPrice + pc;


                        if(newPrice < 0){
                            newPrice =  largestPrice;
                        }


                            HeapInsert(prices, newPrice);

                    }






            }




        }
//        arr[1].reserve(arr[0].size());
//        for(int i =0; i<arr[0].size(); i++){
//            cout<<arr[1][i] << " ";
//        }
//        for(int i =0; i<arr[0].size(); i++){
//            res[n] += arr[0][i] * arr[1][i];
//        }
//        cout<<res[n]<<endl;
        long long totalTax = 0;
        while (prices->count > 0 && taxes->count > 0) {
            long long price  = heapExtractMax(prices);
            long long negTax = heapExtractMax(taxes);
            long long tax    = negTax * -1;
            totalTax += price * tax;
        }



        cout << totalTax << endl;
        
        destroyHeap(prices);
        destroyHeap(taxes);
    }


//    for(int i =0; i<res.size(); i++){
//        cout<<res[i]<<endl;
//    }

    int k  = 0;
    for(int i =0; i<ROW; i++){
        k =+ arr[i];
        k =+ kl;
    }




    delete[] arr;
    arr = nullptr;
   // k = nullptr;
    return 0;

}
