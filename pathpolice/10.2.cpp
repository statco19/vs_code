#include <iostream>
using namespace std;

class Point 
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl; 
	}
	Point& operator++()
	{
		xpos+=1;
		ypos+=1;
		return *this;
	}
	friend Point& operator--(Point &ref);

    Point operator-()
    {
        Point pos2(xpos * -1, ypos * -1);
        return pos2;
    }

    friend Point operator~(const Point &);
};

Point& operator--(Point &ref)
{
	ref.xpos-=1;
	ref.ypos-=1;
	return ref;
}

Point operator~(const Point &ref)
{
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(void)
{
	Point pos(1, 2);
	Point pos2 = -pos;
    pos.ShowPosition();
    pos2.ShowPosition();

    Point pos3 = ~pos;
    pos3.ShowPosition();
	return 0;
}