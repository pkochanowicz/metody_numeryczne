#include <iostream>
#include <string>
#include <chrono>

#define N 4000

using namespace std;

class Macierz
{
public:
    int matryca[N][N];

    static void Mnozenie(int A[N][N], int B[N][N], int C [N][N] ) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
    void WyswietleniePoczatku()
    {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cout << "[" << matryca[i][j] << "]";
            }
            cout << endl;
        }
    }
    void WyswietlenieKonca()
    {
        cout << endl << "Dolny prawy rog" << endl;
        for (int i = N - 1; i > N - 5; i--) {
            for (int j = N - 1; j > N - 5; j--) {
                cout << "[" << matryca[i][j] << "]";
            }
            cout << endl;
        }
    }
    void Wypelnienie()
    {
        int a = 0;
        cout << "\nPodaj wartosc, ktora matryca zostanie wypelniona. \n";
        cin >> a;
        for (int i=0; i<N; i++){
             for(int j=0; j<N; j++){
              matryca[i][j] = 0;
            }
        }
        cout << endl;
    }
    Macierz(){
        int a = 0;
        for (int i=0; i<N; i++){
             for(int j=0; j<N; j++){
              matryca[i][j] = 0;
            }
        }
        cout << endl;
    }
};

int main(){

    cout << "Macierz A: ";
    Macierz A;
    A.Wypelnienie();

    cout << "Macierz B: ";
    Macierz B;
    B.Wypelnienie();

    Macierz C;
    auto start = std::chrono::high_resolution_clock::now();
    cout << "\nMnozenie macierzy: \n";
    Macierz::Mnozenie(A.matryca,B.matryca, C.matryca);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Czas obliczen: " << elapsed.count() << " s\n";

    C.WyswietleniePoczatku();
    C.WyswietlenieKonca();
    return 0;
}
