#include "funkcje.h"
#include "funkcje.cpp"
using namespace std;

int main() {
    double x = 2.0;
    double data[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
    int dataSize = sizeof(data) / sizeof(data[0]);

    // Użycie funkcji
    double wynikLog = logarytmNaturalny(x);
    double wynikOdchylenia = odchylenieStandardowe(data, dataSize);
    double wynikExponentu = wartoscExponentu(x);

    // Wyświetlenie wyników
    cout << "Logarytm naturalny: " << wynikLog << endl;
    cout << "Odchylenie standardowe: " << wynikOdchylenia << endl;
    cout << "Wartosc exponentu: " << wynikExponentu << endl;

    return 0;
}