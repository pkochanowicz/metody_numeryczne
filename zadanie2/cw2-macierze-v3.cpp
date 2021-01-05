#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

void MatrixMultiplication(int col, int row, auto sourceA, auto sourceB, auto output) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < col; k++) {
                output[i][j] += sourceA[i][k] * sourceB[k][j];
            }
        }
    }
}

void MatrixSum(int col, int row, auto sourceA, auto sourceB, auto output) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < col; k++) {
                output[i][j] = sourceA[i][k] + sourceB[i][j];
            }
        }
    }
}

void MatrixPartitioning(int newCols, auto source, auto output) {       
    for (int i = 0; i < newCols; i++) {
        for (int j = 0; j < newCols; j++) {
            output[0][i][j] = source[i][j];
            output[1][i][j] = source[i][j+newCols];
            output[2][i][j] = source[i+newCols][j];
            output[3][i][j] = source[i + newCols][j + newCols];
        }
    }
}

void MatrixSetValues(float value, int col, int row, auto matrix) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            matrix[i][j] = value;
        }
    }
}

void MatrixOutput(int col, int row, auto matrix) {
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void MatrixOutputCell(int col, int row, auto matrix){
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < row; j++) {
            cout << "[" << i << "][" << j << "]: " << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    //Vars
    const int col = 4, row = 4, timeCounter = 1, partNum = 4, newCol = sqrt(col * col / partNum);
    auto a = new float[col][row];
    auto b = new float[col][row];
    auto c = new float[col][row];
    auto bigA = new float[partNum][newCol][newCol];
    auto bigB = new float[partNum][newCol][newCol];
    auto bigC = new float[partNum][newCol][newCol];
    auto bigTemp = new float[2][newCol][newCol];
    int i, j, initValue;

    //Input
    cout << endl << "Podaj elementy macierzy A" << endl;
    cin >> initValue;
    MatrixSetValues(initValue, col, row, a);

    cout << endl << "Podaj elementy macierzy B" << endl;
    cin >> initValue;
    MatrixSetValues(initValue, col, row, b);
    
    
    MatrixPartitioning(newCol, a, bigA);
    delete[] a;

    MatrixPartitioning(newCol, b, bigB);
    delete[] b;
    

    //Time test
    std::chrono::duration<double> elapsed;
    for (i = 0; i < timeCounter; i++) {

        auto start = std::chrono::high_resolution_clock::now(); //time calc start

        MatrixSetValues(0, newCol, newCol, bigTemp[0]);
        MatrixSetValues(0, newCol, newCol, bigTemp[1]);
        MatrixMultiplication(newCol, newCol, bigA[0], bigB[0], bigTemp[0]);
        MatrixMultiplication(newCol, newCol, bigA[1], bigB[2], bigTemp[1]);
        MatrixSum(newCol, newCol, bigTemp[0], bigTemp[1], bigC[0]);

        MatrixSetValues(0, newCol, newCol, bigTemp[0]);
        MatrixSetValues(0, newCol, newCol, bigTemp[1]);
        MatrixMultiplication(newCol, newCol, bigA[0], bigB[1], bigTemp[0]);
        MatrixMultiplication(newCol, newCol, bigA[1], bigB[3], bigTemp[1]);
        MatrixSum(newCol, newCol, bigTemp[0], bigTemp[1], bigC[1]);

        MatrixSetValues(0, newCol, newCol, bigTemp[0]);
        MatrixSetValues(0, newCol, newCol, bigTemp[1]);
        MatrixMultiplication(newCol, newCol, bigA[2], bigB[0], bigTemp[0]);
        MatrixMultiplication(newCol, newCol, bigA[3], bigB[2], bigTemp[1]);
        MatrixSum(newCol, newCol, bigTemp[0], bigTemp[1], bigC[2]);

        MatrixSetValues(0, newCol, newCol, bigTemp[0]);
        MatrixSetValues(0, newCol, newCol, bigTemp[1]);
        MatrixMultiplication(newCol, newCol, bigA[2], bigB[1], bigTemp[0]);
        MatrixMultiplication(newCol, newCol, bigA[3], bigB[3], bigTemp[1]);
        MatrixSum(newCol, newCol, bigTemp[0], bigTemp[1], bigC[3]);

        auto finish = std::chrono::high_resolution_clock::now();
        elapsed += finish - start;
    }

    delete[] bigA;
    delete[] bigB;
    delete[] bigTemp;

    for (i = 0; i < newCol; i++) {
        for (j = 0; j < newCol; j++) {
            c[i][j] = bigC[0][i][j];
            c[i][j+newCol] = bigC[1][i][j];
            c[i+newCol][j] = bigC[2][i][j];
            c[i+newCol][j+newCol] = bigC[3][i][j];
        }
    }

    delete[] bigC;

    //cout << endl << "Macierz C:" << endl;
    //MatrixOutput(col, row, c);

    //Podglad rogow macierzy
    cout << endl << "Elementy macierzy pomnozonej:";
    cout << endl << "Gorny lewy rog" << endl;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            cout << "[" << c[i][j] << "]";
        }
        cout << endl;
    }
    cout << endl << "Dolny prawy rog" << endl;
    for (i = row - 1; i > row - 5; i--) {
        for (j = col - 1; j > col - 5; j--) {
            cout << "[" << c[i][j] << "]";
        }
        cout << endl;
    }

    std::cout << endl << "Czas obliczen: " << elapsed.count() / timeCounter << " s\n";

    delete[] c;

    return 0;

}