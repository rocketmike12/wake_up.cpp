// wake_up.cpp
// Copyright (c) 2025 rocketmike12
// Licensed under the MIT License (see LICENSE.md)

#include <cstdlib>
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <time.h>

using namespace std;

// Function to print out a string character by character with random delays in range between [delayMin] and [delayMax]
void slow (string str, int delayMin, int delayMax) {
	using namespace std::chrono_literals;
	system("clear");
    for (int c = 0; c < str.length(); c++) {
        cout << str[c] << flush;
        this_thread::sleep_for(chrono::milliseconds((rand() % (delayMax - delayMin)) + delayMin));
    }
}

// Function to flicker a string on screen [times] times with random delays in range between [delayMin] and [delayMax]
void flicker (string str, int times, int delayMin, int delayMax) {
	for (int i = 0; i < times; i++) {
		system("clear");
		this_thread::sleep_for(chrono::milliseconds((rand() % (delayMax - delayMin)) + delayMin));
		cout << str << flush;
		this_thread::sleep_for(chrono::milliseconds((rand() % (delayMax - delayMin)) + delayMin));
	}
}

int main () {
	// Setting some variables. Feel free to change them to suit your desired look and feel
	int letterDelayMin = 0;
	int letterDelayMax = 500;
	chrono::milliseconds phraseDelay = 4000ms;

	// Initialize RNG	
	srand (time(NULL));

	// Initial delay
	system("clear");
	this_thread::sleep_for(phraseDelay);	

	// slow() first three phrases

	slow("Wake up, Neo... ", letterDelayMin, letterDelayMax);
	this_thread::sleep_for(phraseDelay);

	slow("The Matrix has you... ", letterDelayMin, letterDelayMax);
	this_thread::sleep_for(phraseDelay);

	slow("Follow the white rabbit. ", letterDelayMin, letterDelayMax);
	this_thread::sleep_for(phraseDelay);

	// flicker() the last phrase
    flicker("Knock, knock, Neo. ", 5, 0, 20);
    this_thread::sleep_for(phraseDelay);

	// Clear and wait for input, then clear and exit 
	system("clear");
	system("read tmp");
	system("clear");
	
	return 0;
}
