#include <iostream>

using namespace std;

int main() {
    double marks;
    
    cout << "Student Grading System\n";
    cout << "Enter the marks: ";
    cin >> marks;

    char grade;

    if (marks >= 90) {
        grade = 'A';
    } else if (marks >= 80) {
        grade = 'B';
    } else if (marks >= 70) {
        grade = 'C';
    } else if (marks >= 60) {
        grade = 'D';
    } else if (marks >= 50) {
        grade = 'E';
    } else {
        grade = 'F';
    }

    cout << "Grade: " << grade << endl;

    return 0;
}
