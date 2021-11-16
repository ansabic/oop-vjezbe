#include<iostream>
#include <ostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

typedef struct matrix {
    int n;
    int m;
    float **field;

    matrix nullMatrix() {
        matrix tempMatrix;
        tempMatrix.n = 0;
        tempMatrix.m = 0;
        return tempMatrix;
    }

    matrix newMatrix() {
        cout << "Insert number of rows for a new matrix: \n";
        cin >> n;
        cout << "Insert number of columns for a new matrix: \n";
        cin >> m;
        field = new float *[n];
        for (int i = 0; i < n; i++) {
            field[i] = new float[m];
            for (int j = 0; j < m; j++) {
                cin >> field[i][j];
            }

        }
        return *this;
    }

    matrix randomRangeMatrix() {
        int lower, higher;
        cout << "Insert number of rows for a matrix: \n";
        cin >> n;
        cout << "Insert number of columns for a given matrix: \n";
        cin >> m;
        field = new float *[n];
        cout << "Insert lower number for range: \n";
        cin >> lower;
        cout << "Insert higher number for range: \n";
        cin >> higher;
        for (int i = 0; i < n; i++) {
            field[i] = new float[m];
            for (int j = 0; j < m; j++) {
                field[i][j] = lower + rand() % (higher - lower + 1);
            }
        }
        return *this;
    }

    matrix add(matrix b) {
        if (n == b.n && m == b.m) {
            matrix newMatrix;
            newMatrix.m = m;
            newMatrix.n = n;
            newMatrix.field = new float *[n];
            for (int i = 0; i < n; i++) {
                newMatrix.field[i] = new float[m];
                for (int j = 0; j < m; j++) {
                    newMatrix.field[i][j] = field[i][j] + b.field[i][j];
                }
            }
            return newMatrix;

        } else {
            cout << "Number of rows and columns must be the same! \n";
            return nullMatrix();
        }
    }

    matrix substract(matrix b) {
        if (n == b.n && m == b.m) {
            matrix newMatrix;
            newMatrix.m = m;
            newMatrix.n = n;
            newMatrix.field = new float *[n];
            for (int i = 0; i < n; i++) {
                newMatrix.field[i] = new float[m];
                for (int j = 0; j < m; j++) {
                    newMatrix.field[i][j] = field[i][j] - b.field[i][j];
                }
            }
            return newMatrix;

        } else {
            cout << "Number of rows and columns must be the same! \n";
            return nullMatrix();
        }
    }

    matrix multiply(matrix b) {
        if (m == b.n) {
            matrix newMatrix;
            newMatrix.n = n;
            newMatrix.m = b.m;
            newMatrix.field = new float *[n];
            for (int i = 0; i < n; i++) {
                newMatrix.field[i] = new float[b.m];
                for (int j = 0; j < b.m; j++) {
                    float sum = 0;
                    for (int k = 0; k < b.n; k++) {
                        sum = sum + field[i][k] * b.field[k][j];
                    }
                    newMatrix.field[i][j] = sum;
                }
            }
            return newMatrix;
        } else {
            cout << "Number of columns of the first matrix must be as same as number of rows of the second matrix! \n";
            return nullMatrix();
        }
    }

    matrix transpose() {
        matrix newMatrix;
        newMatrix.n = m;
        newMatrix.m = n;
        newMatrix.field = new float *[m];
        for (int i = 0; i < m; i++) {
            newMatrix.field[i] = new float[n];
            for (int j = 0; j < n; j++) {
                newMatrix.field[i][j] = field[j][i];
            }
        }
        return newMatrix;
    }

    int printMatrix() {
        cout << fixed;
        cout << setprecision(4);
        cout << right;
        if (n != 0 || m != 0) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << field[i][j] << " ";
                }
                cout << "\n";
            }
            return 1;
        } else {
            cout << "Wrong input! \n";
            return -1;
        }

    }


};

int main() {
    matrix newMatrix, randomMatrix, a, b;
    //Unos matrice i ispis
    cout << "Insert a test matrix: \n";
    newMatrix.newMatrix();
    newMatrix.printMatrix();
    //Unos dviju matrica
    cout << "\nInsert a first matrix: \n";
    a.newMatrix();
    cout << "\nInsert a second matrix: \n";
    b.newMatrix();
    //Njihovo zbrajanje
    cout << "\nFirst + Second result: \n";
    a.add(b).printMatrix();
    //Njhovo oduzimanje
    cout << "\nFirst - Second result: \n";
    a.substract(b).printMatrix();
    //Njihovo mnozenje
    cout << "\nFirst * Second result: \n";
    a.multiply(b).printMatrix();
    //Njihovo suprotno mnozenje ( nije komutativno !)
    cout << "\nSecond * First result: \n";
    b.multiply(a).printMatrix();
    //Transponiranje
    cout << "\nFirst transposed result: \n";
    a.transpose().printMatrix();
    return 0;
}
