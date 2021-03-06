/*
 * MsgQueue.h
 *
 *  Created on: Oct 19, 2016
 *      Author: tov
 */

#ifndef TF_MSGQUEUE_H_
#define TF_MSGQUEUE_H_

#include "TF/TF.h"
#include "TF/Mutex.h"
#include "TF/Event.h"

namespace TF {

class MsgQueue {
public:
    MsgQueue();
    ~MsgQueue();

    /// Send a message
    /// \param buffer is message to be sent
    /// \param nBytes is size of buffer
    void send(uint8_t *buffer, size_t nBytes);

    /// Receive a message
    /// \param buffer is array where message will be received
    /// \param maxBytes is size of buffer
    /// \param timeout_ms is maximum time to wait for message, 0 means forever
    /// \return number of bytes received
    int receive(uint8_t *buffer, size_t maxBytes, unsigned timeout_ms=0);

    /// \return number of messages available in queue
    int getMessagesInQueue();

    // TODO: Make configurable, e.g. in constructor
    static const unsigned MAX_MSG_LEN = 32;
    static const unsigned MAX_NUM_MSG = 8;

private:
    Event txevent;
    Mutex mutex;
    volatile uint8_t msg_data[MAX_MSG_LEN][MAX_NUM_MSG] = {0};
    volatile size_t  msg_size[MAX_NUM_MSG] = {0};
    volatile size_t tail = 0;
    volatile size_t num_msg = 0;
};

} /* namespace TF */

#endif /* TF_MSGQUEUE_H_ */
