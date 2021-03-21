#include<bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> paper;
vector<int> cntBW = {0, 0};

int cut(vector<int> pRange, int psize);

void setRange(vector<int>& range, int rStart, int rEnd, int cStart, int cEnd){
    range[0] = rStart;
    range[1] = rEnd  ;
    range[2] = cStart;
    range[3] = cEnd  ;
}

void countBW(int valCut){
    if(valCut == 0 || valCut == 1) cntBW[valCut]++;
}

void nextStep(vector<int>pRange, int psize){
    int rStart = pRange[0], rEnd = pRange[1],
        cStart = pRange[2], cEnd = pRange[3];
    for(int i=0; i<4; i++){
        vector<int> nextRange(4);

        switch(i){
        case 0:
            setRange(nextRange, rStart        , rStart+psize/2, cStart        , cStart+psize/2);
            break;
        case 1:
            setRange(nextRange, rStart+psize/2, rEnd          , cStart        , cStart+psize/2);
            break;
        case 2:
            setRange(nextRange, rStart        , rStart+psize/2, cStart+psize/2, cEnd          );
            break;
        case 3:
            setRange(nextRange, rStart+psize/2, rEnd          , cStart+psize/2, cEnd          );
            break;
            }

        countBW(cut(nextRange, psize/2));
    }
}

int cut(vector<int> pRange, int psize){
    int rStart = pRange[0], rEnd = pRange[1],
        cStart = pRange[2], cEnd = pRange[3],
        now, prev = paper.at(rStart).at(cStart);

    if(psize == 1) return prev;

    else{
        for(int i=rStart; i < rEnd; i++){
            for(int j=cStart; j < cEnd; j++){

                now = paper.at(i).at(j);

                if(prev != now){
                    nextStep(pRange, psize);
                    return -1;
                }
            }
        }

        return now;
    }
}

int main(){
    cin >> N;
    paper.resize(N);

    for(auto& prow : paper){
        prow.resize(N);
        for(auto& p: prow) cin >> p;
    }

    vector<int> pRange = {0, N, 0, N};

    countBW(cut(pRange, N));

    cout << cntBW[0] << endl << cntBW[1];
}
