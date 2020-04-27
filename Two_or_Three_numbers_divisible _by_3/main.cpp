/*
    Given an array of n distinct numbers , write a program to find the count of groups of 2 or 3 integers that can be formed from
    the array such that the sum of the integers is divisible by 3
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int freq[3];
    memset(freq, 0, sizeof(freq));
    for(int i=0;i<n;i++){
        int index = arr[i]%3;
        freq[index]++;
    }
    int c = 0;
    for(int i=0;i<3;i++){
        if(i == 0){
            c += freq[i]*freq[i+1]*freq[i+2];
            if(freq[i] > 1){
                c += (freq[i]*(freq[i]-1))/2;
            }
        }
        else if(i == 1){
            c += freq[i]*freq[i+1];
        }
        if(freq[i] > 2){
                c += ((freq[i])*(freq[i]-1)*(freq[i]-2))/6;
        }
    }
    cout<<c;
}
