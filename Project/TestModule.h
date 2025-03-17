#ifndef TESTMODULE_H
#define TESTMODULE_H
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <random>
#include <string>
using namespace std;


class TestModule {
private:
    map<string, string> questions = {
        {"\033[1;34mПодію, яка може відбутися або не відбутися внаслідок випробування, називають достовірною?\033[0m", "Ні"},
        {"\033[1;34mПодія, яка обов'язково відбудеться, називається випадковою?\033[0m", "Ні"},
        {"\033[1;34mПодія, яка не може відбутися, називається неможливою?\033[0m", "Так"},
        {"\033[1;34mПодія 'Під час вимірювання довільного тупого кута дістали 50°' є неможливою?\033[0m", "Так"},
        {"\033[1;34mПодія 'Під час вимірювання довільного гострого кута дістали 130°' є неможливою?\033[0m", "Так"}
    };

public:
    void Run() {
        system("cls");
        cout << "\033[1;33m===========================================================" << endl;
        cout << "\t\tТестування з ймовірностей " << endl;
        cout << "===========================================================\033[0m" << endl;
        cout << "Введіть \033[1;32m'Так'\033[0m або \033[1;31m'Ні'\033[0m у відповідь на 3 випадкові питання." << endl;
        cout << "-------------------------------------" << endl;

        srand(time(0));
        vector<string> keys;
        for (const auto& pair : questions) {
            keys.push_back(pair.first);
        }
        shuffle(keys.begin(), keys.end(), default_random_engine(time(0)));

        int score = 0;
        for (int i = 0; i < 3; i++) {
            string userAnswer;
            cout << "\nПитання " << (i + 1) << ": " << keys[i] << "\nВаш відповідь: ";
            cin >> userAnswer;

            if (userAnswer == questions[keys[i]]) {
                cout << "\033[1;32m[!] Правильно!\033[0m" << endl;
                score++;
            }
            else {
                cout << "\033[1;31m[Х] Неправильно!\033[0m Правильна відповідь: " << questions[keys[i]] << endl;
            }
            cout << "-------------------------------------" << endl;
            system("pause");
            system("cls");
        }

        cout << "\n\033[1;36mВаш результат:\033[0m " << score << " з 3 правильних відповідей." << endl;

        if (score == 3) {
            cout << "\033[1;32m* Відмінно! У вас чудове розуміння ймовірностей!\033[0m" << endl;
        }
        else if (score == 2) {
            cout << "\033[1;33m* Добре! Але варто ще раз переглянути основи теорії ймовірностей.\033[0m" << endl;
        }
        else {
            cout << "\033[1;31m* Рекомендується повторити теоретичний матеріал, щоб краще зрозуміти поняття.\033[0m" << endl;
        }

        cout << "-------------------------------------" << endl;
        system("pause");
    }
};
#endif