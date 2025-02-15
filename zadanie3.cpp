#include <iostream>
#include <climits>
#include <string>

using namespace std;
string s256 =  "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
//Vladyslav Meroniuk
#define kl 1000

#define MAX_C 30000


struct customer {
    long long time;
    customer *next;

    customer() : time(0), next(nullptr) {}
    customer(int t) : time(t), next(nullptr) {}
};

struct queue {
    bool isopen = false;
    int id;
    long long available_time = 0;
    int ilosc_osob = 0;
    customer *head = nullptr;
    customer *tail = nullptr;

    queue() {}

    bool isEmpty() {
        return head == nullptr;
    }

    void push(int service_time) {
        customer *new_customer = new customer(service_time);
        if (isEmpty()) {
            head = tail = new_customer;
            available_time = service_time;
        } else {
            available_time += service_time;
            tail->next = new_customer;
            tail = new_customer;
        }
        ilosc_osob++;
    }

    void pop() {
        if (!isEmpty()) {
            customer *temp = head;
            head = head->next;
            ilosc_osob--;
            if (head == nullptr) {
                tail = nullptr;
            }
            //available_time -= temp->time;
            delete temp;
        }
    }

    long long get_sum_time() {
        return available_time;
    }

    ~queue() {
        while (!isEmpty()) {
            pop();
        }
    }

};


int select_minq(queue *queues, int l, int exclude_id = -1) {
    int min_id = -1;
    long long min_sum_time = LLONG_MAX;

    for (int i = 0; i < l; ++i) {
        if (queues[i].isopen && i != exclude_id) {
            long long current_sum_time = queues[i].get_sum_time();
            if (current_sum_time < min_sum_time) {
                min_id = i;
                min_sum_time = current_sum_time;
            }
            else if (current_sum_time == min_sum_time && (min_id == -1 || i < min_id)) {
                min_id = i;
            }
        }
    }
    return min_id;
}

void redistribute_customers(queue *queues, int l, int closed_id) {
    queue &closed_queue = queues[closed_id];

    if (!closed_queue.isEmpty()) {
        closed_queue.pop();
    }

    customer *current = closed_queue.head;
    while (current != nullptr) {
        int service_time = current->time;
        int min_id = select_minq(queues, l, closed_id);
        if (min_id != -1) {
            queues[min_id].push(service_time);
        }

        customer *temp = current;
        current = current->next;
        delete temp;
    }

    closed_queue.head = closed_queue.tail = nullptr;
    closed_queue.available_time = 0;
    closed_queue.ilosc_osob = 0;
}

void process_time(queue &q, int czas) {
    if (!q.isopen || q.isEmpty()) {
        return;
    }

    while (czas > 0 && !q.isEmpty()) {
        if (q.head->time > czas) {
            q.head->time -= czas;
            q.available_time -= czas;
            czas = 0;
        }
        else {
            czas -= q.head->time;
            q.available_time -= q.head->time;
            q.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t, l, s, z;
    cin >> t >> l >> s >> z;
    //queue ques[l];
    queue* ques = new queue[l];
    char c;
    bool frg = 1;
    int time_to_break = 0;

    while (frg ) {
        cin >> c;
        switch (c) {
            case 'o': {
                int num_kasy;
                cin >> num_kasy;
                if (num_kasy >= 0 && num_kasy < l) {
                    ques[num_kasy].isopen = 1;
                    ques[num_kasy].id = num_kasy;

                    ques[num_kasy].available_time = 0;
                    ques[num_kasy].ilosc_osob = 0;


                }
                break;
            }
            case 'z': {
                int num_kasy;
                cin >> num_kasy;
                int open_queues = 0;
                for (int j = 0; j < l; j++) {
                    if (ques[j].isopen) {
                        open_queues++;
                    }
                }

                if (ques[num_kasy].isopen) {

                    if (open_queues > 1) {
                        redistribute_customers(ques, l, num_kasy);
                        ques[num_kasy].isopen = 0;
                        ques[num_kasy].available_time = 0;
                        ques[num_kasy].ilosc_osob = 0;
                        ques[num_kasy].head = nullptr;
                        ques[num_kasy].tail = nullptr;
                    }

                }
                break;
            }
            case 'k': {
                int czas, products;
                cin >> czas >> products;

                time_to_break += czas;
                if (time_to_break  > t) {
                    int remaining_time = t - (time_to_break - czas);
                    for (int i = 0; i < l; i++) {
                        if (ques[i].isopen) {
                            process_time(ques[i], remaining_time);
                        }
                    }
                    frg = 0;
                    break;
                }

                //                if(time_to_break == t){
                //                    frg = 0;
                //                    break;
                //                }

                for (int i = 0; i < l; i++) {
                    if (ques[i].isopen) {
                        process_time(ques[i], czas);
                    }
                }


                int min_id = select_minq(ques, l);


                if (min_id != -1) {
                    ques[min_id].push(s * products + z);
                }

                break;
            }


        }
    }


    for (int i = 0; i < l; i++) {
        if (!ques[i].isopen) {
            cout << "K" << i << ": z";
        } else {
            cout << "K" << i << ": " << ques[i].ilosc_osob << "o " << ques[i].get_sum_time() << "s";
        }
        if (i < l - 1) {
            cout << ", ";
        }
    }
    int ml = kl+1;
    cout << "\n";
    delete[] ques;
    return 0;
}
