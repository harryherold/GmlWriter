/*
 * gml_writer.hpp
 *
 *  Created on: 24 Jan 2015
 *      Author: Christian Herold
 */

#ifndef SRC_GML_WRITER_HPP_
#define SRC_GML_WRITER_HPP_
#include <fstream>
#include <string>

namespace gw
{

class GmlWriter
{

public:
	GmlWriter(const char *, bool, bool, const std::string &);

	template<typename T>
	void writeNode(uint64_t id, T label)
	{
		fileOut_ << "node\n";
		fileOut_ << "[\n";
		fileOut_ << "id " << id << '\n';
		fileOut_ << "label " << '"' << label << '"' << '\n';
		fileOut_ << "]\n";
	}

	void writeEdge(uint64_t id_src, uint64_t id_dest);

	~GmlWriter();

private:
	std::ofstream fileOut_;
	bool bHierarchic_;
	bool bDirected_;
};

}

#endif /* SRC_GML_WRITER_HPP_ */
