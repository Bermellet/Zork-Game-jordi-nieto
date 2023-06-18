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

	string userInput;
	vector<string> tokens;
	tokens.reserve(10);
	bool running = true;

	while (running) {
		// Read input line
		getline(cin, userInput);
		istringstream split(userInput);
		for (string token; getline(split, token, splitChar); ) {
			if (!token.empty()) { tokens.push_back(Trim(token)); }
		}

		// Process tokens
		if (tokens.size() > 0) {
			if (Equals(tokens[0], "exit")) {
				running = false;
				break;
			}

		}

		tokens.clear();
	}

}