#include "state_machine.h"

State::State() {
  // Konstruktor-Code
}

State::~State() {
  // Destruktor-Code
}

void State::onEnter() {
  // Code, der ausgeführt wird, wenn der Zustand betreten wird
}

void State::onExit() {
  // Code, der ausgeführt wird, wenn der Zustand verlassen wird
}

StateMachine::StateMachine() {
  // Konstruktor-Code
}

StateMachine::~StateMachine() {
  // Destruktor-Code
}

void StateMachine::addState(State* state) {
  // Fügt den übergebenen Zustand zur Zustandsmaschine hinzu
}

void StateMachine::transitionTo(State* state) {
  // Wechselt den aktuellen Zustand der Zustandsmaschine zum übergebenen Zustand
}

void StateMachine::update() {
  // Aktualisiert den aktuellen Zustand der Zustandsmaschine
}
