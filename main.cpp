// #include <bits/stdc++.h>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <limits>
#include <string> 
#include <vector> 
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <memory> 
#include <variant>
#include <optional> 
#include <tuple>
#include <format> 

enum class OrderType {

    GoodTillCancel,
    FillAndKill

};

enum class Side {
    Buy,
    Sell
};

using Price = std::int32_t;
using Quantity = std::uint32_t;
using OrderId = std::uint64_t;

struct LevelInfo {

    Price price_;
    Quantity quantity_;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderbookLevelInfos {

    public:
        OrderbookLevelInfos(const LevelInfos& bids, const LevelInfos& asks) 
            : bids_{ bids }
            , asks_ { asks } 
        { }

        const LevelInfos& GetBids() const { return bids_; } 
        const LevelInfos& GetAsks() const { return asks_: }

    private:

        LevelInfos bids_;
        LevelInfos asks_;
};        

class Order {

    public: 
        Order(OrderType orderType, OrderId orderId, Side side, Price price, Quantity quantity) 
            : orderType_ { orderType }
            , orderId_ { orderId } 
            , side_ { side }
            , price_ { price }
            , initialQuantity_ { quantity }
            , remainingQuantity_ { quantity }
        { }

        OrderId GetOrderId() const { return orderId_; } 
        Side GetSide() const { return side_; } 
        Price GetPrice() const { return price_; }
        OrderType GetOrderType() const { return orderType_; }
        Quantity GetInitialQuantity()  const { return initialQuantity_; }
        Quantity GetRemainingQuantity() const { return remainingQuantity_; }
        Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); } 

        void Fill(Quantity quantity) {
            if(quantity > GetRemainingQuantity()) {
                throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity.", GetOrderId()));
            } 

            remainingQuantity_ -= quantity; 
        }
    private: 
        OrderType orderType_; 
        OrderId orderId;
        Side side_; 
        Price price_; 
        Quantity initialQuantity_; 
        Quantity remainingQuantity_; 
};







int main () {

    return 0;
}

