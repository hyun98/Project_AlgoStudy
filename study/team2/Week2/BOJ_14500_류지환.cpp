#include <bits/stdc++.h>

using namespace std;

class point{
public:
    bool check_dfs = false, check_bfs = false;
    int val;
    vector<point*> children;
    point()     : val(0) {};
    point(int v): val(v) {};

    int getVal()             {return val;}
    void DFS(int&);
    void BFS(int&);
    void max_tech();
};

bool out = false;
int N, M, ans = 0;
vector<point*> picked, vmax, prow;
vector<vector<point*>> paper;


bool myfunc(point* p1, point* p2) { return p1->getVal() < p2->getVal();   }

void point::DFS(int& total){


    if(picked.size()==4){

        ans = max(total, ans);

        out = true;

        return ;
    }

    this -> check_dfs = true;
    total += this->val;
    picked.push_back(this);

    for(auto child: children){
        if(!child->check_dfs)
            child->DFS(total);

        if(out){
            out = false;
            break;
        }
    }

    total -= picked.back()->val;
    picked.back()->check_dfs = false;
    picked.pop_back();
}

void point::BFS(int& total){

    if(!this->check_bfs){
    if(children.size() >= 3){
        int idx = 0;

        total += this->val;

        if(children.size() == 4){
            idx++;
            sort(children.begin(), children.end(), myfunc);
        }

        for(; idx<(int)children.size(); idx++){
            total += children.at(idx)->val;
        }
    }

    ans = max(total, ans);
    this->check_bfs = true;
    }
}

void point::max_tech(){
    int dfs = 0, bfs = 0;

    DFS(dfs);

    BFS(bfs);

    for(auto child: children){
        int tbfs = 0;
        child -> BFS(tbfs);
    }
}

void makeGraph(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            point * root = paper.at(i).at(j);
            if(j-1>=0) root->children.push_back(paper.at(i).at(j-1));
            if(j+1<M ) root->children.push_back(paper.at(i).at(j+1));
            if(i-1>=0) root->children.push_back(paper.at(i-1).at(j));
            if(i+1<N ) root->children.push_back(paper.at(i+1).at(j));
        }
    }
}

int main()
{
    cin >> N >>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int data;
            cin >> data;
            point* pp = new point(data);
            prow.push_back(pp);
        }
        paper.push_back(prow);
        prow.clear();
    }
    makeGraph();

    for(auto pr: paper){
        for(auto p: pr)
            p->max_tech();
    }

    cout << ans ;

    return 0;
}
