#include <SFML/Graphics.hpp>
#include <iostream>
#include "../cmake-build-debug/_deps/sfml-src/src/SFML/Window/InputImpl.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw( shape );
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			shape.move({0.f,-1.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			shape.move({0.f,1.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			shape.move({-1.f,0.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			shape.move({1.f,0.f});
		}
	}
	std::cout << "Hello word!" << '\n';
}
