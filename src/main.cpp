#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window( sf::VideoMode( { 800, 800 } ), "SFML works!" );
	window.setFramerateLimit(60);
	sf::CircleShape shape( 400.f );
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
	}
	std::cout << "Hello word!" << '\n';
}
