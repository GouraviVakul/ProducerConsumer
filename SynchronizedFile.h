/*
 * SynchronizedFile.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#ifndef SYNCHRONIZEDFILE_H_
#define SYNCHRONIZEDFILE_H_

#include <string>
#include <mutex>
#include <fstream>
using namespace std;

class SynchronizedFile
{
public:
	SynchronizedFile(const string& path);
	~SynchronizedFile();
	void Write(const string& dataToWrite);

private:
    string m_path;
    //std::mutex writerMutex;
    ofstream m_outFile;
};


#endif /* SYNCHRONIZEDFILE_H_ */
