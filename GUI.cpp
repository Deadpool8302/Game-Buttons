#include "GUI.hpp"

template<typename T>
void rendergroup(std::map<std::string, T*>& group, sf::RenderWindow& win) {
	for (auto it = group.begin(); it != group.end(); it++) {
		it->second->draw(win);
	}
}

template<typename T>
void deleteGroup(std::map<std::string, T*>& group) {
	for (auto it = group.begin(); it != group.end(); it++) {
		delete it->second;
	}
	group.clear();
}

void gui::render(sf::RenderWindow& win)
{
	rendergroup(Textbox::Group, win);
	rendergroup(Button::Group, win);
}

void gui::deleteAllGuiGroups()
{
	deleteGroup(Textbox::Group);
	deleteGroup(Button::Group);
}
