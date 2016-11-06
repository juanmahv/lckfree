## Lckfree

Lckfree is a lock-free implementation of some typical Abstract Data Types (ADTs).
The classical approach of making ADTs thread safe is using locks to serialize the access between threads.
While using locks is a perfectly valid solution in many contexts, it also reduce the concurrency level
and therefore the performance.Conversely, using a lock free approach has the advantage an ADT
can be accessed by two or more threads and remains always in a consistent state.      

The building blocks of lock-free algorithms are the atomic operations, that is, operations that each thread see as
"done" or "not done", but never "half-done". This requires support of the platform underneath. And historically there was
not native support in C++ for atomic operations.  

One of the big advantages of the C++11 standard is the introduction of a memory model
where the use of atomic types was added to the language. Now lock-free algorithm can be implemented in
C++ in a portable manner. Without need of third party libraries.

At the end, if the software behaves really in a lock-free manner depends on the properties of the
CPU, but the C++ code is standard for all platforms.

I decided to create lckfree due to the lack of lock-free ADTs available in C++11.
Feel free to use it at your convenience under the terms specified in the LICENSE.txt file.

## Content

Lckfree offers the following ADTs:

* lckfree_queue: A lock free queue supporting only 1 producer and 1 consumer.           


## License

Lckfree is released under the MIT license as stated in LICENSE.txt.
This makes the library eligible also for commercial software. If you plan to
use it, please provide the text in LICENSE.txt unmodified as part of your release.
