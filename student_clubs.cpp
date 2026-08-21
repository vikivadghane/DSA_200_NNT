#include <iostream>
using namespace std;

int main() {
    int n = 200, s = 120, m = 90, b = 50;
    cout << "Total number of students: " << n << endl;
    cout << "Students member of only sport club: " << s-b << endl;
    cout << "Students member of only music club: " << m-b << endl;
    cout << "Students are in both club: " << b << endl;
    cout << "Students who are neither club: " << (n - (s + m - b)) << endl;
    cout << "Atleast in one club: " << s + m - b << endl;
    return 0;
}