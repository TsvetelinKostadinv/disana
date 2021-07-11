#include <iostream>
#include <string>

std::string test()
{
    return "Hello World";
}

int main()
{
    std::cout << test() << std::endl;
    return 0;
}