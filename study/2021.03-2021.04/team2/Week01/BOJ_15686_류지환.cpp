#include <bits/stdc++.h>

using namespace std;

class point{
private:
    int x, y, cost = 0;
public:
    point(): x(0), y(0) {};
    point(int d1, int d2): x(d1), y(d2) {};
    int getX() {    return x;  }
    int getY() {    return y;  }
    void setCost(point chk) {
        cost = abs(this->x - chk.x) + abs(this->y - chk.y);
    }
    int getCost()   { return cost;}
};

vector<int> picked;
vector<point> house;
vector<point> chicken;

int N, M, ans = 5000;

void inputData(){
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            int data;
            cin >> data;
            point p(i, j);
            switch(data){
            case 1:
                house  .push_back(p);
                break;
            case 2:
                chicken.push_back(p);
                break;
            }
        }
    }
}

void pick(){
    if((int)picked.size() == M){
        int temp = 0;
        for(auto h: house){
            int minCost = 100;
            for(auto p: picked){
                h.setCost(chicken.at(p));
                minCost = min(h.getCost(), minCost);
            }
            temp += minCost;
        }
        ans = min(temp, ans);
        return;
    }

    int smallest;
    if(picked.empty()) smallest = 0;
    else               smallest = picked.back() +1;

    for(int next = smallest; next < (int)chicken.size(); next++){
        picked.push_back(next);
        pick();
        picked.pop_back();
    }
    return;
}

int main()
{
    inputData();
    pick();
    cout << ans;

    return 0;
}
