#include "EnfantHandicape.cpp"
#include <vector>
#include <iomanip>
#include <chrono>

bool YesOrNo(string test){
    if (test == "yes" || test == "no") return true;
    else return false;
}

int calculateAge(int Day, int Month, int Year) {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);
    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = 1900 + localTime->tm_year; 
    int age = currentYear - Year;
    if (currentMonth < Month || (currentMonth == Month && currentDay < Day)) age--; 

    return age;
}
void compare(int a ,int b){
    if (a<b) cout<<"1<2"<<endl;
    else cout<<"2<1"<<endl;
}


int main(){
    
    vector<Enfant*> Ecole;
    string choice;
    int NbEnfant ;



    cout<<"How many children you want to enter : ";
    cin>>NbEnfant;

    for (int i = 0;i<NbEnfant;i++){
        
        string WithDisease;
        cout<<"********Does the child has a disease (Answer with 'yes' or 'no') "; 
        do{
            cout<<"Please type in a correct answer : ";
            cin>>WithDisease;

        }while(YesOrNo(WithDisease) == false);
        
        if (WithDisease == "yes"){
            int Code,Day,Month,Year,Type;
            string Name,Lastname;
            cout<<"Type the Name of the child : ";
            cin>>Name;
            cout<<"Type the Lastname of the child : ";
            cin>>Lastname;
            cout<<"Type the date of birth of the child : "<<endl;;
            cout<<"Day : ";
            cin>>Day;
            cout<<"Month : ";
            cin>>Month;
            cout<<"Year : ";
            cin>>Year;
            cout<<"Choose the diseaso of the child (1 = 'test' , 2 = 'test' , 3 = 'test') : ";
            cin>>Type;
            EnfantHandicape* e = new EnfantHandicape(i+1,Name,Lastname,{Day,Month,Year},Type);
            Ecole.push_back(e);
        }
        else if (WithDisease == "no"){
            int Code,Day,Month,Year;
            string Name,Lastname;
            cout<<"Type the Name of the child : ";
            cin>>Name;
            cout<<"Type the Lastname of the child : ";
            cin>>Lastname;
            cout<<"Type the date of birth of the child : "<<endl;;
            cout<<"Day : ";
            cin>>Day;
            cout<<"Month : ";
            cin>>Month;
            cout<<"Year : ";
            cin>>Year;
            Enfant* e = new Enfant(i+1,Name,Lastname,{Day,Month,Year});
            Ecole.push_back(e);
        }
        cout<<"***_________________________________***"<<endl;
    }

    string More;
    cout<<"Do you want to add more children : (Answer with 'yes' or 'no') : ";
    cin>>More;
    while(YesOrNo(More)){
        if (More == "yes"){
            
        string WithDisease;
        cout<<"********Does the child has a disease (Answer with 'yes' or 'no') "; 
        do{
            cout<<"Please type in a correct answer : ";
            cin>>WithDisease;

        }while(YesOrNo(WithDisease) == false);
        
        if (WithDisease == "yes"){
            int Code,Day,Month,Year,Type;
            string Name,Lastname;
            cout<<"Type the Name of the child : ";
            cin>>Name;
            cout<<"Type the Lastname of the child : ";
            cin>>Lastname;
            cout<<"Type the date of birth of the child : "<<endl;;
            cout<<"Day : ";
            cin>>Day;
            cout<<"Month : ";
            cin>>Month;
            cout<<"Year : ";
            cin>>Year;
            cout<<"Choose the diseaso of the child (1 = 'test' , 2 = 'test' , 3 = 'test') : ";
            cin>>Type;
            EnfantHandicape* e = new EnfantHandicape(Ecole.size(),Name,Lastname,{Day,Month,Year},Type);
            Ecole.push_back(e);
        }
        else if (WithDisease == "no"){
            int Code,Day,Month,Year;
            string Name,Lastname;
            cout<<"Type the Name of the child : ";
            cin>>Name;
            cout<<"Type the Lastname of the child : ";
            cin>>Lastname;
            cout<<"Type the date of birth of the child : "<<endl;;
            cout<<"Day : ";
            cin>>Day;
            cout<<"Month : ";
            cin>>Month;
            cout<<"Year : ";
            cin>>Year;
            Enfant* e = new Enfant(Ecole.size(),Name,Lastname,{Day,Month,Year});
            Ecole.push_back(e);
        }
        cout<<"***_________________________________***"<<endl;
        cout<<"Do you want to add more children : (Answer with 'yes' or 'no') : ";
        cin>>More;
        }
        else break;
    }
    cout<<endl<<"***********Affichage************"<<endl;
    int sumE = 0,sumEh = 0,max = 0;

    for (int i = 0;i<Ecole.size();i++){
        if (typeid(*Ecole[i]) == typeid(Enfant*)) sumE +=1;
        else sumEh +=1;
        Ecole[i]->Afficher();
        cout<<"**************************"<<endl;
    }
    cout<<"There is "<<sumE<<" normal children and "<<sumEh<<" children with disease"<<endl;

    int Day = Ecole[0]->GetDay(); 
    int Month = Ecole[0]->GetMonth(); 
    int Year = Ecole[0]->GetYear();
    int Max = calculateAge(Day,Month,Year);
    int Min = calculateAge(Day,Month,Year);
    int IndMax = 0;
    int IndMin = 0;

    for (int i = 0;i<Ecole.size()-1;i++){
        int Day1 = Ecole[i]->GetDay(); 
        int Month1 = Ecole[i]->GetMonth(); 
        int Year1 = Ecole[i]->GetYear(); 
        if (calculateAge(Day1,Month1,Year1) > Max) {
            Max  = calculateAge(Day1,Month1,Year1);
            IndMax = i;
        }
        if (calculateAge(Day1,Month1,Year1) < Min) {
            Min  = calculateAge(Day1,Month1,Year1);
            IndMin = i;
        }
    }

    cout<<"The oldest child is the one with the code : "<<IndMax<<endl;
    cout<<"The youngest child is the one with the code : "<<IndMin<<endl;

    system("PAUSE");
    return 1;
}