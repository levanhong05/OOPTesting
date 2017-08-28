#include "product.h"

Product::Product()
{

}

void Product::input(int id, int index) {
    _id = id;

    cout << "Nhap ten san pham thu " << index << ": ";
    cin >> _name;

    cout << "Nhap gia san pham thu " << index << ": ";
    cin >> _price;
}

int Product::id() const
{
    return _id;
}

void Product::setId(int id)
{
    _id = id;
}

string Product::name() const
{
    return _name;
}

void Product::setName(const string &name)
{
    _name = name;
}

int Product::price() const
{
    return _price;
}

void Product::setPrice(int price)
{
    _price = price;
}
