#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

class Experiment {
private:
    int red, blue, green; // Number of balls of each color
    int totalBalls;
    int results[3] = { 0, 0, 0 }; // Count occurrences
    int totalDraws = 0;

public:
    Experiment(int r, int b, int g) : red(r), blue(b), green(g) {
        totalBalls = red + blue + green;
        std::srand(std::time(0));
    }

    char drawBall() {
        int randomValue = std::rand() % totalBalls;
        totalDraws++;
        if (randomValue < red) {
            results[0]++;
            return 'R';
        }
        else if (randomValue < red + blue) {
            results[1]++;
            return 'B';
        }
        else {
            results[2]++;
            return 'G';
        }
    }

    void runExperiment(int draws) {
        cout << "\n\033[1;34m" << string(40, '=') << "\n";
        cout << "    Симуляція " << draws << " витягувань\n";
        cout << string(40, '=') << "\033[0m\n";

        for (int i = 0; i < draws; i++) {
            char ball = drawBall();
            switch (ball) {
            case 'R': cout << "\033[1;31m[R] "; break;
            case 'B': cout << "\033[1;34m[B] "; break;
            case 'G': cout << "\033[1;32m[G] "; break;
            }
        }
        cout << "\033[0m\n";

        cout << "\n\033[1;36m" << string(40, '-') << "\n";
        cout << "[R] Червоних: " << results[0]
            << "   [B] Синіх: " << results[1]
            << "   [G] Зелених: " << results[2] << "\n";
        cout << string(40, '-') << "\033[0m\n";

    }

    void showFrequencies() {
        cout << "\n\033[1;33m" << string(40, '=') << "\n";
        cout << "     Імовірності витягувань (%)\n";
        cout << string(40, '=') << "\033[0m\n";

        cout << "\033[1;31mЧервона (R): " << fixed << setprecision(2) << (results[0] * 100.0 / totalDraws) << "%\033[0m\n";
        cout << "\033[1;34mСиня (B): " << fixed << setprecision(2) << (results[1] * 100.0 / totalDraws) << "%\033[0m\n";
        cout << "\033[1;32mЗелена (G): " << fixed << setprecision(2) << (results[2] * 100.0 / totalDraws) << "%\033[0m\n";

        system("pause");
    }

  
};