//
// Created by Bruno Gómez García on 20/6/23.
//
#include <iostream>
#include "Sqlite.h"

#define RESET_COLOR "\033[0m"
#define GREEN_TEXT "\033[32m"


Sqlite::Sqlite(Logger::Logger* logger) {
    this->logger = logger;
}

bool Sqlite::executeQuerie(const char* querie) {
    int status = sqlite3_exec(db, querie, 0, 0, 0);

    if (status) {
        logger->error("No se ha ejecutar la querie");
        return false;
    } else {
        logger->info("La querie se ha ejecutado correctamente");
        return false;
    }
}

bool Sqlite::connect() {
    int status = sqlite3_open("game.db", &db);

    if (status) {
        logger->error("Error al abrir la base de datos");
        return false;
    } else {
        logger->info("Conexión exitosa a la base de datos");
        return true;
    }
}

void Sqlite::disconnect() {
    int status = sqlite3_close(db);

    if (status) {
        logger->error("No se pudo desconectar correctamente la BDs");
    } else {
        logger->info("Desconectado correctamente a la BD");
    }
}

Sqlite::~Sqlite() {
    this->disconnect();
}