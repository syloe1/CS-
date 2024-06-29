#ifndef TOPOLOGICAL_SORT_HPP_
#define TOPOLOGICAL_SORT_HPP_
#include <deque>
#include <stdexcept>
template<class Graph, class Nodes>
void topsort_clean_graph(Graph& graph, Nodes& nodes) {
	for (auto iter(graph.begin()), end(graph.end()); iter != end;) {
		if (iter->second.empty()) {
			nodes.push_back(iter->first);
			graph.erase(iter++); // advance iterator before erase invalidates it
		} else
			++iter;
	}
}
template<class Graph, class OutIterator>
void topological_sort(Graph graph, OutIterator sorted) {
	std::deque<typename Graph::key_type> nodes {};
// Start with the set of nodes with no incoming edges.
	topsort_clean_graph(graph, nodes);
	while (not nodes.empty()) {
// Grab the first node to process, output it to sorted,
// and remove it from the graph.
		typename Graph::key_type n {nodes.front()};
		nodes.pop_front();
		*sorted = n;
		++sorted;
// Erase n from the graph
		for (auto& node : graph) {
			node.second.erase(n);
		}
// After removing n, find any nodes that no longer
// have any incoming edges.
		topsort_clean_graph(graph, nodes);
	}
	if (not graph.empty())
		throw std::invalid_argument("Dependency graph contains cycles");
}
#endif
