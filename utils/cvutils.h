#ifndef CVUTILS_H
#define CVUTILS_H

#pragma once

#include "opencv2/opencv.hpp"


class Point{
    public:
    int x,y;
    Point():x(0),y(0){}
    Point(int _x,int _y):x(_x),y(_y){}

    Point operator+(const Point& o){
        return Point(x+o.x,y+o.y);
    }
    Point operator+=(const Point& o){
        x+=o.x;
        y+=o.y;
        return *this;
    }
    Point operator*(const int o){
        return Point(x*o,y*o);
    }
    Point operator-(const Point& o){
        return Point(x-o.x,y-o.y);
    }
    bool operator==(const Point& o){
        return x==o.x&&y==o.y;
    }
    bool operator!=(const Point& o){
        return x!=o.x||y!=o.y;
    }
    bool operator<(const Point& o)const{
        return y<o.y || (y==o.y && x<o.x);
    }

    int norm_1(){return abs(x)+ abs(y);}
    double norm_2(){return sqrt(x*x+y*y);}
};

extern void show(std::string title,int i);
void resize(int x);
void  showResize(std::string title,int i);
extern cv::Vec3b getPixel(int x,int y);
extern void setPixel(int x,int y,cv::Vec3b c);
extern void setBackgroundPixel(int x,int y,cv::Vec3b c);
extern void newFrame(cv::Size size = cv::Size(1000,1000),cv::Scalar c = cv::Scalar(0,0,0));
extern void newBackgroundFrame(cv::Size size = cv::Size(1000,1000),cv::Scalar c = cv::Scalar(0,0,0));
extern void newFrameBW(cv::Size size = cv::Size(1000,1000));
extern void drawText(double x,double y , cv::Scalar c , std::string msg,int s);
extern void drawCircle( double x, double y,double r, cv::Scalar c, std::string msg = "");
extern void drawLine( std::vector<cv::Point> pts , cv::Scalar c, int thickness, std::string msg = "");
extern void saveFrame(std::string title);
extern void showROI(cv::Rect r,std::string title , int i);
extern void showROI(int x,int y,int w,std::string title , int i);

#endif