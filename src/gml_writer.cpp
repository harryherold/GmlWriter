/*
 * gml_writer.cpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */
#include "gml_writer.hpp"
#include <iomanip>

using namespace gw;

GmlWriter::GmlWriter(const char * file, bool h, bool d, const std::string & label)
:fileOut_{file},bHierarchic_{h},bDirected_{d}
{
	fileOut_ << "graph\n[\n";
	fileOut_ << "hierarchic " << h << '\n';
	fileOut_ << "label " << '"' << label << '"' << "\n";
	fileOut_ << "directed " << d << '\n';
}

GmlWriter::~GmlWriter()
{
	if (fileOut_.is_open())
	{
		fileOut_ << "]\n";
		fileOut_.close();
	}
}

void GmlWriter::writeEdge(uint64_t id_src, uint64_t id_dest)
{
	fileOut_ << "edge\n";
	fileOut_ << "[\n";
	fileOut_ << "source " << id_src << '\n';
	fileOut_ << "target " << id_dest << '\n';
	fileOut_ << "]\n";
}

