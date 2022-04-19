#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

void merge(int l, int m, int r, int arr[]) {
    static int tmp[maxn];
    int i, j, idx = l;
    for(i = l, j = m; i < m; i++) {
        while(j < r && arr[j] < arr[i]) {
            tmp[idx++] = arr[j++];
        }
        tmp[idx++] = arr[i];
    }
    while(j < r) tmp[idx++] = arr[j++];
    for(idx = l; idx < r; idx++) {
        arr[idx] = tmp[idx];
    }
}

void NaturalMergeSort(int arr[], int n) {
    static int cnt, tmp[maxn];
    arr[0] = 0; cnt = 1; 
    for(int i = 1; i < n; i++) {
        if(arr[i - 1] > arr[i]) tmp[cnt++] = i;
    }
    tmp[cnt++] = n;
    while(cnt > 2) {
        int sz = cnt, idx = 0;
        for(int i = 0; i < cnt; i += 2) {
            tmp[idx++] = tmp[i];
            if(i + 2 < cnt) {
                merge(tmp[i], tmp[i + 1], tmp[i + 2], arr);
            }
        }
        if(cnt % 2 == 0) tmp[idx++] = n;
        cnt = idx;
    }
}

int arr[maxn];
int n;

bool chk(int arr[], int sz) {
    for(int i = 1; i < sz; i++) {
        if(arr[i - 1] > arr[i]) return false;
    }
    return true;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    /*for(int i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }*/
    NaturalMergeSort(arr, n);
    /*for(int i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }*/
    cout << chk(arr, n);
    return 0;
}