#include "Menu.h"
#include "Theory.h"
#include "Simulation.h"
#include "TestModule.h"
#include "Experiment.h"
#include "Cards.h"

#include <iostream>
#include <Windows.h>

#ifdef _WIN32
#include <windows.h>
void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
#else
void enableANSI() {} // Для Unix-подібних систем не потрібно
#endif

using namespace std;
int main()
{
    enableANSI(); // Додає підтримку кольорів для Windows
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));
    int choice;
    do 
    {
        ShowMainMenu();
        cin >> choice;
        switch (choice) 
        {
            case 1:
            { ProbabilityTheory theory; theory.Run(); }
            break;
            case 2:
            { TaskSolver dice; dice.Run(); }
            break;
            case 3:
            { TestModule test; test.Run(); }
            break;
            case 4:
            {
                int choice2 = 0;
                system("cls");
                cout << "=====================================================\n";
                cout << "         4. Імітація простих експериментів              \n";
                cout << "=====================================================\n\n";
                cout << "[1] Випадковий вибір кульок з коробки." << endl;
                cout << "[2] Випадковий вибір карток з коробки." << endl;
                cout << "[0] Вихід" << endl;

                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    system("cls");
                    Experiment exp(rand() % 10, rand() % 10, rand() % 10); // 5 червоних, 3 синіх, 2 зелених кульки
                    exp.runExperiment(rand() % 30 + 10);
                    exp.showFrequencies();
                }
                break;
                case 2:
                {
                    system("cls");
                    ProbabilityCalculator calculator;
                    calculator.displayDescription(); // Відображення опису задачі
                    calculator.displayResults(); // Обчислення ймовірностей та виведення
                }
                break;
                case 0:
                    break;
                default: {
                    cout << "Невірний вибір. Спробуйте ще раз." << endl;
                    system("pause");
                }
                }

            }
            case 0:
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
            }
        } while (choice != 0);
        cout << "Вихід з програми..." << endl;

    return 0;

}