#ifndef A2STUDENTCOURSELIST_STUDENT_H
#define A2STUDENTCOURSELIST_STUDENT_H
#include <string>
#include <iostream>
#include <sstream>
#include <string.h>
#include <iostream>


using namespace std;
class Student
{
private:
//public:
    int courseNum;
    string name;
    string * courseList ;
public:
    Student();
    ~Student();
    void setName(string pName);
    string getName();
    int getCourseNum();
    void setCourseNum(int pCourseNum);
    void addCourse(string pCourseName);
    string getCourse(int count);

    void resetCourseList();
    void printCourseList();//dirty use toString for clean
    string toString();//clean output method
    void stCopy( Student *stToCopy);

    Student& operator= (Student &student);

    friend ostream& operator<<(ostream& output, Student& studentOut)
    {
        stringstream stringStream;
        stringStream << studentOut.getCourseNum();
        string strCourseNum = stringStream.str();

        output << ("Student:" + studentOut.getName())<<endl;
        output << ("Enrolled in " + strCourseNum + " courses:")<<endl;
        for (int i = 0; i < studentOut.getCourseNum(); i++)
        {
            output <<  "\t-" << studentOut.getCourse(i) << endl;
        }
        return output;//return an ostream
    }

//    friend istream &operator >> (istream& input, Student& studentIn)
//    {
//        string courseName;
//        input >> studentIn.name
//    }
// input will not work for name, cause in my program Student class is private

};//end class Student
#endif //A2STUDENTCOURSELIST_STUDENT_H
