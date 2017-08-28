#include <iostream>
#include <string>
#include <vector>

#include "store.h"

using namespace std;

static int numberCustomer = 0;
static int numberProduct = 0;
static int numberOrder = 0;

int main()
{
    Store *store = new Store();
    int numCustomer, numProduct;

    cout << "1. TAO DANH SACH KHACH HANG" << endl << endl;
    cout << "Nhap so luong khach hang: ";
    cin >> numCustomer;

    int index = 1;

    while (numCustomer > 0) {
        store->addCustomer(numberCustomer, index);
        numberCustomer++;

        cout << endl;

        numCustomer--;

        index++;
    }
    cout << endl;

    //In danh sach khach hang
    cout << "-----IN DANH SACH KHACH HANG-----" << endl;
    for (Customer *customer : store->customers) {
        cout << "ID: " << customer->id()
             << ", ten khach hang: " << customer->name()
             << endl;
    }
    cout << endl;

    cout << "2. TAO DANH SACH SAN PHAM" << endl << endl;
    cout << "Nhap so luong san pham: ";
    cin >> numProduct;

    index = 1;
    while (numProduct > 0) {
        store->addProduct(numberProduct, index);
        numberProduct++;

        cout << endl;

        numProduct--;

        index++;
    }

    cout << endl;

    //In danh sach san pham
    cout << "-----IN DANH SACH SAN PHAM-----" << endl;
    for (Product *product : store->products) {
        cout << "ID: " << product->id()
             << ", ten san pham: " << product->name()
             << ", gia san pham: " << product->price()
             << endl;
    }
    cout << endl;

    cout << "3. THEM SAN PHAM VAO KHO" << endl << endl;
    string enter = "N";

    do {
        store->importStocks();

        cout << endl << "Nhan <Y> de tiep tuc, bat ky phim khac de thoat." << endl;
        cin >> enter;

        cout << endl;
    } while (enter == "Y" || enter == "y");
    cout << endl;

    cout << "4. IN DANH SACH SAN PHAM TRONG KHO" << endl;
    store->showStock();
    cout << endl;

    cout << "5. TAO DON DAT HANG" << endl << endl;
    store->createOrder(numberOrder,numberCustomer);
    cout << endl;

    cout << "6. TRUY VAN DON DAT HANG CUA KHACH HANG THEO TEN" << endl << endl;
    string name;
    cout << "Nhap ten khach hang muon truy van: ";
    cin >> name;
    vector<Order *> orderByName = store->listCustomerOrdersByName(name);

    cout << "Order by " << name << endl;

    for (Order *order : orderByName) {
        cout << "ID: " << order->id() << endl;

        vector<Stock *> stocks = order->stocks();
        for (Stock *stock : stocks) {
            cout << "Ten san pham: " << stock->product()->name() << ", so luong: " << stock->numProduct() << endl;
        }
        cout << endl;
    }

    return 0;
}
