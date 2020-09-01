#include <iostream>
#include <thread>

void threadFunction()
{
    //simulate work in thread
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Finished work in thread \n"<<std::endl;
}

int main()
{
    //create thread

    std::thread t(threadFunction);

    //detach (near to separate) thread and continue with main
    t.detach();

    //do some work (simulate work in main() )
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work in main \n"<< std::endl;
    
    return 0;
}