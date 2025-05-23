#include "CoR.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

using ::testing::Return;

TEST(TaskTests, GetNameOfTask_Test) {
    EXPECT_EQ(GetNameOfTask(Task::CustomerIssue), "CustomerIssue");
    EXPECT_EQ(GetNameOfTask(Task::Programming), "Programming");
    EXPECT_EQ(GetNameOfTask(Task::HardProgramming), "HardProgramming");
    EXPECT_EQ(GetNameOfTask(Task::MoneyIssue), "MoneyIssue");
    EXPECT_EQ(GetNameOfTask(Task::M_And_A), "M_And_A");
    EXPECT_EQ(GetNameOfTask(Task::ImpossibleTask), "ImpossibleTask");
    EXPECT_THROW(GetNameOfTask(static_cast<Task>(999)), std::invalid_argument);
}


class MockWorker : public Worker {
public:
    MockWorker() : Worker(nullptr) {}
    MOCK_METHOD(bool, WorkImpl_, (Task task), (override));
};


TEST(WorkerTest, DelegatesTaskToSuccessorIfCannotHandle) {
    MockWorker programmer;
    MockWorker ceo;
    programmer.ChangeSuccessor(&ceo);
    Task task = Task::MoneyIssue;

    EXPECT_CALL(programmer, WorkImpl_(task)).WillOnce(Return(false));
    EXPECT_CALL(ceo, WorkImpl_(task)).WillOnce(Return(true));

    programmer.Work(task);
}


TEST(SoftEngiTest, CanLearn) {
    SoftwareEngineer engi(nullptr);
    Task hardTask = Task::HardProgramming;

 
    testing::internal::CaptureStdout();
    engi.Work(hardTask);
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output1.find("Try to solve hard problem. But failed.") != std::string::npos);

    engi.Train();


    testing::internal::CaptureStdout();
    engi.Work(hardTask);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output2.find("Successfully solve hard problem!") != std::string::npos);
}


TEST(FaithCheck, Almighty) {
    God god(nullptr);
    Task validTask = Task::ImpossibleTask;
    Task invalidTask = static_cast<Task>(1337);

    testing::internal::CaptureStdout();
    god.Work(validTask);
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output1.find("[God] God can do anything!") != std::string::npos);

    testing::internal::CaptureStdout();
    god.Work(invalidTask);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output2.find("[God] God can do anything!") != std::string::npos);
}


TEST(CEOTest, TestCEO) {
    CEO ceo(nullptr);

    testing::internal::CaptureStdout();
    ceo.Work(Task::MoneyIssue);
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output1.find("[CEO] Resolve money issue.") != std::string::npos);

  
    testing::internal::CaptureStdout();
    ceo.Work(Task::HardProgramming);
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output2.find("Fail to handle task.") != std::string::npos);
}


TEST(CustomerSupporterTest, HandlesCustomerIssue) {
    CustomerSupporter supporter(nullptr);
    testing::internal::CaptureStdout();
    supporter.Work(Task::CustomerIssue);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("[CustomerSupporter] Resolve customer issue.") != std::string::npos);
}
