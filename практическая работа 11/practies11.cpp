//задание 1
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    int N, M;
    cout << "Введите количество строк (N) и столбцов (M): ";
    cin >> N >> M;
    
    int a[100][100]; // карта с баллами
    int dp[100][100]; // здесь будем хранить максимальные суммы
    char from[100][100]; // откуда пришли: 'U' - сверху, 'L' - слева
    
    cout << "Введите баллы в клетках:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    
    // Стартовая клетка
    dp[0][0] = a[0][0];
    
    // Заполняем первую строку (можно идти только слева)
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + a[0][j];
        from[0][j] = 'L';
    }
    
    // Заполняем первый столбец (можно идти только сверху)
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
        from[i][0] = 'U';
    }
    
    // Заполняем остальную таблицу
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            // Сравниваем, откуда прийти выгоднее
            if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                from[i][j] = 'U'; // пришли сверху
            } else {
                dp[i][j] = dp[i][j - 1] + a[i][j];
                from[i][j] = 'L'; // пришли слева
            }
        }
    }
    
    cout << "Максимальная сумма баллов: " << dp[N - 1][M - 1] << endl;
    
    // Восстанавливаем маршрут с конца в начало
    int path_i[200], path_j[200];
    int len = 0;
    int i = N - 1;
    int j = M - 1;
    
    while (true) {
        path_i[len] = i;
        path_j[len] = j;
        len++;
        
        if (i == 0 && j == 0) {
            break; // дошли до старта
        }
        
        if (from[i][j] == 'U') {
            i = i - 1;
        } else {
            j = j - 1;
        }
    }
    
    cout << "Путь (координаты ячеек):" << endl;
    // Выводим в обратном порядке (от старта к финишу)
    for (int k = len - 1; k >= 0; k--) {
        cout << path_i[k] << " " << path_j[k] << endl;
    }
    
    return 0;
}

//задание 2
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    int N, D;
    cout << "Введите количество пирожков (N) и дней (D): ";
    cin >> N >> D;
    
    int kal[1000];
    cout << "Введите калорийность каждого пирожка:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> kal[i];
    }
    
    // Сортировка массива вручную (пузырьком), чтобы не подключать алгоритмы
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (kal[j] > kal[j + 1]) {
                int temp = kal[j];
                kal[j] = kal[j + 1];
                kal[j + 1] = temp;
            }
        }
    }
    
    // Бинарный поиск по ответу
    int left = 0;            // минимально возможная разница
    int right = kal[N - 1] - kal[0]; // максимально возможная разница
    
    int answer = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        
        // Проверяем: можно ли разбить на D дней с разницей не больше mid?
        int days_used = 1; // первый день уже начали
        int min_v = kal[0]; // минимум в текущем дне
        
        for (int i = 1; i < N; i++) {
            // Если разница превышает mid, начинаем новый день
            if (kal[i] - min_v > mid) {
                days_used++;
                min_v = kal[i]; // новый день начинается с этого пирожка
            }
        }
        
        if (days_used <= D) {
            // Успели разложить за D дней или меньше
            answer = mid;
            right = mid - 1; // пробуем найти разницу поменьше
        } else {
            left = mid + 1; // не уложились, нужно увеличить допустимую разницу
        }
    }
    
    cout << "Минимальная возможная разница: " << answer << endl;
    
    return 0;
}

//задание 3
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    int N, K, L;
    cout << "Введите количество растений (N), размер букета (K) и лимит одинаковых (L): ";
    cin >> N >> K >> L;
    
    int cost[100]; // стоимость каждого растения
    cout << "Введите стоимость каждого растения:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    
    // Сортировка по убыванию (пузырьком, чтобы было просто)
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (cost[j] < cost[j + 1]) {
                int temp = cost[j];
                cost[j] = cost[j + 1];
                cost[j + 1] = temp;
            }
        }
    }
    
    int total = 0;      // общая стоимость букета
    int taken = 0;      // сколько растений уже взяли
    int last_cost = -1; // стоимость последнего взятого растения
    int last_count = 0; // сколько раз мы уже взяли растение с такой стоимостью
    
    for (int i = 0; i < N; i++) {
        if (taken == K) {
            break; // букет уже собран
        }
        
        // Если это растение той же стоимости, что и предыдущее - увеличиваем счетчик
        if (cost[i] == last_cost) {
            last_count = last_count + 1;
        } else {
            // Если стоимость другая - начинаем счет заново
            last_cost = cost[i];
            last_count = 1;
        }
        
        // Берем растение, только если не превысили лимит L
        if (last_count <= L) {
            total = total + cost[i];
            taken = taken + 1;
        }
    }
    
    cout << "Максимальная стоимость букета: " << total << endl;
    
    return 0;
}