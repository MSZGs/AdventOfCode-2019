#pragma once
#include <string>
#include <vector>

namespace Day6 {

	class Leaf {
	public:
		Leaf(std::string name) : _name{ name }, _parent{ nullptr } {};

		void addChild(Leaf* child) {
			_children.push_back(child);
			child->_parent = this;
		}

		const Leaf* getParent() const { return _parent; }
		const std::vector<Leaf*>& getChildren() const { return _children; }
		bool haveChildren() const { return _children.size(); }

	private:
		std::string _name;
		std::vector<Leaf*> _children;
		Leaf* _parent;
	};
};