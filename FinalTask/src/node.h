#pragma once

#include "date.h"

#include <string>
#include <memory>

enum class LogicalOperation
{
	And,
	Or
};

enum class Comparison
{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

class Node
{
public:
	virtual bool Evaluate(const Date& date1, const string& event1) = 0;
};

class EmptyNode : public Node
{
public:
	bool Evaluate(const Date& date1, const string& event1) override;
};

class DateComparisonNode : public Node
{
public:
	DateComparisonNode(const Comparison& _cmp, const Date& _date);

	bool Evaluate(const Date& date1, const string& event1) override;
private:
	Date date;
	Comparison cmp;
};

class EventComparisonNode : public Node
{
public:
	EventComparisonNode(const Comparison& _cmp, const string& _event);

	bool Evaluate(const Date& date1, const string& event1) override;
private:
	Comparison cmp;
	string event;
};

class LogicalOperationNode : public Node
{
public:
	LogicalOperationNode(const LogicalOperation& _op, const shared_ptr<Node>& _node1, const shared_ptr<Node>& _node2);

	bool Evaluate(const Date& date1, const string& event1) override;
private:
	LogicalOperation op;
	shared_ptr<Node> node1, node2;
};