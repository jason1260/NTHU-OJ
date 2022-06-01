#ifndef function_h
#define function_h
#include <iostream>

using namespace std;

class Matrix
{
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, Matrix &);
public:
    Matrix(int s = 5);
    Matrix(const Matrix &);// copy constructor

    ~Matrix() {
        delete [] matrix;
        delete [] buf;
    }

    Matrix &operator=(const Matrix &a);

    Matrix &clockwise90(){
        int tmp[size*size];
        int num = 0;
        for(int i=0;i<this->size;i++){
            for(int j = 0;j<this->size;j++){
                tmp[num] = this->matrix[i][j];
                num++;
            }
        }
        num=0;
        for(int i=size-1; i>=0; i--){
            for(int j=0; j<size; j++){
                matrix[j][i] = tmp[num];
                num++;
            }
        }
        return *this;
    }
private:
    int **matrix;
    int *buf;   // 2D matrix stored in 1D raster scan order
    int size;
}; //end class Matrix

ostream &operator<<(ostream &os, const Matrix &m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            (j != m.size - 1) ? os << m.matrix[i][j] << ' ' : os << m.matrix[i][j] << '\n';
        }
    }
    return os;
}

istream &operator>>(std::istream &is, Matrix &m) {
    for (int i = 0; i < m.size; i++) {
        for (int j = 0; j < m.size; j++) {
            int tmp;
            is >> tmp;
            m.matrix[i][j] = tmp;
            m.buf[i * m.size + j] = tmp;
        }
    }
    //cout << "matrix made!\n";
}

Matrix::Matrix(int s) {
    size = s;
    matrix = new int *[s];
    for (int i = 0; i < s; i++) *(matrix + i) = new int [s];
    buf = new int [s * s];
}

Matrix &Matrix::operator= (const Matrix &a) {

}

#endif /* function_h */
