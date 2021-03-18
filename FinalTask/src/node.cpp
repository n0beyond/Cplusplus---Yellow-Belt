#include "node.h"

bool EmptyNode::Evaluate(const Date& date1, const string& event1)
{
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& _cmp, const Date& _date)
	: cmp(_cmp), date(_date) {}

template <class T>
bool Compare(const Comparison& cmp, const T& lhs, const T& rhs)
{
	switch (cmp)
	{
		case Comparison::Less: return lhs < rhs;
		case Comparison::LessOrEqual: return lhs <= rhs;
		case Comparison::Equal: return lhs == rhs;
		case Comparison::Greater: return lhs > rhs;
		case Comparison::GreaterOrEqual: return lhs >= rhs;
		case Comparison::NotEqual: return lhs != rhs;
	}
}

bool DateComparisonNode::Evaluate(const Date& date1, const string& event1)
{
	return Compare(cmp, date1, date);
}

EventComparisonNode::EventComparisonNode(const Comparison& _cmp, const string& _event)
	: cmp(_cmp), event(_event) {}

bool EventComparisonNode::Evaluate(const Date& date1, const string& event1)
{
	return Compare(cmp, event1, event);
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& _op, const shared_ptr<Node>& _node1, const shared_ptr<Node>& _node2) 
	: op(_op),  node1(_node1), node2(_node2) {}

bool LogicalOperationNode::Evaluate(const Date& date1, const string& event1)
{
	if (op == LogicalOperation::And)
	{
		return node1->Evaluate(date1, event1) && node2->Evaluate(date1, event1);
	}
	else
	{
		return node1->Evaluate(date1, event1) || node2->Evaluate(date1, event1);
	}
}
