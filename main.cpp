#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

enum Spec { COMPUTERSCIENCE, IT, ECONOMY, PHYSICS, ART };

string specStr[] = { "комп'ютерні науки", "інформатика", "математика та економіка", "фізика та інформатика", "трудове навчання" };
struct Student
{
    string prizv;
    unsigned kurs;
    Spec spec;
    unsigned physicsGrades;
    unsigned mathsGrades;
    unsigned ITGrades;
};

void Create(Student* s, const int N);
void Sort(Student* s, const int N);
void Print(Student* s, const int N);
void highphysics(Student* s, const int N);
double highmark(Student* s, const int N);

int main()
{
    int N;
    cout << "Введіть N: "; cin >> N;

    Student* s = new Student[N];
    Create(s, N);
    Sort(s, N);
    Print(s, N);
    double proc = highmark(s, N);
    cout << "Процент студентів які навчаються на відміно:" << endl;
        cout << proc << "%" << endl;
        highphysics(s, N);
    return 0;
}

void Create(Student* s, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "Студент № " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " прізвище: "; getline(cin, s[i].prizv);
        cout << " курс: "; cin >> s[i].kurs;
        cout << " спеціальність (0 - комп'ютерні науки, 1 - інформатика, 2 - математика та економіка, 3 - фізика та інформатика, 4 - трудове навчання): ";
        cin >> spec;
        cout << " оцінки з фізики: "; cin >> s[i].physicsGrades;
        cout << " оцінки з математики: "; cin >> s[i].mathsGrades;
        cout << " оцінки з інформатики: "; cin >> s[i].ITGrades;
        s[i].spec = (Spec)spec;
        cout << endl;
    }
}
void Print(Student* s, const int N)
{
    cout << "=================================================================================================================="
        << endl;
    cout << "| №  | Прізвище    | курс| спеціальність          | оцінка з фізики | оцінка з математики | оцінка з інформатики |"
        << endl;
    cout << "------------------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " ";
        cout << "| " << setw(12) << left << s[i].prizv
            << "| " << setw(3) << right << s[i].kurs << " "
            << "| " << setw(23) << left << specStr[s[i].spec]
            << "| " << setw(15) << right << s[i].physicsGrades << " "
            << "| " << setw(19) << left << s[i].mathsGrades << " "
            << "| " << setw(20) << right << s[i].ITGrades << " " << "|";
        cout << endl;
    }
    cout << "================================================================================================================="
        << endl;
    cout << endl;
}

void Sort(Student* s, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++)
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if (s[i1].prizv > s[i1 + 1].prizv)
            {
                tmp = s[i1];
                s[i1] = s[i1 + 1];
                s[i1 + 1] = tmp;
            }
}

double highmark(Student* s, const int N)
{
    int k = 0;

    for (int i = 0; i < N; i++) {
        if (
            s[i].mathsGrades == 5 &&
            s[i].physicsGrades == 5 &&
            s[i].ITGrades == 5)
            k++;
    }
    return  100.0*k / N;

}

void highphysics(Student* s, const int N)
{
    cout << "Прізвища студентів в яких фізика 5:" << endl;
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i].physicsGrades == 5)
        {
            cout << setw(3) << right
             << s[i].prizv << endl;

        }
    }
}