#include <cassert>
#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

void testMutantStackBasicOperations()
{
	std::cout << "\n=== Testing MutantStack Basic Operations ===\n";
	
	MutantStack<int> mstack;
	
	// Test empty stack
	std::cout << "Initial size: " << mstack.size() << std::endl;
	
	// Test push operations
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top after pushing 5, 17: " << mstack.top() << std::endl;
	std::cout << "Size after 2 pushes: " << mstack.size() << std::endl;
	
	// Test pop
	mstack.pop();
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	std::cout << "Top after pop: " << mstack.top() << std::endl;
	
	// Add more elements
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(3);
	mstack.push(2);
	mstack.push(1);
	
	std::cout << "Final size: " << mstack.size() << std::endl;
	std::cout << "Final top: " << mstack.top() << std::endl;
}

void testMutantStackCopyConstructor()
{
	std::cout << "\n=== Testing MutantStack Copy Constructor ===\n";
	
	MutantStack<int> original;
	original.push(10);
	original.push(20);
	original.push(30);
	
	std::cout << "Original stack size: " << original.size() << std::endl;
	std::cout << "Original stack top: " << original.top() << std::endl;
	
	// Test copy constructor
	MutantStack<int> copy(original);
	std::cout << "Copy stack size: " << copy.size() << std::endl;
	std::cout << "Copy stack top: " << copy.top() << std::endl;
	
	// Modify original to ensure deep copy
	original.push(40);
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original stack size: " << original.size() << std::endl;
	std::cout << "Original stack top: " << original.top() << std::endl;
	std::cout << "Copy stack size: " << copy.size() << std::endl;
	std::cout << "Copy stack top: " << copy.top() << std::endl;
}

void testMutantStackAssignmentOperator()
{
	std::cout << "\n=== Testing MutantStack Assignment Operator ===\n";
	
	MutantStack<int> stack1;
	stack1.push(100);
	stack1.push(200);
	stack1.push(300);
	
	MutantStack<int> stack2;
	stack2.push(999);
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "Stack1 size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
	std::cout << "Stack2 size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
	
	// Test assignment operator
	stack2 = stack1;
	
	std::cout << "After assignment (stack2 = stack1):" << std::endl;
	std::cout << "Stack1 size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
	std::cout << "Stack2 size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
	
	// Modify stack1 to ensure deep copy
	stack1.push(400);
	std::cout << "After modifying stack1:" << std::endl;
	std::cout << "Stack1 size: " << stack1.size() << ", top: " << stack1.top() << std::endl;
	std::cout << "Stack2 size: " << stack2.size() << ", top: " << stack2.top() << std::endl;
}

void testMutantStackIterators()
{
	std::cout << "\n=== Testing MutantStack Iterators ===\n";
	
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(3);
	mstack.push(2);
	mstack.push(1);
	
	std::cout << "Stack contents using iterators: ";
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	
	// Test iterator increment/decrement
	it = mstack.begin();
	std::cout << "First element: " << *it << std::endl;
	++it;
	std::cout << "Second element after increment: " << *it << std::endl;
	--it;
	std::cout << "Back to first element after decrement: " << *it << std::endl;
}

void testStdListComparison()
{
	std::cout << "\n=== Testing std::list with Same Operations ===\n";
	
	std::list<int> lst;
	
	// Basic operations equivalent to stack operations
	std::cout << "Initial size: " << lst.size() << std::endl;
	
	// push_front simulates stack push (LIFO)
	lst.push_front(5);
	lst.push_front(17);
	std::cout << "Front after pushing 5, 17: " << lst.front() << std::endl;
	std::cout << "Size after 2 pushes: " << lst.size() << std::endl;
	
	// pop_front simulates stack pop
	lst.pop_front();
	std::cout << "Size after pop: " << lst.size() << std::endl;
	std::cout << "Front after pop: " << lst.front() << std::endl;
	
	// Add more elements
	lst.push_front(3);
	lst.push_front(5);
	lst.push_front(737);
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);
	
	std::cout << "Final size: " << lst.size() << std::endl;
	std::cout << "Final front: " << lst.front() << std::endl;
	
	// Test copy constructor
	std::cout << "\n--- std::list Copy Constructor ---" << std::endl;
	std::list<int> original;
	original.push_front(10);
	original.push_front(20);
	original.push_front(30);
	
	std::cout << "Original list size: " << original.size() << std::endl;
	std::cout << "Original list front: " << original.front() << std::endl;
	
	std::list<int> copy(original);
	std::cout << "Copy list size: " << copy.size() << std::endl;
	std::cout << "Copy list front: " << copy.front() << std::endl;
	
	original.push_front(40);
	std::cout << "After modifying original:" << std::endl;
	std::cout << "Original list size: " << original.size() << std::endl;
	std::cout << "Original list front: " << original.front() << std::endl;
	std::cout << "Copy list size: " << copy.size() << std::endl;
	std::cout << "Copy list front: " << copy.front() << std::endl;
	
	// Test assignment operator
	std::cout << "\n--- std::list Assignment Operator ---" << std::endl;
	std::list<int> list1;
	list1.push_front(100);
	list1.push_front(200);
	list1.push_front(300);
	
	std::list<int> list2;
	list2.push_front(999);
	
	std::cout << "Before assignment:" << std::endl;
	std::cout << "List1 size: " << list1.size() << ", front: " << list1.front() << std::endl;
	std::cout << "List2 size: " << list2.size() << ", front: " << list2.front() << std::endl;
	
	list2 = list1;
	
	std::cout << "After assignment (list2 = list1):" << std::endl;
	std::cout << "List1 size: " << list1.size() << ", front: " << list1.front() << std::endl;
	std::cout << "List2 size: " << list2.size() << ", front: " << list2.front() << std::endl;
	
	list1.push_front(400);
	std::cout << "After modifying list1:" << std::endl;
	std::cout << "List1 size: " << list1.size() << ", front: " << list1.front() << std::endl;
	std::cout << "List2 size: " << list2.size() << ", front: " << list2.front() << std::endl;
	
	// Test iterators
	std::cout << "\n--- std::list Iterators ---" << std::endl;
	std::list<int> testList;
	testList.push_front(5);
	testList.push_front(17);
	testList.push_front(3);
	testList.push_front(5);
	testList.push_front(737);
	testList.push_front(3);
	testList.push_front(2);
	testList.push_front(1);
	
	std::cout << "List contents using iterators: ";
	std::list<int>::iterator listIt = testList.begin();
	std::list<int>::iterator listIte = testList.end();
	
	while (listIt != listIte)
	{
		std::cout << *listIt << " ";
		++listIt;
	}
	std::cout << std::endl;
	
	listIt = testList.begin();
	std::cout << "First element: " << *listIt << std::endl;
	++listIt;
	std::cout << "Second element after increment: " << *listIt << std::endl;
	--listIt;
	std::cout << "Back to first element after decrement: " << *listIt << std::endl;
}

int main()
{
	std::cout << "=== COMPREHENSIVE MUTANTSTACK TESTS ===\n";
	
	testMutantStackBasicOperations();
	testMutantStackCopyConstructor();
	testMutantStackAssignmentOperator();
	testMutantStackIterators();
	
	testStdListComparison();
	
	std::cout << "\n=== ALL TESTS COMPLETED ===\n";
	return 0;
}
