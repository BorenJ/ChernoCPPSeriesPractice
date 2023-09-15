#include <iostream>
#include <string>
#include <memory>
#include <vector>

 struct Vertex
 {
    float x, y, z;
    Vertex(float initX, float initY, float initZ)
        : x(initX), y(initY), z(initZ)
        {
    
        }
    Vertex(const Vertex& vertex)
    {
        std::cout << "Copied!" << std::endl;
    }
 };

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

int main()
{
    std::vector<Vertex> vertices;
    vertices.reserve(3);
    vertices.emplace_back(1,2,3);
    vertices.emplace_back(4,5,6);
    vertices.emplace_back(Vertex(7,8,9));

    std::cout << multiple(3,2,"result").name << multiple(3,2,"result").x << std::endl;



    std::cin.get();
}
