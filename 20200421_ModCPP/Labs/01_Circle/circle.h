#ifndef CIRCLE_H
#define CIRCLE_H

#include "baseshapes.h"

class Circle : public Shape {
public:

	Circle(point p1, point p2) {
		dataPoints.push_back(p1);
		dataPoints.push_back(p2);
	}
	~Circle() { cout << "~Circle\n"; }

	void Draw() {
		cout << "Drawing Circle" << endl;
	}
private:
    double m_radius;
};

#endif