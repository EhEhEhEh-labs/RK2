#ifndef COR_H
#define COR_H

#include <string>

enum class Task
{
    CustomerIssue,
    Programming,
    HardProgramming,
    MoneyIssue,
    M_And_A,
    ImpossibleTask
};

inline std::string GetNameOfTask(Task task);

class Worker
{
public:
    explicit Worker(Worker* successor);
    virtual ~Worker() = default;
    void Work(Task task);
    Worker* ChangeSuccessor(Worker* successor);

private:
    virtual bool WorkImpl_(Task task) = 0;
    Worker* successor_;
};

class CustomerSupporter : public Worker
{
public:
    using Worker::Worker;

private:
    bool WorkImpl_(Task task) override;
};

class SoftwareEngineer : public Worker
{
public:
    using Worker::Worker;
    void Train();

private:
    bool WorkImpl_(Task task) override;
    bool isTrained_{ false };
};

class CEO : public Worker
{
public:
    using Worker::Worker;

private:
    bool WorkImpl_(Task task) override;
};

class God : public Worker
{
public:
    using Worker::Worker;

private:
    bool WorkImpl_(Task) override;
};

#endif
