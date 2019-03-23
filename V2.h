#pragma once
#include "pch.h"

#include<cmath>

#include <iostream>

class Vector2 {
public:
	Vector2();
	Vector2(const double& x1, const double& y1);
	double GetX() const;
	double GetY() const;
	void SetX(const double& new_x);
	void SetY(const double& new_y);
	double Length() const;
	//Vector2 Norm() const;
	//Vector2 GetNorm();

	//Vector2 operator*(const double& num);

	double operator*(const Vector2& other);
private:
	double x;
	double y;
};

Vector2 distance(const Vector2& lhs, const Vector2& rhs);

Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

Vector2 operator-(const Vector2& lhs, const Vector2& rhs);

Vector2 operator*(const Vector2& rhs, const double& num);

Vector2 operator/(const Vector2& rhs, const double& num);

std::ostream& operator << (std::ostream& os, const Vector2& vect);