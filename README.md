A simple priority queue (min heap in this case) for integers in C.

This is a very minimal implementation, just for brushing up on my rusty C. It
probably reveals I've been in a more object oriented language for a while.

Running
-------

To run tests:

    make run_tests

Assumptions
-----------

- assuming that there is infinite amount of memory available. There's no checking
- the queue size can grow, but never shrinks
- the caller checks that there are elements on the heap before using top or pop

Heap structure
--------------

The tree is stored internally in memory as an array, where position 0 is the
smallest element. For each element at position `i`, its children are located at
`2 * i + 1` and `2 * i + 2`.

Showing example indices in this tree of six elements:

         0
      1     2
     3 4   5

TODO
----

- Make as generic as C allows.
- Model import like [stb](https://github.com/nothings/stb)

