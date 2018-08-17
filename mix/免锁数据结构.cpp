#include<iostream>
#include<atomic>

using namespace std;

template<class T>
class LockBasedStack
{
private:
	AtomicBoolean lock;
	
public:
	LockBasedStack()
	{
		lock = new AtomicBoolean(false);
	}

	void push(T value)
	{
		Node node = new Node(value);
		while(true)
		{
			if(tryPush(node))
			{
				return;
			}
			else
			{
				contentionManager.backoff();
			}
		}
	}
	
	T pop() throw EmptyException
	{
		while(true)
		{
			Node returnNode = tryPop();
			if(returnNode != null)
			{
				return returnNode.value;
			}
			else
			{
				contentionManager.backoff();
			}
		}
	}

protected:
	bool tryPush(Node node)
	{
		bool gotLock = lock.compareAndSet(false, true);
		if(gotlock)
		{
			Node oldTop = top;
			node.next = oldTop;
			top =node;
			lock.set(false);
		}
		return gotLock;
	}
	
	Node tryPop() throw EmptyException
	{
		bool gotLock = lock.compareAndSet(false, true);
		if(gotlock)
		{
			Node oldTop = top;
			if(oldTop == null)
			{
				lock.set(false);
				throw new EmptyException();
			}
			top = oldTop.next;
			lock.set(false);
			return oldTop;
		}
		else return null;
	}
};

template<class T>
class LockFreeStack
{
private:
	ActomicReference<Node> top;
	
public:
	ActomicReference<Node> top = new ActomicReference<Node>(null);
	
protected:
	bool tryPush(Node node)
	{
		Node oldTop = top.get();
		node.next = oldTop;
		return top.compareAndSet(oldTop, node);
	}
	
	Node tryPop() throw EmptyException
	{
		Node oldTop = top.get();
		if(oldTop == null)
		{
			throw new EmptyException();
		}
		Node newTop = oldTop.next;
		if(top.compareAndSet(oldTop, newTop))
		{
			return oldTop;
		}
		else
		{
			return null;
		}
	}
};

int update(cursor c)
{
	if(c.pre_aux.next = c.target)
	{
		return;
	}
	AuxNode* p = c.pre_aux;
	void* n = SafeRead(p->next);
	while(n != last && strcmp(typeof(n), "Node") != 0)
	{
		CAS(c.pre_cell.next, p, n);
		Release(p);
		p = n;
		n = SafeRead(p->next);
	}
	c.pre_aux = p;
	c.target = n;
	return 0;
}

int first(cursor c)
{
	c.pre_cell = SafeRead(First);
	c.pre_aux = SafeRead(First.next);
	c.target = null;
	update(c);
	return 0;
}

bool next(cursor c)
{
	if(c.target = Last)
	{
		return false;
	}
	c.pre_cell = SafeRead(c.target);
	c.pre_aux = SafeRead(c.target.next);
	update(c);
	return true;
}

bool tryInsert(cursor c, CellNode q, AuxNode a)
{
	Write(q.next, a);
	Write(a.next, c.target);
	bool r = CSW(c.pre_aux.next, c.target, q);
	return r;
}

bool tryDelete(cursor c)
{
	Node d = c.target;
	void* n = c.target.next;
	bool r = CSW(c.pre_aux.next, d, n);
	if(!r)
	{
		return false;
	}
	Write(d.back_link, c.pre_cell);
	Node p = c.pre_cell;
	while(p.back_link != null)
	{
		q = SafeRead(p.back_link);
		Release(p);
		p = q;
	}
	AuxNode s = SafeRead(p.next);
	while(strcmp(typeof(n.next), "Node") != 0)
	{
		q = SafeRead(n.next);
		Release(n);
		n = q;
	}
	do
	{
		r = CSW(p.next, s, n);
		if(!r)
		{
			Release(s);
			s = SafeRead(p.next);
		}
	}while(!(r || p.back_link != null || strcmp(typeof(n.next), "Node") != 0));
	return true;
}

Node* search(KeyType search_key, Node** left_node)
{
	Node *left_node_next, *right_node;
	search_again:
		do
		{
			Node* t = head;
			Node* t_next = head.next;
			
			do
			{
				if(!is_marked_reference(t_next))
				{
					(*left_node) = t;
					left_node_next = t_next;
				}
				t = get_unmarked_reference(t_next);
				if(t == tail)
				{
					break;
				}
				t_next = t.next;
			}while(is_marked_reference(t_next) || t.key < search_key);
			right_node = t;
			
			if(left_node_next == right_node)
			{
				if((right_node != tail ) && is_marked_reference(right_node))
				{
					goto search_again;
				}
				else
				{
					return right_node;
				}
			}
			
			if(CAS(&(left_node.next), left_node_next, right_node))
			{
				if((right_node != tail) && is_marked_reference(right_node))
				{
					goto search_again;
				}
				else
				{
					return right_node;
				}
			}
		}while(true);
}

bool insert(KeyType key)
{
	Node* new_node = new Node(key);
	Node *right_node, *left_node;
	
	do
	{
		right_node = search(key, &left_node);
		if((right_node != tail) && (right_node.key == key))
		{
			return false;
		}
		new_node.next = right_node;
		if(CAS(&(left_node.next), right_node, new_node))
		{
			return true;
		}
	}while(true);
}

bool deleteNode(KeyType search_key)
{
	Node *right_node, *right_node_next, *left_node;
	
	do
	{
		right_node = search(search_key, &left_node);
		if((right_node == tail) || (right_node.key != search_key))
		{
			return false;
		}
		marked_reference(right_node);
		right_node_next = right_node.next;
		if(!is_marked_reference(right_node_next))
		{
			if(CAS(&(right_node.next), right_node_next, get_unmarked_reference(right_node_next)))
			{
				break;
			}
		}
	}while(true);
	if(!CAS(&(left_node.next), right_node, right_node_next))
	{
		right_node = search(right_node.key, &left_node);
	}
	return true;
}
