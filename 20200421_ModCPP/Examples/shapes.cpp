#include <iostream>
#include <vector>

struct Shape
{
    virtual void draw() const = 0;
    virtual ~Shape() { std::cout << "~Shape\n"; }
};

//class Circle : Shape // implicity private
struct Circle : Shape // implicity public
{
    void draw() const { std::cout << "Circle draw\n"; }
    ~Circle() { std::cout << "~Circle\n"; }
};


struct Line : Shape // implicity public
{
    void draw() const { std::cout << "Line draw\n"; }
    ~Line() { std::cout << "~Line\n"; }
};


void render(std::vector<Shape*> shapes) {
    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        (*it)->draw();
    }
}

int main()
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Line);
    shapes.push_back(new Circle);
    shapes.push_back(new Circle);

    render(shapes);

    for (auto it = shapes.begin(); it != shapes.end(); ++it) {
        delete *it;
    }
}