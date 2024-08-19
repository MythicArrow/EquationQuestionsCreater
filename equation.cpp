#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// Linear equation formula
double linearEquation(double a, double b, double c) {
    return (c - b) / a;
}

// Quadratic equation formula
pair<double, double> quadraticEquation(double a, double b, double c) {
    double discriminant = b*b - 4*a*c;
    if (discriminant >= 0) {
        double root1 = (-b + sqrt(discriminant)) / (2*a);
        double root2 = (-b - sqrt(discriminant)) / (2*a);
        return make_pair(root1, root2);
    } else {

        return make_pair(NAN, NAN);
    }
}

// Random number function
double randomDouble(double min, double max) {
    return min + (rand() / (RAND_MAX / (max - min)));
}

int main() {
    srand(time(0));  // Random number seed
    int correctAnswers = 0;
    clock_t startTime = clock();

    // 5 equation question
    for (int i = 0; i < 5; i++) {
        int equationType = rand() % 2;  // 0: linear, 1: quadratic
        double userAnswer1, userAnswer2;

        if (equationType == 0) {
            // Linear equation
            double a = randomDouble(1, 10);
            double b = randomDouble(0, 10);
            double c = randomDouble(0, 20);

            cout << "Equation: " << a << "*x + " << b << " = " << c << endl;
            cout << "x = ";
            cin >> userAnswer1;

            // Answer checker
            double correctSolution = linearEquation(a, b, c);
            if (fabs(userAnswer1 - correctSolution) < 0.01) {
                correctAnswers++;
            }

        } else {
            // Quadratic equation
            double a = randomDouble(1, 5);
            double b = randomDouble(-10, 10);
            double c = randomDouble(-10, 10);

            cout << "Denklem: " << a << "*x^2 + " << b << "*x + " << c << " = 0" << endl;
            cout << "x1 = ";
            cin >> userAnswer1;
            cout << "x2 = ";
            cin >> userAnswer2;

            // Answer checker
            pair<double, double> solutions = quadraticEquation(a, b, c);
            if ((fabs(userAnswer1 - solutions.first) < 0.01 || fabs(userAnswer1 - solutions.second) < 0.01) &&
                (fabs(userAnswer2 - solutions.first) < 0.01 || fabs(userAnswer2 - solutions.second) < 0.01)) {
                correctAnswers++;
            }
        }
    }

    clock_t endTime = clock();
    double totalTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    cout << "\nCorrect answers: " << correctAnswers << "/5" << endl;
    cout << "Total time : " << totalTime << " seconds " << endl;
    cout << "Average time: " << totalTime / 5 << "seconds " << endl;
    cout<< "Made by MyhticArrow" <<endl;

    return 0;
}
