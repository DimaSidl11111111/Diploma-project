#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>


using namespace std;

class ProbabilityCalculator {
private:
    vector<int> numbers;
    int totalNumbers;

    static bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    double calculateProbability(std::function<bool(int)> condition) {
        int count = 0;
        for (int num : numbers) {
            if (condition(num)) count++;
        }
        return (count * 100.0) / totalNumbers;
    }

    static bool isMultipleOf3(int n) { return n % 3 == 0; }
    static bool isEven(int n) { return n % 2 == 0; }
    static bool isMultipleOf4(int n) { return n % 4 == 0; }

public:
    ProbabilityCalculator() {
        totalNumbers = 20;
        for (int i = 1; i <= totalNumbers; i++) {
            numbers.push_back(i);
        }
    }

    void displayDescription() {
        cout << "\n\033[1;36m" << string(60, '=') << "\n";
        cout << "                     ** Задача випадкового витягування карток з коробки **\n";
        cout << string(60, '=') << "\033[0m\n";

        cout << "\033[1;37m У коробці лежить 20 карток, пронумерованих від 1 до 20.\n"
            << "   Навмання беруть одну картку. Яка ймовірність того, що на ній записано:\n"
            << "   - число, кратне 3\n"
            << "   - парне число\n"
            << "   - просте число\n"
            << "   - число, кратне 4\n\033[0m";

        cout << "\033[1;36m" << string(60, '=') << "\033[0m\n\n";
    }

    void displayResults() {
        cout << "\033[1;34m" << string(50, '=') << "\n";
        cout << "       ** Ймовірності випадіння числа\n";
        cout << string(50, '=') << "\033[0m\n";

        cout << "\033[1;33m! Число, кратне 3 [P = 6/20 = 3/10]:  \033[1;32m" << fixed << setprecision(2)
            << calculateProbability(isMultipleOf3) << "%\033[0m\n";

        cout << "\033[1;33m! Парне число [P = 10/20 = 1/2]:       \033[1;32m" << fixed << setprecision(2)
            << calculateProbability(isEven) << "%\033[0m\n";

        cout << "\033[1;33m! Просте число [P = 8/20 = 2/5]:      \033[1;32m" << fixed << setprecision(2)
            << calculateProbability([this](int n) { return isPrime(n); }) << "%\033[0m\n";

        cout << "\033[1;33m! Число, кратне 4 [P = 5/20 = 1/4]:   \033[1;32m" << fixed << setprecision(2)
            << calculateProbability(isMultipleOf4) << "%\033[0m\n";

        cout << "\033[1;34m" << string(50, '=') << "\033[0m\n";
        system("pause");
    }
};
