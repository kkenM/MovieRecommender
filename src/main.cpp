#include <iostream>
#include "crow_all.h"

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "Hello from C++ backend!";
    });

    CROW_ROUTE(app, "/api/echo/<string>")
    ([](std::string msg){
        return crow::response("You said: " + msg);
    });

    app.port(8080).multithreaded().run();
}