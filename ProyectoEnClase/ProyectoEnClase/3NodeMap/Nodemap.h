#pragma once

#include <vector>
#include <functional>
#include <list>
#include "Node.h"
class Nodemap
{
public:
	typedef std::vector<Node*> NodeColumn;
	typedef std::vector<NodeColumn*> NodeGrid;

	typedef std::function<void(Node* node)> SafePick;
	typedef std::function<void(std::list<Node*> nodes)> SafeMultiPick;
	
public:
	Nodemap(Vector2 size, Vector2 offset);
	Vector2 GetSize();

	void UnSafeDraw();
	void SafePickNode(Vector2 position, SafePick safePickAction);
	void SafeMultiPickNode(std::list<Vector2> positions, SafeMultiPick safePickAction);
	
private:
	Vector2 _offset;

	Vector2 _size;
	std::mutex _sizeMutex;

	NodeGrid _grid;
	std::mutex _gridMutex;

	std::mutex _safeMultiPickNodeMutex;

	Node* UnSafeGetNode(Vector2 position);

};

