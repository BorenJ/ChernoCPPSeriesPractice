#include <iostream>
#include <string>
#include <memory>
#include <vector>

 struct Vertex
 {
    float x, y, z;
 };

std :: ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
    stream << vertex.x << "," << vertex.y << "," << vertex.z;
    return stream;
}

void FunctionRef(const std::vector<Vertex>& vertices)
{

}

void FunctionPtr(const std::vector<Vertex>* vertices)
{

}

 int main()
 {
    // Vertex* vertices = new Vertex[5];
    // Vertex v[5];
    // v[0].x = 1.0;
    // v[0].y = 2.0;
    // v[0].z = 3.0;
    // v[1].x = 4.0;
    // v[1].y = 5.0;
    // v[1].z = 6.0;
    // std::cout << v[0].x << std::endl;

    std::vector<Vertex> vertices; 
    vertices.push_back({1, 2, 3});
    vertices.push_back({4, 5, 6});
    vertices.push_back({7, 8, 9});
    FunctionRef(vertices);
    FunctionPtr(&vertices);
    
    for (int i = 0; i < vertices.size(); i++)
        std::cout << vertices[i] << std::endl;
    
    vertices.erase(vertices.begin() + 1);

    for (Vertex v : vertices)
        std::cout << v << std::endl;


    std::vector<int> arr;
    arr.push_back(6);
    arr.push_back(66);
    arr.push_back(666);

for (int a : arr)
    std::cout << a << std::endl;
    

 }