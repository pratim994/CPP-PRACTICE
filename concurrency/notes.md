
here I will be keeping notes of what I learned and my questions after reading session to keep myself accountable

-> you can't return a value directly from a thread , you must pass in a reference or use future

ch3 : thread safety

-> use of invariants : statements that are always true for a particular data structure

->race conditions : when two or more processes compete for the same memory , variable or ffiles
                    in c++ race conditions are undefined behaviour

-> protection against race conditions :
        -> use mutexes
        -> lock free programming  
        ->use of transactions : series of all data modifications  and reads are  stored in a transaction log
                              : also called software transaction memory