#ifndef TUTORIALLEVELSTATE_H
#define TUTORIALLEVELSTATE_H

#include "State.h"

#include "SFML/Graphics.hpp"

class StateMachine;

namespace sf {
	class RenderWindow;
}

class TutorialLevelState : public State {
	public:
		TutorialLevelState(StateMachine& game, sf::RenderWindow& window, bool replace = true);

		void pause();
		void resume();

		void update();
		void render();

	private:
		sf::Event sfEvent;
};

#endif // INTROSTATE_HPP