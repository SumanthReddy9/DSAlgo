#include<bits/stdc++.h>
using namespace std;

struct HeapData{
    int ele, idx, nextidx;
};

void heapify(HeapData heap[], int i, int k){
    int left = 2*i+1;
    int right = 2*i+2;
    int smallest = i;
    if(left < k && heap[left].ele < heap[smallest].ele){
        smallest = left;
    }
    if(right < k && heap[right].ele < heap[smallest].ele){
        smallest = right;
    }
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        heapify(heap, smallest, k);
    }
}

void heapit(HeapData heap[], int k){
    int heap_size = k;
    int i = (heap_size-1)/2;
    while(i>=0){
        heapify(heap, i, k);
        i--;
    }
}

void getArr(int arr[][100], int ans[], int n, int k){
    HeapData *heap = new HeapData[k];
    for(int i=0;i<k;i++){
        heap[i].ele = arr[i][0];
        heap[i].idx = i;
        heap[i].nextidx = 1;
    }
    heapit(heap, k);

    for(int i=0;i<n*k;i++){
        HeapData cur = heap[0];
        ans[i] = cur.ele;
        if(cur.nextidx < n){
            heap[0].ele = arr[cur.idx][cur.nextidx];
        }
        else{
            heap[0].ele = INT_MAX;
        }
        heap[0].idx = cur.idx;
        heap[0].nextidx = cur.nextidx + 1;
        heapify(heap, 0, k);
    }
    for(int i=0;i<n*k;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[100][100];
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int *ans = new int[n*k];
    getArr(arr, ans, n, k);
}
