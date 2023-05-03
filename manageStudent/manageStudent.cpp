#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef enum {
    MALE,
    FEMALE
}Sex;

typedef enum {
    EXELLENT,
    GOOD,
    COMPLETE,
    BAD,
} RankedAcademic;

class Student {
    private:
        static int id;
        string name;
        Sex sex;
        int age;
        float mathGrade;
        float physicalGrade;
        float chemistryGrade;
        float averageGrade;
        RankedAcademic rankedAcademic;
    public:
        Student(string, Sex, int, float, float, float);
        int getId();
        void setId();
        void setName(string name);
        string getName();
        void setAge(int age);
        int getAge();
        void setSex(Sex sex);
        string getSex();
        void setMathGrade(float mathGrade);
        void setPhysicalGrade(float physicalGrade);
        void setChemistryGrade(float chemistryGrade);
        float getMathGrade();
        float getChemistry();
        float getPhysical();
        float getHandelAverage();
        RankedAcademic getRankedAcademic();
};

Student::Student (string name, Sex sex, int age, float mathGrade, float physicalGrade, float chemistryGrade) {
    this->name = name;
    this->age = age;
    this->sex = sex;
    this->mathGrade = mathGrade;
    this->chemistryGrade = chemistryGrade;
    this->physicalGrade = physicalGrade;
}

void Student::setMathGrade (float mathGrage) {
    this->mathGrade = mathGrade;
}

void Student::setPhysicalGrade (float physicalGrade) {
    this->physicalGrade = physicalGrade;
}

void Student::setChemistryGrade (float chemistryGrade) {
    this->chemistryGrade = chemistryGrade;
}

float Student::getMathGrade () {
    return this->mathGrade;
}

float Student::getChemistry () {
    return this->chemistryGrade;
}

float Student::getPhysical () {
    return this->physicalGrade;
}

float Student::getHandelAverage () {
    return ((this->getChemistry() + this->getMathGrade() + this->getPhysical()) /3);
}

string Student::getSex () {
    if(this->sex == MALE){
        return "MALE";
    }else if(this->sex == FEMALE){
        return "FEMALE";
    }
}

void Student::setSex (Sex sex) {
    this->sex = sex;
}

void Student::setName (string name) {
    this->name = name;
}

string Student::getName () {
    return this->name;
}

int Student::id = 0;
void Student::setId () {
    ++id;
}
int Student::getId () {
    return this->id;
}

void Student::setAge (int age) {
    this->age = age;
}

int Student::getAge () {
    return this->age;
}

RankedAcademic Student::getRankedAcademic () {
    if(this->getHandelAverage() >= 8){
        return EXELLENT;
    }else if(this->getHandelAverage() >=6.5){
        return GOOD;
    }else if(this->getHandelAverage() >=4.5){
        return COMPLETE;
    }else{
        return BAD;
    }
}

class Menu {
    private:
        vector<Student> database;
    public:
        Menu();
        void swap(Student *element1, Student *element2);
        void addStudent();
        void showStudent();
        void optionStudent();
        void sortStudentByGPA();
        void sortStudentByAlphabet();
        void updateInforOfStudentById();
};

Menu::Menu () {
    int press = 0;

     while (true)
    {
        cout << "\n------------------MENU--------------------" << endl;
        cout << "| 1: Add a student                       |\n";
        cout << "| 2: Show list student                   |\n";
        cout << "| 3: Sort list student by average grade  |\n";
        cout << "| 4: Sort list student by alphabet       |\n";
        cout << "| 5: Update a student by id              |\n";
        cout << "| 0. Close.                              |\n";
        cout << "------------------------------------------\n";
        cout << "===> Please enter your option: ";
        cin >> press;
        switch (press)
        {
        case 1:
            cout << "You chose to add a student!\n";
            cout << endl;
            
            this->addStudent();
            break;
        case 2:
            cout << "You chose to show infor of student\n";
            this->showStudent();
            break;
        case 3:
            cout << "You chose to sort list student by average grade\n";
            cout << endl;
            this->sortStudentByGPA();
            break;
        case 4:
            cout << "You chose to sort list student by alphabet\n";
            cout << endl;
            this->sortStudentByAlphabet();
            break;
        case 5:
            cout << "You chose to update a student by Id \n" << endl;
            this->updateInforOfStudentById();
            break;
        default:
        case 0:
            return;
            break;
        }
    }
}

void Menu::swap (Student *element1, Student *element2) {
    Student temp = *element1;
    *element1 = *element2;
    *element2 = temp;
}
void Menu::addStudent () {
    string name;
    Sex sex;
    int age;
    float mathGrade;
    float physicalGrade;
    float chemistryGrade;
    string gender;
    cin.ignore();
    cout << "************ENTER INFORMATION***********" << endl;
    cout << "Let enter the information below: \n";
    cout << "Student name: ";
    getline(cin, name);
    cout << "Your age: ";
    cin >> age;
    cin.ignore();
    cout << "Your sex (MALE/FEMALE): ";
    getline(cin, gender);
    if(gender == "MALE"){
        sex = MALE;
    }else if(gender == "FEMALE"){
        sex = FEMALE;
    }
    cout << "Math grade: ";
    do{
    cin >> mathGrade;
    if (mathGrade < 0 || mathGrade > 10)
       cout<<"Pls enter again! Math grade is invalid -.- ";
    }while (mathGrade < 0 || mathGrade > 10);  

    cout << "Physical grade: ";
    do{
    cin >> physicalGrade;
    if (physicalGrade < 0 || physicalGrade > 10)
       cout<<"Pls enter again! Physical grade is invalid -.- ";
    }while (physicalGrade < 0 || physicalGrade > 10);  
       
    cout << "Chemistry grade: ";
    do{
    cin >> chemistryGrade;
    if (chemistryGrade < 0 || chemistryGrade > 10)
        cout<<"Pls enter again! Chemistry grade is invalid -.- ";
    }while (chemistryGrade < 0 || chemistryGrade > 10);  
    cout << "*******************END******************" << endl;
    cin.ignore();
    Student student(name,sex, age, mathGrade, physicalGrade, chemistryGrade);
    database.push_back(student);
}

void Menu::showStudent () {
    cout << "+-----------------------INFORMATION OF THE STUDENT LIST-----------------------+\n";
    cout << "|MSSV\t|Name\t\t|Age\t|Sex\t|Math\t|Physical|Chemistry\t|Average\n";
    for (int i = 0; i < database.size(); i++) {
        cout << "|" << database[i].getId() << "\t|"
             << database[i].getName() << "\t|"
             << database[i].getAge() << "\t|"
             << database[i].getSex() << "\t|"
             << database[i].getMathGrade() << "\t|"
             << database[i].getPhysical() << "\t |"
             << database[i].getChemistry() << "\t\t|"
             << database[i].getHandelAverage() << "\n";
    }
}

void Menu::sortStudentByGPA () {
    for (int i = 0; i < database.size(); i++)
    {
        for (int j = i + 1; j < database.size(); j++)
        {
            if(database[i].getHandelAverage() < database[j].getHandelAverage()){
                swap(&database[i], &database[j]);
            }
        }
    }
}

void Menu::sortStudentByAlphabet () {
    int count = 0;
    vector<int> indexArray;
    string databaseClone[database.size()];
    for(int i = 0; i < database.size(); i++){
        databaseClone[i] = database[i].getName();
    }
    for (int i = 0; i < database.size(); i++)
    {
        for (int j = databaseClone[i].length(); j >= 0 ; j--)
        {
            if((databaseClone[i][j]) == ' '){
                break;
            }else if((databaseClone[i][j]) != ' '){
                count++;
            }
        }
        int index = ((databaseClone[i].length()) - count)+1;
        indexArray.push_back(index);
        count = 0;
    }
    for (int i = 0; i < database.size(); i++)
    {
        for (int j = i+1; j < indexArray.size(); j++)
        {
            string char1 = database[i].getName();
            string char2 = database[j].getName();
            if(char1[indexArray[i]] < char2[indexArray[j]]){
                swap(&database[i], &database[j]);
            }
        }
    }
}

void Menu::updateInforOfStudentById () {
    int index;
    int infor;
    string strUpdate;
    int intUpdate;
    cout << "Please enter the index of the student you want to update: ";
    cin >> index;
    cout << "Do you want to update which information: \n";
    cout << "1: name\n";
    cout << "2: age\n";
    cout << "3: sex\n";
    cout << "4: math grade\n";
    cout << "5: physical grad\n";
    cout << "6: chemistry grade\n";
    cout << "0: ==> go to menu\n";
    cin >> infor;
    cin.ignore();
    switch (infor)
    {
    case 1:
        cout << "Please enter the name: ";
        getline(cin, strUpdate);
        database[index].setName(strUpdate);
        break;
    case 2:
        cout << "Please enter the age: ";
        cin >> intUpdate;
        database[index].setAge(intUpdate);
        break;
    case 3:
        cout << "Please choose the sex options: \n";
        cout << "1: MALE\n";
        cout << "2: FEMALE\n";
        cin >> intUpdate;
        switch (intUpdate)
        {
        case 1:
            database[index].setSex(MALE);
            break;
        case 2:
            database[index].setSex(FEMALE);
            break;
        }
        break;
    case 4:
        cout << "Please enter the math grade: ";
        cin >> intUpdate;
        database[index].setMathGrade(intUpdate);
        break;
    case 5:
        cout << "Please enter the physical grade: ";
        cin >> intUpdate;
        database[index].setPhysicalGrade(intUpdate);
        break;
    case 6:
        cout << "Please enter the chemistry grade: ";
        cin >> intUpdate;
        database[index].setChemistryGrade(intUpdate);
        break;
    case 0:
        Menu();
        break;
    }
    for (int i = 0; i < database.size(); i++){
        if(database[i].getId() == index){
        }
    }
}

int main() {
    Menu* menu = new Menu();
    return 0;
}