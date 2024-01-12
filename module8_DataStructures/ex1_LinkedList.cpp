#include <iostream>
#include <iomanip>
using std::cout;


/*
* CLASS DECLARATION
*/
class Node {
private:
    int value;
    Node *next; 
    Node *prev;

public:
    Node(int value = 0, Node *next = nullptr, Node *prev = nullptr)  //constructor
    : value(value), next(next), prev(prev) {} 

    //function to link to the next node
    void linkNextNode(Node *nextNode){
        next = nextNode;
        if (nextNode != nullptr) {
            nextNode->prev = this;  //link backward from nextNode
        }
    }

    //function to link to the previous node  
    void linkPrevNode(Node *prevNode){
        prev = prevNode;
        if (prevNode != nullptr) {
            prevNode->next = this; //link forward from nextNode
        }
    }


    friend void showFordwLinks(Node *head);
    friend void showBackwLinks(Node *tail);
    friend void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode);
    friend void swapNodes(Node *&headNode, Node *&tailNode, Node *nodeA, Node *nodeB);
    friend void sortNodesAcend(Node *&headNode, Node *&tailNode);
};



/*
* FUNCTIONS TO SHOW LINKS
*/
void showFordwLinks(Node *head){
    cout << "Forward links : ";
    Node *temp = head; //temp is the current node
    while (temp != nullptr){
        cout << std::setw(3) << temp->value  << " -> "; //value of current node
        temp = temp->next; //go the next node
    }
    cout << "\n";
}

void showBackwLinks(Node *tail){
    cout << "Backward links: ";
    Node *temp = tail; //temp is the current node
    while (temp != nullptr){
        cout << std::setw(3) << temp->value << " -> "; //value of current node
        temp = temp->prev; //go the previous node  
    }
    cout << "\n";
}

void showLinks(Node *head, Node *tail){
    showFordwLinks(head);
    showBackwLinks(tail);
}

/*
* FUNCTION TO INSERT NODE
*/
//Note: *& is pass-by-reference for the pointer variable
//(same as pass-by-reference for a normal data type)

void insertNode(Node *&headNode, Node *&tailNode, Node *priorNode, Node *newNode){
    if (priorNode == nullptr) { //Inserting at the beginning
        //Connect newNode to the current head
        newNode->linkNextNode(headNode);

        //the newNode become the new head
        headNode = newNode;

    } else if (priorNode == tailNode){ //Inserting at the end
        //Connect tailNode to the newNode
        tailNode->linkNextNode(newNode);

        //the newNode become the new tail
        tailNode = newNode;

    } else { //Inserting at the middle
        //Connect newNode to the node after the priorNode
        newNode->linkNextNode(priorNode->next);

        //Connect priorNode to the newNode
        priorNode->linkNextNode(newNode);
    }
}

/*
* FUNCTION TO DELETE NODE: TRY IT YOURSELF
*/

/*
* FUNCTION TO SWAP NODES
*/
void swapNodes(Node *&headNode, Node *&tailNode, Node *nodeA, Node *nodeB){
    //store all values of NodeB first (since its values will be changed)
    Node temp = *nodeB;

    //A stands before B --> after swapping, B will stand before A
    if (nodeB->prev == nodeA) { 
        nodeB->linkPrevNode(nodeA->prev);  //second way:  (nodeA->prev)->linkNextNode(nodeB); 
        nodeB->linkNextNode(nodeA);
        nodeA->linkNextNode(temp.next);

    //B stands before A --> after swapping, A will stand before B
    } else if (nodeB->next == nodeA) {
        nodeB->linkNextNode(nodeA->next);
        nodeB->linkPrevNode(nodeA);
        nodeA->linkPrevNode(temp.prev);

    } else { //Normal case
        //Connect B with next node of A
        nodeB->linkNextNode(nodeA->next);
        //Connect B with previous node of A
        nodeB->linkPrevNode(nodeA->prev);

        //Connect A with next node of B
        nodeA->linkNextNode(temp.next);
        //Connect A with previous node of B
        nodeA->linkPrevNode(temp.prev);
    }

    //Update the head and the tail if A or B is head/ tail
    headNode =  (headNode == nodeA) ? nodeB :  
                (headNode == nodeB) ? nodeA : headNode;

    tailNode =  (tailNode == nodeA) ? nodeB :
                (tailNode == nodeB) ? nodeA : tailNode;
}

/*
* FUNCTION TO SORT USING BUBBLE SORT (ASCENDING: left < right)
*/
void sortNodesAcend(Node *&headNode, Node *&tailNode){
    while (1) {
        int swap = 0; //did not swap yet

        //Loop to go from the left (starting from head)
        for (Node *node = headNode; node != nullptr && node != tailNode; ){
            //compare current node with the next node and swap if not in correct order
            if (node->value > node->next->value){
                swapNodes(headNode, tailNode, node, node->next);
                swap = 1; //already swapped at least once
            } else {
                node = node->next; //go to next node
            }
        }

        if (swap == 0)// no swapping above (the list is already sorted)
            break;
    }
}

int main() {
    //Qa
    Node node1(8), node2(5), node3(3), node4(6);

    //Connect nodes
    Node *head = &node1;   //head is a pointer variable
    node1.linkNextNode(&node2);
    node2.linkNextNode(&node3);
    node3.linkNextNode(&node4);  
    Node *tail = &node4;   //tail is a pointer variable

    //show connections
    cout << "Original linked list: \n";
    showLinks(head, tail);


    // Qb)
    // Test insert node in the middle
    cout << "\nInsert 200 after 3: \n";
    Node newNode1(200);
    insertNode(head, tail, &node3, &newNode1);
    showLinks(head, tail);

    //Test replace the head
    cout << "\nInsert 100 at the head: \n";
    Node newNode2(100);
    insertNode(head, tail, nullptr, &newNode2);
    showLinks(head, tail);


    //Qc Swap nodes
    cout << "\nTest Swapping 8 and 3: \n";
    swapNodes(head, tail, &node1, &node3);
    showLinks(head, tail);

    //Qd Sorting with Bubble Sort
    cout << "\nTest Sorting: \n";
    sortNodesAcend(head, tail);
    showLinks(head, tail);

    return 0;
}