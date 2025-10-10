#include <cassert>
#include <iostream>
#include <stack>
#include "MutantStack.hpp"
#include "Node.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(3);
	mstack.push(2);
	mstack.push(1);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	(void)it;
	(void)ite;
	++it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	while (it != ite)
	{
		std::cout << *it << "\t";
		++it;
	}
	std::cout << std::endl;
	// std::stack<int> s(mstack);
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
