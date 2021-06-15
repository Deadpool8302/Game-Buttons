#pragma once
#include<SFML/Graphics.hpp>
#include"TextBox.hpp"
#include<map>
#include<iostream>
#include<functional>

class Button:public Textbox {
public:
	~Button();
	static std::map<std::string, Button*> Group;
	static Button* create(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font&, std::string title, const sf::Color& boxColor);

	enum class State{ORIGINAL,SELECTED};


	bool contains(sf::Vector2f&);
	void updateProperties(State);
	void setAction(const std::function<void()>& func);
	State getButtonState();
	std::function<void()> action;

	static Button* clickable(sf::Vector2f& mPos);
	static void updateAllProperties(sf::Vector2f&);
	static void registerClick(sf::Mouse::Button);
	static Button* mouseHoveringOn;
	static Button* clicked;
	static sf::Mouse::Button pressedMouseButton;

private:
	State currState;
};