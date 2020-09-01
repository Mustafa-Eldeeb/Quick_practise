#include<iostream>
#include<thread>

void threadFunction()
{
    // to simulate work 
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    
}