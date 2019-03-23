#pragma once

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "V2.h"
#include <cmath>
#include <iostream>


class MaterialPoint {
public:
	MaterialPoint();
	MaterialPoint(const double& M, const Vector2& pos, const Vector2& s, const double& t);

	void SetNewPosition(const Vector2& NewPos);

	Vector2 UpdatePosition();

	void UpdateTime(const double& t);

	void UpdSpeed(const Vector2& s);

	Vector2 GetPosition() const;

	Vector2 GetSpeed() const;
	Vector2 GetImpulse();

	double GetX() const;
	double GetY() const;

	double GetSize() const;
	double GetMass() const;

	void WallCollision(const char& ort);

	void Collision(const Vector2& dP);

private:
	double radius = 25.0;
	double time_created;
	double mass;
	Vector2 Position;
	Vector2 Speed;
};