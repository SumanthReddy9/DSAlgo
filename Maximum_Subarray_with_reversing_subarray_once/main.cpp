#include<bits/stdc++.h>
using namespace std;

int getans1(int arr[], int n){
    int ans = INT_MIN, tempAns = 0;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            tempAns += arr[i];
        }
        else{
            tempAns = 0;
        }
        if(tempAns > ans){
            ans = tempAns;
        }
    }
    return ans;
}

int getans2(int arr[], int n){
    int tempAns = 0, prev  =INT_MIN, idx = -1, t1 = INT_MIN, t2;
    for(int i=0;i<n;i++){
        if(arr[i] > 0){
            tempAns += arr[i];
        }
        else{
            t2 = tempAns;
            for(int j=i+1;j<n;j++){
                if(t2 > t1){
                    t1 = t2;
                }
                t2 += arr[j];
            }
            if(t2 > t1){
                t1 = t2;
            }
            tempAns += arr[i];
        }
    }
    return t1;
}

int getans3(int arr[], int n){
    int tempAns = 0, prev  =INT_MIN, idx = -1, t1 = INT_MIN, t2;
    for(int i=n-1;i>=0;i--){
        if(arr[i] > 0){
            tempAns += arr[i];
        }
        else{
            t2 = tempAns;
            for(int j=i-1;j>=0;j--){
                if(t2 > t1){
                    t1 = t2;
                }
                t2 += arr[j];
            }
            if(t2 > t1){
                t1 = t2;
            }
            tempAns += arr[i];
        }
    }
    return t1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        int op1 = getans1(arr, n);
        int op2 = getans2(arr, n);
        int op3 = getans3(arr, n);
        cout<<op1<<" "<<op2<<" "<<op3<<endl;
        if(op1 >= op2 && op1 >= op3){
            cout<<op1<<" NONE"<<endl;
        }
        else if(op2 >= op1 && op2 >= op3){
            cout<<op2<<" OPERATION1"<<endl;
        }
        else{
            cout<<op3<<" OPERATION2"<<endl;
        }
    }
}
