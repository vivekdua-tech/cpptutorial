#ifndef BASESHAPES_H
#define BASESHAPES_H

#include <string>
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

typedef tuple<int, int> point;

class Shape {
	public:

	virtual void Draw() = 0;
	virtual ~Shape() {}
	Shape() {
		++count;
	}

	virtual void DrawPoints(bool forward) {
		for (std::vector<point>::iterator iter =
		    dataPoints.begin(); iter != dataPoints.end(); ++iter) {
		    cout << get<0>(*iter) << "  " << get<1>(*iter) << endl;
	   }
   }

virtual point GetCenterPoint() {
	int totalx = 0;
	int totaly = 0;
	for (std::vector<point>::iterator iter =
		dataPoints.begin(); iter != dataPoints.end(); ++iter) {
		totalx += get<0>(*iter);
		totaly += get<1>(*iter);
	}
return(point(totalx/2, totaly/2));
}
static int GetCount() {
	return count;
}

protected:

	string shapeType;
	vector<point> dataPoints;

	private:
	static int count;

};

int Shape::count = 0;

class Triangle : public Shape {
public:

	Triangle(point p1, point p2, point p3) {
		dataPoints.push_back(p1);
		dataPoints.push_back(p2);
		dataPoints.push_back(p3);
	}
	void Draw() {
		cout << "Drawing Triangle" << endl;
	}
};

class Rectangle : public Shape {
public:

	Rectangle(point p1, point p2, point p3, point p4) {
		dataPoints.push_back(p1);
		dataPoints.push_back(p2);
		dataPoints.push_back(p3);
		dataPoints.push_back(p4);
	}
	void Draw() {
		cout << "Drawing Rectangle" << endl;
	}
};

#endif