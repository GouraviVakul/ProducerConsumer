/*
 * Writer.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */


#ifndef WRITER_H_
#define WRITER_H_

#include "SynchronizedFile.h"
#include <memory>

class Writer {
public:
    Writer(std::shared_ptr<SynchronizedFile> sfptr) : sf(sfptr) { }

    void WritesToFile (const string& data) {
        sf->Write(data);
    }

private:
    std::shared_ptr<SynchronizedFile> sf;
};


#endif /* WRITER_H_ */
