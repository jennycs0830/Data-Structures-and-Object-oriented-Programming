#include<iostream>
#include<vector>
#include<cstring>
#define MAX 100

using namespace std;

class Element{
    public:
        Element(int row = -1, int col = -1, int val = -1): row(row), col(col), val(val){}
        int row;
        int col;
        int val; 
};

class SparseMatrix{
    public:
        SparseMatrix(){}
        SparseMatrix(int row_num, int col_num, int r): row_num(row_num), col_num(col_num), r(r){}
        SparseMatrix(const SparseMatrix &other);
        SparseMatrix operator*(SparseMatrix &other);
        void set_M();
        void set_vec();
        void display();

        int row_num;
        int col_num;
        int r;
        int M[MAX][MAX];
        vector<Element> vec;
};

SparseMatrix::SparseMatrix(const SparseMatrix &other)
{
    // your implementation here
}

void SparseMatrix::set_M()
{
    memset(M, 0, sizeof(M));
    for (int i = 0; i < r; i++)
        M[vec[i].row][vec[i].col] = vec[i].val;
}

void SparseMatrix::set_vec()
{
    int count = 0;
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            if (M[i][j] != 0){
                Element element(i, j, M[i][j]);
                vec.push_back(element);
                count++;
            }
        }
    }
    
    r = count;
}

void SparseMatrix::display()
{
    for (int i = 0; i < row_num; i++){
        for (int j = 0; j < col_num; j++){
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

SparseMatrix SparseMatrix::operator*(SparseMatrix &other)
{
    SparseMatrix mul_SM(row_num, other.col_num, 0);

    if (other.col_num * r <= row_num * other.r){
        // your implementation here  
    }
    else{
        // your implementation here
    }

    mul_SM.set_vec();
    return mul_SM;
}

void set_input(SparseMatrix &SM)
{
    cin >> SM.row_num >> SM.col_num >> SM.r;
    for (int i = 0; i < SM.r; i++){
        int row, col, val;
        cin >> row >> col >> val;
        Element element(row, col, val);
        SM.vec.push_back(element);
    }
    SM.set_M();
}

int main()
{
    SparseMatrix SM1;
    SparseMatrix SM2;
    set_input(SM1);
    set_input(SM2);

    // multiplication
    SparseMatrix mul_SM = SM1 * SM2;
    cout << "multiplication result: " << endl;
    mul_SM.display();
    
    // copy 
    SparseMatrix copy_SM = SM1;
    cout << "copy result: " << endl;
    copy_SM.display();

    return 0;
}