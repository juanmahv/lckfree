/////////////////////////////////////////////////////////////
// This is a lock free implementation of a queue for only
// 1 producer and 1 consumer.
// It makes use of the atomic types provided in <atomic>
// to guarantee the queue is always in a consistent state.
// By avoding the use of locks for thread synchronization
// the queue offers a high level of concurrency.
//
// Author: Juan M. de Hoyos <juanmahv@gmail.com>
// Web: juanmanueldehoyos.com
// License: See LICENSE.txt
/////////////////////////////////////////////////////////////

#include <cstdint>
#include <memory>
#include <atomic>

namespace lckfree
{

template <typename T>
class lckfree_queue_1p1c
{

public:

  lckfree_queue_1p1c():
    queue_size(0)
    {
      Node* dummy = new Node();
      head = dummy;
      tail = head;
    };

  ~lckfree_queue_1p1c(){
    while (nullptr != head) {
      auto val = head;
      head = head->next;
      delete val;
    }
  }

  lckfree_queue_1p1c(const lckfree_queue_1p1c&) = delete;
  lckfree_queue_1p1c& operator=(const lckfree_queue_1p1c&) = delete;

  uint32_t size() const { return queue_size; };

  void push(std::shared_ptr<T> item) {
    Node* final = new Node();
    tail->data = item;
    tail->next = final;
    tail = final;
    ++queue_size;
  };

  std::shared_ptr<T> pop() {
    std::shared_ptr<T> item;
    if (queue_size > 0){
        Node* aux = head;
        head = head->next;
        --queue_size;
        item = aux->data;
        delete aux;
    }
    return item;
  }

private:

  typedef struct _Node {
    std::shared_ptr<T> data;
    struct _Node* next = nullptr;
  } Node;

  Node* head;
  Node* tail;
  std::atomic<uint32_t> queue_size;
};

}
