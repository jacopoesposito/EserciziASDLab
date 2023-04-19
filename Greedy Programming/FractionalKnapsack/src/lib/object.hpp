using namespace std;


#ifndef object_hpp
#define object_hpp

class Object{

    public:
        Object(double value, double weigth);
        double getValue();
        double getWeigth();
        void setWeigth(double weigth);
    private:
        double value;
        double weigth;
};

Object::Object(double value, double weigth){
    this->value = value;
    this->weigth = weigth;
}

double Object::getValue(){
    return value;
}

double Object::getWeigth(){
    return weigth;
}

void Object::setWeigth(double weigth){
    this->weigth = weigth;
}


#endif