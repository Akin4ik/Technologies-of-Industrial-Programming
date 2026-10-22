//задание №3
//упрощаем выражение 9(7x - 6) - 18x = 45x - 54
#include <iostream>
using namespace std;
int main() {
    double x, y;

    //вводим значение x
    cout << "Введите x: ";
    cin >> x;

    y = 45 * x - 54;

    //вывод результата
    cout << "Результат: " << y << endl;
    return 0;
}