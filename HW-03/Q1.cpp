#include <iostream>
using namespace std;

int rotateLeft(int n, int k) {
    int bits = sizeof(n) * 8; 
    k = k % bits; 
    return (n << k) | (n >> (bits - k));
}

int main() {
    int n = 16;
    int k = 3;
    int result = rotateLeft(n, k);
    cout << "Base Number-: "<<n<<" Shift Amount-: "<<k<<" Result-: "<< result << endl;
    return 0;
}