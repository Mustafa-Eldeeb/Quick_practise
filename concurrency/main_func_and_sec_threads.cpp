#include<iostream>
#include<thread>

void threadFunction()
{
    // to simulate work 
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Finished work in thread\n"<<std::endl;
}

int main()
{
    std::thread t(threadFunction);

    // to simulate work
    std::this_thread::sleep_for(std::chrono::microseconds(50));
    std::cout<<"Finished work in main function \n"<<std::endl;

    // wait thread to finish
    t.join();

    
    return 0;
}