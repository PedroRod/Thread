#pragma once
#include <thread>
#include <atomic>
#include <functional>

class Thread
{

public:
	Thread();

	~Thread();

	void Start(const std::function<void(std::atomic_bool& stop)>& logic);

	void Detach();

	void SwapThreads(Thread& exchangeThread);

	void Stop();

	void StopAndWait();

	bool IsBusy();

	void Wait();

private:
	std::atomic_bool _stop;

	bool _isDetached;

	bool _isBusy;

	std::thread _thread;
};

