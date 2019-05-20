#include "FirstLevelState.h"

#include "StateMachine.h"
#include "TutorialLevelState.h"

#include <iostream>
#include <memory>

FirstLevelState::FirstLevelState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace } {

	std::cout << "first level state\n";
}

void FirstLevelState::pause() {
}

void FirstLevelState::resume() {
}

void FirstLevelState::update() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch (sfEvent.key.code) {
					case sf::Keyboard::Escape:
						machine.quit();
						break;

					case sf::Keyboard::M:
						next = StateMachine::build<TutorialLevelState>(machine, window, false);
						break;

					default:
						break;
				}

			default:
				break;
		}
	}

}

void FirstLevelState::render() {
	window.clear();

	//Render items



	window.display();
}
