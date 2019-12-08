#include "Tree.hpp"

namespace Day6 {

	void Tree::addData(OrbitMapData& data) {
		makeLeafExisting(data.getCenter());
		makeLeafExisting(data.getObject());

		Leaf* from = this->getLeaf(data.getCenter());
		Leaf* to = this->getLeaf(data.getObject());

		from->addChild(to);
	}

	const Leaf* Tree::firstCommonParent(const std::string& a, const std::string& b) const {
		const Leaf* first = this->getLeaf(a);
		const Leaf* second = this->getLeaf(b);
		return firstCommonParent(first, second);
	}
	const Leaf* Tree::firstCommonParent(const Leaf* a, const Leaf* b) const {
		const Leaf* comP = a;
		while (!inSubTree(comP, b) && comP != nullptr) {
			comP = comP->getParent();
		}
		return comP;
	}

	bool Tree::inSubTree(const Leaf* root, const Leaf* target) const {
		const Leaf* current = target;
		const Leaf* parent = current->getParent();

		while (parent != nullptr) {
			if (parent == root) {
				return true;
			}
			current = current->getParent();
			parent = current->getParent();
		}

		return false;
	}

	bool Tree::inSubTree(const std::string& root, const std::string& target) const {
		const Leaf* rootL = this->getLeaf(root);
		const Leaf* targetL = this->getLeaf(target);
		return inSubTree(rootL, targetL);
	}

	int Tree::distance(const Leaf* a, const Leaf* b) const {
		const Leaf* commmon = this->firstCommonParent(a, b);
		return distanceInChain(commmon, a) + distanceInChain(commmon, b);
	}

	int Tree::distanceInChain(const Leaf* a, const Leaf* b) const {
		bool deeper = depth(a) < depth(b);
		const Leaf* deltaLeaf = deeper ? b : a;
		const Leaf* targetLeaf = deeper ? a : b;

		int distance = 0;
		while (deltaLeaf != nullptr) {
			if (deltaLeaf == targetLeaf) {
				return distance;
			}
			distance++;
			deltaLeaf = deltaLeaf->getParent();
		}
		return -1;
	}

	void Tree::makeLeafExisting(const std::string& name) {
		if (!checkExistance(name)) {
			_leaves.insert(std::make_pair(name, new Leaf(name)));
		}
	}

	bool Tree::checkExistance(const std::string& name) const {
		return (_leaves.find(name) != _leaves.end());
	}

	int Tree::depth(const Leaf* leaf) const {
		const Leaf* current = leaf;
		int depth = 0;
		while (current->getParent() != nullptr && current != _root) {
			depth++;
			current = current->getParent();
		}
		return depth;
	}
}