#include "order.h"

Order::Order()
{

}

vector<Stock *> Order::stocks() const
{
    return _stocks;
}

void Order::setStocks(const vector<Stock *> &stocks)
{
    _stocks = stocks;
}

int Order::id() const
{
    return _id;
}

void Order::setId(int id)
{
    _id = id;
}

int Order::idCustomer() const
{
    return _idCustomer;
}

void Order::setIdCustomer(int idCustomer)
{
    _idCustomer = idCustomer;
}

void Order::addStock(Stock *stock)
{
    _stocks.push_back(stock);
}
