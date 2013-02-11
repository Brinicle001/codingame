// CodinGame - Session du 29/01/2013 - Test 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/* CLASS PROPAL --------------------------------------------- */
class Propal
{
public:
    unsigned int startDate;
    unsigned int endDate;
    unsigned int nOverlappedOri,nOverlappedOptimized;
    bool isNew;
    bool isOptimized,isOK;

    Propal(const unsigned int start, const unsigned int duration) throw(int);
    Propal(const unsigned int start, const unsigned int duration, const unsigned int nOverlapped) throw(int);
    ~Propal();
    bool sooner (const Propal &a) const;
    bool operator< (const Propal &a) const;
    bool isOverlappedWith(const Propal &a) const;
    friend ostream &operator<<(ostream &flux, const Propal &a);
};

Propal::Propal(const unsigned int start, const unsigned int duration) throw(int) :
    startDate(start),
    endDate(start),
    nOverlappedOri(0),
    nOverlappedOptimized(0),
    isNew(true),
    isOptimized(false),
    isOK(false)
{
    try
    {
        if (duration==0)
            throw 1;
        else
            this->endDate=start+duration -1;
    }
    catch (int)
    {
        cerr << "Propal(" << start << "," << duration << ") illegal" << endl;
    }
}

Propal::Propal(const unsigned int start, const unsigned int duration, const unsigned int nOverlapped) throw(int) :
    startDate(start),
    endDate(start),
    nOverlappedOri(nOverlapped),
    nOverlappedOptimized(nOverlapped),
    isNew(true),
    isOptimized(false),
    isOK(false)
{
    try
    {
        if (duration==0)
            throw 1;
        else
            this->endDate=start+duration -1;
    }
    catch (int)
    {
        cerr << "Propal(" << start << "," << duration << ") illegal" << endl;
    }
}

Propal::~Propal() {}

bool Propal::sooner (const Propal &a) const
{
    if (this->startDate==a.startDate)
        return this->endDate<a.endDate;
    else
        return this->startDate<a.startDate;
}

bool Propal::operator< (const Propal &a) const
{
    return this->sooner(a);
}

bool Propal::isOverlappedWith(const Propal &a) const
{
    if ((this->startDate>=a.startDate) && (this->startDate<=a.endDate))
    {
        return true;
    }
    if ((this->endDate>=a.startDate) && (this->endDate<=a.endDate))
    {
        return true;
    }
    if ((this->startDate<a.startDate) && (this->endDate>a.endDate))
    {
        return true;
    }
    return false;
}


ostream &operator<<(ostream &flux, const Propal &a)
{
    flux << a.startDate << "," << a.endDate << " poids=" << a.nOverlappedOri << "/" << a.nOverlappedOptimized << " new=" << a.isNew << " opti=" << a.isOptimized << " OK?" << a.isOK;
    return flux;
}


/* CLASS PROPAL_MANAGER ---------------------------------------- */
typedef vector<Propal> VecPropal;
struct FoncteurMinPropal
{
   inline bool operator() (const Propal &a, const Propal &b) const
   {
      return a.nOverlappedOptimized < b.nOverlappedOptimized;
   }
};

class Propal_manager
{
public:
    VecPropal Propals;
    bool hasChanged;
    unsigned int maxOccurs;
    Propal_manager();
    ~Propal_manager();
    void addPropal(unsigned int start, unsigned int duration);
    void calcOverlapped();
    void optimize();
    unsigned int getBestNumber();
    friend istream &operator>>(istream &flux, Propal_manager &p);
    friend ostream &operator<<(ostream &flux, const Propal_manager &p);
};

Propal_manager::Propal_manager() :
    Propals(),
    hasChanged(false),
    maxOccurs(0) {}

Propal_manager::~Propal_manager() {}

void Propal_manager::addPropal(unsigned int start, unsigned int duration)
{
    this->Propals.push_back(Propal(start, duration));
    this->hasChanged=true;
}

void Propal_manager::calcOverlapped()
{
    VecPropal::iterator currentPropal=this->Propals.begin();
    VecPropal::iterator tmpIt=this->Propals.begin();
    while(currentPropal != this->Propals.end())
    {
        tmpIt=currentPropal+1;
        while((tmpIt->startDate<=currentPropal->endDate) && (tmpIt != this->Propals.end()))
        {
            if (currentPropal->isOverlappedWith(*tmpIt))
            {
                currentPropal->nOverlappedOri++;
                tmpIt->nOverlappedOri++;
            }
            ++tmpIt;
        }
        currentPropal->isNew=false;
        currentPropal->nOverlappedOptimized=currentPropal->nOverlappedOri;
        ++ currentPropal;
    }
}

void Propal_manager::optimize()
{
    VecPropal::iterator currentPropal=this->Propals.begin();
    VecPropal::iterator tmpIt=this->Propals.begin();
    this->maxOccurs=0;
    while(currentPropal != this->Propals.end())
    {
        if (currentPropal->isOptimized)
        {
            if (!currentPropal->isOK)
            {
                tmpIt=currentPropal+1;
                while((tmpIt->startDate<=currentPropal->endDate) && (tmpIt != this->Propals.end()))
                {
                    tmpIt->nOverlappedOptimized--;
                    ++tmpIt;
                }
                currentPropal->nOverlappedOptimized=0;
            }
        }else
        {
            if (currentPropal->nOverlappedOptimized==0)
            {
                currentPropal->isOptimized=true;
                currentPropal->isOK=true;
                this->maxOccurs++;
            }else
            {
                if (currentPropal == min_element(currentPropal,currentPropal+currentPropal->nOverlappedOptimized,FoncteurMinPropal()))
                {
                    // Current occur is the one between the next nOverlappedOptimised ones
                    tmpIt=currentPropal+1;
                    while((tmpIt->startDate<=currentPropal->endDate) && (tmpIt != this->Propals.end()))
                    {
                        tmpIt->isOptimized=true;
                        tmpIt->isOK=false;
                        ++tmpIt;
                    }
                    currentPropal->nOverlappedOptimized=0;
                    currentPropal->isOptimized=true;
                    currentPropal->isOK=true;
                    this->maxOccurs++;
                }else
                {
                    // current occur is not the best, so is ignored
                    tmpIt=currentPropal+1;
                    while((tmpIt->startDate<=currentPropal->endDate) && (tmpIt != this->Propals.end()))
                    {
                        tmpIt->nOverlappedOptimized--;
                        ++tmpIt;
                    }
                    currentPropal->nOverlappedOptimized=0;
                    currentPropal->isOptimized=true;
                    currentPropal->isOK=false;
                }
            }
        }
        //cout << *currentPropal << endl;
        ++currentPropal;
    }
}

unsigned int Propal_manager::getBestNumber()
{
    if (this->hasChanged)
    {
        sort(this->Propals.begin(),this->Propals.end());
        this->hasChanged=false;
        this->calcOverlapped();
        this->optimize();
    }
    return this->maxOccurs;
}

istream &operator>>(istream &flux, Propal_manager &p)
{
    unsigned int a,b;
    flux >> a >> b;
    p.addPropal(a,b);
    return flux;
}


/* MAIN FUNCTION  --------------------------------------------- */
int main()
{
    unsigned int nInput;
    Propal_manager manager;

    cin >> nInput;
    cin.ignore();

    for(unsigned int i=0; i<nInput; i++)
    {
        cin >> manager;
        cin.ignore();
    }
    cout << manager.getBestNumber() << endl;

    return 0;
}
