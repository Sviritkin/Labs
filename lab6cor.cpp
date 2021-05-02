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
    unsigned long long value1; //integer number
    bool value2; //boolean value
    long double value3;  //real number

    Data() : value1(0) {}
};


//element of the second type
struct ElementTwo
{
    Data data;
    TypeElement te;
    ElementTwo* next;

    //constructor
    ElementTwo(unsigned long long value) : te(TypeElement::one), next(nullptr)
    {
        data.value1 = value;
    }

    //destructor
    ~ElementTwo()
    {
        freeTwo(&next);
        next = nullptr;
    }

private:

    //recursively deletes an object
    void freeTwo(ElementTwo** two)
    {
        if (*two)freeTwo(&(*two)->next);
        else
            return;
        delete* two;
        *two = nullptr;
    }
};


//element of the first type
struct ElementOne
{
    Data data;
    TypeElement te;
    ElementOne* left; //pointers to the left and right elements
    ElementTwo* right;

    //constructor
    ElementOne(unsigned long long value) : te(TypeElement::two), left(nullptr), right(nullptr)
    {
        data.value1 = value;
    }

    //destructor
    ~ElementOne()
    {
        delete right;
        right = nullptr;
        freeOne(&left);
    }

private:

    //recursively deletes an object
    void freeOne(ElementOne** one)
    {
        if (*one)freeOne(&(*one)->left);
        else
            return;
        delete* one;
        *one = nullptr;
    }
};



int main()
{
    ElementOne* root = new ElementOne(0);
    root->left = new ElementOne(1);
    root->right = new ElementTwo(1);

    root->left->left = new ElementOne(2);
    root->left->right = new ElementTwo(2);
    root->right->next = new ElementTwo(2);

    root->left->left->left = new ElementOne(3);
    root->left->left->right = new ElementTwo(3);
    root->left->right->next = new ElementTwo(3);
    root->right->next->next = new ElementTwo(3);

    //testing
    cout << root->data.value1 << " " << root->left->data.value1 << " " << root->right->next->next->data.value1 << endl;

    delete root;
    return 0;
}
