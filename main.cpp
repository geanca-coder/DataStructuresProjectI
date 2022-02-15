#include "Controller.h"

int main() {
    auto* controller = new Controller;
    controller->main();
    delete controller;
    return EXIT_SUCCESS;
}