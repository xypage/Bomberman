#ifndef VEC_H
#define VEC_H


class Vec
{
public:
    int x, y;

    Vec();
    Vec(int, int);

    Vec add(Vec&);
    Vec add(int, int);
};

#endif // VEC_H
