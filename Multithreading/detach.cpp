#include<iostream>
#include<thread>
#include<chrono>

void independentThread()
{
	std::cout << "Starting concurrent thread.\n";
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "Exiting concurrent thread.\n";
}

void threadCaller()
{
	std::cout << "Starting thread caller.\n";
	std::thread t(independentThread);
	t.detach();
	std::this_thread::sleep_for(std::chrono::seconds(5));
	std::cout << "Exiting thread caller.\n";
}

int main()
{
	threadCaller();
//	std::this_thread::sleep_for(std::chrono::seconds(15));
	return 0;	
}
