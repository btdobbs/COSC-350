#include "Element.h"

class Map{
public:
    virtual int size() = 0;                         //Return the number of entries in M.
    virtual bool empty() = 0;                       //Return true if M is empty and false otherwise.
    virtual Iterator find(Element k) = 0;           //If M contains an entry e=(k,v),with key equal to k,then return an iterator p referring to this entry, and otherwise return the special iterator end.
    virtual Iterator put(Element k,Element v) = 0;  //If M does not have an entry with key equal to k, then add entry (k,v) to M, and otherwise, replace the value field of this entry with v; return an iterator to the inserted/modified entry.
    virtual void erase(Element k) = 0;              //Remove from M the entry with key equal to k; an error condition occurs if M has no such entry.
    virtual void erase(Iterator p) = 0;             //Remove from M the entry referenced by iterator p; an error condition occurs if p points to the end sentinel.
    virtual Iterator begin() = 0;                   //Return an iterator to the first entry of M.
    virtual Iterator end() = 0;                     //Return an iterator to a position just beyond the end of M.
};