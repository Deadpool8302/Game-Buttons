#include "TextBox.hpp"

std::map<std::string, Textbox*>Textbox::Group;

sf::Vector2f Textbox::getPosition()
{
	return rect.getPosition();
}

void Textbox::setUpTextbox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font& font, std::string title, const sf::Color& boxColor)
{
	this->setOrigin(size / 2.f);
	this->setSize(size);
	this->text.setCharacterSize(40);
	this->setPosition(pos);
	this->setFont(font);
	this->setString(title);
	this->setBoxColor(boxColor);
}

Textbox::~Textbox()
{
}

void Textbox::setFont(const sf::Font& font)
{
	text.setFont(font);
}

void Textbox::setString(std::string t)
{
	text.setString(t);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2 + 15);
}

void Textbox::setTextColor(const sf::Color& color)
{
	text.setFillColor(color);
}

void Textbox::setLetterSpacing(float spacing)
{
	text.setLetterSpacing(spacing);
}

void Textbox::setLineSpacing(float spacing)
{
	text.setLineSpacing(spacing);
}

void Textbox::align(int a)
{
	float shift = (rect.getGlobalBounds().width - text.getGlobalBounds().width) / 2;
	text.setPosition(rect.getPosition().x + a*(shift - 6), text.getPosition().y);
}

void Textbox::setBoxColor(const sf::Color& color)
{
	rect.setFillColor(color);
}

void Textbox::setOutlineColor(const sf::Color& color)
{
	rect.setOutlineColor(color);
}

void Textbox::setOutlineThickness(float t)
{
	rect.setOutlineThickness(t);
}

void Textbox::setTexture(const sf::Texture* texture)
{
	rect.setTexture(texture);
}

void Textbox::setTextureRect(const sf::IntRect& bound)
{
	rect.setTextureRect(bound);
}

void Textbox::setOrigin(const sf::Vector2f& origin)
{
	rect.setOrigin(origin);
}

void Textbox::setSize(const sf::Vector2f& size)
{
	rect.setSize(size);
}

void Textbox::setPosition(const sf::Vector2f& pos)
{
	text.setPosition(pos);
	rect.setPosition(pos);
}

void Textbox::move(const sf::Vector2f& d)
{
	rect.move(d);
	text.move(d);
}

sf::FloatRect Textbox::getGlobalBounds()
{
	return rect.getGlobalBounds();
}

Textbox* Textbox::create(const sf::Vector2f& pos, const sf::Vector2f& size,const sf::Font& font, std::string title,const sf::Color& boxColor)
{
	Textbox* ptr = new Textbox;
	ptr->setUpTextbox(pos, size, font, title, boxColor);
	return ptr;
}


void Textbox::draw(sf::RenderWindow& win)
{
	win.draw(text);
	win.draw(rect);
}
