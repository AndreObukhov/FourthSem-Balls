// Balls.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "SFML/Graphics.hpp"
#include "V2.h"
#include "MaterialPoint.h"

#include <iostream>
#include <vector>


bool IsInsideWindow(sf::Vector2u WSize, const Vector2& Position) {
	if (Position.GetX() >= 10 && Position.GetY() >= 10 &&
		Position.GetX() <= WSize.x && Position.GetY() <= WSize.y) {
		return true;
	}
	else {
		return false;
	}
}

//добавить передачу размера шарика == сделано
void WallCollision(sf::Vector2u WSize, MaterialPoint& ball) {
	if (ball.GetX() <= ball.GetSize() || ball.GetX() >= WSize.x - ball.GetSize()) {
		ball.WallCollision('x');
	}

	if (ball.GetY() <= ball.GetSize() || ball.GetY() >= WSize.y - ball.GetSize()) {
		ball.WallCollision('y');
	}
}

bool AreColliding(const Vector2& d, const MaterialPoint& p1, const MaterialPoint& p2) {
	//Vector2 d = distance(p1.GetPosition(), p2.GetPosition());
	if ((d.Length() <= (p1.GetSize() + p2.GetSize()) ) && ((p2.GetSpeed() - p1.GetSpeed()) * d < 0)) {
			std::cout << "COLL" << std::endl;
			return true;
	}
	return false;
}

Vector2 CountdP(Vector2& d, const MaterialPoint& P1, const MaterialPoint& P2) {
	Vector2 dV = P2.GetSpeed() - P1.GetSpeed();
	Vector2 n = d / d.Length();
	double MassFactor = (1.0 / P1.GetMass()) + (1.0 / P2.GetMass());
	return n * (2 * (dV * n) / MassFactor);
}

void Collision(std::vector<MaterialPoint>& balls) {

	for (unsigned i = 0; i < balls.size() - 1; i++) {
		
		for (unsigned j = i + 1; j < balls.size() ; j++) {

			Vector2 d = distance(balls[i].GetPosition(), balls[j].GetPosition());
			//std::cout << d.Length() << std::endl;

			if (AreColliding(d, balls[i], balls[j])) {

				/*Vector2 dV = balls[j].GetSpeed() - balls[i].GetSpeed();

				double MassFactor = (1.0 / balls[i].GetMass()) + (1.0 / balls[j].GetMass());

				dV = dV * (2.0 / MassFactor);

				Vector2 N = d / d.Length();

				//std::cout << N.Length() << std::endl;

				Vector2 dP = N * (dV * N);
				*/

				Vector2 dP = CountdP(d, balls[i], balls[j]);

				balls[i].Collision(dP * (-1.0));
				balls[j].Collision(dP);

				//balls[i].UpdSpeed(dP /(balls[i].GetMass()*(-1.0)), t);
				//balls[j].UpdSpeed((dP / balls[j].GetMass()), t);

				//std::cout << balls[i].GetSpeed() << std::endl;
			}
		}
	}
}

int main()
{
	std::vector<MaterialPoint> balls;
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1500, 900), "BIG Ballz.");

	while (window.isOpen())
	{
		sf::Time time = clock.getElapsedTime();

		window.clear(sf::Color::Black);

		if (balls.size() > 1) {
			Collision(balls);
		}

		for (auto& b : balls) {
			WallCollision(window.getSize(), b);

			Vector2 pos = b.UpdatePosition();

			sf::CircleShape Ch(25.f);

			Ch.setPosition(pos.GetX() - 25.0, pos.GetY() - 25.0);
			Ch.setFillColor(sf::Color::White);
			
			window.draw(Ch);
		}

		sf::Event event;
		sf::Vector2i MousePos = sf::Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonReleased) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					balls.push_back(MaterialPoint(20.0, Vector2(MousePos.x, MousePos.y), 
						Vector2(-350.0, 200.0), time.asSeconds()));
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {		//clearing the picture
			balls.clear();
		}

		//Vector2 MP(MousePos.x, MousePos.y);

		/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			balls.push_back(MaterialPoint(20.0, Vector2(MousePos.x, MousePos.y), Vector2(-2.0, 1.0), time.asSeconds()));
		}*/

		window.display();
	}


    std::cout << "Hello World!\n"; 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
