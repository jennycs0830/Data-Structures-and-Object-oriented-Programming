#include <bits/stdc++.h>
using namespace std;

struct Node {
    int v;
    Node *l,*r; 
    Node(int x) : v(x), l(nullptr), r(nullptr) {}
};

Node *root = nullptr;

void insert(int x) {
    if(!root) {
        root = new Node(x);
    }
    else {
        Node *ptr = root;
        while(true) {
            if(x <= ptr -> v) {
                if(ptr -> l) {
                    ptr = ptr -> l;
                }
                else {
                    ptr -> l = new Node(x);
                    return;
                }
            }
            else {
                if(ptr -> r) {
                    ptr  = ptr -> r;
                }
                else {
                    ptr -> r = new Node(x);
                    return;
                }
            }
        }
    }
}

void dfs(Node *x) {
    if(!x) return;
    dfs(x -> l);
    dfs(x -> r);
    printf("%d ", x -> v);
}

void NCD(Node *x) {
    stack<pair<Node*, int>> stk;
    stk.push({x, 0});
    while(stk.size()) {
        auto &aqua = stk.top(); 
        // for(auto it : stk) {
        //     printf("%d ", it.second);
        // }
        // printf("\n");
        if(aqua.second == 0) {
            aqua.second++;
            if(aqua.first -> l) stk.push({aqua.first -> l, 0});
        }
        else if(aqua.second == 1) {
            aqua.second++;
            if(aqua.first -> r) stk.push({aqua.first -> r, 0});
        }
        else {
            printf("%d ", aqua.first -> v);
            stk.pop();
        }
    }
}

int main(){
    int n = 10;
    for(int i = 0; i < n; i++) {
        insert(rand());
    }   
    dfs(root); //recursive version
    printf("\n");
    NCD(root); //non-recursive version
    return 0;
}
