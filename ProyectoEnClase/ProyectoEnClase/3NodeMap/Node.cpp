#include "Node.h"
#include "../utils/ConsoleControler.h"
Node::Node(Vector2 position)
{
	_position = position;
}
INodeContent* Node::GetContent()
{
	return _contents;
}
void Node::SetContent(INodeContent* nodeContent)
{
	_contents = nodeContent;
}
void Node::DrawContent(Vector2 offset)
{
	Vector2 pos = offset + _position;
	if (_contents == nullptr)
	{
		CC::Lock();
		CC::SetPosition(pos.X, pos.Y);
		std::cout << " ";
		CC::Unlock();
		return;
	}
	_contents->Draw(pos);
}
void Node::Lock()
{
	_classMutex.lock();
}
void Node::Unlock()
{
	_classMutex.unlock();
}