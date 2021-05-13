#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Line{
    int st;
    int ed;
    long long value;
};

int V, E;
long long result = 0;
int Node[100001];
vector<Line> Edge;

bool compare(Line &a, Line &b){
    return a.value < b.value;
}

int find_topnode(int a){
    if(Node[a] < 0) return a;
    return find_topnode(Node[a]);
}

bool is_cycle(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(a == b) return true;
    else return false;
}

void Union_node(int a, int b){
    a = find_topnode(a);
    b = find_topnode(b);
    if(Node[a] > Node[b]){
        Node[b] += Node[a];
        Node[a] = b;
    }
    else{
        Node[a] += Node[b];
        Node[b] = a;
    }
}

void solve(){
    int va, vb, cnt = 0, rm_load;
    for(int i = 0; i < Edge.size(); i++){
        if(cnt == V-1) break;
        va = Edge[i].st;
        vb = Edge[i].ed;
        if(!is_cycle(va, vb)){
            Union_node(va, vb);
            result += Edge[i].value;
            cnt++;
            rm_load = Edge[i].value;
        }
    }
    cout << result - rm_load;
}

void init(){
    int a, b, c;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        Edge.push_back({a, b, c});
    }
    sort(Edge.begin(), Edge.end(), compare);
    memset(Node, -1, sizeof(Node));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    init();
    solve();
    
    return 0;
}
