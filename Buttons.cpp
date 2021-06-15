#include "Buttons.hpp"

std::map<std::string, Button*>Button::Group;
Button* Button::mouseHoveringOn = nullptr;
Button* Button::clicked = nullptr;
sf::Mouse::Button Button::pressedMouseButton;

Button::~Button()
{
}

Button* Button::create(const sf::Vector2f& pos, const sf::Vector2f& size, const sf::Font& font, std::string title, const sf::Color& boxColor)
{
	Button* ptr = new Button;
	ptr->currState = State::ORIGINAL;
	ptr->setUpTextbox(pos,size,font,title,boxColor);
	return ptr;
}

bool Button::contains(sf::Vector2f& mPos)
{
	if (mPos.x >= this->getGlobalBounds().left
		&& mPos.x <= this->getGlobalBounds().left + this->getGlobalBounds().width
		&& mPos.y >= this->getGlobalBounds().top
		&& mPos.y <= this->getGlobalBounds().top + this->getGlobalBounds().height) return true;
	return false;
}

void Button::updateProperties(State state) 
{	
	if (state != currState) {
		if (state == State::ORIGINAL) setBoxColor(sf::Color::Transparent);
		else if (state == State::SELECTED) setBoxColor(sf::Color((126, 126, 126, 100)));
		currState = state;
	}
}

void Button::setAction(const std::function<void()>& func)
{
	action = func;
}

Button::State Button::getButtonState()
{
	return currState;
}

Button* Button::clickable(sf::Vector2f& mPos)
{
	for (auto it = Button::Group.begin(); it != Button::Group.end(); it++) {
		if (it->second->contains(mPos)) return it->second;
	}
	return nullptr;
}

void Button::updateAllProperties(sf::Vector2f& mPos)
{
	Button* currMouseHoveringOn = nullptr;

	if (Button::mouseHoveringOn == nullptr && Button::clickable(mPos) != nullptr) {
		currMouseHoveringOn = Button::clickable(mPos);
		currMouseHoveringOn->updateProperties(Button::State::SELECTED);
	}
	else if (Button::mouseHoveringOn != nullptr && Button::clickable(mPos) == nullptr) {
		currMouseHoveringOn = Button::mouseHoveringOn;
		currMouseHoveringOn->updateProperties(Button::State::ORIGINAL);
	}

}

void Button::registerClick(sf::Mouse::Button button)
{
	Button::clicked = Button::mouseHoveringOn;
	Button::pressedMouseButton = button;
}
