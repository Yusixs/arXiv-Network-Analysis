#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

using namespace std;

// Group Members
// Sarim Aeyzaz i21-0328
// Ehtsham Walidad i21-0260

// Node class used for making Linked List
int* diameter = new int[10001];
class Node {
    int data;
    Node* next;
public:
    // Parameterised Constructor
    Node(int v = 0) {
        data = v;
        next = 0;
    }

    // Getters and setters
    int getData() { return data; }
    Node* getNext() { return next; }
    void setData(int v) { data = v; }
    void setNext(Node* n) { next = n; }
};

class LinkedList {
    Node* head;
public:
    LinkedList() {
        head = 0;
    }

    Node* getHead() {
        return head;
    }

    void setHead(Node* h) {
        head = h;
    }

    int countList() {
        if (head == 0) {
            return 0;
        }
        else {
            int count = 0;
            Node* temp = head;
            while (temp) {
                count++;
                temp = temp->getNext();
            }
            return count;
        }
    }

    int countNeighbours() {
        if (head == 0) {
            return 0;
        }
        else {
            int count = 0;
            Node* temp = head->getNext();
            while (temp) {
                count++;
                temp = temp->getNext();
            }
            return count;
        }
    }

    bool insertAtHead(int value) {
        if (head == 0) {                            // If head is empty, insert value at head
            head = new Node(value);
        }
        else {
            Node* temp = new Node();                // If head exists, create a new node and set that as head
            temp->setNext(head);
            temp->setData(value);
            head = temp;
        }
        return true;
    }

    bool insertAtEnd(int value) {
        if (head == 0) {                            // If head is empty, insert value at head
            head = new Node(value);
        }
        else {
            Node* temp = head;                      // If head exists, bring a temp pointer to the last node (not NULL!), and set a new node there in temp->setNext()
            while (temp->getNext() != 0) {
                temp = temp->getNext();
            }
            temp->setNext(new Node(value));
        }
        return true;
    }

    bool search(int value) {
        if (head == 0) {                            // If head is empty, insert value at head
            return false;
        }
        else {
            Node* temp = head;                      // If head exists, bring a temp pointer to the last node (not NULL!), and set a new node there in temp->setNext()
            while (temp != 0) {
                if (temp->getData() == value)
                    return true;
                temp = temp->getNext();
            }
        }
        return false;
    }

    bool searchNeighbours(int value) {
        if (head == 0) {                            // If head is empty, insert value at head
            return false;
        }
        else {
            Node* temp = head->getNext();           // If head exists, bring a temp pointer to the last node (not NULL!), and set a new node there in temp->setNext()
            while (temp != 0) {
                if (temp->getData() == value)
                    return true;
                temp = temp->getNext();
            }
        }
        return false;
    }

    void display() {
        if (head == 0) {                            // If head is empty, return a cout statement
            cout << "The list is empty" << endl;
            return;
        }
        else {
            Node* temp = head;                      // If head exists, create a temp pointer which cout's each value and traverses the linked list
            while (temp != 0) {
                cout << temp->getData() << " ";
                temp = temp->getNext();
            }
            cout << endl;
        }
    }

    bool insertAfter(int checkValue, int value) {
        if (head == 0)                              // If head doesn't exist, return false
            return false;

        Node* temp = head;                          // Traverse the linked list until either one of these conditions become false
        while (temp != NULL && temp->getData() != checkValue)
            temp = temp->getNext();

        if (temp == 0)                              // If temp reaches null before finding the value, return false
            return false;

        Node* temp2 = new Node(value);              // Otherwise, create a new node and set it's next address as the curren't node's next address
        temp2->setNext(temp->getNext());
        temp->setNext(temp2);                       // Set the next address of current node as the new node
        return true;
    }

    bool deleteNode(int v) {
        if (head == 0)                              // If head doesn't exist, return false
            return false;

        Node* temp = head->getNext();               // Traverse the array with 2 trailing pointers, one after another
        Node* temp2 = head;
        while (temp != 0 && temp->getData() != v) { // Traverse the linked list until either one of these conditions become false
            temp2 = temp2->getNext();
            temp = temp->getNext();
        }

        if (temp == 0)                              // If temp reaches null before finding the value, return false
            return false;

        Node* tempAddress = temp->getNext();        // create a temporary address holding the current value's node's next address
        delete temp;                                // Delete current note
        temp = 0;
        temp2->setNext(tempAddress);                // Set the trailer's next adddress as tempAddress variable
        return true;
    }

    bool deleteAtStart() {
        if (head == 0)                              // Check if head exists
            return false;

        Node* temp = head;                          // Otherwise, store's head's node as temp node
        head = head->getNext();                     // Set head's address as next address
        delete temp;                                // Delete temp node
        temp = 0;
        return true;
    }

    bool deleteAtEnd() {
        if (head == 0)                              // Check if head exists
            return false;

        Node* temp = head->getNext();               // Create 2 pointers traversing the linked list, one after another
        Node* temp2 = head;
        while (temp->getNext() != 0) {              // Traverse the list until the first one reaches the last node
            temp = temp->getNext();
            temp2 = temp2->getNext();
        }
        delete temp;                                // Delete the last node and set the previous pointer's address as null
        temp = 0;
        temp2->setNext(0);
        return true;
    }

    bool clearList() {
        if (head == 0)                              // Check if head exists
            return true;

        Node* temp = head;
        while (temp != 0) {                         // We're basically doing the deleteAtStart() code but for the whole list
            temp = temp->getNext();
            delete head;
            head = 0;
            head = temp;
        }
        return true;

    }

    bool deleteNode(Node* address) {
        if (head == 0)                              // Check if head exists
            return false;

        Node* temp = head->getNext();
        Node* temp2 = head;
        while (temp != 0 && temp->getNext() != address) {       // Traverse the list with 2 pointers, one after another until one of the conditions return false
            temp2 = temp2->getNext();
            temp = temp->getNext();
        }

        if (temp == 0)                              // Return if temp reaches the end before finding the value
            return false;

        Node* tempAddress = temp->getNext();        // Otherwise create a tempAddress node storing the current node's next address
        delete temp;                                // Delete current node
        temp = 0;
        temp2->setNext(tempAddress);                // Set previous pointer's address as tempAddress
        return true;
    }
};

class Queue {
    Node* front;
    Node* rear;
public:

    // Constructor
    Queue() {
        front = 0;
        rear = 0;
    }

    // Return true if queue is empty, else false
    bool isEmpty() {
        if (front == 0)
            return true;
        return false;
    }

    // Insert at tail function from linked list
    bool enQueue(int v) {
        if (front == 0) {
            front = new Node(v);
            rear = front;
        }
        else {
            Node* temp = new Node(v);
            rear->setNext(temp);
            rear = temp;
        }
        return true;
    }

    // Remove at head function from linked list
    int deQueue() {
        if (front == 0) {
            cout << "Error: Stack is empty" << endl;
            return INT_MIN;
        }

        Node* temp = front;
        int c = temp->getData();
        front = front->getNext();
        delete temp;
        temp = 0;
        return c;
    }

    // Show the first integer of the queue
    int showFront() {
        if (front == 0) {
            cout << "Error: Stack is empty" << endl;
            return -32000;
        }

        return front->getData();
    }

    // Show the rear integer of the queue
    int showRear() {
        if (rear == 0) {
            cout << "Error: Stack is empty" << endl;
            return -32000;
        }

        return rear->getData();
    }

    // Display the entire queue (used for debugging only!)
    void displayQueue() {
        Node* temp = front;
        while (temp != 0) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }


};

class Graph {
    int numberOfVertices;
    int numberOfEdges;
    LinkedList** vertexlist;
    static int currentListsCreated;
    static int currentUnDirectedListsCreated;
public:
    Graph(int v, int e) {
        numberOfVertices = v;
        numberOfEdges = e;
        vertexlist = new LinkedList * [v];
    }

    // Helper function to return undirected graph's linked list count
    int getCurrentUnDirectedListsCreated() {
        return currentUnDirectedListsCreated;
    }

    // Helper function to get head node's value
    int getUnDirectedLinkedListHeadValue(int index) {
        for (int i = 0; i < currentUnDirectedListsCreated; i++) {
            if (i == index) {
                return vertexlist[i]->getHead()->getData();
            }
        }
    }

    // Add a directed edge in the graph
    void addEdge(int num1, int num2) {

        // Only add those nodes which are not in the vertexlist

        bool num1InList = false;
        bool num2InList = false;
        for (int i = 0; i < currentListsCreated; i++) {
            if (vertexlist[i]->getHead()->getData() == num1)
                num1InList = true;
            if (vertexlist[i]->getHead()->getData() == num2)
                num2InList = true;
        }

        if (!num1InList) {
            vertexlist[currentListsCreated] = new LinkedList;
            vertexlist[currentListsCreated]->insertAtEnd(num1);
            currentListsCreated++;
        }

        // The second check is the make sure a node pointing to itself isn't inserted in the vertexlist twice

        if (!num2InList && num1 != num2) {
            vertexlist[currentListsCreated] = new LinkedList;
            vertexlist[currentListsCreated]->insertAtEnd(num2);
            currentListsCreated++;
        }

        // At the end, insert num2 as neighbour of num1

        for (int i = 0; i < currentListsCreated; i++) {
            if (vertexlist[i]->getHead()->getData() == num1)
                vertexlist[i]->insertAtEnd(num2);
        }


    }

    // Add an undirected edge in the graph
    void addUndirectedEdge(int num1, int num2) {

        // Only add those nodes which are not in the vertexlist

        bool num1InList = false;
        bool num2InList = false;
        for (int i = 0; i < currentUnDirectedListsCreated; i++) {
            if (vertexlist[i]->getHead()->getData() == num1)
                num1InList = true;
            if (vertexlist[i]->getHead()->getData() == num2)
                num2InList = true;
        }

        if (!num1InList) {
            vertexlist[currentUnDirectedListsCreated] = new LinkedList;
            vertexlist[currentUnDirectedListsCreated]->insertAtEnd(num1);
            currentUnDirectedListsCreated++;
        }

        // The second check is the make sure a node pointing to itself isn't inserted in the vertexlist twice

        if (!num2InList && num1 != num2) {
            vertexlist[currentUnDirectedListsCreated] = new LinkedList;
            vertexlist[currentUnDirectedListsCreated]->insertAtEnd(num2);
            currentUnDirectedListsCreated++;
        }

        // At the end, insert num2 as neighbour of num1

        for (int i = 0; i < currentUnDirectedListsCreated; i++) {
            if (vertexlist[i]->getHead()->getData() == num1)
                vertexlist[i]->insertAtEnd(num2);
            if (vertexlist[i]->getHead()->getData() == num2)
                vertexlist[i]->insertAtEnd(num1);
        }


    }

    // Count the total Sink Nodes by counting how many nodes point to nothing as their neighbour
    void countSinkNodes() {

        int count = 0;
        for (int i = 0; i < currentListsCreated; i++)
            if (vertexlist[i]->getHead()->getNext() == NULL)
                count++;
        cout << "Total Sink Nodes = " << count << endl;

    }

    // Count the total source nodes by counting how many nodes are not present in any neighbour list
    void countSourceNodes() {

        int count = 0;

        for (int i = 0; i < currentListsCreated; i++) {
            int value = vertexlist[i]->getHead()->getData();
            bool found = false;
            for (int j = 0; j < currentListsCreated; j++) {
                if (vertexlist[j]->search(value) == true) {
                    count++;
                    break;
                }
            }
        }
        cout << "Total Source Nodes = " << numberOfVertices - count << endl;
    }

    // Count the total Isolated Nodes by counting how many nodes exhibit properties of both sink and source node
    void countIsolatedNodes() {

        int count = 0;
        for (int i = 0; i < currentListsCreated; i++) {
            bool isSource = true, isSink = true;
    
            if (vertexlist[i]->getHead()->getNext() == NULL)
                isSink = false;
        
            int value = vertexlist[i]->getHead()->getData();
            for (int j = 0; j < currentListsCreated; j++) {
                if (vertexlist[j]->search(value) == false) {
                    isSource = true;
                    break;
                }
            }

            if (isSink == false && isSource == false)
                count++;
        }

        cout << "Total Isolated Nodes = " << count << endl;

    }

    // Displays the graph
    void displayNodes() {
        for (int i = 0; i < currentListsCreated; i++) {
            vertexlist[i]->display();
        }

    }

    // Displays a table showing how many nodes are of out-degree 'k' and what is their probability distribution
    // Over here, array's index is used as the 'degree' and the value is used as the 'count'. This is to avoid a whole layer of complexity
    void outDegreeTable() {

        int* arr = new int[numberOfVertices + 1];
        for (int i = 0; i <= numberOfVertices; i++)
            arr[i] = 0;

        // Loop 0 degree to largest degree
        for (int i = 0; i < currentListsCreated; i++) {
            int value = vertexlist[i]->countNeighbours();
            arr[value] = arr[value] + 1;
        }
        cout << "Out-Degree distribution table" << endl << endl;
        cout << "Degree\tCount\tProbability Distribution" << endl;

        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0)
                cout << i << "\t" << arr[i] << "\t" << float(arr[i]) / float(numberOfVertices) << endl;

        delete[] arr;
    }

    // Displays a table showing how many nodes are of in-degree 'k' and what is their probability distribution
    // Over here, array's index is used as the 'degree' and the value is used as the 'count'. This is to avoid a whole layer of complexity
    void inDegreeTable() {

        int* arr = new int[numberOfVertices + 1];
        for (int i = 0; i <= numberOfVertices; i++)
            arr[i] = 0;
       

        for (int i = 0; i < currentListsCreated; i++) {
            int count = 0;
            int value = vertexlist[i]->getHead()->getData();
            for (int j = 0; j < currentListsCreated; j++)
                if (vertexlist[j]->searchNeighbours(value) == true) 
                    count++; 
            arr[count] = arr[count] + 1; // False positive error caused by static variable
        }

        cout << "In-Degree distribution table" << endl << endl;
        cout << "Degree\tCount\tProbability Distribution" << endl;

        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0)
                cout << i << "\t" << arr[i] << "\t" << float(arr[i]) / float(numberOfVertices) << endl;

        delete[] arr;
    }

    // Returns a list of nodes linked with the node 'v' by using Breadth-First search. It uses a queue-based system to dequeue the front and enqueue it's neighbours in the back
    // A check is also done to make sure no repeated nodes end up in the queue so the final list doesn't become invalidated
    // Finally, return the list
    LinkedList* BFS(int v) {
        LinkedList* nodes = new LinkedList;
        Queue q;
        q.enQueue(v);
        nodes->insertAtEnd(v);
        while (!q.isEmpty()) {
            int v = q.deQueue();
            for (int i = 0; i < currentListsCreated; i++) {
                if (v == vertexlist[i]->getHead()->getData()) {
                    Node* temp = vertexlist[i]->getHead()->getNext();
                    while (temp) {
                        if (!nodes->search(temp->getData())) {
                            q.enQueue(temp->getData());
                            nodes->insertAtEnd(temp->getData());
                        }
                        temp = temp->getNext();
                    }
                }
            }
        }
        nodes->deleteAtStart();
        return nodes;
    }

    // Gathers a list of all nodes that point towards the node 'v'
    LinkedList* inAlgorithm(int v) {
        LinkedList* inNodes = new LinkedList;
        for (int i = 0; i < currentListsCreated; i++) {
            LinkedList* bfsList = BFS(vertexlist[i]->getHead()->getData());
            if (bfsList->search(v))  
                inNodes->insertAtEnd(vertexlist[i]->getHead()->getData());
            bfsList->clearList();
        }
        return inNodes;
    }

    // Gathers a list of all nodes that point away from node 'v'
    LinkedList* outAlgorithm(int v) {
        LinkedList* outNodes = 0;
        outNodes = BFS(v);
        return outNodes;
    }

    // Return the list of all the nodes which are found commonly between the inAlgorithm and outAlgorithm of each node
    LinkedList* SCNodesORIGINAL() {
        LinkedList* scc = new LinkedList;
        for (int i = 0; i < currentListsCreated; i++) {
            LinkedList* inNodes = inAlgorithm(vertexlist[i]->getHead()->getData());
            LinkedList* outNodes = outAlgorithm(vertexlist[i]->getHead()->getData());
            Node* temp = inNodes->getHead();
            while (temp) {
                if (outNodes && outNodes->search(temp->getData()))
                    scc->insertAtEnd(temp->getData());
                temp = temp->getNext();
            }
            inNodes->clearList();
            outNodes->clearList();
        }

        LinkedList* sccUnique = new LinkedList;
        Node* temp = scc->getHead();
        while (temp) {
            if (!sccUnique->search(temp->getData()))
                sccUnique->insertAtEnd(temp->getData());
            temp = temp->getNext();
        }
        scc->clearList();
        return sccUnique;
    }
    
    // Since in the project, it is mentioned that every cluster is a completely connected sub-graph, we will use this fine-tuned version which will reduce the complexity
    // of finding SCC Nodes by A LOT. This approach still works due to the graph having 0 sink, source and isolates nodes, causing it to become symmetric and fully connected
    // and so, according to graph theory, every cluster will have every node as an SCC Node
    // Therefore, just return a list of all the nodes in the graph
    LinkedList* SCNodes() {
        LinkedList* scc = new LinkedList;
        for (int i = 0; i < currentListsCreated; i++)
            scc->insertAtEnd(vertexlist[i]->getHead()->getData());
        return scc;
    }

    // We will use an array here where index will represent the SCC Cluster size and the value will represent the count (reduce time complexity by O(n))
    // Loop over every singly SCC node and generate its BFS
    // Get the count of nodes in the BFS are included in the SCC List
    // Increment the array's value accordingly (arr[count] = arr[count] + 1)
    // Iterate over the next SCC Node
    // Shortcut skip: if the next scc node is already in the previous BFS, that means it will generate the same BFS since this is a fully connected cluster graph
    // So, just increment the count again, get the next value and continue to the next iteration
    // Over here, the position of clusterCount = 0 is key as when we are using the shortcut skip, we don't want it to increment arr[0]'s size by 1, we want to incrememnt the current size's value instead
    // Finally, generate a text file and store the array
    void sccTable() {
        
        int* arr = new int[numberOfVertices + 1];
        for (int i = 0; i <= numberOfVertices; i++)
            arr[i] = 0;
        

        LinkedList* scc = SCNodes();
        LinkedList* bfs = new LinkedList;
        int count = 0;
        int clusterCount = 0;

        Node* temp = scc->getHead();
        while (temp) {

            cout << count << " ";
            count++;

            if (bfs->search(temp->getData())) {
                arr[clusterCount] = arr[clusterCount] + 1;
                temp = temp->getNext();
                continue;
            }
            
            bfs->clearList();
            bfs = BFS(temp->getData());
            
            clusterCount = 0;
            
            Node* temp2 = bfs->getHead();
            while (temp2) {
                if (scc->search(temp2->getData()))
                    clusterCount++;
                temp2 = temp2->getNext();
            }

            arr[clusterCount] = arr[clusterCount] + 1;
            temp = temp->getNext();
        }
        bfs->clearList();
        scc->clearList();

        ofstream myFile("scctable.txt");
        for (int i = 0; i <= numberOfVertices; i++)
            myFile << arr[i] << "\n";

        myFile.close();
        delete[] arr;

    }

    // Check if the file exists, if not, generate it and then load it to an array
    // Now display the distribution table where index of the array = size and it's value = count of the size
    // Also display the largest SCC
    void displaySccTable() {

        ifstream myFile("scctable.txt");
        if (!myFile) {
            myFile.close();
            sccTable();
            ifstream myFile("scctable.txt");
        }

        int value = 0;
        int* arr = new int[numberOfVertices + 1];
        arr[0] = 0;
        for (int i = 1; i <= numberOfVertices; i++) {
            myFile >> value;
            arr[i] = value;
        }


        cout << "SCC distribution table" << endl << endl;
        cout << "Size\tCount\tProbability Distribution" << endl;

        int max = INT_MIN;
        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0 && max < arr[i])
                max = arr[i];

        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0)
                cout << i << "\t" << arr[i] << "\t" << float(arr[i]) / float(numberOfVertices) << endl;

        cout << endl << "Largest SCC = " << max << endl << "Probability of largest SCC = " << float(max) / float(numberOfVertices) << endl;

        myFile.close();
        delete[] arr;
    }

    // Exact same logic as SC Nodes but this time, any BFS/vertexlist stuff is grabbed from an undirected version of this graph
    LinkedList* WCNodesOriginal(Graph* undirected) {
        LinkedList* wccNodes = new LinkedList;
        int undirectedCount = undirected->getCurrentUnDirectedListsCreated();
        for (int i = 0; i < undirectedCount; i++) {
            LinkedList* bfs = undirected->BFS(undirected->getUnDirectedLinkedListHeadValue(i));
            Node* temp = bfs->getHead();
            while (temp) {
                wccNodes->insertAtHead(temp->getData());
                temp = temp->getNext();
            }
            bfs->clearList();
        }

        LinkedList* wccUnique = new LinkedList;
        Node* temp = wccNodes->getHead();
        while (temp) {
            if (!wccUnique->search(temp->getData()))
                wccUnique->insertAtEnd(temp->getData());
            temp = temp->getNext();
        }
        wccNodes->clearList();
        return wccUnique;
    }

    // Same as SCNodes logic
    LinkedList* WCNodes(Graph* undirected) {
        LinkedList* wcc = new LinkedList;
        for (int i = 0; i < currentListsCreated; i++)
            wcc->insertAtEnd(vertexlist[i]->getHead()->getData());
        return wcc;
    }

    // Same as scc Table logic
    void wccTable(Graph* undirected) {

        int* arr = new int[numberOfVertices + 1];
        for (int i = 0; i <= numberOfVertices; i++)
            arr[i] = 0;

        LinkedList* wcc = WCNodes(undirected);
        LinkedList* bfs = new LinkedList;
        
        int count = 0;
        int clusterCount = 0;

        Node* temp = wcc->getHead();
        while (temp) {

            cout << count << " ";
            count++;

            if (bfs->search(temp->getData())) {
                arr[clusterCount] = arr[clusterCount] + 1;
                temp = temp->getNext();
                continue;
            }

            bfs->clearList();
            bfs = undirected->BFS(temp->getData());

            // Unique BFS Lists
            clusterCount = 0;

            Node* temp2 = bfs->getHead();
            while (temp2) {
                if (wcc->search(temp2->getData()))
                    clusterCount++;
                temp2 = temp2->getNext();
            }

            arr[clusterCount] = arr[clusterCount] + 1;
            temp = temp->getNext();
        }
        bfs->clearList();
        wcc->clearList();

        ofstream myFile("wcctable.txt");
        for (int i = 0; i <= numberOfVertices; i++)
            myFile << arr[i] << "\n";

        myFile.close();

        delete[] arr;
    }

    // Same as scc display logic
    void displayWccTable(Graph* undirected) {

        ifstream myFile("wcctable.txt");
        if (!myFile) {
            wccTable(undirected);
            ifstream myFile("wcctable.txt");
        }

        int value = 0;
        int* arr = new int[numberOfVertices + 1];
        arr[0] = 0;
        for (int i = 1; i <= numberOfVertices; i++) {
            myFile >> value;
            arr[i] = value;
        }


        cout << "WCC distribution table" << endl << endl;
        cout << "Size\tCount\tProbability Distribution" << endl;

        int max = INT_MIN;
        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0 && max < arr[i])
                max = arr[i];

        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0)
                cout << i << "\t" << arr[i] << "\t" << float(arr[i]) / float(numberOfVertices) << endl;

        cout << endl << "Largest WCC = " << max << endl << "Probability of largest WCC = " << float(max) / float(numberOfVertices) << endl;

        myFile.close();
        delete[] arr;
    }

    // Start from a node and get it's shortest path length w.r.t every other node (over here we used dijkstra's algorithm)
    // Store this array into a file in append mode
    // Repeat until every node's shortest path length is recorded and then close the file
    void pathLengthDistribution() {
        int* arr = new int[numberOfVertices];
        bool* visited = new bool[numberOfVertices];
        
    
        ofstream myFile("pathNumbers.txt");
        ofstream myFile2("pathNumbers2.txt");

        for (int index = 0; index < numberOfVertices; index++) {

            for (int i = 0; i < numberOfVertices; i++) {
                arr[i] = INT_MAX;
                if (i == index)
                    arr[i] = 0;
                visited[i] = false;
            }
        
            cout << index << " ";

            for (int count = 0; count < numberOfVertices - 1; count++) {

                int min = INT_MAX, minIndex;

                for (int i = 0; i < numberOfVertices; i++) {
                    if (visited[i] == false && arr[i] <= min) {
                        min = arr[i];
                        minIndex = i;
                    }
                }

                visited[minIndex] = true;

                for (int i = 0; i < numberOfVertices; i++)
                    if (visited[i] == false && vertexlist[minIndex]->search(vertexlist[i]->getHead()->getData()) && arr[minIndex] != INT_MAX && arr[minIndex] + int(vertexlist[minIndex]->search(vertexlist[i]->getHead()->getData())) < arr[i])
                        arr[i] = arr[minIndex] + int(vertexlist[minIndex]->search(vertexlist[i]->getHead()->getData()));
            }


            for (int i = 0; i < numberOfVertices; i++) {
                myFile << arr[i] << " ";
                if (arr[i] == INT_MAX)
                    arr[i] = 0;
                myFile2 << arr[i] << " ";
            }
            myFile << "\n";
            myFile2 << "\n";
        }

        myFile.close();
        myFile2.close();
        delete[] arr;
        delete[] visited;
    }

    // Check if file exists, if not, generate it and then load it
    // Now create an array where the index will represent the path legnth and the value of the index represents the count of said path length
    // E.g there are 14 paths with path length 17 in this entire network
    // Also display the largest diameter
    void displayPathTable() {
        ifstream myFile("pathNumbers2.txt");
        int* arr = new int[numberOfVertices + 1];
        int value = 0;
        for (int i = 0; i <= numberOfVertices; i++)
            arr[i] = 0;

        int max = INT_MIN;
        while (myFile >> value) {
            if (value != 0)
                arr[value] = arr[value] + 1;
            if (max < value)
                max = value;
        }

        cout << "Path length distribution table" << endl << endl;
        cout << "Length\tCount\tProbability Distribution" << endl;

        int total = 0;
        for (int i = 0; i <= numberOfVertices; i++)
            total += arr[i];

        for (int i = 0; i <= numberOfVertices; i++)
            if (arr[i] != 0)
                cout << i << "\t" << arr[i] << "\t" << float(arr[i]) / float(total) << endl;

        cout << endl << "The largest diameter is: " << max << endl;
    }
    
    // Traverse over every node's edge and disconnect it. However before disconnecting it, record the adjacent node's value
    // Now do a BFS on the parent node and see if the value is still included it (This means there was still another path to this node)
    // Only increase the bridge count when the value is not found in the BFS
    // After the loop ends, store the value in a text file (TAKES A VERY LONG TIME TO RUN)
    void findBridges(int start = 0, int end = currentListsCreated) {
        int count = 0;
        LinkedList* bfs = 0;
        
        ofstream myFile("bridgeCount.txt");

        for (int i = start; i < end; i++) {

            Node* neighbours = vertexlist[i]->getHead()->getNext(); // Loop neighbours

            while (neighbours) {
                int value = neighbours->getData();
                neighbours->setData(-1);
                bfs = BFS(vertexlist[i]->getHead()->getData());
                if (!bfs->search(value))
                    count++;
                neighbours->setData(value);
                neighbours = neighbours->getNext();
                bfs->clearList();
            }
        }

        myFile << count;
        myFile.close();

    }
    
    // Check if the bridgeCount file exists, if not then generate it.
    // Load the value from the file and display it
    void displayBridges() {
    
        ifstream myFile("bridgeCount.txt");
        if (!myFile) {
            findBridges();
            ifstream myFile("bridgeCount.txt");
        }

        int value = 0;
        myFile >> value;
        cout << "Total Bridges = " << value << endl;
        myFile.close();

    }

    // Almost the same logic as bridges but a few details change
    // Traverse over every node and store it's value, now disconnect it (by temporarily changing it to -1).
    // Now do a BFS on all the neighbours of this node 
    // If any one of the BFS's doesn't include the parent node's value, that means the node was an articulation node so increase it count
    // Remember to also break out of the neighbour list's iteration as we do not want a singly articulation node to be counted more than once
    // Finally store the count in the file
    void findArticulationNodes(int start = 0, int end = currentListsCreated) {
        int count = 0;
        LinkedList* bfs = 0;

        ofstream myFile("articulationNodes.txt");

        for (int i = start; i < end; i++) {

            int value = vertexlist[i]->getHead()->getData();
            vertexlist[i]->getHead()->setData(-1);
            Node* neighbours = vertexlist[i]->getHead()->getNext();
            while (neighbours) {
                bfs = BFS(neighbours->getData());
                if (!bfs->search(value)) {
                    count++;
                    break;
                }
                neighbours = neighbours->getNext();
                bfs->clearList();
            }
            bfs->clearList();
            vertexlist[i]->getHead()->setData(value);
        }

        myFile << count;
        myFile.close();

    }

    // Check if the articulationNode file exists, if not then generate it.
    // Load the value from the file and display it
    void displayArticulationNodes() {

        ifstream myFile("articulationNodes.txt");
        if (!myFile) {
            findArticulationNodes();
            ifstream myFile("articulationNodes.txt");
        }

        int value = 0;
        myFile >> value;
        cout << "Total Articulation Nodes = " << value << endl;
        myFile.close();

    }

};
int Graph::currentListsCreated = 0;
int Graph::currentUnDirectedListsCreated = 0;
