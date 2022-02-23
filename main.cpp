//Tyler Taormina
//tyler.taormina@oit.edu
//CST 126 Lab 6

#include "LinkedList.h"
#include "Linked.h"

int main()
{
    std::cout << "\n\n***Parameterized constructor test***" << std::endl;
    LList parameter_test(11);
    parameter_test.printList();

    LList a;
    a.pushBack(1);
    a.pushBack(2);
    a.pushBack(3);
    a.pushBack(4);
    std::cout << "\n\n***Linked List a ***" << std::endl;
    a.printList();
    LList c;
    c.pushBack(10);
    c.pushBack(20);
    c.pushBack(30);
    c.pushBack(40);
    std::cout << "\n\n***Linked List b ***" << std::endl;
    c.printList();

    LList b(a);
    std::cout << "\n\n***Copy constructor test***" << std::endl;
    b.printList();

    b = c;
    std::cout << "\n\n***Move constructor test***" << std::endl;
    b.printList();

    LList d;
    d = a;
    std::cout << "\n\n***Copy assigment test***" << std::endl;
    d.printList();

    std::cout << "\n\n***Delete Node test***" << std::endl;
    a.deleteNode(4);
    a.printList();

    std::cout << "\n\n***Get Data test***" << std::endl;
    int result = a.getData();
    std::cout << result << std::endl;

    std::cout << "\n\n***Insert head test***" << std::endl;
    a.insertHead(8);
    a.printList();

    std::cout << "\n\n***Set data test***" << std::endl;
    a.setData(22);
    a.printList();

    std::cout << "\n\n***Get Next test***" << std::endl;
    std::cout << a.getNext() << std::endl;

    std::cout << "\n\n***Get Data test***" << std::endl;
    int result2 = a.getData();
    std::cout << result2 << std::endl;

    std::cout << "\n\n***Delete Linked List test***" << std::endl;
    a.deleteList();
    a.printList();

    return 0;
}
