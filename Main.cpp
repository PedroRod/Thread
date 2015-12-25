#include <gtest/gtest.h>
#include "Thread.h"

void InfiniteTask(std::atomic_bool& stop);

void FiniteTask(std::atomic_bool& stop);

int main(int argc,char* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}

void InfiniteTask(std::atomic_bool& stop)
{
	for (;;)
	{
		if (stop)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

void FiniteTask(std::atomic_bool& stop)
{
	for (auto&& i = 0; i < 100; i++)
	{
		if (stop)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
}

TEST(BaseTest, Can_Start_And_Stop_The_Thread)
{
	Thread thread;

	thread.Start(InfiniteTask);

	ASSERT_TRUE(thread.IsBusy());

	thread.Stop();
	
	thread.Wait();

	ASSERT_FALSE(thread.IsBusy());
}

TEST(BaseTest, Can_Start_And_Wait_The_Thread)
{
	Thread thread;

	thread.Start(FiniteTask);

	thread.Wait();

	ASSERT_FALSE(thread.IsBusy());
}

TEST(BaseTest, Can_Start_And_StopWait_The_Thread)
{
	Thread thread;

	thread.Start(FiniteTask);

	thread.StopAndWait();

	ASSERT_FALSE(thread.IsBusy());
}

TEST(BaseTest, Cannot_Start_New_Task_If_Thread_Is_Busy)
{
	Thread thread;

	thread.Start(FiniteTask);

	ASSERT_THROW(thread.Start(FiniteTask), std::exception);
}

TEST(BaseTest, Can_Start_New_Task_If_Thread_Is_Not_Busy)
{
	Thread thread;

	thread.Start(FiniteTask);

	thread.StopAndWait();

	thread.Start(InfiniteTask);

	ASSERT_TRUE(thread.IsBusy());

	thread.StopAndWait();
}

TEST(BaseTest, Can_Stop_Thread_Once_Detached)
{
	Thread thread;

	thread.Start(InfiniteTask);

	thread.Detach();

	ASSERT_TRUE(thread.IsBusy());

	thread.Stop();

	std::this_thread::sleep_for(std::chrono::milliseconds(100));


	ASSERT_FALSE(thread.IsBusy());
}

TEST(BaseTest, Cannot_Detach_Same_Thread_Twice)
{
	Thread thread;

	thread.Start(FiniteTask);

	thread.Detach();

	ASSERT_THROW(thread.Detach(),std::exception);
}

TEST(BaseTest, Can_Start_New_Task_If_Detached_Thread_Is_Not_Busy)
{
	Thread thread;

	thread.Start(InfiniteTask);

	thread.Detach();

	thread.Stop();

	std::this_thread::sleep_for(std::chrono::milliseconds(100));

	ASSERT_NO_THROW(thread.Start(FiniteTask), std::exception);
}