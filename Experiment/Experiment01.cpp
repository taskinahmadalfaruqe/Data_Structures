#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 100

// Student information
typedef struct {
    int id;
    string name;
    string sex;
    int chinese;
    int math;
    int english;
    int total;
} Student;

// Sequential list structure
typedef struct {
    Student data[MAXSIZE];
    int length;
} SeqList;

// 1. Create a linear list
void InitList(SeqList &L) {
    L.length = 0;
}

// 2. Get the length of the list
int ListLength(SeqList L) {
    return L.length;
}

// 3. Output the linear list
void PrintList(SeqList L) {
    if (L.length == 0) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "ID\tName\tSex\tChinese\tMath\tEnglish\tTotal\n";
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i].id << "\t"
             << L.data[i].name << "\t"
             << L.data[i].sex << "\t"
             << L.data[i].chinese << "\t"
             << L.data[i].math << "\t"
             << L.data[i].english << "\t"
             << L.data[i].total << endl;
    }
}

// 4. Insert element at specified position
bool InsertList(SeqList &L, int pos, Student s) {
    if (pos < 1 || pos > L.length + 1 || L.length >= MAXSIZE)
        return false;

    for (int i = L.length; i >= pos; i--) {
        L.data[i] = L.data[i - 1];
    }

    s.total = s.chinese + s.math + s.english;
    L.data[pos - 1] = s;
    L.length++;
    return true;
}

// 5. Find student by StudentID
int LocateElem(SeqList L, int id) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i].id == id)
            return i + 1;
    }
    return -1;
}

// 6. Get element by position
bool GetElem(SeqList L, int pos, Student &s) {
    if (pos < 1 || pos > L.length)
        return false;

    s = L.data[pos - 1];
    return true;
}

// 7. Delete element at specified position
bool DeleteList(SeqList &L, int pos) {
    if (pos < 1 || pos > L.length)
        return false;

    for (int i = pos - 1; i < L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }

    L.length--;
    return true;
}

// Main function
int main() {
    SeqList L;
    InitList(L);

    Student s1 = {1001, "Tom", "M", 80, 85, 90};
    Student s2 = {1002, "Lucy", "F", 90, 92, 88};
    Student s3 = {1003, "Jack", "M", 78, 75, 80};

    InsertList(L, 1, s1);
    InsertList(L, 2, s2);
    InsertList(L, 3, s3);

    cout << "Student List:\n";
    PrintList(L);

    cout << "\nList Length: " << ListLength(L) << endl;

    int pos = LocateElem(L, 1002);
    cout << "Student ID 1002 position: " << pos << endl;

    Student temp;
    GetElem(L, 2, temp);
    cout << "Student at position 2: " << temp.name << endl;

    DeleteList(L, 1);
    cout << "\nAfter deleting first student:\n";
    PrintList(L);

    return 0;
}
