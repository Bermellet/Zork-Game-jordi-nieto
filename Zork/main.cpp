#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "Utils.h"
#include "World.h"

using namespace std;

int main() {
	World world;

	char splitChar = ' ';

	string userInput, result;
	vector<string> tokens;
	tokens.reserve(10);
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
			cout << result << endl;
		}

		tokens.clear();
	}

}