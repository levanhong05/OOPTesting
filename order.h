#ifndef ORDER_H
#define ORDER_H

#include <vector>

#include "stock.h"

using namespace std;

class Order
{
public:
    Order();

    vector<Stock *> stocks() const;
    void setStocks(const vector<Stock *> &stocks);

    int id() const;
    void setId(int id);

    int idCustomer() const;
    void setIdCustomer(int idCustomer);

    void addStock(Stock *stock);

private:
    int _id;
    int _idCustomer;
    vector<Stock *> _stocks;
};

#endif // ORDER_H
