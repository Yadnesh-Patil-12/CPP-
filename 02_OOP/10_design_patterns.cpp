#include <iostream>
#include <memory>
using namespace std;

// Singleton Design Pattern
class Logger {
private:
    Logger() = default;

public:
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const string& message) {
        cout << "[LOG] " << message << endl;
    }
};

int main() {
    Logger::getInstance().log("Application started");
    Logger::getInstance().log("Processing data");
    Logger::getInstance().log("Application finished");

    return 0;
}