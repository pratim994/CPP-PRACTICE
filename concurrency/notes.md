
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


-> std::recursive_mutex : doesn't allow multiple locks on a single thread

-> avoid nested locks , if you already have a lock don't acquire another 

-> Use a lock hierarchy :

        -> use: hierachical_mutex some_mutex_name(value of importance) ;

                -> for example : hierachical_mutex hig_mut(10000);

                                hierarchical_mutex low_mut(5000);
