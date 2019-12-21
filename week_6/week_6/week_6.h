//
//  week_6.h
//  week_6
//
//  Created by 曲晓昆 on 2019/12/21.
//  Copyright © 2019 曲晓昆. All rights reserved.
//

#ifndef WEEK_6_H
#define WEEK_6_H

const double PI = 3.1415926;

class String
{
  
public:
    String(const char *str = NULL);
    String(const String& other);
    ~String(void);
    String & operator = (const String &other);
    
public:
    int getLength();
    
private:
    char *m_data;
    
};


struct Point
{
    double x, y;
    void set(double _x, double _y);
};


class Shape
{
public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
    virtual void printShapeInfo() = 0;
    virtual void showShape() = 0;
    
};


class Circle: public Shape
{
private:
    Point o;
    double r;
public:
    Circle(Point a, double _r);
    double getArea();
    double getPerim();
    void printShapeInfo();
    void showShape();
    ~Circle();
};

class Square: public Shape
{
private:
    double left, right, bot, top;
public:
    Square(double l, double r, double b, double t);
    double getArea();
    double getPerim();
    void printShapeInfo();
    void showShape();
    ~Square();
};



class Rectangle: public Shape
{
private:
    double left, right, bot, top;
public:
    Rectangle(double l, double r, double b, double t);
    double getArea();
    double getPerim();
    void printShapeInfo();
    void showShape();
    ~Rectangle();
};


class Trapezoid: public Shape
{
/*
     p4______________p3
      /              \
     /                \
    /                  \
   /                    \
  /                      \
 /________________________\
 p1                        p2
 
 */
private:
    Point p1, p2, p3, p4;
public:
    Trapezoid(Point a, Point b, Point c, Point d);
    double getArea();
    double getPerim();
    void printShapeInfo();
    void showShape();
    ~Trapezoid();
};


class Triangle: public Shape
{
private:
    Point p1, p2, p3;
public:
    Triangle(Point a, Point b, Point c);
    double getArea();
    double getPerim();
    void printShapeInfo();
    void showShape();
    ~Triangle();
};



#endif /* week_6_h */
