#include <iostream>

using namespace std;

class Shape {
private:
	int point_count_;
	int x_;
	int y_;
public:
	Shape(int point_count,int x,int y)
		:point_count_(point_count),x_(x),y_(y)
	{

	}
	int get_point_count(int point_count) {
		return point_count;
	}
	void  get_position(int x,int y) {
		x_ = x;
		y_ = y;
	}
	void draw() {
		cout << "Shape draw" << endl;
	}
	virtual ~Shape() {}
};
class RectangleShape : public Shape {
private:
	int width_;
	int height_;

	RectangleShape(int point_count,int x,int y,int width,int height)
		: Shape(point_count,x,y),width_(width), height_(height)
	{
	}
	void draw() {
		cout << "Rectangle Shape draw" << endl;
	}
};
class CircleShape : public Shape {
private:
	int radius_;
	CircleShape(int point_count, int x, int y, int radius) 
	:Shape(point_count,x,y),radius_(radius)
	{
	}
	void draw() {
		cout << "CIrcle Shape draw" << endl;
	}
};
int main() {

}