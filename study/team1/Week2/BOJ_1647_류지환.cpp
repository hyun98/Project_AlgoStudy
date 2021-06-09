#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> path;
typedef pair<path,int> edge;

int V, E, from, to, cost, ans = 0, maxCost = 0;

vector<edge> vedge;

vector<int> check;


int *DP;

bool sortEdge(edge e1, edge e2){
    return e1.second < e2.second;
}

int jump(int idx){
    if(check.at(idx) > 0) return jump(check.at(idx));
    else                  return idx;
}

int main()
{
    cin >> V >>E;

    check.resize(V+1, -1);

    for(int i=0; i<E; i++){
        cin >> from >>to >>cost;
        vedge.push_back(edge(path(from,to),cost));
    }

    sort(vedge.begin(), vedge.end(), sortEdge);

    for(auto edg: vedge){
        path p  = edg.first;
        int cst = edg.second, jp1 = jump(p.first), jp2 = jump(p.second);

        if(jp1 > jp2){
            int tmp = jp1;
            jp1 = jp2;
            jp2 = tmp;
        }

        if(jp1 != jp2){
            check.at(jp2) = check.at(jp1) + check.at(jp2);
            check.at(jp1) = jp2;
            ans += cst;
            maxCost = max(maxCost, cst);
            if(check.at(jp2) == (-1) * V){
                cout << ans - maxCost;
                return 0;
            }
        }

    }

    cout << ans - maxCost;

    return 0;
}
