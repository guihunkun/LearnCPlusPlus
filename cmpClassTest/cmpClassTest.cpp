#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <math.h>
#include <iomanip>

using namespace std;

const double EPS = 1;

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
    double x = p.getX();
    double y = p.getY();
    double dis = (_x-x)*(_x-x) + (_y-y)*(_y-y);
    dis = sqrt(dis);
    return dis > EPS;
}


class lessCmpTest
{
public:
    lessCmpTest(const double eps = 0.1) : _eps(fabs(eps)) {}
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
    dis = sqrt(dis);
    return dis > _eps;
}

void generatePoint(set<Point, lessCmpTest>& record)
{
    record.clear();
    record.insert(Point(0, 0));
    record.insert(Point(0, 0.1));
    record.insert(Point(0, 2));
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

    set<Point> rec;
    rec.insert(Point(0, 0));
    rec.insert(Point(1, 1));
    rec.insert(Point(0, 1));

    for(set<Point>::iterator iter = rec.begin(); iter != rec.end(); iter++) {
        cout<<(*iter).getX()<<" "<<(*iter).getY()<<endl;
    }

    lessCmpTest cmperGreat(1);
    lessCmpTest cmperSmall(0.01);

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
