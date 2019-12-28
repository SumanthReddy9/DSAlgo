#include<bits/stdc++.h>
using namespace std;

void M(char str[], int l, int m, int h){
    int n1 = m-l+1;
    int n2 = h-m;
    char L[n1], R[n2];
    for(int i=0;i<n1;i++)
        L[i] = str[l+i];
    for(int j=0;j<n2;j++)
        R[j] = str[m+j+1];
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(L[i] < R[i]){
            str[k] = L[i];
            i++;
        }
        else{
            str[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        str[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        str[k] = R[j];
        j++;
        k++;
    }
}

void Msort(char str[], int l, int h){
    if(l<h){
        int m = (l+h)/2;
        Msort(str, l, m);
        Msort(str, m+1,h);
        M(str, l, m, h);
    }
}

void getNext(char str[], int l){
    int i=0, j=0;
    for(i=l-1;i>0;i--){
        if(str[i] > str[i-1]){
            break;
        }
    }
    int sm = i, num = str[i-1];
    for(j=i+1;j<l;j++){
        if(str[j] > num && str[j] < str[sm]){
            sm = j;
        }
    }
    swap(str[i-1], str[sm]);
    Msort(str, i, l-1);
    cout<<str;
}

int main(){
    char str[] = "123654";
    getNext(str, 6);
}
