#ifndef AAFEF02B_8017_492A_B710_ED679DFADA9A
#define AAFEF02B_8017_492A_B710_ED679DFADA9A

#include <string>
#include <stdint.h>

enum Direction {
    LONG,
    SHORT
};

class Order {
    uint64_t order_id;
    uint64_t user_id;

    std::string symbol;
    Direction direction;
    
    uint64_t transaction_time;
    float order_quantity;
    float price;

    public:
        Order(uint64_t order_id_, uint64_t user_id_, const std::string& symbol_,
            Direction direction_, uint64_t transaction_time_, 
            float order_quantity_, float price_);
};

#endif /* AAFEF02B_8017_492A_B710_ED679DFADA9A */
