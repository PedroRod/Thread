#include "Thread.h"


Thread::Thread()
{
	_stop = false;

	_isDetached = false;

	_isBusy = false;
}

Thread::~Thread()
{
	if (!_isDetached)
		Wait();
}

void Thread::Start(const std::function<void(std::atomic_bool& stop)>& logic)
{
	if (_isBusy)
		throw std::exception("Thread is busy");


	auto task = [&]()
	{
		_isBusy = true;

		logic(_stop);

		_stop = false;

		_isBusy = false;

		_isDetached = false;
	};
	
	_thread = std::thread(task);
}

void Thread::Detach()
{
	if (!_isDetached)
		_thread.detach();
	else
		throw std::exception("Thread is already detached");

	_isDetached = true;
}

void Thread::SwapThreads(Thread& exchangeThread)
{
	_thread.swap(exchangeThread._thread);
}

void Thread::Stop()
{
	_stop = true;
}

void Thread::StopAndWait()
{
	_stop = true;

	Wait();
}

bool Thread::IsBusy()
{
	return _isBusy;
}

void Thread::Wait()
{
	if (_thread.joinable())
		_thread.join();
}