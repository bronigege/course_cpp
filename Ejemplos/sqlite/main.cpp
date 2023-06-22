#include "utils/bd/Sqlite.h"

int main() {
    Logger::Logger logger;
    Sqlite sqlite(&logger);
    bool connect = sqlite.connect();

    if (connect) {
        sqlite.executeQuerie("CREATE TABLE IF NOT EXISTS books (id INTEGER PRIMARY KEY, title TEXT)");
    }
}
