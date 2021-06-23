# Part A

## A.1) II is correct

## A.2)

```cpp
int tab[5] = {1,4,2,7,8};
std::vector<int> v;
std::copy(tab, tab+5, v.begin());
```

## A.3)

```cpp
class Point{
    int d_x, d_y;
    public:
        Point(int _x, int _y) : d_x(_x), d_y(_y){}
        operator int() const{
            return d_x*d_x + d_y*d_y;
        }
};
```

## A.4)

```cpp
class A{
    int* d_a;
    int d_sz;
    public:
        A(int sz=0) : d_sz(sz){
            d_a = new int[d_sz];
        }
        A& operator =(const A& obj){
            if (this != &obj){
                d_sz = obj.d_sz;
                delete d_a;
                d_a = new int[d_sz];
                for (int i=0; i<d_sz; i++){
                    d_a[i] = obj.d_a[i];
                }
            }
            return *this;
        }
};
```

## A.5) D

## A.6) 

```cpp
catch(...){cout << "exception other than int in main \n";}
```

## A.7)

```cpp
void printReverseOrder(vector<int>& container){
    for (vector<int>::reverse_iterator iter = container.rbegin(); iter != container.rend(); ++iter){
        cout << *iter << '';
    }
    cout << endl;
    return;
}
```

## A.8)

```cpp
#include <iostream>
#include <vector>
using namespace std;

void printData(vector<int> v){
    for (int i=0; i<v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> lData;
    lData.push_back(27);
    lData.push_back(0);
    lData.pop_back();
    printData(lData);
}
```

## A.9)
```cpp
#include <iostream>
#include <list>
using namespace std;

class Point{
    public:
        int x, y;
        Point(int x, int y) : x(x), y(y){}
};

bool compare(const Point& p1, const Point& p2){
    if (p1.x == p2.x)
        return p1.y < p2.y;
    else
        return p1.x < p2.x;
}

int main(){
    Point p1(2, 5), p2(5, 2), p3(1, 3);
    list<Point> lis;
    lis.push_back(p1);
    lis.push_back(p2);
    lis.push_back(p3);
    lis.sort(compare);
    list<Point>::iterator itr;
    cout << "sorted list: {";
    for (itr = lis.begin(); itr != lis.end(); itr++){
        if (itr == lis.begin()) cout << "(" << (*itr).x << ", " << (*itr).y << ")";
        else cout << ", (" << (*itr).x << ", " << (*itr).y << ")";
    }
    cout << ")" << endl;
}
```

## A.10) All sort algorithm calls are correct