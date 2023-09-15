#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <array>
// Using structure to return multi type data
struct MultiType
{
    float x;
    std::string name;
};
 MultiType multiple(const float& x, const float& y, const std::string& name)
 {
    float z = x * y;
    return {z, name};
 }

std::string* stringArr(const std::string& A, const std::string& B)
{
    std::string* name = new std::string[2];
    name[0] = A;
    name[1] = B;
    return name;

}

int main()
{
    std::cout << multiple(3,2,"result").name << multiple(3,2,"result").x << std::endl;
    
    std::cout << stringArr("Brett", "Blake") << std::endl;

    int ne[5] = {11, 22, 33, 44, 55};
    int* neP = new int[5]{11, 22, 33, 44, 55};

    for(const int& arr:ne)
    {
        std::cout << arr << std::endl;
        
    }
    std::cout << ne[1] << std::endl;
    std::cout << neP[1] << std::endl;
    
    std::array<float, 5> Traj;
    Traj[0] = 1;

    std::cin.get();
}
