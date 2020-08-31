#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>

using namespace std;


class Point
{
public:
    Point(const double x = 0, const double y = 0) : _x(x), _y(y) {}
    void setX(const double x) {_x = x;}
    void setY(const double y) {_y = y;}
    const double getX() const {return _x;}
    const double getY() const {return _y;}
    bool operator < (const Point& p) const;

private:
    double _x, _y;
};

bool Point::operator < (const Point& p) const
{
    const double EPS = 1e-5;
    double x = p.getX();
    double y = p.getY();
    double dis = (_x-x)*(_x-x) + (_y-y)*(_y-y);
    if(fabs(dis-EPS) < 1e-10)
        return true;
    return false;
}

class lessCmpTest
{
public:
    lessCmpTest(const double eps = 0.0) : _eps(fabs(eps)) {}
public:
    bool operator() (const Point& p1, const Point& p2) const;

private:
    const double _eps;
};


bool lessCmpTest::operator() (const Point& p1, const Point& p2) const
{
    double x1 = p1.getX();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double y2 = p2.getY();
    double dis = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return (dis >= (_eps*_eps));
}

void generatePoint(set<Point, lessCmpTest>& record)
{
    Point p;

    p = Point(1.0, 1.0);
    record.insert(p);
    p = Point(1.0, 1.009);
    record.insert(p);
    p = Point(1.0, 1.0000001);
    record.insert(p);
}

void printPoints(set<Point, lessCmpTest>& record)
{
    double x, y;
    set<Point, lessCmpTest>::iterator iter = record.begin();
    for(; iter != record.end(); iter++)
    {
        x = (*iter).getX();
        y = (*iter).getY();
        printf("%.10f %.10f", x, y);
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    lessCmpTest cmperGreat(0.01);
    lessCmpTest cmperSmall(0.00001);

    set<Point, lessCmpTest> tmpG(cmperGreat);
    set<Point, lessCmpTest> tmpS(cmperSmall);

    cout<<"cmperGreat"<<endl;
    generatePoint(tmpG);
    printPoints(tmpG);

    cout<<"cmperSmall"<<endl;
    generatePoint(tmpS);
    printPoints(tmpS);


    return 0;
}
