#ifndef PRINTUTILITIES_H_
#define PRINTUTILITIES_H_

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

/**
 * This function simulates a person typing, with random variances in delays between each character
 */
void typeOutput(const std::string& text, int base_delay = 50, int variance = 20) {
    for (char c : text) {
        std::cout << c << std::flush;
        int total_delay = base_delay + (std::rand() % (2 * variance + 1)) - variance; //base ± variance
        std::this_thread::sleep_for(std::chrono::milliseconds(std::max(10, total_delay)));
    }
}

void typeOutputLine(const std::string& text, int base_delay = 50, int variance = 20) {
    typeOutput(text, base_delay, variance);
    std::cout << std::endl;
}

#endif