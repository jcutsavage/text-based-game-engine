#ifndef PRINTUTILITIES_H_
#define PRINTUTILITIES_H_

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void printSlowly(const std::string& text, int delay_ms) {
    for (char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    std::cout << std::endl;
}

#endif