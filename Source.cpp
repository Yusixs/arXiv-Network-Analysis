#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"
#include <thread>
#include <windows.h>  

using namespace std;

int main() {

	// Initialization and reading the file until the graph starts

	int totalNodes = 0, totalEdges = 0;
	ifstream file("CA-GrQc.txt");
	string temp;

	getline(file, temp);
	getline(file, temp);
	file >> temp >> temp >> temp;
	totalNodes = stoi(temp);
	file >> temp >> temp;
	totalEdges = stoi(temp);
	getline(file, temp);
	getline(file, temp);

	// Graph Construction

	Graph g(totalNodes, totalEdges);
	Graph undirected(totalNodes, totalEdges);

	int edge = 0, node = 0;

	for (int i = 0; i < totalEdges; i++) {
		
		file >> node >> edge;
		g.addEdge(node, edge);
		undirected.addUndirectedEdge(node, edge);

	}
	
	int input = 0;
	char c;

	// Loop Menu system

	do {

		system("cls");
		cout << "Welcome to Network Analysis of Arxiv GR-QC (General Relativity and Quantum Cosmology)" << endl;
		cout << "Please select an option to run (Input 0 to exit): " << endl;
		cout << "\t1 - Display Number of Nodes & Edges" << endl;
		cout << "\t2 - Display Number of Source Nodes & Sink Nodes & Isolates Nodes" << endl;
		cout << "\t3 - Display Number of Articulation Nodes & Bridge Edges" << endl;
		cout << "\t4 - Display Path Length Distribution & Diamater" << endl;
		cout << "\t5 - Display in-Degree Distribution" << endl;
		cout << "\t6 - Display out-Degree Distribution" << endl;
		cout << "\t7 - Display Size Distribution of SCC and Largest SCC" << endl;
		cout << "\t8 - Display Size Distribution of WCC and Largest WCC" << endl;
		cout << endl << "Choice: ";
		cin >> c;
		cout << endl;

		input = int(c - '0');

		if (input == 0)
			break;

		if (input > 8 || input < 1) {
			system("cls");
			cout << "Wrong Input!" << endl;
			system("cls");
			continue;
		}

		switch (input) {
			case 1:
				cout << "Total Nodes = " << totalNodes << endl;
				cout << "Total Edges = " << totalEdges << endl;
				Sleep(10000);
				break;
			case 2:
				g.countSourceNodes();
				g.countSinkNodes();
				g.countIsolatedNodes();
				Sleep(10000);
				break;
			case 3:
				g.displayArticulationNodes();
				g.displayBridges();
				Sleep(10000);
				break;
			case 4:
				g.displayPathTable();
				Sleep(10000);
				break;
			case 5:
				g.inDegreeTable();
				Sleep(10000);
				break;
			case 6:
				g.outDegreeTable();
				Sleep(10000);
				break;
			case 7:
				g.displaySccTable();
				Sleep(15000);
				break;
			case 8:
				g.displayWccTable(&undirected);
				Sleep(15000);
				break;
		}


	} while (1);

	return 0;
}