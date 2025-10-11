#include <cassert>
#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"
#include "Node.hpp"

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

// int main() {
//     std::cout << "Running CustomList::removeBack() tests...\n";

//     // ========================
//     // Test 1: Remove from empty list
//     // ========================
//     {
//         CustomList<int> list;
//         list.removeBack(); // should do nothing
//         assert(list.getHead() == nullptr);
//         std::cout << "✔️  removeBack() on empty list passed.\n";
//     }

//     // ========================
//     // Test 2: Remove from single-node list
//     // ========================
//     {
//         CustomList<int> list;
//         Node<int> n1(42);
//         list.addFront(n1); // list: [42]
//         list.removeBack(); // list should be empty now
//         assert(list.getHead() == nullptr);
//         std::cout << "✔️  removeBack() on single-node list passed.\n";
//     }

//     // ========================
//     // Test 3: Remove last node in multi-element list
//     // ========================
//     {
//         CustomList<int> list;
//         Node<int> n1(10);
//         Node<int> n2(20);
//         Node<int> n3(30);

//         list.addFront(n3); // [30]
//         list.addFront(n2); // [20, 30]
//         list.addFront(n1); // [10, 20, 30]

//         list.removeBack(); // remove 30 → [10, 20]

//         Node<int>* head = list.getHead();
//         assert(head->getContent() == 10);
//         assert(head->getNextNode()->getContent() == 20);
//         assert(head->getNextNode()->getNextNode() == nullptr);
//         std::cout << "✔️  removeBack() on multi-element list passed.\n";
//     }

//     // ========================
//     // Test 4: Remove repeatedly until list is empty
//     // ========================
//     {
//         CustomList<int> list;
//         Node<int> n1(1);
//         Node<int> n2(2);
//         Node<int> n3(3);
//         list.addFront(n3);
//         list.addFront(n2);
//         list.addFront(n1); // [1, 2, 3]

//         list.removeBack(); // [1, 2]
//         list.removeBack(); // [1]
//         list.removeBack(); // []
//         assert(list.getHead() == nullptr);
//         std::cout << "✔️  removeBack() multiple times passed.\n";
//     }

//     // ========================
//     // Test 5: removeBack() works with other types (string)
//     // ========================
//     {
//         CustomList<std::string> strList;
//         Node<std::string> s1("world");
//         Node<std::string> s2("hello");
//         strList.addFront(s1);
//         strList.addFront(s2); // ["hello", "world"]

//         strList.removeBack(); // should remove "world"
//         Node<std::string>* head = strList.getHead();
//         assert(head->getContent() == "hello");
//         assert(head->getNextNode() == nullptr);
//         std::cout << "✔️  removeBack() with strings passed.\n";
//     }

//     std::cout << "✅ All CustomList::removeBack() tests passed successfully!\n";
//     return 0;
// }


// int main()
// {
//     std::cout << "Running CustomList::addFront() tests...\n";

//     // ========================
//     // Test 1: Add to empty list
//     // ========================
//     CustomList<int> list1;
//     Node<int> n1(10);
//     list1.addFront(n1);

//     Node<int>* head = list1.getHead();
//     assert(head != nullptr);
//     assert(head->getContent() == 10);
//     assert(head->getNextNode() == nullptr);
//     assert(list1.getLastNode()->getContent() == 10);

//     // ========================
//     // Test 2: Add multiple nodes to front
//     // ========================
//     Node<int> n2(20);
//     Node<int> n3(30);
//     list1.addFront(n2); // list: [20] -> [10]
//     list1.addFront(n3); // list: [30] -> [20] -> [10]

//     head = list1.getHead();
//     assert(head->getContent() == 30);
//     assert(head->getNextNode()->getContent() == 20);
//     assert(head->getNextNode()->getNextNode()->getContent() == 10);
//     assert(head->getNextNode()->getNextNode()->getNextNode() == nullptr);
//     assert(list1.getLastNode()->getContent() == 10);

//     // ========================
//     // Test 3: AddFront with strings
//     // ========================
//     CustomList<std::string> strList;
//     Node<std::string> s1("world");
//     Node<std::string> s2("hello");

//     strList.addFront(s1); // ["world"]
//     strList.addFront(s2); // ["hello", "world"]

//     Node<std::string>* sHead = strList.getHead();
//     assert(sHead->getContent() == "hello");
//     assert(sHead->getNextNode()->getContent() == "world");
//     assert(sHead->getNextNode()->getNextNode() == nullptr);

//     // ========================
//     // Test 4: AddFront preserves independence (deep copy)
//     // ========================
//     Node<int> external(99);
//     list1.addFront(external);
//     Node<int>* newHead = list1.getHead();
//     assert(newHead != &external); // list created a deep copy
//     assert(newHead->getContent() == 99);

//     std::cout << "✅ All CustomList::addFront() tests passed successfully!\n";
//     return 0;
// }

// int main() {
//     // ========================
//     // Test 1: Node creation
//     // ========================
//     Node<int> node1(10);
//     assert(node1.getContent() == 10);
//     assert(node1.getNextNode() == nullptr);

//     Node<int> node2(20);
//     node1.setNextNode(node2);
//     assert(node1.getNextNode()->getContent() == 20);

//     // ========================
//     // Test 2: CustomList creation
//     // ========================
//     CustomList<int> list;
//     assert(list.getSize() == 0); // assuming empty list returns size 0
//     // Note: adjust if getSize() works differently

//     // ========================
//     // Test 3: Add nodes to CustomList
//     // ========================
//     Node<int> n1(1);
//     Node<int> n2(2);
//     Node<int> n3(3);

//     list.addNode(n1);
//     list.addNode(n2);
//     list.addNode(n3);

//     assert(list.getSize() == 3); // list should now have 3 nodes
//     assert(list.getLastNode()->getContent() == 3); // last node content

//     // ========================
//     // Test 4: Copy constructor
//     // ========================
//     CustomList<int> copyList(list);
//     assert(copyList.getSize() == 3);
//     assert(copyList.getLastNode()->getContent() == 3);

//     // ========================
//     // Test 5: Assignment operator
//     // ========================
//     CustomList<int> assignList;
//     assignList = list;
//     assert(assignList.getSize() == 3);
//     assert(assignList.getLastNode()->getContent() == 3);

//     // ========================
//     // Test 6: Node content & next
//     // ========================
//     Node<std::string> sn1("hello");
//     Node<std::string> sn2("world");
//     sn1.setNextNode(sn2);

//     assert(sn1.getContent() == "hello");
//     assert(sn1.getNextNode()->getContent() == "world");

//     std::cout << "All CustomList and Node tests passed!\n";
//     return 0;
// }

// #include <cassert>
// #include <iostream>
// #include "Node.hpp"

// int main() {
//     std::cout << "Running Node tests...\n";

//     // ========================
//     // Test 1: Copy constructor copies content correctly
//     // ========================
//     Node<int> n1(42);
//     Node<int> n2(n1); // Copy constructor

//     assert(n2.getContent() == 42); // content copied
//     assert(&n2 != &n1);            // distinct objects
//     assert(n2.getNextNode() == nullptr); // typically should not copy links automatically

//     // ========================
//     // Test 2: Assignment operator copies content correctly
//     // ========================
//     Node<int> n3(99);
//     n3 = n1; // Assignment
//     assert(n3.getContent() == 42); // content updated
//     assert(&n3 != &n1);            // still distinct
//     assert(n3.getNextNode() == nullptr); // next pointer not copied

//     // ========================
//     // Test 3: Copy does not share next pointers
//     // ========================
//     Node<int> nextNode(100);
//     n1.setNextNode(nextNode);

//     Node<int> n4(n1);
//     assert(n4.getContent() == 42);
//     assert(n4.getNextNode() == nullptr); // deep copy shouldn’t link to same next node
//     assert(n1.getNextNode() != nullptr);
//     assert(n1.getNextNode()->getContent() == 100);

//     // ========================
//     // Test 4: Different types (string)
//     // ========================
//     Node<std::string> s1("Hello");
//     Node<std::string> s2(s1);
//     assert(s2.getContent() == "Hello");

//     Node<std::string> s3("World");
//     s3 = s1;
//     assert(s3.getContent() == "Hello");

//     std::cout << "✅ All Node copy/assignment tests passed successfully!\n";
//     return 0;
// }
