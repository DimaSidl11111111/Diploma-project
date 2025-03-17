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
void enableANSI() {} // ��� Unix-������� ������ �� �������
#endif

using namespace std;
int main()
{
    enableANSI(); // ���� �������� ������� ��� Windows
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
                cout << "         4. ������� ������� ������������              \n";
                cout << "=====================================================\n\n";
                cout << "[1] ���������� ���� ������ � �������." << endl;
                cout << "[2] ���������� ���� ������ � �������." << endl;
                cout << "[0] �����" << endl;

                cin >> choice2;
                switch (choice2)
                {
                case 1:
                {
                    system("cls");
                    Experiment exp(rand() % 10, rand() % 10, rand() % 10); // 5 ��������, 3 ����, 2 ������� ������
                    exp.runExperiment(rand() % 30 + 10);
                    exp.showFrequencies();
                }
                break;
                case 2:
                {
                    system("cls");
                    ProbabilityCalculator calculator;
                    calculator.displayDescription(); // ³���������� ����� ������
                    calculator.displayResults(); // ���������� ����������� �� ���������
                }
                break;
                case 0:
                    break;
                default: {
                    cout << "������� ����. ��������� �� ���." << endl;
                    system("pause");
                }
                }

            }
            case 0:
                break;
            default:
                cout << "������� ����. ��������� �� ���." << endl;
            }
        } while (choice != 0);
        cout << "����� � ��������..." << endl;

    return 0;

}