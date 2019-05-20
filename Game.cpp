#include "Game.h"



void Game::run() {
	window.create(sf::VideoMode(1000, 900), "StateEngine Testing");
	window.setPosition({ window.getPosition().x, window.getPosition().y - 50 });
	window.setFramerateLimit(120);


	machine.run(StateMachine::build<TutorialLevelState>(machine, window, true));

	//Main game loop
	while (window.isOpen() && machine.running()) {
		machine.nextState();
		machine.update();
		machine.render();
	}
}
