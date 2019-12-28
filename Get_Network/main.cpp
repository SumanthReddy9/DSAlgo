#include<bits/stdc++.h>
using namespace std;

int root(int x, int idx[]){
    while(idx[x] != x){
        idx[x] = idx[idx[x]];
        x = idx[x];
    }
    return x;
}

void union1(int x, int y, int sizeArr[], int idx[]){
    if(sizeArr[x] > sizeArr[y]){
        idx[y] = idx[x];
        sizeArr[x] += sizeArr[y];
    }
    else{
        idx[x] = idx[y];
        sizeArr[x] += sizeArr[y];
    }
}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> >sdx;
    vector<pair<int, int> >sdy;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        sdx.push_back(make_pair(a, i));
        sdy.push_back(make_pair(b, i));
    }
    sort(sdx.begin(), sdx.end());
    sort(sdy.begin(), sdy.end());
    vector<pair<int, pair<int, int> > >v;
    for(int i=1;i<n;i++){
        v.push_back(make_pair(sdx[i].first-sdx[i-1].first, make_pair(sdx[i].second, sdx[i-1].second)));
    }
    for(int i=1;i<n;i++){
        v.push_back(make_pair(sdy[i].first-sdy[i-1].first, make_pair(sdy[i].second, sdy[i-1].second)));
    }
    sort(v.begin(), v.end());

    /*cout<<v.size()<<endl;
    for(int i=0;i<2*n-2;i++){
        cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
    }*/
    int idx[n], sizeArr[n];
    for(int i=0;i<n;i++){
        idx[i] = i;
        sizeArr[i] = 1;
    }
    int ans = 0;
    for(int i=0;i<2*n-2;i++){
        if(root(v[i].second.first , idx) != root(v[i].second.second, idx)){
            ans += v[i].first;
            union1(v[i].second.first, v[i].second.second, sizeArr, idx);
        }
    }
    cout<<ans<<endl;
}
