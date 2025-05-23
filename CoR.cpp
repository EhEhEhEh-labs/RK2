#include "CoR.h"
#include <iostream>
#include <stdexcept>

std::string GetNameOfTask(Task task)
{
    switch (task)
    {
    case Task::CustomerIssue:
        return "CustomerIssue";
    case Task::Programming:
        return "Programming";
    case Task::HardProgramming:
        return "HardProgramming";
    case Task::MoneyIssue:
        return "MoneyIssue";
    case Task::M_And_A:
        return "M_And_A";
    case Task::ImpossibleTask:
        return "ImpossibleTask";
    default:
        throw std::invalid_argument("Unknown task");
    }
}

Worker::Worker(Worker* successor)
    : successor_(successor)
{}

void Worker::Work(Task task)
{
    if (WorkImpl_(task))
    {
        return;
    }
    if (successor_)
    {
        successor_->Work(task);
    }
    else
    {
        std::cout << "Fail to handle task. (" << GetNameOfTask(task) << ")" << std::endl;
    }
}

Worker* Worker::ChangeSuccessor(Worker* successor)
{
    Worker* old = successor_;
    successor_ = successor;
    return old;
}

bool CustomerSupporter::WorkImpl_(Task task)
{
    switch (task)
    {
    case Task::CustomerIssue:
        std::cout << "[CustomerSupporter] Resolve customer issue." << std::endl;
        return true;
    default:
        return false;
    }
}

void SoftwareEngineer::Train()
{
    isTrained_ = true;
}

bool SoftwareEngineer::WorkImpl_(Task task)
{
    switch (task)
    {
    case Task::Programming:
        std::cout << "[SoftwareEngineer] Programming." << std::endl;
        return true;
    case Task::HardProgramming:
        if (isTrained_)
        {
            std::cout << "[SoftwareEngineer] Successfully solve hard problem!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "[SoftwareEngineer] Try to solve hard problem. But failed." << std::endl;
            return false;
        }
    default:
        return false;
    }
}

bool CEO::WorkImpl_(Task task)
{
    switch (task)
    {
    case Task::MoneyIssue:
        std::cout << "[CEO] Resolve money issue." << std::endl;
        return true;
    case Task::M_And_A:
        std::cout << "[CEO] Do M&A." << std::endl;
        return true;
    default:
        return false;
    }
}

bool God::WorkImpl_(Task)
{
    std::cout << "[God] God can do anything!" << std::endl;
    return true;
}
