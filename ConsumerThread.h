/*
 * ConsumerThread.h
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */

#ifndef CONSUMERTHREAD_H_
#define CONSUMERTHREAD_H_

#include "BufferQueue.h"
#include "Thread.h"
#include "WorkItem.h"

class ConsumerThread : public Thread
{
  public:
    ConsumerThread(BufferQueue<WorkItem*>& queue, const char* outFile, const char* sort);
    void* run();
  private:
    BufferQueue<WorkItem*>& m_queue;
    string m_outFile;
    const char* m_sortAlgorithm;
};

#endif /* CONSUMERTHREAD_H_ */
