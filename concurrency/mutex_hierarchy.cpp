class hierarchical_mutex 
{
    std::mutex internal_mutex;

    unsigned long const hierarchical_value;

    unsigned long const prev_hier_val ;

    static thread_local unsigned long this_thread_hierarchy_val;

    void check_for_hierarchy_violation()
    {
        if(this_thread_hierarchy_val <= hierarchical_value)
        {
                throw std::logic_error("mutex hierarchy violated");
        }
    }

    void update_hier_val()
    {
        
        previous_hierarchy_value  =  this_thread_hierarchy_val;

        this_thread_hierarchy_val = hierarchical_value;
    }

    public:

        explicit hierarchical_mutex(unsigned long value) :

            hierarchical_value(value) , previous_hierarchy_value(0) {}


            void lock()
            {
                check_for_hierarchy_violation();

                internal_mutex.lock();

                update_hier_val();
            }

            void unlock()
            {

                this_thread_hierarchy_val = prev_hier_val;

                internal_mutex.unlock();
            }

            bool try_lock()
            {
                check_for_hierarchy_violation();

                if(!internal_mutex.try_lock())

                return false;

                update_hier_val();

                    return true;
            }
};

thread_local unsigned long
     
    hierarchical_mutex::this_thread_hierarchy_val(ULONG_MAX);


// not a complete driver code implementation but just a practice of mutex hierarchy 