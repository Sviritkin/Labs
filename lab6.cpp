//Structures, unions, and enumerations
#include <iostream>

using namespace std;


//item type
enum class TypeElement
{
    one, two
};

//element data
union Data
{
    unsigned long long value; //число
    const char *svalue; //строка

    Data() : value(0) {}
};


struct ElementTwo;

//element of the first type
struct ElementOne
{
    Data data;
    TypeElement te;
    ElementOne *left; //pointers to the left and right elements
    ElementTwo *right;

    //constructors
    ElementOne(char *val) : te(TypeElement::two), left(nullptr), right(nullptr)
    {
        data.svalue = val;
    }

    ElementOne(unsigned long long value) : te(TypeElement::two), left(nullptr), right(nullptr)
    {
        data.value = value;
    }
};

//element of the second type
struct ElementTwo
{
    Data data;
    TypeElement te;
    ElementTwo *next;

    ElementTwo(char *val) : te(TypeElement::one), next(nullptr)
    {
        data.svalue = val;
    }

    ElementTwo(unsigned long long value) : te(TypeElement::one), next(nullptr)
    {
        data.value = value;
    }
};


int main()
{
    ElementOne root("Root");
    root.left = new ElementOne(1);
    root.right = new ElementTwo(1);

    root.left->left = new ElementOne(2);
    root.left->right = new ElementTwo(2);
    root.right->next = new ElementTwo(2);

    root.left->left->left = new ElementOne(3);
    root.left->left->right = new ElementTwo(3);
    root.left->right->next = new ElementTwo(3);
    root.right->next->next = new ElementTwo(3);

    //testing
    cout << root.data.svalue << " " << root.left->data.value << " " << root.right->next->next->data.value << endl;

    return 0;
}
