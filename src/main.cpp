#include <iostream>
#include <thread>

#include <matching-engine.h>

using namespace std;

void hi() {
    return;
}

int main() {
    Trade t = Trade("HI", "HI", 1, 1);
    MatchingEngine engine = MatchingEngine();
    engine.run_engine();

    cout << "HIII";
    return 0;
}

