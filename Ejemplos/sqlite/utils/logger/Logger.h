//
// Created by Bruno Gómez García on 20/6/23.
//

#ifndef SQLITE_LOGGER_H
#define SQLITE_LOGGER_H

#include <iostream>
#include "Colors.h"

namespace Logger {
    class Logger {
    public:
        static void info(const std::string& message);
        static void error(const std::string& message);
    };
}




#endif //SQLITE_LOGGER_H
