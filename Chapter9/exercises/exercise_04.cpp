
//user defined object X
struct X
{
    //member function of X 
    void f(int x)
    {
        //user defined object Y
        struct Y
        {
            //member function of Y
            int f() 
            {
                return 1;
            }
            int m; 
        };
        int m;
        m = x;
        //creates struct Y (m2)
        Y m2;
        //returns 1
        return f(m2.f());
    }
    int m;
    //member function of X
    void g(int m)
    {
        if (m)
            f(m+2);
        else
        {
            g(m+2);
        }        
    }
    //struct X default constructor
    X()
    {}
    //member function of X
    void m3()
    {}

//
    void main()
    {
        // create struct X (a) with default constructor
        X a;
        // returns 1
        a.f(2);
    }
};