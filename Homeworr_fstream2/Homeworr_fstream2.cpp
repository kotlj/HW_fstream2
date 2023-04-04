
#include <iostream>
#include <string>

struct Unit
{
    std::string _firm;
    std::string _leader;
    std::string _phone;
    std::string _adress;
    std::string _activity;
};

class Directory
{
private:
    Unit* _unit = nullptr;
    int size = 0;
public:
    Directory(const char* firm, const char* leader, const char* phone, const char* adress, const char* activity)
    {
        size = 1;
        _unit = new Unit[size];
        _unit[0]._firm = firm;
        _unit[0]._leader = leader;
        _unit[0]._phone = phone;
        _unit[0]._adress = adress;
        _unit[0]._activity = activity;
    }

    void findByFirm(const char* firm)
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                if (this->_unit[i]._firm == firm)
                {
                    this->print(i);
                }
            }
        }
        else
        {
            std::cerr << "No such firm\n";
        }
    }
    void findByLeader(const char* leader)
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                if (this->_unit[i]._leader == leader)
                {
                    this->print(i);
                }
            }
        }
        else
        {
            std::cerr << "No such firm\n";
        }
    }
    void findByPhone(const char* phone)
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                if (this->_unit[i]._phone == phone)
                {
                    this->print(i);
                }
            }
        }
        else
        {
            std::cerr << "No such firm\n";
        }
    }
    void findByActivity(const char* activity)
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                if (this->_unit[i]._activity == activity)
                {
                    this->print(i);
                }
            }
        }
        else
        {
            std::cerr << "No such firm\n";
        }
    }
    void print(int indx)
    {
        if (indx < size)
        {
            std::cout << "--------------------------------\n";
            std::cout << this->_unit[indx]._firm << '\n';
            std::cout << this->_unit[indx]._leader << '\n';
            std::cout << this->_unit[indx]._phone << '\n';
            std::cout << this->_unit[indx]._adress << '\n';
            std::cout << this->_unit[indx]._activity << '\n';
            std::cout << "--------------------------------\n";
        }
        else
        {
            std::cout << "Invalid index\n";
        }
    }
    void printAll()
    {
        if (!this->isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                this->print(i);
            }
        }
        else
        {
            std::cout << "Empty\n";
        }
    }
    void printNAdd(Unit& unit)
    {
        if (!this->isEmpty())
        {
            Unit* temp = new Unit[size + 1];
            temp[size]._firm = unit._firm;
            temp[size]._leader = unit._leader;
            temp[size]._phone = unit._phone;
            temp[size]._adress = unit._adress;
            temp[size]._activity = unit._activity;
            for (int i = 0; i < size; i++)
            {
                temp[i]._firm = this->_unit[i]._firm;
                temp[i]._leader = this->_unit[i]._leader;
                temp[i]._phone = this->_unit[i]._phone;
                temp[i]._adress = this->_unit[i]._adress;
                temp[i]._activity = this->_unit[i]._activity;
            }
            this->size++;
            delete[] this->_unit;
            this->_unit = temp;
            temp = nullptr;
        }
        else
        {
            size = 1;
            this->_unit = new Unit[size];
            this->_unit[0]._firm = unit._firm;
            this->_unit[0]._leader = unit._leader;
            this->_unit[0]._phone = unit._phone;
            this->_unit[0]._adress = unit._adress;
            this->_unit[0]._activity = unit._activity;
        }
        this->printAll();
    }

    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }
    ~Directory()
    {
        if (_unit != nullptr && size != 0)
        {
            delete[] _unit;
        }
    }
};

int main()
{
    Directory test1("Firm1", "leader1", "phone1", "adress1", "activity1");
    test1.print(0);
    Unit helper; helper._firm = "firm2"; helper._leader = "leader2"; helper._phone = "phone2"; helper._adress = "adress2";
    helper._activity = "activity2";
    std::cout << "testAdd\n";
    test1.printNAdd(helper);
    helper._firm = "firm3"; helper._leader = "leader3"; helper._phone = "phone3"; helper._adress = "adress3";
    helper._activity = "activity3";
    test1.printNAdd(helper);
    std::cout << "testFind\n";
    test1.findByFirm("firm2");
}