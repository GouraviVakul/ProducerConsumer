/*
 * Thread.cpp
 *
 *  Created on: Dec 27, 2018
 *      Author: Gouravi
 */


#ifndef THREAD_H_
#define THREAD_H_

#include <pthread.h>

class Thread
{
  public:
    Thread();
    virtual ~Thread();

    int start();
    int join();
    int detach();
    pthread_t self();

    virtual void* run() = 0;

  private:
    pthread_t  m_tid;
    int        m_running;
    int        m_detached;
};


#endif /* THREAD_H_ */
