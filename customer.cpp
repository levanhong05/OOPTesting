#include "customer.h"

Customer::Customer()
{

}

void Customer::input(int id, int index) {
    _id = id;

    cout << "Nhap ten khach hang thu " << index << ": ";
    cin >> _name;
}

int Customer::id() const
{
    return _id;
}

void Customer::setId(int id)
{
    _id = id;
}

string Customer::name() const
{
    return _name;
}

void Customer::setName(const string &name)
{
    _name = name;
}
