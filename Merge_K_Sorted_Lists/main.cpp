#include<bits/stdc++.h>
using namespace std;


vector<int> msort(vector<int> vec1, vector<int> vec2){
    vector<int> ans;
    /*for(int i=0;i<vec1.size();i++){
        cout<<vec1[i]<<" ";
    }
    cout<<endl;
    for(int j=0;j<vec2.size();j++){
        cout<<vec2[j]<<" ";
    }
    cout<<endl;*/
    int i=0, j=0;

    while(i < vec1.size() && j < vec2.size()){
        if(vec1[i] > vec2[j]){
            ans.push_back(vec2[j]);
            j++;
        }
        else{
            ans.push_back(vec1[i]);
            i++;
        }
    }
    //cout<<i<<" "<<j<<" "<<vec1.size()<<" "<<vec2.size()<<endl;
    while(i < vec1.size()){
        ans.push_back(vec1[i]);
        i++;
    }
    while(j < vec2.size()){
        ans.push_back(vec2[j]);
        j++;
    }
    return ans;
}

void getArr(vector<int> vec[], int k){
    vector<int> ans;
    for(int i=0;i<k;i++){
        if(i == 0){
            for(int j=0;j<vec[i].size();j++){
                ans.push_back(vec[i][j]);
            }
        }
        else{
            ans = msort(ans, vec[i]);
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int k;
    cin>>k;
    vector<int> vec[k];
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        for(int j=0;j<t;j++){
            int p;
            cin>>p;
            vec[i].push_back(p);
        }
    }
    getArr(vec, k);
}
