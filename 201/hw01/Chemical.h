#ifndef CHEMICAL_H
#define CHEMICAL_H


class Chemical
{
    public:
        Chemical();
        Chemical(int id, int type);
        ~Chemical();
        int getType();//const
        int getid();//const
        void setId(int);
        void setType(int);
    private:
        int chemid;
        int type;//1 for redu... 2 for combustive
};

#endif // CHEMICAL_H
