#pragma once
#include "Common.hpp"

/*
* Representation of functions as a callback that is fired when an action is taken place
*/

namespace DesignPatterns {
	namespace Basic {

		enum class ACTIONS : uint8_t{
			MOVE,
			JUMP
		};

		// Abstract class containing the main command function
		class Command {
		public:
			virtual ~Command() {}
			virtual void execute() = 0;
		};

		//Implementation of each functionality
		class JumpCommand : public Command {
			virtual void execute() {
				throw new std::exception("not implemented");
			}
		};

		class MoveCommand : public Command {
		private:
			std::shared_ptr<int> x;
			std::shared_ptr<int> y;
		public:
			MoveCommand(std::shared_ptr<int> _x, std::shared_ptr<int> _y) : x{ _x}, y{ _y }{}
			virtual void execute() {
				(*x)++;
				(*y)++;
			}
			~MoveCommand() {
			}
		};


		//Handler class that will execute appropriate command
		//This class will then create an instance of the Command to be executed whenever necessary
		class InputHandler {
		private:
			std::shared_ptr<int> x, y;
		public:
			InputHandler(int _x, int _y) : x{ std::make_shared<int>(_x) }, y{ std::make_shared<int>(_y) }{ }
		
			Command* handle(ACTIONS action) {
				switch (action) {
				case ACTIONS::MOVE:
					return new MoveCommand(x, y);
				case ACTIONS::JUMP:
					return new JumpCommand();
				default:
					return nullptr;
				}
			}

			~InputHandler() {
			}

		};
	}
}