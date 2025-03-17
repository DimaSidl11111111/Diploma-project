﻿#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class TaskSolver {
private:
    map<string, pair<double, string>> tasks = {
        {"Під час виборів президента в країні X було проведене вибіркове опитування виборців 'Exit poll'. \nЗа результатами опитування 10000 виборців виявилося, що 900 виборців віддали свій голос претендентові С. \nЯка імовірність того, що претендент С виграє вибори?", {0.09, "Розв'язання: \nP(A) = m/n = 900/10000 = 0.09 (9%)"}},
        {"У локальній мережі міститься 100 комп'ютерів. Протягом години звертається до сервера 8 комп'ютерів. \nЯка імовірність того, що це був 1-й комп'ютер?", {0.08, "Розв'язання: \nP(A) = m/n = 8/100 = 0.08 (8%)"}},
        {"Конференція продовжується три дні. У перший і другий день виступають по 15 доповідачів, \nу третій - 20. Яка імовірність того, що доповідь професора Буракова випаде на третій день?", {0.40, "Розв'язання: \nВсього: 15*2+20 = 50(доповідачів), тоді \nP(A) = m/n = 20/50 = 2/5 = 0.40 (40%)"}},
        {"У спортивних змаганнях 'Козацькі забави' прийняли участь 3 хлопці з 10 класу, \n4 хлопців 9-Б класу, 2 із 9-А класу, 1 з 11 класу. \nЯка імовірність того, що виграє випускник 11 класу?", {0.10, "Розв'язання: \nВсього: 3 + 4 + 2 + 1 = 10(учасників), тоді \nP(A) = m/n = 1/10 = 0.10 (10%)"}},
        {"Набираючи номер телефону, абонент забув останню цифру. \nЗнайти ймовірність того, що номер набрано правильно (подія А), якщо відомо, що цифра непарна.", {0.50, "Розв'язання: \nHомер телефону можна набрати з 10 цифр, (0, 1, 2, ... , 9), з яких 5 - непарні цифри, тоді \nP(A) = m/n = 5/10 = 1/2 = 0.50 (50%)"}},
        {"Набір для гри в доміно має 28 кісточок. Навмання беруть 2 кісточки. Вони виявляються не дублями. \nЗнайти ймовірність, що третя навмання взята кісточка виявилася дублем.", {0.27, "Розв'язання: \nДубль - це кісточка з одним і тим же числом.ю всього таких кісточок - 7. \nЯкщо навмання вибирають 2 кісточки, тоді залишається: 28 - 2 = 26. \nМаємо: ймовірність, що третя, навмання взята кісточка, виявилася дублем \nP(A) = m/n = 7/26 ≈ 0.27 (27%)"}},
        {"В цеху по виготовленню м'ячів для гольфу в одній коробці було 67 правильної форми м'ячів \nта 23 м'ячі з дефектами в іншій. М'ячі зсипали в одну коробку. \nЯка ймовірність того, що навмання витягнутий м'яч буде бракованим?", {0.23, "Розв'язання: \nЗагальне число рівно можливих подій, рівне кількості всіх мячів \nn = 67 + 23 = 100. \nЧисло сприятливих події, яка полягає у витягненні бракованого мяча\nрівне їх кількості: m = 23. \nЗа формулою ймовірності знаходимо: P(A) = m/n = 23/100 = 0.23 (23%)\nЙмовірність витягнути бракований м'яч рівна 0,23 = 0,23 * 100% = 23%"}}
    };

public:
    void Run()
    {
        system("cls");
        cout << "\033[1;33m\t\t*** Випадкові ймовірнісні задачі ***\033[0m\n";
        cout << "Всього буде три задачі. Введіть відповідь у десятковому форматі (наприклад, 0.23).\n";
        srand(time(0));
        vector<string> keys;
        for (const auto& pair : tasks) {
            keys.push_back(pair.first);
        }
        random_shuffle(keys.begin(), keys.end());

        int correctAnswers = 0;
        for (int i = 0; i < 3; i++) {
            cout << "\n\033[1;34mЗадача " << (i + 1) << ": \033[0m" << keys[i] << endl;
            double userAnswer;
            cout << "\nВведіть вашу відповідь: ";
            cin >> userAnswer;

            if (abs(userAnswer - tasks[keys[i]].first) < 1e-2) {
                cout << "\033[1;32m[!] Правильно!\033[0m" << endl;
                correctAnswers++;
            }
            else {
                cout << "\033[1;31m[Х] Неправильно!\033[0m Правильна відповідь: " << tasks[keys[i]].first << endl;
            }
            cout << tasks[keys[i]].second << "\n";
            system("pause");
            system("cls");
        }

        cout << "\n\033[1;36mВаш результат:\033[0m " << correctAnswers << " з 3 правильних відповідей." << endl;
        system("pause");
    }
};

#endif