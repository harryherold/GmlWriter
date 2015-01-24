/*
 * test.cpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */
#include <iostream>
#include "gml_writer.hpp"

using namespace gw;

int main()
{
	const char * file = "/home/harry/GmlWriter/test/test.gml";
	GmlWriter g(file,true, true,"MyGraph");

	g.writeNode<const char *>(1,"foo");
	g.writeNode<double>(2,3.14);
	g.writeNode<std::string>(3,"bar");
	g.writeNode<int>(4,4);

	g.writeEdge(1,2);
	g.writeEdge(1,3);

	g.writeEdge(2,4);
	g.writeEdge(3,4);

	std::cout << "Finished" << '\n';
	return 0;
}
