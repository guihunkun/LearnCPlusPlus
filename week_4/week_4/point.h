#ifndef _MY_POINT_H_
#define _MY_POINT_H_
#include <iostream>
#include <vector>
using namespace std;

class MyPoint {

private:
 double m_x;
 double m_y;

public:
	MyPoint();
	MyPoint(int x, int y) : m_x(x), m_y(y) { }
	
	void setX(int x) {m_x = x;}
	void setY(int y) {m_y = y;}
	int x() const {return m_x;}
	int y() const {return m_y;}
	void getXY(int& x, int& y) 
	{
		x = m_x;
		y = m_y;
	}
};

//请判断两个点列数组是否相交。 
bool isIntersectArray(const vector<MyPoint>& fstVec, const vector<MyPoint>& scdVec);

 

 


#endif
