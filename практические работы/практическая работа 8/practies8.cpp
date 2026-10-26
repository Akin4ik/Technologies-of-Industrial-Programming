//задание 1 (рекурсивный способ)

#include <iostream>
using namespace std;

// Быстрое возведение в степень: на каждом шаге степень уменьшается вдвое
long long Recursive(long long base, int exp) {
    // любое число в 0 степени = 1
    if (exp == 0) {
        return 1;
    }

    // чётная степень: считаем половину и возводим её в квадрат
    if (exp % 2 == 0) {
        long long half = Recursive(base, exp / 2);
        return half * half;
    }

    // нечётная: выносим один base и сводим к чётной степени
    return base * Recursive(base, exp - 1);
}

int main() {
    cout << Recursive(10, 12) << endl; // 1000000000000
    return 0;
}

//задание 1 (через цикл)

#include <iostream>
using namespace std;

// Быстрое возведение в степень без рекурсии: идём по битам степени
long long powerIterative(long long base, int exp) {
    long long result = 1;  // здесь копим ответ

    while (exp > 0) {
        // если младший бит степени = 1, домножаем результат на base
        if (exp & 1) {
            result *= base;
        }

        base *= base;  // base, base^2, base^4, base^8 
        exp >>= 1;     // сдвигаем степень вправо (делим на 2)
    }

    return result;
}

int main() {
    cout << powerIterative(10, 12) << endl; // 1000000000000
    cout << powerIterative(2, 10) << endl;  // 1024
    cout << powerIterative(5, 0) << endl;   // 1
    return 0;
}

//задание 2

#include <iostream>

// Рекурсивная функция поиска НОД по алгоритму Евклида.
int gcd(int a, int b) {
    // база рекурсии: если b == 0, значит a и есть наибольший общий делитель
    if (b == 0) {
        return a;
    }
    // иначе сдвигаемся: остаток от деления становится новым вторым числом
    return gcd(b, a % b);
}

int main() {
    int a, b;
    std::cin >> a >> b;          // читаем расходы Паши и Егора
    std::cout << gcd(a, b) << std::endl;  // печатаем сумму сброса (НОД)
    return 0;
}

//задание 3

#include <iostream>
using namespace std;

// Функция перекладывает n ингредиентов с салфетки from на салфетку to,
// используя салфетку helper как промежуточную.
void hanoi(int n, int from, int to, int helper) {
    // Если ингредиентов нет — делать нечего, выходим
    if (n == 0) {
        return;
    }

    // 1.перекладываем все ингредиенты кроме самого большого
    // с исходной салфетки на промежуточную
    hanoi(n - 1, from, helper, to);

    // 2.самый большой ингредиент переносим на нужную салфетку
    cout << "Ingredient " << n << " move from " << from << " to " << to << endl;

    // 3.теперь перекладываем оставшиеся ингредиенты
    // с промежуточной салфетки на нужную
    hanoi(n - 1, helper, to, from);
}

int main() {
    int n;
    cin >> n;  // читаем количество ингредиентов

    // Перекладываем все n ингредиентов с салфетки 1 на салфетку 3,
    // а салфетка 2 будет промежуточной
    hanoi(n, 1, 3, 2);

    return 0;
}
