/*
 * ConsumerThread.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#ifndef WORKITEM_H_
#define WORKITEM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include "BufferQueue.h"

class WorkItem
{
  public:
    WorkItem(const char* message)
          : m_message(message) {}
    ~WorkItem() {}

    const char* getMessage() { return m_message.c_str(); }

  private:
    //string message to wrap the string inside a WorkItem class
    std::string m_message;

};

#endif /*WORKITEM_H_*/
