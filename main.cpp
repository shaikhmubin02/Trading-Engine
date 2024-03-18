#include "Instrument/Instrument.h"
#include "Logging/Logger.h"
#include "OrderBook/OrderBook.h"
#include "Orders/Order.h"
// #include "RiskManagement/RiskManager.h"
#include "Server/Server.h"
// #include "Client/Client.h"

#include <iostream>

int main() {
    // Create an instrument
    Instrument instrument("AAPL", "Apple Inc.", "NASDAQ", 0.01, 100);

    // Create a server
    Server server;

    // Create client orders
    Order buyOrder1 = Client::createOrder("123456", instrument, "BUY", 150.0, 100, "trader1");
    Order buyOrder2 = Client::createOrder("123457", instrument, "BUY", 151.0, 200, "trader2");
    Order sellOrder = Client::createOrder("789012", instrument, "SELL", 151.0, 150, "trader3");

    // Submit orders to the server
    server.submitOrder(buyOrder1);
    server.submitOrder(buyOrder2);
    server.submitOrder(sellOrder);

    // Match orders
    server.matchOrders();

    // Print order book
    server.printOrderBook();

    // Update instrument price and volume
    instrument.updatePrice(151.0);
    instrument.updateVolume(150);

    // Print updated instrument details
    instrument.printDetails();

    // Cancel an order
    server.cancelOrder("123456");

    // Match orders again
    server.matchOrders();

    // Print order book after cancellation
    server.printOrderBook();

    // Logging example
    Logger::log(Logger::INFO, "Trading session ended.");

    return 0;
}
