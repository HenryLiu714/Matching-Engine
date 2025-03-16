#ifndef AAFEF02B_8017_492A_B710_ED679DFADA9A
#define AAFEF02B_8017_492A_B710_ED679DFADA9A

#include <string>

class Trade {
    std::string symbol;
    std::string user_id;
    double price;
    bool direction;

    public:
        Trade(const std::string& symbol_, const std::string& user_id_, double price_, bool direction_);
};

#endif /* AAFEF02B_8017_492A_B710_ED679DFADA9A */
