#include "pch.h"

#include "MaterialPoint.h"

MaterialPoint::MaterialPoint() {
	mass = 1;
}

MaterialPoint::MaterialPoint(const double& M, const Vector2& pos, const Vector2& s, const double& t) {
	mass = M;
	Position = pos;
	Speed = s;
	time_created = t;
}

void MaterialPoint::SetNewPosition(const Vector2& NewPos) {
	Position = NewPos;
}

Vector2 MaterialPoint::UpdatePosition() {
	Position = Position + Speed * 0.01;
	return Position;
	//time_created = time;
}

void MaterialPoint::UpdateTime(const double& t) {
	time_created = t;
}

void MaterialPoint::UpdSpeed(const Vector2& s) {
	Speed = Speed + s;
	//time_created = t;
}

Vector2 MaterialPoint::GetPosition() const {
	return Position;		// +Speed * (t - time_created);
}

Vector2 MaterialPoint::GetSpeed() const {
	return Speed;
}

double MaterialPoint::GetX() const {
	Vector2 pos = Position;		// +Speed * (t - time_created);
	return pos.GetX();
}

double MaterialPoint::GetY() const {
	Vector2 pos = Position;		// +Speed * (t - time_created);
	return pos.GetY();
}

double MaterialPoint::GetSize() const {
	return radius;
}

double MaterialPoint::GetMass() const {
	return mass;
}

Vector2 MaterialPoint::GetImpulse() {
	return Speed * mass;
}

void MaterialPoint::WallCollision(const char& ort) {
	//Position = pos;
	//time_created = t;

	if (ort == 'x') {
		Speed.SetX(-Speed.GetX());
	}
	if (ort == 'y') {
		Speed.SetY(-Speed.GetY());
	}
}

void MaterialPoint::Collision(const Vector2& dP) {
	Speed = Speed + dP / mass;

	//Position = pos;
	//time_created = t;
}

