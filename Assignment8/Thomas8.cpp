#include "roster.cpp"

int main()
{
    GradeBook class_roster;
    class_roster.loadData();
    class_roster.printAll();
    class_roster.menu();
    return 0;
}