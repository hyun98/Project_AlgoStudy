#include <bits/stdc++.h>

using namespace std;

int n;

double ans = 0;

typedef pair<double, double> star;
typedef pair<int, int> path;
typedef pair<path,double> edge;

vector<int> check;


vector<edge> vedge;

vector<star> vstar;

bool sortEdge(edge e1, edge e2){
    return e1.second < e2.second;
}

int jump(int idx){
    if(check.at(idx) > 0) return jump(check.at(idx));
    else                  return idx;
}

int main()
{
    cin >> n;

    check.resize(n+1, -1);

    vstar.resize(n);

    for(auto& star: vstar) cin >> star.first >> star.second;


    for(int from=0; from<n-1; from++){
        for(int to = from+1; to<n; to++){
            double cost = sqrt(pow(vstar.at(from).first - vstar.at(to).first,2)
                               + pow(vstar.at(from).second - vstar.at(to).second,2));
            vedge.push_back(edge(path(from,to),cost));
        }
    }

    sort(vedge.begin(), vedge.end(), sortEdge);

    for(auto edg: vedge){
        path p  = edg.first;
        double cst = edg.second, jp1 = jump(p.first), jp2 = jump(p.second);

        if(jp1 > jp2){
            int tmp = jp1;
            jp1 = jp2;
            jp2 = tmp;
        }

        if(jp1 != jp2){
            check.at(jp2) = check.at(jp1) + check.at(jp2);
            check.at(jp1) = jp2;
            ans += cst;
            if(check.at(jp2) == (-1) * n){
                cout << fixed;
                cout.precision(2);
                cout << ans;
                return 0;
            }
        }

    }


    cout << fixed;
    cout.precision(2);

    cout << ans;


    return 0;
}
