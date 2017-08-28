#include "stock.h"

Stock::Stock()
{

}

void Stock::input() {
    cout << "Nhap ten san pham: ";
    cin >> _productName;

    cout << "Nhap so luong san pham: ";
    cin >> _numProduct;
}

Product *Stock::product() const
{
    return _product;
}

void Stock::setProduct(Product *product)
{
    _product = product;
}

int Stock::numProduct() const
{
    return _numProduct;
}

void Stock::setNumProduct(int numProduct)
{
    _numProduct = numProduct;
}

string Stock::productName() const
{
    return _productName;
}

void Stock::setProductName(const string &productName)
{
    _productName = productName;
}
