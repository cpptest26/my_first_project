  template<typename T>
    void doSomethingTemplate_O(T && vec)//l-value와 r-value를 구분해서컴파일 한다.
    {
        doSomething(std::forward<T>(vec));
    } // l-value 와 R-value 구분함