#include <iostream>
#include "Storage.h"

using namespace std;

template<typename T>
class Storage8
{
private:
    T m_array[8];
public:
    void set(int index, const T &value)
    {
        m_array[index] = value;
    }
    
    const T& get(int index)
    {
        return m_array[index];
    }
};


template<>
class Storage8<bool>
{
private:
    unsigned char m_data;
public:
    Storage8() 
        : m_data(0)
    {}

    void set(int index, bool value)
    {
        unsigned char mask = 1 << index;
        
        if (value)
            m_data |= mask;
        else
            m_data &= ~mask;
    }
    
    bool get(int index)
    {
        unsigned char mask = 1 << index;
        return (m_data & mask) != 0;
    }
};


int main()
{
    Storage8<int> intStorage;
    
    for (int count = 0; count < 8; ++count)
        intStorage.set(count, count);
    
    for (int count = 0; count < 8; ++count)
        cout << intStorage.get(count) << " ";
    
    cout << " Sizeof Storage8<int> " << sizeof(Storage8<int>) << endl;
    
    
    Storage8<bool> boolStorage;
    
    for (int count = 0; count < 8; ++count)
        boolStorage.set(count, count & 3);
    
    for (int count = 0; count < 8; ++count)
        cout << boolStorage.get(count) << " ";
    
    cout << " Sizeof Storage8<bool> " << sizeof(Storage8<bool>) << endl;
    
    return 0;
}
bool
template<>
  class Storage8<bool>
  {
  private:
      unsigned char m_data;
  public:
      Storage8() 
          : m_data(0)
      {}

      void set(int index, bool value)
      {
          unsigned char mask = 1 << index;
        
          if (value)
              m_data |= mask;
          else
              m_data &= ~mask;
      }
    
      bool get(int index)
      {
          unsigned char mask = 1 << index;
          return (m_data & mask) != 0;
      }
  };