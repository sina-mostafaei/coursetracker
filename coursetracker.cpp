// for beter experience you should comment other parts of main functino

#include <iostream>
using namespace std;
class student;
class Lesson
{
    friend double avrage(student a);
    friend class student;

public:
    Lesson()
    {
        unit_code++;
        lesson_num = unit_code;
    };

private:
    static int unit_code;
    string name;
    int credit;
    int score;
    int lesson_num;
};
class student
{
    friend void search(student s[], int size, string name, string last_name);
    friend student top_student(student s[], int size);
    friend double avrage(student a);
    friend class Lesson;

public:
    student()
    {
        s_code++;
        studentnum = s_code;
    };
    void print()
    {
        cout << "name: " << name << endl
             << "last name: " << Last_name << endl
             << "student id: " << studentnum << endl;
    }
    void add_lesson()
    {
        cout << "Enter the number of lessons: ";
        cin >> size;
        size = (size < 0) ? 0 : size;
        lesson = new Lesson[size];
        for (int i = 0; i < size; i++)
        {
            // lesson[i].unit_code++;
            // cout<<"Enter the lesson code"<<endl;
            // cin>>lesson[i].unit_code;
            cout << "Enter the lesson name" << endl;
            cin >> lesson[i].name;
            cout << "Enter the lesson credit" << endl;
            cin >> lesson[i].credit;
            lesson[i].credit = (lesson[i].credit < 1) ? 1 : lesson[i].credit;
            cout << "Enter the lesson score" << endl;
            cin >> lesson[i].score;
            lesson[i].score = (lesson[i].score < 0 || lesson[i].score > 20) ? 0 : lesson[i].score;
        }
    };
    void Lesoons_list()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Lesson " << i + 1 << ":" << lesson[i].name << " " << lesson[i].lesson_num << " " << lesson[i].credit << " " << lesson[i].score << endl;
        }
    };
    void set_student_info()
    {
        string n;
        cout << "Enter the name of the student" << endl;
        cin >> n;
        name = n;
        cout << "Enter the last name of the student" << endl;
        string last;
        cin >> last;
        Last_name = last;
    };

private:
    static long long s_code;
    long long studentnum;
    string name;
    string Last_name;
    Lesson *lesson;
    int size = 0;
};
long long student::s_code = 4031331000;
int Lesson::unit_code = 1000;
double avrage(student a)
{
    int sum_credit = 0;
    int sum = 0;
    for (int i = 0; i < a.size; i++)
    {
        sum_credit += a.lesson[i].credit;
        sum += a.lesson[i].score * a.lesson[i].credit;
    }
    return sum / sum_credit;
}
student top_student(student s[], int size)
{
    int i = 0;
    int top = 0;
    int max = avrage(s[i]);
    for (i; i < size; i++)
    {
        if (avrage(s[i]) > max)
        {
            max = avrage(s[i]);
            top = i;
        }
    }
    return s[top];
}
void search(student s[], int size, string name, string last_name)
{
    bool flag = false;
    for (int i = 0; i < size; i++)
    {
        if (s[i].name == name && s[i].Last_name == last_name)
        {
            // cout << "Student found!" << endl;
            s[i].print();
            s[i].Lesoons_list();
            cout << "Average: " << avrage(s[i]) << endl;
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << "Student not found!" << endl;
    }
}
int main()
{

    //======first part======
    student s1;
    s1.add_lesson();
    cout << avrage(s1);

    //======second part======

    int size;
    cout << "Enter Students Number" << endl;
    cin >> size;
    size = (size < 0) ? 0 : size;
    student *s2;
    s2 = new student[size];
    for (int i = 0; i < size; i++)
    {
        s2[i].set_student_info();
        s2[i].add_lesson();
    }
    top_student(s2, size).print();

    //======thried part======
    int size;
    cout << "Enter Students Number" << endl;
    cin >> size;
    size = (size < 1) ? 1 : size;
    student *s3;
    s3 = new student[size];
    for (int i = 0; i < size; i++)
    {
        s3[i].set_student_info();
        s3[i].add_lesson();
        s3[i].Lesoons_list();
    }
    search(s3, size, "Ali", "Rezaei");

    return 0;
}
