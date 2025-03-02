#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
using namespace std;

enum MannerT{SelfInformationT, MutualInformationT, EntropyT};

MannerT manner;

void CalculateSelfInformation(){
    int NumOfVarites = 0;
    cout << "Enter the number of probabilities: ";
    cin >> NumOfVarites;
    double sum = 0.0, tmp = 0.0;
    for(int i = 0; i < NumOfVarites; ++i){
        cout << "Enter probability " << i + 1 << ": ";
        cin >> tmp;
        tmp = (-1.0) * (log(tmp) / log(2));
        sum += tmp;
    }
    cout << "Final result: " << fixed << setprecision(6) << sum << endl;
}

void CalculateEntropyType1(){
    int NumOfVarites = 0;
    cout << "Enter the number of probabilities: ";
    cin >> NumOfVarites;
    double sum = 0.0, tmp = 0.0;
    for(int i = 0; i < NumOfVarites; ++i){
        cout << "Enter probability " << i + 1 << ": ";
        cin >> tmp;
        double tmp_t = (-1.0) * (log(tmp) / log(2)) * (tmp);
        sum += tmp_t;
    }
    cout << "Final result: " << fixed << setprecision(6) << sum << endl;
}

void CalculateEntropyType2(){
    int NumOfVarites = 0;
    cout << "Enter the number of probabilities: ";
    cin >> NumOfVarites;
    int Type = 0;
    cout << "Enter the type of probabilities you know: 1. P(y) and P(x|y); 2. P(x,y) and P(x|y): ";
    cin >> Type;
    double sum = 0.0;
    for(int i = 0; i < NumOfVarites; ++i){
        double p1, p2;
        cout << "Enter the first probability for group " << i + 1 << ": ";
        cin >> p1;
        cout << "Enter the second probability for group " << i + 1 << ": ";
        cin >> p2;
        double tmp = p1 * (-1.0) * (log(p2) / log(2));
        if(Type == 1) tmp *= p2;
        sum += p2;
    }
    cout << "Final result: " << fixed << setprecision(6) << sum << endl;
}

void CalculateEntropy(){
    int TypeOfEntropy = 0;
    cout << "Enter the type of entropy to calculate: 1. Source entropy (uncertainty); 2. Conditional entropy (two variables); 3. Joint entropy (two variables): ";
    cin >> TypeOfEntropy;
    switch(TypeOfEntropy){
        case 1: CalculateEntropyType1(); break;
        case 2: CalculateEntropyType1(); break;
        case 3: CalculateEntropyType2(); break;
        default: cout << "Invalid input, please try again." << endl;
    }
}

void CalculateMutualInformationT(){
    int NumOfVarites = 0;
    cout << "Enter the number of probabilities: ";
    cin >> NumOfVarites;
    int type = 0;
    cout << "Enter the type of probabilities you know: 1. p(x,y), p(x|y), p(x); 2. p(x,y), p(x), p(y): ";
    cin >> type;
    double sum = 0.0;
    for(int i = 0; i < NumOfVarites; ++i){
        double p1, p2, p3;
        cout << "Enter the first probability for group " << i + 1 << ": ";
        cin >> p1;
        cout << "Enter the second probability for group " << i + 1 << ": ";
        cin >> p2;
        cout << "Enter the third probability for group " << i + 1 << ": ";
        cin >> p3;
        double tmp = 0.0;
        switch(type){
            case 1: tmp = p1 * (log(p2 / p3) / log(2)); break;
            case 2: tmp = p1 * (log(p1 / p2 / p3) / log(2)); break;
        }
        sum += tmp;
    }
    cout << "Final result: " << fixed << setprecision(6) << sum << endl;
}

int main(){
    int num = 0;
    bool flag = true;
    while(flag){
        cout << "What information do you want to calculate? 1. Self-information; 2. Mutual information; 3. Entropy: ";
        cin >> num;
        switch(num){
            case 1: manner = SelfInformationT; flag = false; break;
            case 2: manner = MutualInformationT; flag = false; break;
            case 3: manner = EntropyT; flag = false; break;
            default: cout << "Invalid input, please try again." << endl;
        }
    }
    switch(manner){
        case SelfInformationT: CalculateSelfInformation(); break;
        case MutualInformationT: CalculateMutualInformationT(); break;
        case EntropyT: CalculateEntropy(); break;
        default: cout << "?" << endl; return 0;
    }
    return 0;
}
