//W0465511, Ashton Burgess
//C++, Assignment2

#include "Student.h"
using namespace std;

int main() {
  string response="";
    do {

        //•	Ask for the 1st students’ name and courses; looping until the student is finished.
        // Note that you may not ask the student how many classes they intend to enter before
        // they enter them nor may any entry be left blank
        string courseName;
        string stName;
        Student st1;
        int cCount = 0;
        cout << "Enter student 1 name:" << endl;
        cin >> stName;
        st1.setName(stName);
        string temp;
        do {
            cout << "Enter course name (type 'end' to exit loop):" << endl;
            cin >> temp;
            cCount++;
            if (temp != "end" && !temp.empty()) { st1.addCourse(temp); }
        } while (temp != "end");

//cout << st1.toString();

//    •	Display the 1st student’s name, number of courses in their list and their list of courses.
        cout << "\nSTUDENT 1" << endl;
//    st1.printCourseList();
        cout << st1;

//•	Ask for the name of a second student and display this new student after copying the 1st student’s
// course information and writing in the new name.
        cout << "\nSTUDENT 2" << endl;
        Student st2;
        st2.stCopy(&st1);//deep copy of st1
        cout << "Enter student 2 name :" << endl;
        cin >> temp;
        st2.setName(temp);
//    st2.printCourseList();
        cout << st2;

//•	Display the 1st student’s name, the number of courses in their list of courses after executing a function that
// resets the number of courses to 0 and the courseList array to an empty list
        cout << "\nSTUDENT 1(After Course Reset)" << endl;
        st1.resetCourseList();
//    st1.printCourseList();
        cout << st1;

//•	Display the 2nd student’s name, number of courses in their list and their list of courses
// (to demonstrate that a deep copy took place).
        cout << "\nSTUDENT 2(Post Student 1 Reset)" << endl;
//    st2.printCourseList();//demonstrates that it is indeed a deep copy
        cout << st2;

//    •	Enter a third student and use the custom assignment operator  i.e. 3rd student = 2nd student
        cout << "\nSTUDENT 3(Deep Copy student 2 into Student 3 using '=' assignment operator)" << endl;
        Student st3;
        st3 = st2;
//    st3.printCourseList();
        cout << st3;
cout<<"Loop back to beginning? \n Submit 'end' to end program, or anything else to loop back to beginning:";
cin>>response;
    }while(response!="end");
    return 0;
}


