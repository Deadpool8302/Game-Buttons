#pragma once
#include<SFML/Graphics.hpp>
#include<map>
#include<string>
#include<vector>

class Textbox {
	sf::RectangleShape rect;
	sf::Text text;

protected:
	void setUpTextbox(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font&, std::string title, const sf::Color& boxColor);

public:
	virtual ~Textbox();

	enum {LEFT = -1,CENTER,RIGHT};

	void setFont(const sf::Font&);
	void setString(std::string);
	void setTextColor(const sf::Color&);
	void setLetterSpacing(float);
	void setLineSpacing(float);
	void align(int);

	void setBoxColor(const sf::Color&);
	void setOutlineColor(const sf::Color&);
	void setOutlineThickness(float);
	void setTexture(const sf::Texture*);
	void setTextureRect(const sf::IntRect&);
	void setOrigin(const sf::Vector2f&);
	void setSize(const sf::Vector2f&);
	
	void setPosition(const sf::Vector2f&);
	void move(const sf::Vector2f&);

	sf::FloatRect getGlobalBounds();
	sf::Vector2f getPosition();

	void draw(sf::RenderWindow&);

	static Textbox* create(const sf::Vector2f& pos, const sf::Vector2f& size,const sf::Font& ,std::string title,const sf::Color& boxColor);

	static std::map<std::string,Textbox*> Group;
};