#include "baseshapes.h"
#include "circle.h"

void renderShape(Shape* s)
{
    s->Draw();
    point center = s->GetCenterPoint();
    cout << "(" << get<0>(center) << ", " << get<1>(center) << ")\n";
}

void release(Shape* s)
{
    delete s;
}

int main()
{
    vector<Shape*> shapes;
    point p1(0,0), p2(2,2), p3(0,4), p4(5,2);
    point c1(0,4), c2(4,4), c3(4,0), c4(0,0);
    shapes.push_back(new Triangle(p3, p2, p1));
    shapes.push_back(new Rectangle(p1,p4,p3,p2));
    shapes.push_back(new Circle(c1,c3));

    for_each(shapes.begin(), shapes.end(), renderShape);

    for_each(shapes.begin(), shapes.end(), release);
}