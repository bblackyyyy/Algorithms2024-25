#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define k 10

string s256 = "2be3f3aa3af1f3304884d6a4fbb2cd66982b1ab0a7851c0d96e9eaa9c786c9e6";
// Vladyslav Meroniuk

//#define maxiN  100005
//
//
//vector<int> graph;
//bool visited[maxiN][2];
//int parent[maxiN][2];
//int out_degree[maxiN];
//bool onStack[maxiN];
//bool visitDFS[maxiN];
vector<vector<int>> graph;
vector<int> out_degree;
vector<bool> visited;
vector<int> parent;
vector<bool> onStack;
vector<bool> visitDFS;


// struct Graph {
// public:
//     int V;
//     vector<vector<int>> graph;
//     vector<vector<bool>> visited;
//     vector<vector<int>> parent;
//     vector<int> out;


//     Graph(int V) {
//         this->V = V;
//         graph.resize(V);
//         visited.assign(V, vector<bool>(2, 0));
//         parent.assign(V, vector<int>(2, -1));
//         out.assign(V, 0);
//     }


//     void Add(int u, int v) {
//         graph[u].push_back(v);
//         out[u]++;
//     }


//     bool bfs(int start_node) {
//         queue<pair<int, int>> q;
//         visited[start_node][0] = 1;
//         parent[start_node][0] = -1;
//         q.push(make_pair(start_node, 0));

//         while (!q.empty()) {
//             int u = q.front().first;
//             int p = q.front().second;
//             q.pop();


//             if (out[u] == 0 && p == 0) {
//                 vector<int> path;
//                 int curr_node = u;
//                 int curr_parity = p;




//                 //    for (unsigned int i = 0; i < graph[u].size(); ++i) {
// //        unsigned int v = graph[u][i];
// //        if (!visitDFS[v]) {
// //            if (dfs(v, onStack, visitDFS)) {
// //                return 1;
// //            }
// //
// //        }
// //        else if (onStack[v]) {
// //            return 1;
// //        }
// //
// //    }

//                 while (curr_node != -1) {
//                     path.push_back(curr_node);
//                     int prev_node = parent[curr_node][curr_parity];
//                     curr_parity = 1 - curr_parity;
//                     curr_node = prev_node;
//                 }


//                 reverse(path.begin(), path.end());


//                 cout << "TAK" << "\n";
//                 for (size_t i = 0; i < path.size(); ++i) {
//                     cout << path[i];
//                     if (i + 1 < path.size()) {
//                         cout << " ";
//                     }
//                 }
//                 cout << "\n";
//                 return 1;
//             }


//             for (size_t i = 0; i < graph[u].size(); ++i) {
//                 int v = graph[u][i];
//                 int np = 1 - p;
//                 if (!visited[v][np]) {
//                     visited[v][np] = 1;
//                     parent[v][np] = u;
//                     q.push(make_pair(v, np));
//                 }
//             }
//         }

//         return 0;
//     }


void InsertionSort(vector<unsigned int>& vec) {
    for (unsigned int i = 1; i < vec.size(); ++i) {
        unsigned int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
    }
}
// nie rabota tuta


bool dfs(int u) {
    visitDFS[u] = 1;
    onStack[u] = 1;

    for (int v : graph[u]) {
        if (!visitDFS[v]) {
            if (dfs(v)) {
                return 1;
            }
        } else if (onStack[v]) {
            return 1;
        }
    }

    onStack[u] = 0;
    return 0;
}


bool bfs(int start_node, int n) {
    queue<pair<int, int>> q;
    fill(visited.begin(), visited.end(), 0);
    
    
    fill(parent.begin(), parent.end(), -1);

     visited[start_node * 2 + 0] = 1;
     q.push({start_node, 0});

    while (!q.empty()) {
        int u = q.front().first;
        int p = q.front().second;
        q.pop();

        if (out_degree[u] == 0 && p == 0) {
            vector<int> path;
            int curr_node = u;
            int curr_parity = p;

            while (curr_node != -1) {
                path.push_back(curr_node);
                int prev_node = parent[curr_node * 2 + curr_parity];
                curr_parity = 1 - curr_parity;
                curr_node = prev_node;
            }

            reverse(path.begin(), path.end());

            cout << "TAK" << "\n";
            for (size_t i = 0; i < path.size(); ++i) {
                cout << path[i];
                if (i + 1 < path.size()) {
                    cout << " ";
                }
            }
            cout << "\n";
            return 1;
        }

        for (int v : graph[u]) {
            int np = 1 - p;
            if (!visited[v   * 2 + np]) {
                visited[v *2 + np] = 1;
                parent[v *2 + np] =  u;
                 
                q.push({v, np});
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    
    
    int d = k+10;
    cin >> t;
    
    while (t--) {
        int n, m, s;



        cin >> n >> m >> s ;

        graph.assign(n, vector<int>());
        out_degree.assign(n, 0);
        visited.assign(2 * n, false);
        parent.assign(2 * n, -1);
        onStack.assign(n, false);
        visitDFS.assign(n, false);

//        for (int i = 0; i < n; ++i) {
//            graph[i].clear();
//            visited[i][0] = visited[i][1] = false;
//            parent[i][0] = parent[i][1] = -1;
//            out_degree[i] = 0;
//            onStack[i] = false;
//            visitDFS[i] = false;
//        }


        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x  >> y;

            graph[x].push_back(y);

            
            
            out_degree[x]++;
        }
        


        for (int i = 0; i < n; ++i) {
            if (!graph[i].empty()) {
                sort(graph[i].begin(),  graph[i].end());


            }
            
            
            
        }
        // InsertionSort(graph[i]); // nie work tutaj dladuzych testow --  dlugi czas
        // }


        if (!bfs(s,n)) {
            
            if (dfs(s)) {
                cout << "PETLA" << "\n";
            } else {
                cout << "NIE"<< "\n";
            }
        }
    }
    d++;
    return 0;






}

//dfs -> if(cycle) = pentla
// dfs -> if(!cycle) ->bfs if stabil ==return way  TAK slak
//wlse NIE
