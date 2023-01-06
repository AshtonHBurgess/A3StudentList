#include "Student.h"

Student :: Student(){
    this->courseNum = 0;
    this -> courseList = new string[courseNum];//initailization of student course dynamic aray "new" decrared on the heap

}//END OF Student Constructor

Student ::~Student(){
    if(!courseList->empty()) {
        delete [] courseList;
    }

}//END OF Student Destructor

void Student ::stCopy( Student *stToCopy)//copy constructor
{
    this->setCourseNum(stToCopy->getCourseNum());
    this->setName(stToCopy->getName());
    this->courseList= new string[this->courseNum];

    for (int i = 0; i < this->courseNum; i++) {
        this->courseList[i] = stToCopy->courseList[i];
    }
}//END OF stCopy

void Student ::setName(string pName){this ->name = pName;}//END OF setName
string Student ::getName(){return this->name;}//END OF getName
int Student ::getCourseNum(){return this->courseNum;}//END OF getCourseNum

void Student ::setCourseNum(int pCourseNum){
    this->courseNum = pCourseNum;
}//END OF setCourseNum

void Student ::resetCourseList(){
//    setName("");
    setCourseNum(0);
    delete[] courseList;//delete my original course array
    this -> courseList = new string[courseNum];
}//END OF resetCourseList

void Student ::addCourse(string pCourseName) {
    int newCourseArrayLen = this->courseNum * 2;
    if (newCourseArrayLen == 0)newCourseArrayLen++;
    string *tempCourseList = new string[newCourseArrayLen];//initailize my temp course list
    for (int i = 0; i < this->courseNum; i++) {
        tempCourseList[i] = courseList[i];//copies current contents of courseList to my new temp course list
    }
    delete[] courseList;//delete my original course array
    courseList = tempCourseList;
    for (int i = this->courseNum; i < this->courseNum; i++) {
        courseList[i] = "";//fills remaining courseList index positions with empty strings.
    }
    courseList[courseNum++] = pCourseName;
}//END OF addCourse

string Student ::getCourse(int courseIndex)
{
    return this->courseList[courseIndex];
}//END OF getCourse

void Student ::printCourseList(){
    cout << "Student name:"<<getName() <<endl;
    cout << "Student is enrolled in"<< getCourseNum() <<" courses:" << endl;
    for (int i = 0; i < getCourseNum(); i++)
    {
        cout << "\t-" << getCourse(i) << endl;
    }}

Student &Student::operator=(Student &student) {
    this->setCourseNum(student.getCourseNum());
    this->setName(student.getName());
    this->courseList= new string[this->courseNum];

    for (int i = 0; i < this->courseNum; i++) {
        this->courseList[i] =  student.courseList[i];
    }
    return *this;
}//END OF printCourseList

string Student::toString()//clean output method
{
string printList;
    for (int i = 0; i < this->getCourseNum(); i++)
    {
        printList = printList + ("\t-" + this->getCourse(i) + "\n");
    }
    stringstream strStream;
    string stName,stCourseNum,stCourseList;
    strStream << "Student:"<< this->getName() << endl;//places student name in stream(buffer/holding place)
    strStream>>stName;// receive back as string
    strStream.clear();
    strStream <<this->getCourseNum();
    strStream>>stCourseNum;// receive back as string
    strStream.clear();
    //create string format for output
    return ("Student:" + stName + "\n" + "is enrolled in " + stCourseNum + "courses.");
}//END OF toString