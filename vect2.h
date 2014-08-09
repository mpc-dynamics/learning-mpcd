/****************************************************************************
**
** Copyright (C) 2014 Sparisoma Viridi
** Copyright (C) 2014 Dhi Aurrahman
** Contact: viridi@fkt.physik.tu-dortmund.de
**
** This file is part of the Learning MPCD and Other Things: A Posdoc Journal
**
** $MCPD_BEGIN_LICENSE:CCATTR4_0$
**
** You may use this file under the terms of the 
** Creative Commons Attribution 4.0 International License
** http://creativecommons.org/licenses/by/4.0/legalcode.txt
**
** $MCPD_END_LICENSE$
**
****************************************************************************/

#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream>
#include <sstream>
#include <math.h>

/**
 * Two dimensional vector structure
 */
struct vect2
{

  double x;
  double y;

  vect2(double x, double y) : x(x), y(y){}

  double r(){
    return sqrt(this->x * this->x + this->y * this->y);
  }

  vect2 * add(const vect2 * vect){
    this->x += vect->x;
    this->y += vect->y;
    return this;
  }

  vect2 * sub(const vect2 * vect){
    this->x -= vect->x;
    this->y -= vect->y;
    return this;
  }

  vect2 * rotate(const double & alpha){
    double theta = this->dir() + alpha;
    double r = this->r();
    this->x = r * cos(theta);
    this->y = r * sin(theta);
    return this;
  }

  vect2 * mult(const double & s){
    this->x *= s;
    this->y *= s;
    return this;
  }

  double cross(const vect2 * vect){
    return this->x * vect->y - this->y * vect->x;
  }

  double dot(const vect2 * vect){
    return this->x * vect->x + this->y + vect->y;
  }

  double dir(){
    double theta;
    if(y >= 0) {
        theta = acos (this->x / this->r());
    } else if (x >= 0){
        theta = asin (this->y / this->r()) + 2 * M_PI;
    } else {
        theta = 2 * M_PI - acos(this->x / this->r());
    }
    return theta;
  }

  void print(){
    std::cout << "(" << this->x << ", " << this->y << ")" << std::endl;
  }

  std::string str(){
    std::stringstream buf;
    buf << "(" << this->x << ", " << this->y << ")";
    return buf.str();
  }

};

#endif

