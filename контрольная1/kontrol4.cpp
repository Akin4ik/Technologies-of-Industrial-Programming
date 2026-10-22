#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    char s;
    
    cout << "Введите a b c: ";
    cin >> a >> b >> c;

    cout << "Введите символ: ";
    cin >> s;

    if (s == 'A') { //символ_1 вывод имени и фамилии студента на английском 
        cout << "Akinina Daria" << endl;
    }
    else if (s == 't') { //символ_2 решение квадратного уравнения
        if (a == 0 && b == 0 && c == 0) {
            cout << "x - любое число" << endl;
        }
        else if ( a== 0 && b == 0) {
            cout << "корней нет" << endl;
        }
        else if ( a == 0) {
            cout << "x = " << -c / b << endl;
        }
        else {
            double d = b * b - 4 * a * c;
            if (d < 0) {
                cout << "корней нет" << endl;
            }
            else if (d == 0) {
                cout << "x =  " << -b / (2 * a) << endl;
            }
            else {
                double x1 = (-b + sqrt(d)) / (2 * a);
                double x2 = (-b - sqrt(d)) / (2 * a);
                cout << "x1 = " << x1 << endl;
                cout << "x2 = " << x2 << endl;
            }
        }
    }
    else if ( s == 'c') { //символ_3 запрос на возрост и вывод про алкоголь
        int age;
        cout << "Введите возраст: ";
        cin >> age;
        if (age >= 18) {
            cout << "Можно покупать алкоголь" << endl;
        
        }
        else {
            cout << "Нельзя покупать алкоголь" << endl;
        }
    }
    else {
        cout << "Неверный символ" << endl;
    }
    return 0;
}