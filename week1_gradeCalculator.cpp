#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

/* students from same semester => same number of courses(n) and credit hours (credits)     but different marks(marks)
 so n, credits will be declared outside the while loop for this case */

// CGPA = (sum of (marks * credits)) / (sum of credits)

// check t,n <= 0 (return 1) to avoid division by zero and invalid input
// return 1 to exit the program with an error code   and 0 to exit successfully


double CGPA(const vector<double>& gradePoint, const vector<int>& credits, int n) {
    double totalPoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < n; ++i) {
        totalPoints += gradePoint[i] * credits[i];
        totalCredits += credits[i];
    }

    if (totalCredits == 0) return 0.0; // Avoid division by zero
    return totalPoints / totalCredits;
}

double getGradePoint(int marks){
    if (marks >= 80) return 4.00;
    else if (marks >= 75) return 3.75;
    else if (marks >= 70) return 3.50;
    else if (marks >= 65) return 3.25;
    else if (marks >= 60) return 3.00;
    else if (marks >= 55) return 2.75;
    else if (marks >= 50) return 2.50;
    else if (marks >= 45) return 2.25;
    else if (marks >= 40) return 2.00;
    else return 0.00;
}


int main(){
    cout << "how many students are there: ";
    int t;
    cin>> t;
    cout << fixed << setprecision(2);
    if (t <= 0) {
        cout << "Invalid number of students." << endl;
        return 1; 
    }

    char choice;
    cout << "are they from the same semester (y / n): ";
    cin >> choice;

    switch (choice){
        case 'y':{
            cout << "how many courses: ";
            int n;
            cin >>n; 
            if (n <= 0) {
                cout << "Invalid number of courses." << endl;
                return 1; 
            }

            vector<int> credits(n);

            int courseNumber = 1;
            for(int i = 0; i<n; i++){
                cout << "enter credit hours for course " << courseNumber << ": ";
                cin >> credits[i];
                courseNumber++;
            }
            
            
            for(int i=0; i<t; i++){
                vector<int> marks(n);  //declaring it inside the loop creates a new vector every iteration so .clear() is not needed
                                 // as a local variable, it goes out of scope after each iteration and the previos vector is destroyed
                cout<< "For student "<< i + 1 << ": " << endl;

                
                //taking marks and calculating grade point for each course
                vector <double> gradePoint(n);
                courseNumber = 1; // reset course number for each student
                for(int j = 0; j<n; j++ ){
                    cout << "enter marks for course "<< courseNumber << ": ";
                    cin >> marks[j];
                    gradePoint[j] = getGradePoint(marks[j]);
                    courseNumber++;
                }   
                


                // and calculating CGPA for each student
                double cgpa =  CGPA(gradePoint, credits, n) ;
                cout << "For student "<< i + 1 << ", their cgpa is: "<< cgpa << endl << endl;
                        //marks.clear();  // clear marks for the next student // not needed as marks are declared inside the loop
                        //credits.clear();   No need to clear credits as they are the same for all students
            
            }

            break;
        }



        case 'n':{
            
            for(int i=0; i<t; i++){

                cout << "how many courses: ";
                int n;
                cin >>n;
                if (n <= 0) {
                    cout << "Invalid number of courses." << endl;
                    return 1; 
                }
                
                vector<int> marks(n);
                vector<int> credits(n);

                int courseNumber = 1;
               
                cout<< "For student "<< i + 1 << ": " << endl;

                vector <double> gradePoint(n);
                for(int j = 0; j<n; j++ ){
                    cout << "enter marks for course "<< courseNumber << ": ";
                    cin >> marks[j];
                    gradePoint[j] = getGradePoint(marks[j]);
                    cout << "enter credit hours for this course : ";
                    cin >> credits[j];
                    courseNumber++;
                }   

                // and calculating CGPA for each student
                double cgpa =  CGPA(gradePoint, credits, n) ;
                cout << "For student "<< i + 1 << ", their cgpa is: "<< cgpa << endl << endl;
                //marks.clear();  // clear marks and credits for the next student  
                //credits.clear();  // not needed as they are declared inside the loop
            
            }

            break;

        }
 
        default:
            cout << "Invalid choice. Please enter 'y' or 'n'." << endl ;
            return 1; 
    } 


    return 0; 
}