#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    int maxVal = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i] > maxVal){
            maxVal = arr[i];
        }
    }
    vector<int>adj[maxVal+1];
    for(int i=0;i<n;i++){
        adj[arr[i]].push_back(i);
    }
    for(int i=0;i<n;i++){
        for(int j = 0; j< adj[arr[i]].size(); j++){
            cout<<adj[arr[i]][j]<<" ";
        }
        cout<<endl;
    }
}
