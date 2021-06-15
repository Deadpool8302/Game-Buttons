#include<SFML/Graphics.hpp>
#include"TextBox.hpp"
#include"Buttons.hpp"
#include"GUI.hpp"
#include<iostream>

int main() {
	sf::RenderWindow window;
	window.create(sf::VideoMode(700, 500), "Buttons");

	sf::Font font;
	font.loadFromFile("assets/Amel Brush Font.ttf");
	Button::Group["first"] = Button::create({ 300, 250 }, { 140, 50 }, font, "Hello", sf::Color::Transparent);
	Button::Group["first"]->setOutlineColor(sf::Color::Blue);
	Button::Group["first"]->setOutlineThickness(2);
	Button::Group["first"]->setAction([] {std::cout << "Hello"; });

	Button::Group["second"] = Button::create({ 500, 250 }, { 140, 50 }, font, "world", sf::Color::Transparent);
	Button::Group["second"]->setOutlineColor(sf::Color::Blue);
	Button::Group["second"]->setOutlineThickness(2);
	Button::Group["second"]->setAction([] {std::cout << "world"; });

	Button::Group["third"] = Button::create({ 300, 100 }, { 140, 50 }, font, "bhavye", sf::Color::Transparent);
	Button::Group["third"]->setOutlineColor(sf::Color::Blue);
	Button::Group["third"]->setOutlineThickness(2);
	Button::Group["third"]->setAction([] {std::cout << "bhavye"; });


	sf::Color color;
	sf::Vector2f mPos;
	while (window.isOpen()) {

		sf::Event event;

		mPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

		while (window.pollEvent(event)) {    
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) Button::registerClick(event.mouseButton.button);

			if (Button::mouseHoveringOn != nullptr ) {
				if (event.type == sf::Event::MouseButtonReleased && Button::pressedMouseButton == sf::Mouse::Button::Left) {
					if (Button::clicked == Button::mouseHoveringOn) Button::mouseHoveringOn->action();
				}
			}

			if (event.type == sf::Event::MouseMoved) {
				Button::updateAllProperties(mPos);
			}
		}

		Button::mouseHoveringOn = Button::clickable(mPos);

		window.clear(color);
		gui::render(window);
		window.display();
	}

	gui::deleteAllGuiGroups();
}