#ifndef FIRSTLEVELSTATE_H
#define FIRSTLEVELSTATE_H

class StateMachine;

#include "State.h"

#include "SFML/Graphics.hpp"

namespace sf {
	class RenderWindow;
}

class FirstLevelState : public State {
	public:
		FirstLevelState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);
		

		void pause();
		void resume();
		
		void update();
		void render();

	private:
		sf::Event sfEvent;
};

#endif