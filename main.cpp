/*
Program name: Grade Statistics.cpp
Name: Judith Nnaji
Date: 11/14/2025
Purpose: This program collects 16 quiz scores (0–15) from the user and stores them in an STL array.
*/

#include <iostream>
#include <array>
#include <numeric>
#include <iomanip>

using namespace std;

const int NUM_MODULES = 16;

// Function prototypes
void getData(array<int, NUM_MODULES>& scores);
int highScore(const array<int, NUM_MODULES>& scores);
int lowScore(const array<int, NUM_MODULES>& scores);
double calculateAverage(const array<int, NUM_MODULES>& scores);
void displayReport(const array<int, NUM_MODULES>& scores, int highModule, int lowModule, double average);

int main() {
    array<int, NUM_MODULES> quizScores;

    getData(quizScores);

    int highModule = highScore(quizScores);
    int lowModule = lowScore(quizScores);
    double average = calculateAverage(quizScores);

    displayReport(quizScores, highModule, lowModule, average);

    return 0;
}

void getData(array<int, NUM_MODULES>& scores) {
    cout << "Enter quiz scores for " << NUM_MODULES << " modules (0–15):\n";
    for (size_t i = 0; i < scores.size(); ++i) {
        do {
            cout << "Module " << (i + 1) << ": ";
            cin >> scores[i];

            if (scores[i] < 0 || scores[i] > 15) {
                cout << "Invalid score! Please enter a value between 0 and 15.\n";
            }

        } while (scores[i] < 0 || scores[i] > 15);
    }
}

int highScore(const array<int, NUM_MODULES>& scores) {
    int maxIndex = 0;
    for (size_t i = 1; i < scores.size(); ++i)
        if (scores[i] > scores[maxIndex])
            maxIndex = i;
    return maxIndex;
}

int lowScore(const array<int, NUM_MODULES>& scores) {
    int minIndex = 0;
    for (size_t i = 1; i < scores.size(); ++i)
        if (scores[i] < scores[minIndex])
            minIndex = i;
    return minIndex;
}

double calculateAverage(const array<int, NUM_MODULES>& scores) {
    double sum = accumulate(scores.begin(), scores.end(), 0.0);
    return sum / scores.size();
}

void displayReport(const array<int, NUM_MODULES>& scores, int highModule, int lowModule, double average) {
    cout << "\nFall 2025 Quiz Grades:\n\n";
    for (size_t i = 0; i < scores.size(); ++i)
        cout << "            Module " << setw(2) << (i + 1)
        << ": " << setw(2) << scores[i] << endl;

    cout << fixed << setprecision(2);
    cout << "\nAverage Grade: " << average << endl;
    cout << "Your lowest score was in Module " << (lowModule + 1)
        << " with " << scores[lowModule] << ".\n";
    cout << "Your highest score was in Module " << (highModule + 1)
        << " with " << scores[highModule] << ".\n";
  
}





