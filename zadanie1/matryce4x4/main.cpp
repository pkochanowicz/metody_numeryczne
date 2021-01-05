#include <iostream>
#include <string>
#include <chrono>

using namespace std;

class Macierz
{
public:
    int matryca[16][16];
    Macierz();
    Mnozenie(int[16][16]);
    Wyswietlanie();
};


Macierz::Macierz()
{
    int a = 0;
    cout << "\nPodaj wartosc, ktora matryca zostanie wypelniona.";
    cin >> a;
    for (int i=0; i<16; i++){
         for(int j=0; j<16; j++){
          matryca[i][j] = a;
        }
    }
    cout << endl;
}

Macierz::Mnozenie(int B[16][16]){
        int temp[16][16], num;

        for (int i=0; i<16; i++){
            for(int j=0; j<16; j++){
                num = 0;
                for(int k=0; k<16; k++){
                  num += matryca[i][k]*B[k][j];
        }
            temp[i][j]=num;
            cout << num << " ";
        }
             cout << endl;
        }
    }

Macierz::Wyswietlanie(){
        for(int j=0; j<16; j++){
            for (int i=0; i<16; i++){
                cout << matryca[i][j] << " ";
            }
                cout << endl;
        }
    }

int main(){


    cout << "Macierz A: ";
    Macierz A;
    A.Wyswietlanie();

    cout << "Macierz B: ";
    Macierz B;
    B.Wyswietlanie();



    cout << "\nMnozenie macierzy: \n";

    auto start = std::chrono::high_resolution_clock::now();
    A.Mnozenie(B.matryca);
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Czas obliczen: " << elapsed.count() << " s\n";

    return 0;
}
