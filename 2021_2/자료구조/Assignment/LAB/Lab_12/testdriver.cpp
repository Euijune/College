/*
	해당 cpp파일은 Q1, Q2를 테스트하는데 사용
*/

#include <iostream>
#include "GraphType.h"
#include <string>

std::string V[13] = { "dog", "cat", "animal", "vertebrate", "oyster", "shellfish",
"invertebrate", "crab", "poodle", "monkey", "banana", "dalmatian", "dachshund"};

std::pair<std::string, std::string> E[11] = { {"vertebrate", "animal"}, {"invertebrate", "animal"}, {"dog", "vertebrate"},
	{"cat", "vertebrate"}, {"monkey", "vertebrate"}, {"shellfish", "invertebrate"}, {"crab", "shellfish"},
	{"oyster", "invertebrate"}, {"poodle", "dog"}, {"dalmatian", "dog"}, {"dachshund", "dog"} };


int main() {
	GraphType<std::string> g;

	for (std::string vertex : V)
		g.AddVertex(vertex);

	int n = 10;
	for (auto edge : E) {
		g.AddEdge(edge.first, edge.second, n);
		n += 10;
	}

	std::cout << "Weight of vertebrate to animal is " << g.WeightIs(E[0].first, E[0].second) << '\n';
	std::cout << "Weight of poodle to dog is " << g.WeightIs(E[8].first, E[8].second) << '\n';

	// test Q2
	/*g.DeleteEdge("poodle", "dog");
	std::cout << "Weight of poodle to dog is " << g.WeightIs(E[8].first, E[8].second) << '\n';
	std::cout << '\n' << "GetToVertice(poodle, queue)" << '\n';
	QueType<std::string> q;
	g.GetToVertices("poodle", q);
	while (!q.IsEmpty()) {
		std::string item;
		q.Dequeue(item);
		std::cout << item << '\n';
	}*/

	// test Q3
	std::cout << "\n\n";
	g.DepthFirstSearch("dalmatian", "animal");

	g.AddVertex("apple");
	g.DeleteEdge("dog", "vertebrate");
	g.AddEdge("dog", "oyster", 200);
	g.AddEdge("dog", "banana", 200);
	g.AddEdge("dog", "apple", 200);
	std::cout << "\n\n";
	g.DepthFirstSearch("dalmatian", "animal");
	std::cout << '\n';

	return 0;
}