using namespace std;


#ifndef activity_hpp
#define activity_hpp

//Classe che rappresenta un'attività, dotata dunque di due attributi privati
//rappresentanti il tempo di inizio e fine, e due metodi getter + il costruttore.
class Activity {
    public:
        Activity(int start, int end);
        int getStart();
        int getEnd();
    private:
        int start;
        int end;

};

Activity::Activity(int start, int end){
    this->start = start;
    this->end = end;
}

int Activity::getStart(){
    return start;
}

int Activity::getEnd(){
    return end;
}

#endif