#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct Node {
    Node *l, *r;
    T val; int hei;
    Node(T x) : val(x), hei(0),
        l(nullptr), r(nullptr) {} 
    ~Node() {delete l; delete r;}
};

template<typename T>
struct AVL {
private:
    Node<T> *root;
    int height(Node<T> *x) {
        return x ? x -> hei : -1;
    }
    int BF(Node<T> *x) {
        return x ? height(x -> l) - height(x -> r) : 0;
    }
    void upd(Node<T> *x) {
        x -> hei = max(height(x -> l), height(x -> r)) + 1;
    }
    Node<T> *getMax(Node<T> *x) {
        while(x -> r) {
            x = x -> r;
        }
        return x;
    }
    Node<T> *getMin(Node<T> *x) {
        while(x -> l) {
            x = x -> l;
        }
        return x;
    }
    Node<T> *R(Node<T> *x) {
        Node<T> *l = x -> l;
        Node<T> *lr = l -> r;
        l -> r = x;
        x -> l = lr;
        upd(x); upd(l);
        return l;
    }
    Node<T> *L(Node<T> *x) {
        Node<T> *r = x -> r;
        Node<T> *rl = r -> l;
        r -> l = x;
        x -> r = rl;
        upd(x); upd(r);
        return r;
    }
    Node<T> *Balance(Node<T> *x) {
        int bf = BF(x);
        if(bf > 1) { // left is heavier
            if(x -> l && x -> l -> l) { // LL
                return R(x);
            }
            else { // LR
                x -> l = L(x -> l);
                return R(x);
            }
        }
        else if(bf < -1) {
            if(x -> r && x -> r -> r) { // RR
                return L(x);
            }
            else { // RL
                x -> r = R(x -> r);
                return L(x);
            }
        }
        return x;
    }
    Node<T> *Insert(T v, Node<T> *x) {
        if(!x) return new Node<T>(v);
        if(v <= x -> val) x -> l = Insert(v, x -> l);
        else x -> r = Insert(v, x -> r);
        upd(x); x = Balance(x);
        return x;
    }
    Node<T> *Erase(T v, Node<T> *x) {
        if(!x) return nullptr;
        if(v < x -> val) x -> l = Erase(v, x -> l);
        else if(v > x -> val) x -> r = Erase(v, x -> r);
        else {
            if(!height(x)) {// leaf
                return nullptr;
            }
            else if(!x -> l) return x -> r;
            else if(!x -> r) return x -> l;
            else {
                Node<T> *tmp = getMax(x -> l);
                swap(tmp -> val, x -> val);
                x -> l = Erase(v, x -> l);
            }
        }
        upd(x);
        return Balance(x);
    }
    Node<T> *Find(Node<T> *x, T v) {
        if(!x) return nullptr;
        if(v < x -> val) return Find(x -> l, v);
        else if(v > x -> val) return Find(x -> r, v);
        else return x;
    }
    void inOrder(Node<T> *x) {
        if(!x) return;
        inOrder(x -> l);
        cout << x -> val << " ";
        inOrder(x -> r);
    }
public:
    AVL() : root(nullptr) {}
    ~AVL() {delete root;}
    void insert(T x) {
        root = Insert(x, root);
    }
    void erase(T x) {
        root = Erase(x, root);
    }
    void All() {
        inOrder(root); cout << "\n";
    }
    bool find(T x) {
        return Find(root, x) != nullptr;
    }
};

int main() {
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    int n, m;
    string str;
    AVL<string> dic;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> str; dic.insert(str);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> str;
        if(dic.find(str)) {
            cout << "yes\n";
        }
        else {
            dic.insert(str);
            cout << "no\n";
        }
    }
    return 0;
}