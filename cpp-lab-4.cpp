//
// Created by virag on 14.10.2023.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; // количество чашек
    cin >> n;
    if (((n + 1) * n / 2) % 2 == 1) {
        //Если сумма граммов в каждой тарелке нечетная, то мы не сможем ее поделить поровну
        cout << "NO" << endl;
    } else {
        //Иначе сможем
        cout << "YES" << endl;
        //Сначала найдем половину от суммы, то есть количество граммов для каждого студента
        long long half_of_sum = (n + 1) * n / 4;
        /*Здесь мы идем от самой большой порции n до самой маленькой 1. Будем вычитать из
        half_of_sum каждый i, который меньше half_of_sum, считается, что в какой-то момент он станет равным нулю.
        Пусть такие порции i пойдут Пете, остальные порции не вошедшие в сумму half_of_sum, пойдут Маше*/
        //Сначала посчитаем p и k (колво порций для каждого студента)
        long long p = 0, m = 0;
        for (long long i = n; i > 0; i--) {
            if (i <= half_of_sum) {
                half_of_sum -= i;
                p++;
            } else {
                m++;
            }
        }
        cout << p << endl;
        //Тем же циклом теперь выведем эти порции для Пети
        half_of_sum = (n + 1) * n / 4;
        for (long long i = n; i > 0; i--) {
            if (i <= half_of_sum) {
                cout << i << ' ';
                half_of_sum -= i;
            }
        }
        //Теперь для Маши
        cout << endl;
        cout << m << endl;
        half_of_sum = (n + 1) * n / 4;
        for (long long i = n; i > 0; i--) {
            if (i <= half_of_sum) {
                half_of_sum -= i;
            } else {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}