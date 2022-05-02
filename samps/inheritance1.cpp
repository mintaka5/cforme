#include <iostream>

using namespace std;

class Polygon
{
    protected:
        int width, height;
    public:
        void setValues(int w, int h)
        {
            width = w;
            height = h;
        }
};

class Output
{
    public:
        int output(int);
};

int Output::output(int i)
{
    return i;
}

class Rectangle: public Polygon, public Output
{
    public:
        int area()
        {
            return width * height;
        }
};

class Triangle: public Polygon, public Output
{
    public:
        int area()
        {
            return (width * height / 2);
        }
};

int main()
{
    Rectangle rect;
    Triangle tri;
    rect.setValues(6, 4);
    tri.setValues(6, 4);

    cout << "area of rectangle is: " << rect.output(rect.area()) << endl;

    cout << "area of triangle is: " << tri.output(tri.area()) << endl;

    return 0;
}