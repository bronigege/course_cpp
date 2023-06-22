//
// Created by Bruno Gómez García on 20/6/23.
//

#include "Logger.h"

void Logger::Logger::info(const std::string& message) {
    std::cout << GREEN << message << RESET << std::endl;
}

void Logger::Logger::error(const std::string& message) {
    std::cerr << RED << message << RESET << std::endl;
}