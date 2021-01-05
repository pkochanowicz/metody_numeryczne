#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Macierz
{
public:
    int matryca[16][16];

    static void Mnozenie(int A[16][16], int B[16][16]){
        int temp[16][16], num;

        for (int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                num = 0;
                for(int k=0; k<16; k++){
                  num += A[i][k]*B[k][j];
        }
            temp[i][j]=num;
            cout << num << " ";
        }
             cout << endl;
        }
    }
    void WyswietleniePoczatku()
    {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 4; j++) {
                cout << "[" << c[i][j] << "]";
            }
            cout << endl;
        }
    }
    void WyswietlenieKonca()
    {
        cout << endl << "Dolny prawy rog" << endl;
        for (i = row - 1; i > row - 5; i--) {
            for (j = col - 1; j > col - 5; j--) {
                cout << "[" << c[i][j] << "]";
            }
            cout << endl;
    }

    Macierz(){
        int a = 0;
        cout << "\nPodaj wartosc, ktora matryca zostanie wypelniona. \n";
        cin >> a;
        for (int i=0; i<16; i++){
             for(int j=0; j<16; j++){
              matryca[i][j] = a;
            }
        }
        cout << endl;
    }
};

int main(){

    cout << "Macierz A: ";
    Macierz A;
    Macierz::Wyswietlanie(A.matryca);

    cout << "Macierz B: ";
    Macierz B;
    Macierz::Wyswietlanie(B.matryca);

    auto start = std::chrono::high_resolution_clock::now();
    cout << "\nMnozenie macierzy: \n";
    Macierz::Mnozenie(A.matryca,B.matryca);
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Czas obliczen: " << elapsed.count() << " s\n";
    return 0;
}
