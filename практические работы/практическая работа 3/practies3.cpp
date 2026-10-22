//задача 1 (гипотенуза)
// Модульный способ
/* 
#include <cmath>
using namespace std;

double hupotenuse(int a, int b){
    return sqrt(a * a + b * b);
}
int main() {
    int a, b;
    cin >> a >> b;
    cout << hupotenuse(a, b);
    return 0;
}
*/

//Процедурный способ
/*
#include <iostream>
#include <cmath>
using namespace std;

void hupotenuse(int a, int b, double &result) {
    result = sqrt(a * a + b * b);
}
int main() {
    int a, b;
    double hyp;
    cin >> a >> b;
    hupotenuse(a, b, hyp);
    cout << hyp;
    return 0;
}
*/

//ООП способ
/*
#include <iostream>
#include <cmath>
using namespace std;

class triangle {
public:
    double hupotenuse(int a, int b) {
        return sqrt(a * a + b * b);       
    }
};
int main() {
    int a, b;
    cin >> a >> b;
    triangle t;
    cout << t.hupotenuse(a, b);
    return 0;
}
*/

//Файловый способ
/*
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int a, b;
    in >> a >> b;
    double hyp = sqrt(a * a + b * b);
    out << hyp;
    in.close();
    out.close();
    return 0;
}
*/

//задание 2 байкер на МКАД
//модульный способ
/*
#include <iostream>
using namespace std;

int mark(int v, int t) {
    int distance = v * t;
    return distance - (distance / 109) * 109;
}
int main () {
    int v, t;
    cin >> v >> t;
    cout << mark(v, t);
    return 0;
}
*/

//процедурный способ
/*
#include <iostream>
using namespace std;

void Mark(int v, int t, int &result) {
    int distance = v * t;
    result = distance - (distance / 109) * 109;
}
int main() {
    int v, t, mark;
    cin >> v >> t;
    Mark(v, t, mark);
    cout << mark;
    return 0;
}
*/

//ООП способ
/*
#include <iostream>
using namespace std;

class biker {
public:
    int mark(int v, int t) {
        int distance = v * t;
        return distance - (distance / 109) * 109;
    }
};
int main () {
    int v, t;
    cin >> v >> t;
    biker b;
    cout << b.mark(v, t);
    return 0;
}
*/

//файловый способ
/*
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int v, t;
    in >> v >> t;
    int distance = v * t;
    int mark = distance - (distance / 109) * 109;
    out << mark;
    in.close();
    out.close();
    return 0;
}
*/