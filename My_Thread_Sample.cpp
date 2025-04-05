// My_Thread_Sample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<thread>


void thread_function() {
    std::cout << "thread function "<<std::this_thread::get_id() << std::endl;

}

class thread_class {
public:
    void operator()() {
        std::cout << "thread class " << std::this_thread::get_id() << std::endl;
    }

};

void run() {
    std::thread function_Thread(thread_function);

    thread_class tc;
    std::thread classthread(tc);

    std::thread lambda_thread([]() {
        
        std::cout << "lambda_thread" << std::this_thread::get_id() << std::endl;
        
        });


    if (function_Thread.joinable()) { std::cout << "function_thread before join" << function_Thread.joinable()<< std::endl; }
    else { std::cout << "function_thread before join" << function_Thread.joinable() << std::endl; }
    //function_Thread.detach();
    function_Thread.join();
    if (function_Thread.joinable()) { std::cout << "function_thread after join" << function_Thread.joinable() << std::endl; }
    else { std::cout << "function_thread after join" << function_Thread.joinable() << std::endl; }

    if (function_Thread.joinable()) { std::cout << "function_thread after detach" << function_Thread.joinable() << std::endl; }
    else { std::cout << "function_thread after detach" << function_Thread.joinable() << std::endl; }

    classthread.join();
    lambda_thread.join();
    

    std::cout << "run function";
}

int main()
{
    run();  //thread running function
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
