#include "CoR.h"
#include <iostream>
int main()
{
    CEO ceo(nullptr);
    SoftwareEngineer se(&ceo);
    CustomerSupporter supporter{ &se };

    std::cout << "----------------------" << std::endl;
    supporter.Work(Task::CustomerIssue);
    supporter.Work(Task::Programming);
    supporter.Work(Task::HardProgramming);

    std::cout << "Train software engineer!" << std::endl;
    se.Train();
    supporter.Work(Task::HardProgramming);
    supporter.Work(Task::MoneyIssue);
    supporter.Work(Task::M_And_A);
    supporter.Work(Task::ImpossibleTask);

    std::cout << "Change ceo's successor to 'GOD'!" << std::endl;
    God god(nullptr);
    ceo.ChangeSuccessor(&god);
    supporter.Work(Task::ImpossibleTask);
}
