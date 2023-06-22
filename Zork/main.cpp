#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Utils.h"
#include "World.h"

using namespace std;

int main() {
	World world;

	string userInput, result;
	vector<string> tokens;
	tokens.reserve(10);
	
	char splitChar = ' ';
	bool running = true;

	while (running) {
		// Read input line
		getline(cin, userInput);
		istringstream split(userInput);
		for (string token; getline(split, token, splitChar); ) {
			if (!token.empty()) {
				Trim(token);
				ToLower(token);
				tokens.push_back(token);
			}
		}

		// Process tokens
		if (tokens.size() > 0) {
			if (Equals(tokens[0], "exit")) {
				running = false;
				break;
			}
			result = world.Run(tokens);
			cout << result << "\n\n";
		}

		tokens.clear();
		running = !world.gameOver() && !world.finished();
	}

	if (world.gameOver()) {
		cout << "\n\t\t GAME OVER \n\n";
		getline(cin, userInput);
	}
	else if (world.finished()) {
		getline(cin, userInput);
		cout << "-----------------------------------\n"
			<< "\n\t Congratulations! You have successfuly finished the game \n\n";
		getline(cin, userInput);
	}

}