/*
 * Copyright (C) 2016 Hedede <haddayn@gmail.com>
 *
 * License LGPLv3 or later:
 * GNU Lesser GPL version 3 <http://gnu.org/licenses/lgpl-3.0.html>
 * This is free software: you are free to change and redistribute it.
 * There is NO WARRANTY, to the extent permitted by law.
 */
#ifndef Daedalus_Visitor
#define Daedalus_Visitor
namespace daedalus {
namespace tree {
class Node;
class FunctionProto;
class Function;
class Variable;
class StatementBlock;
class IfElseStatement;
class ReturnStatement;
class NumberExpr;
class StringExpr;
class IdentifierExpr;
class CallExpr;
class FieldExpr;
class SubscriptExpr;
class UnaryExpr;
class BinaryExpr;

class Visitor {
public:
	virtual ~Visitor() = default;

	virtual void visit(tree::FunctionProto& node) {};
	virtual void visit(tree::Function& node) {};
	virtual void visit(tree::Variable& node) {};
	virtual void visit(tree::StatementBlock& node) {};
	virtual void visit(tree::IfElseStatement& node) {};
	virtual void visit(tree::ReturnStatement& node) {};
	virtual void visit(tree::NumberExpr& node) {};
	virtual void visit(tree::StringExpr& node) {};
	virtual void visit(tree::IdentifierExpr& node) {};
	virtual void visit(tree::CallExpr& node) {};
	virtual void visit(tree::FieldExpr& node) {};
	virtual void visit(tree::SubscriptExpr& node) {};
	virtual void visit(tree::UnaryExpr& node) {};
	virtual void visit(tree::BinaryExpr& node) {};
};

} // namespace tree
} // namespace daedalus
#endif//Daedalus_Visitor