#include <iostream>

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
