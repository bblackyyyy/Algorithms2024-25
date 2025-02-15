#include <iostream>
#include <string>
#define min_V 313
#define max_V 350
#define min_F 20
#define max_F 20000
using namespace std;

string s256 = "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
// Vladyslav Meroniuk



//struct Pair_list {
//    Pair p;
//    Pair_list* next;
//
//    Pair_list(Pair pair) : p(pair), next(nullptr) {}
//
//    void push(Pair pair) {
//        Pair_list* aux = this;
//        while (aux->next != nullptr) {
//            aux = aux->next;
//
//        }
//        aux->next = new Pair_list(pair);
//    }





//    void push_by_f(Pair pair) {
//        if (next == nullptr || next->p.f < pair.f) {
//            Pair_list* newNode = new Pair_list(pair);
//            newNode->next = next;
//            next = newNode;
//        } else {
//            Pair_list* current = this;
//            while (current->next != nullptr && current->next->p.f <= pair.f) {
//                current = current->next;
//            }
//            Pair_list* newNode = new Pair_list(pair);
//            newNode->next = current->next;
//            current->next = newNode;
//        }
//    }



//
//    void display() const {
//        const Pair_list* tmp = this;
//        while (tmp != nullptr) {
//
//            cout << "(" << tmp->p.f << "," << tmp->p.l << ") ";
//            tmp = tmp->next;
//        }
//    }
//
//    void sort() {
//        if (this == nullptr || this->next == nullptr) return;
//
//        bool swapped;
//        do {
//            swapped = false;
//            Pair_list* current = this;
//            while (current != nullptr && current->next != nullptr) {
//                if (current->p.f > current->next->p.f ||
//                    (current->p.f == current->next->p.f && current->p.l > current->next->p.l)) {
//                    swap(current->p, current->next->p);
//                    swapped = true;
//                }
//                current = current->next;
//            }
//        } while (swapped);
//    }
//
//
//
//
//};

//struct Data {
//    unsigned int y;
//    Pair_list* pair;
//
//    Data(unsigned int yy, Pair pair) : y(yy), pair(new Pair_list(pair)) {}
//
//    void show_pairs() const {
//        if (pair != nullptr) {
//            pair->display();
//        }
//    }
//
//};







struct Tria {
    unsigned int y;
    unsigned int f;
    unsigned int l;
    Tria(unsigned int yy, unsigned int ff, unsigned int ll){

        y = yy;
        f = ff;
        l = ll;
    }
};

struct tree {
    Tria d;
    tree* left;
    tree* right;
    unsigned int same;
    //unsigned int size =0;

    tree(unsigned int yy, unsigned int ff, unsigned int ll) : d(yy, ff, ll) {
//        d.y = yy;
//        d.f = ff;
//        d.l = ll;

        left = nullptr;
        right = nullptr;
        same = 1;
        //size++;
    }
    //d(yy, ff, ll), left(nullptr), right(nullptr) , same(1) {}

    void add_node(unsigned int y, unsigned int f, unsigned int l, tree*& MyTree) {
        if (MyTree == nullptr) {
            MyTree = new tree(y, f, l);
            return;
        }

        if (y < MyTree->d.y) {
            add_node(y, f, l, MyTree->left);

        }
        if (y > MyTree->d.y) {
            add_node(y, f, l, MyTree->right);

        }
        if(y == MyTree->d.y){
            if(f < MyTree->d.f){
                add_node(y, f, l, MyTree->left);


            }
            if(f > MyTree->d.f){
                add_node(y, f, l, MyTree->right);


            }
            if(f == MyTree->d.f){
                if(l < MyTree->d.l){
                    add_node(y, f, l, MyTree->left);

                }
                if(l > MyTree->d.l){
                    add_node(y, f, l, MyTree->right);

                }
                if(l == MyTree->d.l){
                    MyTree->same++;
                }
            }
        }
    }

    void show(tree* Tree, unsigned int& last_y) const {

//        if (Tree != nullptr) {
//            show(Tree->left);
//            cout << Tree->d.y << ": (" << Tree->d.f << "," << Tree->d.l << ")" << '\n';
//            show(Tree->right);
//        }
        if (Tree != nullptr) {
            show(Tree->left, last_y);
            if (Tree->d.y != last_y) {
                if (last_y != 0) cout << "\n";
                cout << Tree->d.y << ":";
                last_y = Tree->d.y;
            }
            //cout << " (" << Tree->d.f << "," << Tree->d.l << ")";
            for (unsigned int i = 0; i < Tree->same; ++i) {
                cout << " (" << Tree->d.f << "," << Tree->d.l << ")";
            }

            show(Tree->right, last_y);
        }
    }
};

void del(tree*& Tree) {
    if (Tree == nullptr) return;

    del(Tree->left);
    del(Tree->right);

    delete Tree;
    Tree = nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int n;
    cin >> n;

    tree* MyTree = nullptr;
    bool r = 0;
    bool t =1;

    while (n--) {
        unsigned int y, f, l;
        cin >> y >> f >> l;

        if (  f >= min_F && f <= max_F && (f * l * 0.01) >= min_V && (f * l * 0.01) <= max_V) {
            if(f >= 275 && f <= 325 && t ) {
                r = 1;
            }
            else{
                t =0;
            }
                if (MyTree == nullptr) {
                    MyTree = new tree(y, f, l);
                } else {
                    MyTree->add_node(y, f, l, MyTree);
                }



        }
//        else {
//            r = 0;
//        }
    }

//    if(MyTree == nullptr){
//        r = 0;
//    }

    unsigned int y =0;
    if (r) {

        MyTree->show(MyTree,y);
        cout <<"\n" <<"TAK"; //<< "\n";
    } else {

        MyTree->show(MyTree,y);
        cout <<"\n" <<"NIE"; //<< "\n";
    }
    //cout<<MyTree->size;
    del(MyTree);
    return 0;
}
