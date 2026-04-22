#include <SFML/Graphics.hpp>
#include <iostream>
#include "../cmake-build-debug/_deps/sfml-src/src/SFML/Window/InputImpl.hpp"

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "SFML works!" );
	sf::CircleShape shape( 40.f );
	shape.setFillColor( sf::Color::Green );
	const sf::Texture texture("../../rat2.jpg");
	sf::Sprite sprite(texture);
	sf::Angle angle = sf::degrees(90);

	while ( window.isOpen() )
	{
		while ( const std::optional event = window.pollEvent() )
		{
			if ( event->is<sf::Event::Closed>() )
				window.close();
		}

		window.clear();
		window.draw( sprite );
		window.display();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			sprite.move({0.f,-1.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			sprite.move({0.f,1.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			sprite.move({-1.f,0.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			sprite.move({1.f,0.f});
		} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
			sprite.setRotation(sprite.getRotation()+angle);
		}
	}
	std::cout << "Hello word!" << '\n';
}
