#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

class Subject
{
protected:
    float math, literature, english, physics, chemistry, biology;

public:
    Subject()
    {
        this->math = 0;
        this->literature = 0;
        this->english = 0;
        this->physics = 0;
        this->chemistry = 0;
        this->biology = 0;
    }
    void Math(float _math)
    {
        this->math = _math;
    }
    float getMath()
    {
        return this->math;
    }
    void Literature(float _literature)
    {
        this->literature = _literature;
    }
    float getLiterature()
    {
        return this->literature;
    }
    void English(float _english)
    {
        this->english = _english;
    }
    float getEnglish()
    {
        return this->english;
    }
    void Physics(float _physics)
    {
        this->physics = _physics;
    }
    float getPhysics()
    {
        return this->physics;
    }
    void Chemistry(float _chemistry)
    {
        this->chemistry = _chemistry;
    }
    float getChemistry()
    {
        return this->chemistry;
    }
    void Biology(float _biology)
    {
        this->biology = _biology;
    }
    float getBiology()
    {
        return this->biology;
    }
};

class Student
{
protected:
    int ID;
    string fullname, birth;
    char gender;
    Subject point;

public:
    Student()
    {
        this->ID = -1;
        this->fullname = "Unknown";
        this->birth = "Unknown";
        this->gender = 'X';
    }
    Student(int _ID, string _fullname, string _birth, char _gender)
    {
        this->ID = _ID;
        this->fullname = _fullname;
        this->birth = _birth;
        this->gender = _gender;
    }
    int getID()
    {
        return this->ID;
    }
    string getFullname()
    {
        return this->fullname;
    }
    string getBirth()
    {
        return this->birth;
    }
    char getGender()
    {
        return this->gender;
    }
    Subject getPoint()
    {
        return this->point;
    }
    void setMath(float _math)
    {
        this->point.Math(_math);
    }
    void setLiterature(float _literature)
    {
        this->point.Literature(_literature);
    }
    void setEnglish(float _english)
    {
        this->point.English(_english);
    }
    void setPhysics(float _physics)
    {
        this->point.Physics(_physics);
    }
    void setChemistry(float _chemistry)
    {
        this->point.Chemistry(_chemistry);
    }
    void setBiology(float _biology)
    {
        this->point.Biology(_biology);
    }
    float D_point()
    {
        return (this->point.getMath() + this->point.getLiterature() + this->point.getEnglish()) / 3;
    }
    float A_point()
    {
        return (this->point.getMath() + this->point.getPhysics() + this->point.getChemistry()) / 3;
    }
    float A1_point()
    {
        return (this->point.getMath() + this->point.getPhysics() + this->point.getEnglish()) / 3;
    }
    float B_point()
    {
        return (this->point.getMath() + this->point.getChemistry() + this->point.getBiology()) / 3;
    }
};

class StudentManagement
{
private:
    vector<Student> v;

public:
    void add(Student obj)
    {
        v.push_back(obj);
    }
    void remove(int _ID)
    {
        int pos;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].getID() == _ID)
            {
                pos = i;
                break;
            }
        }
        v.erase(v.begin() + pos);
    }
    void modify(int _ID, string str, float _point)
    {
        int pos;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].getID() == _ID)
            {
                pos = i;
            }
        }
        if (str == "Math")
        {
            v[pos].setMath(_point);
        }
        else if (str == "Literature")
        {
            v[pos].setLiterature(_point);
        }
        else if (str == "English")
        {
            v[pos].setEnglish(_point);
        }
        else if (str == "Physics")
        {
            v[pos].setPhysics(_point);
        }
        else if (str == "Chemistry")
        {
            v[pos].setChemistry(_point);
        }
        else if (str == "Biology")
        {
            v[pos].setBiology(_point);
        }
    }
    void display()
    {
        cout << "ID" << setw(17) << "Fullname" << setw(15) << "Birth" << setw(13) << "Gender" << setw(8) << "Math" << setw(15) << "Literature"
             << setw(13) << "English" << setw(13) << "Physics" << setw(15) << "Chemistry" << setw(15) << "Biology"
             << setw(11) << "D" << setw(10) << "A" << setw(9) << "A1" << setw(10) << "B" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i].getID() << setw(20) << v[i].getFullname() << setw(12) << v[i].getBirth() << setw(5) << v[i].getGender() << setw(10)
                 << v[i].getPoint().getMath() << setw(9) << v[i].getPoint().getLiterature() << setw(16) << v[i].getPoint().getEnglish()
                 << setw(13) << v[i].getPoint().getPhysics() << setw(13) << v[i].getPoint().getChemistry() << setw(17) << v[i].getPoint().getBiology()
                 << setw(15) << v[i].D_point() << setw(10) << v[i].A_point() << setw(9) << v[i].A1_point() << setw(10) << v[i].B_point() << endl;
        }
    }
};

string extractPoint(string str, int &pos)
{
    string point;
    while (str[pos] != ' ' && str[pos] != '\0')
    {
        point += str[pos];
        pos++;
    }
    return point;
}

int main()
{
    StudentManagement obj;
    fstream fileInput("test.txt");
    if (fileInput.fail())
        cout << "Failed to open the file!" << endl;

    while (!fileInput.eof())
    {
        char temp[255];
        fileInput.getline(temp, 255);
        string line = temp;
        string sID, sName, sBirth, sMath, sLiterature, sEnglish, sPhysics, sChemistry, sBiology;
        char sGender;

        // ----------ID----------
        for (int i = 0; i < 7; i++)
        {
            sID += line[i];
        }
        int ID = stoi(sID);

        // ----------Name----------
        int i = 8;
        while (!isdigit(line[i]))
        {
            sName += line[i];
            i++;
        }

        // ----------Birth----------
        sBirth = extractPoint(line, i);

        // ----------Gender----------
        sGender = line[++i];

        Student newStudent(ID, sName, sBirth, sGender);

        // ----------Math----------
        i += 2;
        sMath = extractPoint(line, i);
        float MathPoint = stof(sMath);
        newStudent.setMath(MathPoint);

        // ----------Literature----------
        i++;
        sLiterature = extractPoint(line, i);
        float LiteraturePoint = stof(sLiterature);
        newStudent.setLiterature(LiteraturePoint);

        // ----------English----------
        i++;
        sEnglish = extractPoint(line, i);
        float EnglishPoint = stof(sEnglish);
        newStudent.setEnglish(EnglishPoint);

        // ----------Physics----------
        i++;
        sPhysics = extractPoint(line, i);
        float PhysicsPoint = stof(sPhysics);
        newStudent.setPhysics(PhysicsPoint);

        // ----------Chemistry----------
        i++;
        sChemistry = extractPoint(line, i);
        float ChemistryPoint = stof(sChemistry);
        newStudent.setChemistry(ChemistryPoint);

        // ----------Biology----------
        i++;
        sBiology = extractPoint(line, i);
        float BiologyPoint = stof(sBiology);
        newStudent.setBiology(BiologyPoint);

        obj.add(newStudent);
    }
    obj.remove(1952942);
    obj.modify(1952968, "Math", 9.5);
    obj.display();
    fileInput.close();
    return 0;
}
