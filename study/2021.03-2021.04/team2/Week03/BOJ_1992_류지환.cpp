#include <bits/stdc++.h>

using namespace std;

int N;
string str;
vector<vector<int>> vvdata;

class Node{
private:
    int val;
    vector<Node*> children;
public:
    Node(): val(-1){};
    void setVal  (int v  ){ val = v;               }
    void getChild(Node* n){ children.push_back(n); }
    int  getVal  (       ){ return val;            }
    vector<Node*> getChildren() {return children;}
};

void makeTree(Node* root, vector<int> range, int dsize);

void setRange(vector<int>& range, int rStart, int rEnd, int cStart, int cEnd){
    range.at(0) = rStart;
    range.at(1) = rEnd  ;
    range.at(2) = cStart;
    range.at(3) = cEnd  ;
}

void nextStep(Node* root, vector<int> range, int dsize){
    int rStart = range.at(0), rEnd = range.at(1),
        cStart = range.at(2), cEnd = range.at(3);

    vector<int> nextRange(4);
    for(int i=0; i<4; i++){
    Node* rtemp = new Node();
    switch(i){
    case 0:
        setRange(nextRange, rStart        , rStart+dsize/2, cStart        , cStart+dsize/2);
        break;
    case 1:
        setRange(nextRange, rStart        , rStart+dsize/2, cStart+dsize/2, cEnd          );
        break;
    case 2:
        setRange(nextRange, rStart+dsize/2, rEnd          , cStart        , cStart+dsize/2);
        break;
    case 3:
        setRange(nextRange, rStart+dsize/2, rEnd          , cStart+dsize/2, cEnd          );
        break;
        }

    makeTree(rtemp, nextRange, dsize/2);
    root->getChild(rtemp);
    }
}

void makeTree(Node* root, vector<int> range, int dsize){
    int rStart = range.at(0), rEnd = range.at(1),
        cStart = range.at(2), cEnd = range.at(3),
        now, prev= vvdata.at(rStart).at(cStart);

    if(dsize == 1) root->setVal(prev);

    else{
        for(int i= rStart; i < rEnd; i++){
            for(int j=cStart; j<cEnd;j++){
                now = vvdata.at(i).at(j);
                if(prev != now){
                    nextStep(root, range, dsize);
                    return;
                }
            }
        }
        root->setVal(now);
    }

    return;
}

void out(Node* root){
    int rval = root->getVal();
    if(rval == -1){
        cout<<"(";
        for(auto r: root->getChildren()){
            out(r);
        }
        cout << ")";
    }
    else cout << rval;
}

int main()
{
    cin >> N;

    vvdata.resize(N);

    for(auto &vdata: vvdata){
        cin >> str;
        for(auto c: str)
        vdata.push_back(c - '0');
    }


    Node* root = new Node();

    vector<int> range(4);
    setRange(range, 0, N, 0, N);

    makeTree(root, range, N);

    out(root);

    return 0;
}
