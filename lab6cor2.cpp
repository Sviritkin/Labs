//Structures, unions, and enumerations
#include <iostream>

using namespace std;


enum class TypeElement
{
    one, two
};

union Data
{
    unsigned long long value1;
    bool value2;
    long double value3;

    Data() : value1(0) {}
};


struct ElementTwo
{
    Data data;
    TypeElement te;
    ElementTwo* next;


    ElementTwo(unsigned long long value) : te(TypeElement::two), next(nullptr)
    {
        data.value1 = value;
    }


    ~ElementTwo()
    {
        freeTwo(&next);
        next = nullptr;
    }

private:


    void freeTwo(ElementTwo** two)
    {
        if (*two)freeTwo(&(*two)->next);
        else
            return;
        delete* two;
        *two = nullptr;
    }
};


struct ElementOne
{
    Data data;
    TypeElement te;
    ElementOne* left;
    ElementTwo* right;


    ElementOne(unsigned long long value) : te(TypeElement::one), left(nullptr), right(nullptr)
    {
        data.value1 = value;
    }


    ~ElementOne()
    {
        delete right;
        right = nullptr;
        freeOne(&left);
    }

private:


    void freeOne(ElementOne** one)
    {
        if (*one)freeOne(&(*one)->left);
        else
            return;
        delete* one;
        *one = nullptr;
    }
};

void init(ElementOne*& root, unsigned cnt) {
    int i = 0;
    while (i < cnt) {
        if (!root) root = new ElementOne(i++); else {
            ElementOne* l = root;
            while (i < cnt) {
                if (l->right) {
                    ElementTwo* r = l->right;
                    while (r->next)r = r->next;
                    r->next = new ElementTwo(i++);
                }
                else l->right = new ElementTwo(i++);
                if (!l->left)break;
                l = l->left;
            }
            if (i == cnt)break;
            l->left = new ElementOne(i++);
        }
    }
}

int main()
{

    int k;
    cout << "Enter the number of items" << endl;
    cin >> k;

    ElementOne* root = nullptr;
    init(root, k);

    if (root)delete root;
    return 0;
}
