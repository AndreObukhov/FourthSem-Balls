#include "pch.h"

#include "V2.h"

Vector2::Vector2() {
	x = 0;
	y = 0;
}

Vector2::Vector2(const double& x1, const double& y1) {
	x = x1;
	y = y1;
}

double Vector2::GetX() const {
	return x;
}

double Vector2::GetY() const {
	return y;
}

void Vector2::SetX(const double& new_x) {
	x = new_x;
}

void Vector2::SetY(const double& new_y) {
	y = new_y;
}

double Vector2::Length() const{
	return sqrt(x * x + y * y);
}
/*
Vector2 Vector2::Norm() const {
	return Vector2
}*/


/*Vector2 Vector2::operator*(const double& num) {
	return Vector2(x * num, y * num);
}*/

Vector2 distance(const Vector2& lhs, const Vector2& rhs) {
	Vector2 d = rhs - lhs;
	return d;
}

double Vector2::operator*(const Vector2& other) {
	return (x * other.GetX()) + (y * other.GetY());
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
}

Vector2 operator*(const Vector2& lhs, const double& num) {
	return Vector2(lhs.GetX() * num, lhs.GetY() * num);
}

Vector2 operator/(const Vector2& lhs, const double& num) {
	return Vector2(lhs.GetX() / num, lhs.GetY() / num);
}

std::ostream& operator << (std::ostream& os, const Vector2& vect) {
	os << "(" << vect.GetX() << " " << vect.GetY() << ")";
	return os;
}