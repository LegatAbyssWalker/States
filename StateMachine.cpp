#include "StateMachine.h"
#include "State.h"

#include <iostream>
#include <memory>

StateMachine::StateMachine()
	: stateResume{ false }
	, stateRunning{ false } {
	std::cout << "Statemachine Init\n";
}

void StateMachine::run(std::unique_ptr<State> state) {
	stateRunning = true;
	states.push(std::move(state));
}

void StateMachine::nextState() {
	if (stateResume) {
		//Clean current state
		if (!states.empty()) {
			states.pop();
		}

		//Clean previous state
		if (!states.empty()) {
			states.top()->resume();
		}

		stateResume = false;
	}


	if (!states.empty()) {
		std::unique_ptr<State> temp = states.top()->nextState();


		if (temp != nullptr) {
			if (temp->isReplacing()) {
				states.pop();
			}

			else {
				states.top()->pause();
			}

			states.push(std::move(temp));
		}
	}
}

void StateMachine::lastState() {
	stateResume = true;
}

void StateMachine::update() {
	states.top()->update();
}

void StateMachine::render() {
	states.top()->render();
}