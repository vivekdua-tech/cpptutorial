#include <iostream>

struct String final
{
    // no virtual
};

//struct mystring : public String
//{};
struct Shape
{
    virtual void draw() const { std::cout << "Shape draw\n"; }
    virtual void scale() final {}
    void rotate() {std::cout << "Shape rotate\n";}
    virtual ~Shape() = default;
};

struct Circle : public Shape
{
    void draw() const override { std::cout << "Circle draw\n"; }
    //void scale()  { std::cout << "Circle draw\n"; }
    void rotate()  { std::cout << "Circle rotate\n"; }

    bool override = false;
};


int main()
{
    auto c = Circle{};
    Shape * s = &c;

    s->draw();
    s->rotate();
    c.rotate();
}