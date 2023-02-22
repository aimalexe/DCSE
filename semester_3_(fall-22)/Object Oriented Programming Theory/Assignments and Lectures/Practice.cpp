#include <iostream>
#include <string.h>

class article {
public:
int code;
char name[20];
float weight, length;
};


article *plargeobj(article *px) // functional spec
{ article obj; // local object
obj.code = px->code +1; // increment code
strcpy(obj.name, px->name); // copy name
obj.weight = 2 * px->weight; // double weight
obj.length = 2 * px->length; // double length
return &obj; // ERROR; WHY?
}

int main(){
    article *a;
    a = plargeobj(a);
}
