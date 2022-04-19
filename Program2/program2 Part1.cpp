#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define ElemType string
#define INF 0x3f3f3f3f
typedef char** HuffCode;

int N;

typedef struct huffNode {
    double weight;                 /*權重*/
    int lchild, rchild, parent;    /*左右子節點和父節點*/
} HTNode, * HuffTree;

//找出剩下的節點中全職最小的兩個節點 分别用s1和s2保存
void select(const HuffTree& HT, int n, int& s1, int& s2);

//翻轉字串
void reverseChars(char* chs, int len);

//HT:赫夫曼樹，HC:赫夫曼編碼，w:赫夫曼編碼的權值，n:赫夫曼樹節點的個數
void createHT(HuffTree& HT, HuffCode& HC, double* w, int n);

//輸出赫夫曼編碼
void showHuffCode(ElemType data[], HuffCode HC);

//求wpl
int getWPL(HuffTree& HT, int idx, int depth);

int main() {
    N = 26;  //共26字母
    //第0個保留不用
    ElemType data[N] = {"0", "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
    //第0個保留不用
    double w[N] = { 0,7,2,2,3,11,2,2,6,6,1,1,4,3,7,9,2,1,6,6,8,4,1,2,1,2,1 };

    HuffTree HT;
    HuffCode HC;

    createHT(HT, HC, w, N);

    showHuffCode(data, HC);

    printf("\n");

    cout << "The weighted path length of the HuffmanTree is " << getWPL(HT, N * 2 - 1, 0) << "\n\n";

    system("pause");
    return 0;
}

//找出樹中權值最小的兩個節點 分別存入s1和s2保存
void select(const HuffTree& HT, int n, int& s1, int& s2) {
    s1 = s2 = 0;
    double min1 = INF;     //最小值
    double min2 = INF;     //倒數第二小值

    for (int i = 1; i <= n; i++) {
        //篩選出沒有父節點的最小值和倒數第二小的值
        if (HT[i].parent == 0) {
            //如果比最小值小
            if (HT[i].weight < min1) {
                //更新倒數第二小
                min2 = min1;
                s2 = s1;
                //更新最小值
                min1 = HT[i].weight;
                s1 = i;
            }
            //大於等於最小值 且小於倒數第二小值
            else if ((HT[i].weight >= min1) && (HT[i].weight < min2)) {
                //只更新倒數第二小
                min2 = HT[i].weight;
                s2 = i;
            }
        }
    }
}

void reverseChars(char* chs, int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = chs[i];
        chs[i] = chs[len - 1 - i];
        chs[len - 1 - i] = temp;
    }
}

void createHT(HuffTree& HT, HuffCode& HC, double* w, int n) {
    int s1, s2, m = 2 * n - 1;                  //m: 由n個節點組成的赫夫曼會有2n-1個節點
    char* code;                                 //暂存
    HT = new HTNode[m + 1];                       //第0個不使用

    for (int i = 1; i <= n; i++) {
        //處理初始化前的第0個節點
        HT[i] = { w[i], 0, 0, 0 };
    }

    for (int i = n + 1; i <= m; i++) {
        //處理初始化後n-1個節點 (找出最小兩節點的父節點)
        HT[i] = { 0, 0, 0, 0 };
    }

    //赫夫曼樹建構
    for (int i = n + 1; i <= m; i++) {
        //找出前i-1個節點中權值最小的節點
        select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }

    //赫夫曼編碼
    HC = new char* [n];
    /*這裡以下我真的不知道自己在幹嘛*/
    code = new char[n];


    for (int i = 1; i <= n; i++) {
        //k: 現在的節點，用0和1表示, f: k的父節點, j: 記錄編碼的位置
        int k = i, f = HT[k].parent, j = 0;
        //從葉子到根走一遍
        while (f != 0) {
            if (HT[f].lchild == k) {
                code[j] = '0';
            }
            else if (HT[f].rchild == k) {
                code[j] = '1';
            }
            k = HT[k].parent;
            f = HT[k].parent;
            j++;
        }
        //標記尾巴位置
        code[j] = '\0';
        reverseChars(code, j);
        //站存的編碼移到HC
        HC[i] = new char[n];
        strcpy(HC[i], code);
    }
}

void showHuffCode(ElemType data[], HuffCode HC) {
    cout << "code list{" << endl;
    for (int i = 1; i <= N; i++) {
        cout << data[i] << ": " << HC[i] << "\n";
    }
    cout << "}" << endl;
}

int getWPL(HuffTree& HT, int idx, int depth) {
    //執行dfs直到遇到葉子
    if (HT[idx].lchild == 0 && HT[idx].rchild == 0) {
        return HT[idx].weight * depth;
    }
    return getWPL(HT, HT[idx].lchild, depth + 1) + getWPL(HT, HT[idx].rchild, depth + 1);
}
