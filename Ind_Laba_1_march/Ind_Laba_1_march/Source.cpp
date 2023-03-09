#include <iostream>

//  "Название, ед.изм., цена за ед.изм. и количество товара,
//  название, телефон и e - mail фирмы - поставщика,
//  ФИО кладовщика, дата поступления на склад.
//  + название, телефон и адрес склада."

class Product {
//public:
	std::string name;
	std::string unit;
	float unit_cost;
	int amount;
public:

};

class Provider {
//public:
	std::string name;
	std::string phone_number;
	std::string e_mail;
	std::string provider_name;
public:

};

class Storage {
//public:
	Fio courier_fio;
	Date delivery_date;
	std::string storage_name;
	std::string storage_phone_number;
	std::string storage_address;
public:
	
};

class Fio {
	std::string name, midname, lastname;
};

class Date {
	int day, mount, year;
};

class Base_object {
	int id;
	Product product;
	Provider provider;
	Storage storage;
public:

};

void main() {

}