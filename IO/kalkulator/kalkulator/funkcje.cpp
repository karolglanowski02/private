#include "funkcje.h"
#include <cmath>
#include <vector>
using namespace std;

double logarytmNaturalny(double x) {
    return log(x);
}

double srednia(double* data, int size) {
    double suma = 0.0;
    for (int i = 0; i < size; ++i) {
        suma += data[i];
    }
    return suma / size;
}

double odchylenieStandardowe(double* data, int size) {
    double sredniaWartosc = srednia(data, size);
    double sumaKwadratowRoznic = 0.0;

    for (int i = 0; i < size; ++i) {
        sumaKwadratowRoznic += pow(data[i] - sredniaWartosc, 2);
    }

    double wariancja = sumaKwadratowRoznic / size;
    double odchylenie = sqrt(wariancja);

    return odchylenie;
}

double wartoscExponentu(double x) {
    return exp(x);
}