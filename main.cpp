#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>

int main() {
    std::cout << "Please enter the timer duration [mm:ss] example \'01:05\': ";
    std::tm timerLocal = {};
    std::cin >> std::get_time(&timerLocal, "%M:%S");

    std::time_t future = std::time(nullptr) + 60 * timerLocal.tm_min + timerLocal.tm_sec;
    std::tm* localFuture = std::localtime(&future);
    std::time_t now = time(nullptr);

    std::cout << "---=== Timer is started ===---\n";
    while(std::difftime(future, now) > 0)
    {
        if (time(nullptr) > now)
        {
            std::time_t elapsed = std::difftime(future, now);
            std::tm* elapsedLocal = localtime(&elapsed);
            std::cout << std::put_time(elapsedLocal, "%M:%S") << "\n";
            now = time(nullptr);
        }
    }
    std::cout << "---=== DING! DING! DING! ===---\n";
    return 0;
}