#include <iostream>
#include <string>
using namespace std;

// BF pattern matching algorithm
int BF(string S, string T)
{
    int i = 0; // index of main string
    int j = 0; // index of pattern string

    while (i < S.length() && j < T.length())
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1; // move to next position
            j = 0;
        }
    }

    if (j == T.length())
        return i - j; // return match position
    else
        return -1; // matching failed
}

int main()
{
    // Main string and pattern string
    string S = "datastructstudent";
    // Search pattern
    string T = "tstu";

    int pos = BF(S, T);

    if (pos != -1)
        cout << "Pattern found at position: " << pos << endl;
    else
        cout << "Pattern not found." << endl;

    return 0;
}
