#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

namespace PrintUtils
{
    /**
     * This function simulates a person typing, with random variances in delays between each character
     */
    inline void print(const std::string &text, int base_delay = 40, int variance = 20)
    {
        for (char c : text)
        {
            std::cout << c << std::flush;
            int total_delay = base_delay + (std::rand() % (2 * variance + 1)) - variance; // base ± variance
            std::this_thread::sleep_for(std::chrono::milliseconds(std::max(10, total_delay)));
        }
    }

    /**
     * This function simulates a person typing, with random variances in delays between each character
     * and adds a newline at the end;
     */
    inline void printLine(const std::string &text, int base_delay = 50, int variance = 20)
    {
        print(text, base_delay, variance);
        std::cout << std::endl;
    }
}