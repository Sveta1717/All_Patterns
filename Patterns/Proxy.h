#include "Library.h"

class Image
{
    int m_id;
    static int s_next;
public:
    Image()
    {
        m_id = s_next++;
        cout << "   $$ ctor: " << m_id << '\n';
    }
    ~Image()
    {
        cout << "   dtor: " << m_id << '\n';
    }
    void draw()
    {
        cout << "   drawing image " << m_id << '\n';
    }
};
int Image::s_next = 1;