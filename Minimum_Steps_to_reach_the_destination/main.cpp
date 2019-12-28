#include<bits/stdc++.h>
using namespace std;

int steps(int source, int step, int dest){
    if(source == dest){
        return step;
    }
    if(abs(source) > abs(dest)){
        return INT_MAX;
    }
    int pos = steps(source + step + 1, step + 1, dest);
    int neg = steps(source - step - 1, step + 1, dest);
    return min(pos, neg);

}

int reachTargetOP(int n){
    n = abs(n);
    int steps = 0, sum = 0;
    while(sum < n || (sum - n)%2 != 0){
        steps++;
        sum += steps;
    }
    return steps;
}

int main(){
    int n;
    cin>>n;
    //cout<<steps(0, 0, n)<<endl;
    cout<<reachTargetOP(n);
}
