create database if not exists order_sys;

use order_sys;

create table if not exists tb_dish(
	id int primary key auto_increment,
	name varchar(32) unique not null,
	price int not null,
	ctime datetime
	);


create table if not exists tb_order(
	id int primary key auto_increment,
	dishes varchar(255) comment '[1,2]',
	status int comment '0-未完成; 1-已完成',
	mtime datetime
	);

insert tb_dish values(null, "红烧肉", 2800, now()),
(null, "红烧茄子", 1800, now());

insert tb_order values(null, "[1,2]", 0, now()),
(null, "[2]", 0, now());


#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <jsoncpp/json.json.h>

namespace order_sys
{

	class TableDish
	{
	private:
		MYSQL *_mysql;
		std::mutex _mutex;

	public:
		TableDish() {}
		~TableDish() {}
		bool Insert(const Json::Value &dish);
		bool Delete(int dish_id);
		bool Update(const Json::Value &dish);
		bool SelectAll(Json::Value *dishes);
		bool SelectOne(int dish_id, Json::Value *dish);
	};


	class TableOrder
	{
	private:
		MYSQL *_mysql;
		std::mutex _mutex;

	public:
		TableOrder() {}
		~TableOrder() {}
		bool Insert(const Json::Value &order);
		bool Delete(int order_id);
		bool Update(const Json::Value &order);
		bool SelectAll(Json::Value *orders);
		bool SelectOne(int order_id, Json::Value *order);
	};
}