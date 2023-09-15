#include <iostream>
#include <string>
#include <memory>

class Entity
{
    int x;
public:
    Entity()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    ~Entity()
    {
        std::cout << "Deleted Entity!" << std::endl;
    }

    void Print() const
    {
        std::cout << "Hello!aa" << std::endl;
    }
};

class ScopedPtr
{
public:
    Entity* m_Obj;
 
public:
    ScopedPtr(Entity* entity)
        : m_Obj(entity)
        {

        }
    ~ScopedPtr()
    {
        delete m_Obj;
    }
    Entity* GetObject()
    {
        return m_Obj;
    }
    // reload -> operator
    const Entity* operator->() const
    {
        return m_Obj;
    }

};

class Ent1
{
public:
    float x, y;

    Ent1(float intX, float intY)
        : x(intX), y(intY)
        {

        }

};

class Ent2
{
public:
    Ent1* e;
    Ent2(Ent1* intE)
        : e(intE)
        {

        }

};


int main()
{   
    ScopedPtr entity(new Entity());
    entity->Print();

    // Ent2 ent2(new Ent1(2.0,3.0));


    // std::cout << ent2.e->x << std::endl;

   std::cin.get();
}