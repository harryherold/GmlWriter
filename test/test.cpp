/*
 * test.cpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */
#include <iostream>
#include <string>
#include "gml_writer.hpp"

using namespace gw;

int main()
{
	const char * file = "/home/harry/GmlWriter/test/test.gml";
	GmlWriter g(file,true, true,"MyGraph");

	g.writeNode(1,"foo");
	g.writeNode(2, "3.14");

	Shape shape_elipse = Shape::Ellipse;

	g.writeNode(3, "bar", shape_elipse);
	g.writeNode(4, "4");

	g.writeEdge(1, 2);
	g.writeEdge(1, 3);

	EdgeStyle es = EdgeStyle::Dotted;
	g.writeEdge(2, 4, "1.2", es);
	g.writeEdge(3, 4, "baz", es);

	std::cout << "Finished" << '\n';
	return 0;
}
