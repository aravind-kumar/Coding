#include <iostream>
#include <unordered_map>
#include <list>
#include <assert.h>
#include <algorithm>

template <typename key,typename val>
class lru
{
   private:
      typedef typename std::list<key>::iterator itemPos;
      typedef std::pair<val,itemPos> valuePos;
      typedef std::unordered_map<key,valuePos> cacheMap;

   public:

      cacheMap cache;

      //back represents the latest element;
      //front represents the old element; 
      std::list<key> lruList;
      
      unsigned int capacity;
     
      lru(unsigned int size) : lruList(size),capacity(size)
      {   }
    
     auto begin() { return cache.begin(); }
     
     auto end() { return cache.end(); }  

     
     void update(valuePos it)
     {
        int pos = std::distance(lruList.begin(),it.second);
   	assert(pos>= 0 && pos<=lruList.size()-1); 
        lruList.erase(it.second);
        lruList.push_front(it.first);     
     }

     //If element exsists return element 
     //else return end; 
     typename cacheMap::iterator get(const key& target)
     {
          auto it = cache.find(target);

          if(it != cache.end())
          {
             update (it->second); 
             return it;    
          } 
          return it;
     }

     
     void put(key inputKey, val value)
     {
        auto it = cache.find(inputKey);
        if (it != cache.end())
        {
            update(it->second);
            cache[inputKey] = {value,lruList.begin()};      
            return;
        }
        
        lruList.push_front(inputKey);
        cache[inputKey] = {value,lruList.begin()};

        if(lruList.size()-1 > capacity)
        {
            cache.erase(lruList.back());
            lruList.pop_back(); 
        }
     }

     key getKey(typename cacheMap::iterator it)
     {
         return it->first;
     }

     val getValue(typename cacheMap::iterator it)
     {
         return it->second.first; 
     }
};

int main()
{
   lru<int,int> tempLru(30);
   tempLru.put(1,1);
   tempLru.put(2,2);
   std::cout<<tempLru.getValue(tempLru.get(2));
   return 0;
}
