#include <utility>
#include <functional>
//store elements based on priority; no concept of position
//arbitrary insertion; only min removal
//elements (i.e., E) must define a total order relation (i.e. C)
//therefore, elements must be comparable
//total order relation must be reflexive, antisymmetric (different from not symmetric), and transitive
//example: k <= k; k1 <= k2 and k2 <= k1 implies k1 = k2; k1 <= k2 and k2 <= k3 implies k1 <= k3
//therefore no contradictions and there is always a smallest key
//Example: point comparison, lexicographic order, sorting (add then remove)
// airline reservation by fare paid, the frequent-flyer status, and the time when the passenger is inserted into the priority queue.
//Heap implementation
//complete binary tree (every level has max number of nodes, height is log_2(n))
//left at 2n and right at 2n+1 (so item 0 will have
//insert new items to end and then do an up-heap (Fig 8.7 - swapping upward until element is in right location)
//remove min by returning min and moving last item to top and doing a down-heap (Fig 8.8 - swapping downward until element is in right location)
class PriorityQueue{
public:
    ~PriorityQueue();
    int size() const;         //constant time
    int empty() const;        //constant time
    void insert(int element); //log_2(n) steps
    int min() const;          //constant time
    void remove_min();        //log_2(n) steps
private:
    const int _root = 1;
    int _size = 0;
    int _max_size = 100;
    int *_a = new int[_max_size];
    bool has_left_child(int index) const;
    bool has_right_child(int index) const;
    static int get_parent_index(int index);
    static int get_left_child_index(int index) ;
    static int get_right_child_index(int index);
};
