//задание 1 вариант 1 (циклами)
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){ //внешний цикл по строкам начиная с 0 пока i < N и увеличиваясь на 1
        for (int j = 0; j < N; j++){ // внутренний цикл по столбцам для каждой строки j пробегает 0 1 2 3 (все клетки квадрата)
            int sum = i + j; // сумма индексов текущ клетки
            int diag = N - 1;// вычесление номера побочной диагонали

            if (sum < diag) { //клетка выше побочной диаг = 0
                cout << 0;
            } else if (sum == diag){ // лежит на побочной диаг
                cout << 1;
            } else { // клетка ниже диагонали
                cout << 2;
            }
            if (j != N - 1) cout << " ";//ставим пробел после числа
        }
        cout << endl;
    }
    return 0;
}

//задание 1 вариант 2 (готовые диапозоны)
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int zeros = N - 1 - i;   //считаем длину первого диапозона (нули)

        for (int k = 0; k < zeros; k++) { //печатаем весь диапозон нулей
            cout << 0 << " ";
        }
        cout << 1; // печатаем единственную единицу (диагональ)
        for (int k = 0; k < i; k++) {
            cout << " " << 2; // печатаем диапозон двоек и ставим пробел перед каждой двойкой
        }

        cout << endl;
    }

    return 0;
}

//задание 2 вариант 1 (циклами)
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int W;
    cin >> W;

    int a[32][32]; //массив под поле
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            a[i][j] = 0; //двойной цикл заполняет все нулями

    
    for (int k = 0; k < W; k++) { //цикл k читает W пар координат
        int r, c;
        cin >> r >> c;
        r = r - 1;   //вычитаем 1 чтобы (1,1) стало (0,0)
        c = c - 1;
        a[r][c] = -1;//ставим -1 - метка здесь гриб
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { //основной цикл идет по всем клеткам
            if (a[i][j] == -1) {
                cout << '*';
            } else {
                int cnt = 0;
                for (int di = -1; di <= 1; di++) { //вложенный двойной цикл перебирает 8 соседей 
                    for (int dj = -1; dj <= 1; dj++) {
                        if (di == 0 && dj == 0) continue; // (0,0) пропускаем
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < N && nj >= 0 && nj < M) { //для каждого соседа проверяем границы  и если там -1 увеличиваем cnt
                            if (a[ni][nj] == -1) cnt++;
                        }
                    }
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}

//задание 2 вариант 2 (через прибавление к соседям)
#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int W;
    cin >> W;

    int a[32][32] = {0};//массив сразу обнуляется при объявлении

    for (int k = 0; k < W; k++) {
        int r, c;
        cin >> r >> c;
        r--; c--; //в индексы 0
        a[r][c] = -1; // метка гриба
    }

    for (int i = 0; i < N; i++) { //второй проход для каждого гриба прибавляем 1 ко всем соседям
        for (int j = 0; j < M; j++) {
            if (a[i][j] != -1) continue;  //ищем именно грибы
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) continue;
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < N && nj >= 0 && nj < M) { //если соесд не гриб увеличиваем его счетчик
                        if (a[ni][nj] != -1) a[ni][nj]++; 
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (a[i][j] == -1) cout << '*';
            else cout << a[i][j]; //не трогаем клетки-грибы иначе счетчик гриба испортится
        }
        cout << endl;
    }

    return 0;
}

//задание 3 вариант 1
#include <iostream>
#include <string>
using namespace std;

int main() {
    int X, N;
    cin >> X >> N;

    // переводим число X в строку 
    string s = to_string(X);

    // нужно применить преобразование (N-1) раз,
    // потому что N=1 — это уже сам X
    for (int step = 1; step < N; step++) {
        string next = "";      // сюда собираем новую строку
        int i = 0;             // индекс, с которого читаем текущую строку

        while (i < (int)s.size()) {
            char c = s[i];     // какой символ в текущей группе
            int cnt = 0;       // сколько раз он подряд идёт

            // пока символы совпадают с c — считаем их
            while (i < (int)s.size() && s[i] == c) {
                cnt++;
                i++;
            }

            // дописываем "количество" и "сам символ"
            next += to_string(cnt);   // сколько
            next += c;                // чего
        }

        s = next;   // новая строка становится текущей
    }

    cout << s << endl;
    return 0;
}

//задание 3 вариант 2 (вспомогательная функция)
#include <iostream>
#include <string>
using namespace std;

// одно преобразование "посмотри и скажи"
string lookAndSay(string s) {
    string result = "";
    int i = 0;

    while (i < (int)s.size()) {
        char c = s[i];
        int cnt = 0;
        while (i < (int)s.size() && s[i] == c) {
            cnt++;
            i++;
        }
        result += to_string(cnt);   // сколько
        result += c;                // чего
    }

    return result;
}

int main() {
    int X, N;
    cin >> X >> N;

    string s = to_string(X);

    // применяем преобразование N-1 раз
    for (int step = 1; step < N; step++) {
        s = lookAndSay(s);
    }

    cout << s << endl;
    return 0;
}