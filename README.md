include <iostream>
using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Copy constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols) {
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    // Assignment operator overloading
    Matrix& operator=(const Matrix &other) {
        if (this == &other) {
            return *this;
        }

        // Delete current data
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;

        // Copy data from other
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }

    void input() {
        std::cout << "Enter matrix elements:" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> data[i][j];
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << ' ';
            }
         cout <<endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns for Matrix 1: ";
    cin >> rows >> cols;

    Matrix mat1(rows, cols);
    mat1.input();

    Matrix mat2(2, 2);
    mat2.input();

    Matrix mat3 = mat1;

    cout << "Matrix 1:" << endl;
    mat1.print();
    cout << "Matrix 3 (Copy of Matrix 1):" << endl;
    mat3.print();

    mat2 = mat1;

    cout << "Matrix 2 (Assigned from Matrix 1):" <<endl;
    mat2.print();

    return 0;
}

