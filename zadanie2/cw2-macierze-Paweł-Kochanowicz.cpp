#include <iostream>
#include <string>
#include <chrono>

//N should be passed in a matrix constructor. no need to make it a global const
//#define N 4000 //this will take forever...
#define N 1000 // this takes  about 20 sek already...

using namespace std;

//ALWAYS use English, for god's sake
class Macierz
{
public:
	int** matryca;

	static void Mnozenie(int** A, int** B, int** C) {
		//this naive approach will not work for a large matrix, its too slow
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
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				matryca[i][j] = a;
			}
		}
		cout << endl;
	}
	Macierz() {
		matryca = new int*[N];
		for (int i = 0; i < N; ++i)
			matryca[i] = new int[N];

		int a = 0;
		for (int i = 0; i<N; i++) {
			for (int j = 0; j<N; j++) {
				matryca[i][j] = 0;
			}
		}
		cout << endl;
	}
};

int main() {

	cout << "Macierz A: ";
	Macierz A;
	A.Wypelnienie();

	cout << "Macierz B: ";
	Macierz B;
	B.Wypelnienie();

	Macierz C;
	auto start = std::chrono::high_resolution_clock::now();
	cout << "\nMnozenie macierzy: \n";
	
	// below code is is ugly. 
	// multiplication should be an operator of the matrix class. so you should be able to write C = A * B
	Macierz::Mnozenie(A.matryca, B.matryca, C.matryca);	
	auto finish = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = finish - start;
	std::cout << "Czas obliczen: " << elapsed.count() << " s\n";

	C.WyswietleniePoczatku();
	C.WyswietlenieKonca();
	
	//comment this out if you do not want ppl to see the output
	system("pause");

	return 0;
}
