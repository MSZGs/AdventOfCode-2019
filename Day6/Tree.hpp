#pragma once
#include <map>
#include "OrbitMapData.hpp"
#include "Leaf.hpp"

namespace Day6 {

	class Tree {
	public:

		void addData(OrbitMapData& data);
		void setRoot(std::string name) { _root = this->getLeaf(name); }
		const Leaf* getRoot() const { return _root; }
		const Leaf* firstCommonParent(const std::string& a, const std::string& b) const;
		const Leaf* firstCommonParent(const Leaf* a, const Leaf* b) const;
		bool inSubTree(const Leaf* root, const Leaf* target) const;
		bool inSubTree(const std::string& root, const std::string& target) const;
		int distance(const Leaf* a, const Leaf* b) const;
		int distanceInChain(const Leaf* a, const Leaf* b) const;

		const Leaf* getLeaf(const std::string& name) const {
			return checkExistance(name) ? _leaves.find(name)->second : nullptr;
		}
		Leaf* getLeaf(const std::string& name) {
			return checkExistance(name) ? _leaves.find(name)->second : nullptr;
		}

		~Tree() {
			for (auto& dat : _leaves) {
				delete dat.second;
			}
		}

	private:
		std::map<std::string, Leaf*> _leaves;
		Leaf* _root;

		void makeLeafExisting(const std::string& name);
		bool checkExistance(const std::string& name) const;
		int depth(const Leaf* leaf) const;
	};


}