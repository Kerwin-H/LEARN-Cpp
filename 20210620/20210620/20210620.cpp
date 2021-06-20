#include "db.hpp"
#include "httplib.h"

#define WWWROOT "./wwwroot"
using namespace httplib;

order_sys::TableDish *tb_dish = NULL;
order_sys::TableOrder *tb_order = NULL;

void DishInsert(const Request &req, Response &rsp)
{

	//1.ҵ����
	//json�����л�
	Json::Value dish;
	Json::Reader reader;
	bool ret = reader.parse(req.body, dish);
	if (ret == false)
	{
		rsp.status = 400;
		Json::Value reason;
		Json::FastWriter writer;
		reason["result"] = false;
		reason["reason"] = "dish info parse failed!";
		rsp.body = writer.write(reason);
		rsp.set_header("Content_type", "application/json");
		std::cout << " insert dish error\n";

		return;
	}
	//����Ʒ��Ϣ�������ݿ�
	ret = tb_dish->Insert(dish);
	if (ret == false)
	{
		Json::Value reason;
		Json::FastWriter writer;
		reason["result"] = false;
		reason["reason"] = "mysql insert failed!";
		rsp.status = 500;
		rsp.body = writer.write(reason);
		rsp.set_header("Content_type", "application/json");
		std::cout << "mysql insert dish error\n";
		return;
	}
	//2.������Ӧ��Ϣ
	//rsp.status=200;
	//Ĭ������200

	return;
}

void DishDelete(const Request &req, Response &rsp)
{
	//��ȡɾ����Ʒ����Ϣ
	int dish_id = std::stoi(req.matches[1]);

	//���ݿ�ɾ������
	bool ret = tb_dish->Delete(dish_id);
	if (ret == false)
	{

		std::cout << "mysql delete dish error\n ";
		rsp.status = 500;
		return;
	}
	return;
}
void DishUpdate(const Request &req, Response &rsp)
{
	int dish_id = std::stoi(req.matches[1]);
	Json::Value dish;
	Json::Reader reader;
	bool ret = reader.parse(req.body, dish);
	if (ret == false)
	{
		rsp.status = 400;
		std::cout << "update parse dish info failed\n";
		return;
	}
	dish["id"] = dish_id;
	ret = tb_dish->Update(dish);
	if (ret == false)
	{
		std::cout << "update mysql dish error\n";
		rsp.status = 500;
		return;
	}

	return;
}
void DishGetAll(const Request &req, Response &rsp)
{
	Json::Value dishes;
	bool ret = tb_dish->SelectAll(&dishes);
	if (ret == false)
	{
		std::cout << "select _all mysql dish error\n";
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(dishes);

	return;
}
void DishGetone(const Request &req, Response &rsp)
{
	int dish_id = std::stoi(req.matches[1]);
	Json::Value dish;
	bool ret = tb_dish->SelectOne(dish_id, &dish);
	if (ret == false)
	{
		std::cout << "select _one mysql dish error\n";
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(dish);

	return;
}

void OrderInsert(const Request &req, Response &rsp)
{
	Json::Value order;
	Json::Reader reader;
	bool ret = reader.parse(req.body, order);
	if (ret == false)
	{

		std::cout << "insert parse order info failed!\n";
		rsp.status = 400;
		return;
	}
	ret = tb_order->Insert(order);
	if (ret == false)
	{

		std::cout << "insert parse order info failed!\n";
		rsp.status = 400;
		return;
	}

	return;
}

void OrderDelete(const Request &req, Response &rsp)
{
	int order_id = std::stoi(req.matches[1]);
	bool ret = tb_order->Delete(order_id);
	if (ret == false)
	{

		std::cout << "delete mysql delete order info failed!\n";
		rsp.status = 500;
		return;
	}
	return;
}
void OrderUpdate(const Request &req, Response &rsp)
{
	int order_id = std::stoi(req.matches[1]);
	Json::Value order;
	Json::Reader reader;
	bool ret = reader.parse(req.body, order);
	if (ret == false)
	{

		std::cout << "insert mysql delete order info failed!\n";
		rsp.status = 400;
		return;
	}
	order["id"] = order_id;
	ret = tb_order->Update(order);
	if (ret == false)
	{

		std::cout << "update mysql delete order info failed!\n";
		rsp.status = 500;
		return;
	}

	return;
}
void OrderGetAll(const Request &req, Response &rsp)
{
	Json::Value orders;
	bool ret = tb_order->SelectAll(&orders);
	if (ret == false){

		std::cout << "select  all  order info failed!\n";
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(orders);

	return;
}
void OrderGetone(const Request &req, Response &rsp)
{
	int order_id = std::stoi(req.matches[1]);
	Json::Value order;
	bool ret = tb_order->SelectOne(order_id, &order);
	if (ret == false){

		std::cout << "select  one  order info failed!\n";
		rsp.status = 500;
		return;
	}
	Json::FastWriter writer;
	rsp.body = writer.write(order);

	return;
}
int main()
{
	tb_dish = new order_sys::TableDish();
	tb_order = new order_sys::TableOrder();

	Server server;
	server.set_base_dir(WWWROOT);
	//��
	server.Post("/dish", DishInsert);
	server.Delete(R"(/dish/(\d+))", DishDelete);
	server.Put(R"(/dish/(\d+))", DishUpdate);
	server.Get(R"(/dish)", DishGetAll);
	server.Get(R"(/dish/(\d+))", DishGetone);

	//����
	server.Post("/order", OrderInsert);
	server.Delete(R"(/order/(\d+))", OrderDelete);
	server.Put(R"(/order/(\d+))", OrderUpdate);
	server.Get(R"(/order)", OrderGetAll);
	server.Get(R"(/order/(\d+))", OrderGetone);

	server.listen("0.0.0.0", 9000);

	return 0;
}
