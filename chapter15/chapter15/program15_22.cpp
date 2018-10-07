//
//  program15_22.cpp
//  chapter15
//
//  Created by chenyijun on 2017/12/04.
//  Copyright © 2017年 chenyijun. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Figure
{
public:
    Figure(double x, double y)
    :xSize(x), ySize(y)
    {
        
    }
    double getXSize()
    {
        return xSize;
    }
    double getYSize()
    {
        return ySize;
    }
    
protected:
    double xSize, ySize;//图元的尺寸
};

class Figure_2D: public Figure
{
public:
    Figure_2D(double x, double y)
    :Figure(x, y)
    {
        
    }
    virtual double area() = 0;//求面积操作，纯虚函数
    virtual double perimeter() = 0;//求周长操作，纯虚函数
};

class Figure_3D: public Figure
{
public:
    Figure_3D(double x, double y, double z)
    :Figure(x, y), zSize(z)
    {
        
    }
    double getZSize()
    {
        return zSize;
    }
    virtual double cubage() = 0;
    
protected:
    double zSize;
};

class Rectangle: public Figure_2D
{
public:
    Rectangle(double x, double y)
    :Figure_2D(x, y)
    {
        
    }
    virtual double area()
    {
        double dArea = getXSize() * getYSize();
        cout << "Rectangle area============" << dArea << endl;
        return dArea;
        
    }
    virtual double perimeter()
    {
        double dPerimeter = 2 * (getXSize() + getYSize());
        cout << "Rectangle perimeter============" << dPerimeter << endl;
        return dPerimeter;
    }
};

class Circle: public Figure_2D
{
public:
    Circle(double x, double y)
    :Figure_2D(x, y)
    {
        
    }
    virtual double area()
    {
        double dArea = getXSize() * getYSize();
        cout << "Circle area============" << dArea << endl;
        return dArea;
        
    }
    virtual double perimeter()
    {
        double dPerimeter = 2 * (getXSize() + getYSize());
        cout << "Circle perimeter============" << dPerimeter << endl;
        return dPerimeter;
    }

};

class Sphere: public Figure_3D
{
public:
    Sphere(double x, double y, double z)
    :Figure_3D(x, y, y)
    {
        
    }
    virtual double cubage()
    {
        double dCubage = getXSize() * getYSize() * getZSize();
        cout << "Sphere cubage============" << dCubage << endl;
        return dCubage;
    }
};

class Cone: public Figure_3D
{
public:
    Cone(double x, double y, double z)
    :Figure_3D(x, y, y)
    {
        
    }
    virtual double cubage()
    {
        double dCubage = getXSize() * getYSize() * getZSize();
        cout << "Cone cubage============" << dCubage << endl;
        return dCubage;
    }};

int main()
{
    Rectangle *rect = new Rectangle(20, 10);
    rect->area();
    rect->perimeter();
    Circle circle(15, 20);
    circle.area();
    circle.perimeter();
    
    Sphere *sphere = new Sphere(2, 3, 4);
    sphere->cubage();
    
    Cone cone(5, 6, 7);
    cone.cubage();
    
    std::cout << "Hello, World!\n";
    return 0;
}
