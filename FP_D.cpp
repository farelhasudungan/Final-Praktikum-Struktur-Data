#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std; 
  
struct Graph { 
    int V, E; 

    Graph(int V, int E){ 
        this->V = V; 
        this->E = E;
    } 

    vector< pair<long, pair<long, bool > > > edges[SHRT_MAX]; 

    void addEdge(int u, int v, int w, bool r){
        edges[u].push_back({v, {w, r}});
        edges[v].push_back({u, {w, r}});
    }

    int dijkstra(vector<long> &result, vector<long> &predecessor, long start, long finish, int maximum);
}; 

int Graph::dijkstra(vector<long> &result, vector<long> &predecessor, long start, long finish, int maximum){
    vector<bool> visited(V, false);
    priority_queue <pair<long, long>,
                    vector <pair<long, long>>,
                    greater <pair<long, long>> > pq;
    result = vector<long>(V, LONG_MAX);
    predecessor = vector<long>(V, -1); // predecessor is a vector to store the predecessor (pendahulu) of each node

    pq.push(make_pair(0, start));
    result[start] = 0;

    vector<long> weight_start(V, -1);
    vector<long> weight_prev(V, -1);
    weight_start[start] = 0;
    weight_prev[start] = 0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();


        long u = temp.second;
        if (visited[u]) continue;
        visited[u] = true;


        for(auto vertex:edges[u]){
            long nextVertex = vertex.first;
            long weight = vertex.second.first;
            bool isRisky = vertex.second.second;


            if(weight == 0 && isRisky){
                long weightStart = weight_start[u];
                long weightPrev = weight_prev[u];
                // if(weightStart == -1) weightStart = 0;
                // if(weightPrev == -1) weightPrev = 0;
                weight = weightStart + weightPrev;
                vertex.second.first = weight;
            }


            if(!visited[nextVertex] && result[u] + weight < result[nextVertex]){
                result[nextVertex] = result[u] + weight;
                pq.push(make_pair(result[nextVertex], nextVertex));
                predecessor[nextVertex] = u; // store the predecessor of nextVertex
                if(u == start){
                    weight_start[nextVertex] = weight;
                } else {
                    weight_start[nextVertex] = weight_start[u];
                }

                weight_prev[nextVertex] = weight;
            }
        }
    }

    if(result[finish] == LONG_MAX) return -1;

    bool useRisky = false;
    long curr = finish;
    while(predecessor[curr] != -1){
        long prev = predecessor[curr];
        for(auto edge:edges[prev]){
            if(edge.first == curr && edge.second.second){
                useRisky = true;
                break;
            }
        }
        if(useRisky) break;
        curr = prev;
    }
    
    return useRisky ? 1 : 0;
}


int main(){ 
    int V, E;
    cin >> V >> E;
    
    Graph g(V, E);

    for(int i = 0; i < E; i++){
        int V1, V2, W, R;
        cin >> V1 >> V2 >> W >> R;
        g.addEdge(V1, V2, W, R);
    }

    int Start_Node, Finish_Node;
    cin >> Start_Node >> Finish_Node;

    int Maximum_Weight;
    cin >> Maximum_Weight;

    vector<long> result;
    vector<long> predecessor;
    int output = g.dijkstra(result, predecessor, Start_Node, Finish_Node, Maximum_Weight);
    if(output == 1){
        cout << "Press to overtake and dive bomb please max" << endl;
    } else if(output == 0){
        cout << "Decrease lift and coast please max, oscar is slower in front of you" << endl;
    } else if(output == -1){
        cout << "Increase lift and coast please max, just try to stay in front of Lando" << endl;
    }
    
    return 0; 
} 