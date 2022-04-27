#include "Student.h"
#include "Teacher.h"

int main()
{
    Student std("Jack jack");
    std.setName("Jack jack 2");

    std::cout <<std.getName()<< std::endl;
    Teacher teacher1("Dr. H");
    teacher1.setName("Dr. k");

    std::cout <<teacher1.getName()<< std::endl;

    std.doNothing();
    teacher1.doNothing();

    std.study();
    teacher1.teach();

    Person person;
    person.setName("Mr.incredible");
    person.getName();
    

    return 0;
}