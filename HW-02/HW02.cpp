#include <iostream>
using namespace std;

class Grade {
private:
    int score;

public:
    Grade(int s) {
        score = s;
    }
    void ScoreEvaluate() {
        try {
            if (score < 0 || score > 100) {
                throw "Error: Score must be between 0 and 100.";
            }

            switch (score / 10) {
                case 10:
                case 9:
                    cout << "Excellent" << endl;
                    break;
                case 8:
                    cout << "Good" << endl;
                    break;
                case 7:
                    cout << "Medium" << endl;
                    break;
                case 6:
                    cout << "Pass" << endl;
                    break;
                default:
                    cout << "No pass" << endl;
                    break;
            }
        }
        catch (const char* msg) {
            cout << msg << endl;
        }
    }
};

int main() {
    int score;
    cout << "Enter score (0-100): ";
    cin >> score;

    if (cin.fail()) {
        cout << "Invalid input! Please enter a number." << endl;
        return 0;
    }

    Grade g(score);
    g.ScoreEvaluate();

    return 0;
}
