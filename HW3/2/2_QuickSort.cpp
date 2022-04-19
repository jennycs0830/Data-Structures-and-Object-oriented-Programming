#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int find(int l, int r, int arr[]) {
    int pos[3] = {l, r - 1, (l + r) >> 1};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            if(arr[pos[j]] > arr[pos[j + 1]]) 
                swap(pos[j], pos[j + 1]);
        }
    }
    return pos[1];
}

int partition(int l, int r, int arr[]) {
    int pivot = find(l, r, arr);
    swap(arr[r - 1], arr[pivot]);
    int left = l, right = r - 2;
    while(left < right) {
        while(left < right && arr[left] < arr[r - 1]) left++;
        while(left < right && arr[right] >= arr[r - 1]) right--;
        swap(arr[left], arr[right]);
    }
    // if(arr[left] < arr[r - 1]) left++;
    // if(arr[right] >= arr[r - 1]) right--;
    swap(arr[r - 1], arr[left]);
    return left;
}   

void IterativeQuickSort(int arr[], int n) {
    queue<pair<int, int>> que;
    que.emplace(0, n);
    while(que.size()) {
        auto x = que.front(); que.pop();
        if(x.second - x.first <= 1) continue;
        int mid = partition(x.first, x.second, arr);
        que.emplace(x.first, mid); que.emplace(mid + 1, x.second);
    }
}

int arr[maxn];
int n;

bool chk(int arr[], int sz) {
    for(int i = 1; i < sz; i++) {
        if(arr[i - 1] > arr[i]) {
            printf("pos %d shaoji\n", i);
            return false;
        }
    }
    return true;
}


int main() {
    /*const int n = 3;
    int tmp[n], arr[n];
    for(int i = 0; i < n; i++) arr[i] = i;
    do {    
        memcpy(tmp, arr, sizeof(tmp));
        IterativeQuickSort(tmp, n);
        cout << chk(tmp, n) << '\n';
    } while(next_permutation(arr, arr + n));*/
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    /*for(int i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }*/
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    IterativeQuickSort(arr, n);
    // IterativeQuickSort(arr, n);
    /*for(int i = 0; i < n; i++) {
        printf("%d%c", arr[i], " \n"[i == n - 1]);
    }*/
    cout << "check:"<< chk(arr, n)<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}