#include "TutorialLevelState.h"

#include "StateMachine.h"

#include "FirstLevelState.h"

#include <memory>
#include <iostream>

TutorialLevelState::TutorialLevelState(StateMachine& machine, sf::RenderWindow& window, bool replace)
	: State{ machine, window, replace } {

	std::cout << "Tutorail level Init\n";
}

void TutorialLevelState::pause() {
	std::cout << "Pause Init\n";
}

void TutorialLevelState::resume() {
	std::cout << "Resume Init\n";
}

void TutorialLevelState::update() {
	while (window.pollEvent(sfEvent)) {
		switch (sfEvent.type) {
			case sf::Event::Closed:
				machine.quit();
				break;

			case sf::Event::KeyPressed:
				switch (sfEvent.key.code) {
					case sf::Keyboard::Space:
						next = StateMachine::build<FirstLevelState>(machine, window, true);
						break;

					case sf::Keyboard::Escape:
						machine.quit();
						break;
				}

				break;
		}
	}
}

void TutorialLevelState::render() {
	window.clear();

	//Render items


	window.display();
}
