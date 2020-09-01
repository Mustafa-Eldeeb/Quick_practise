#include <iostream>
#include <thread>

void threadFunction()
{
    //simulate work 1
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Finshed work 1 in thread \n"<<std::endl;

    //simulate work 2
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Finished work 2 in thread\n"<<std::endl;

}

int main()
{
    std::thread t(threadFunction);

    //simulate work 1 in main
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Finished work 1 in main \n"<<std::endl;

    //simulate work 2 in main
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"finished work 2 in main\n"<<std::endl;

    t.join();

    return 0;
}