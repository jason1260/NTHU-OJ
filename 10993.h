#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
using namespace std;
class Polynomial
{
    public:
        Polynomial();
        Polynomial(const int , const int [51]);
        Polynomial add( const Polynomial) const; // add function
        Polynomial subtract( const Polynomial ) const; // subtract function
        Polynomial multiplication( const Polynomial ) const; // multiplication function
        void output() const;
    private:
        int coefficients[101]; // integer coefficients
        int greatestPower; // integer greatestPower
}; // end class Polynomial
Polynomial::Polynomial() {
    greatestPower = 0;
    for (int i = 0; i < 51; i++) coefficients[i] = 0;
};
Polynomial::Polynomial(const int gp, const int co[51]) {
    greatestPower = gp;
    for (int i = 0; i < 51; i++) coefficients[i] = 0;
    for (int i = gp; i >= 0; i--) coefficients[i] = co[i];
}
Polynomial Polynomial::add(Polynomial b) const{
    Polynomial ans;
    int end = (greatestPower > b.greatestPower) ? greatestPower : b.greatestPower;
    for (int i = 0; i <= end; i++) {
        ans.coefficients[i] = coefficients[i] + b.coefficients[i];
    }
    for (end; end > 0 && ans.coefficients[end] == 0; end--);
    ans.greatestPower = end;
    return ans;
}
Polynomial Polynomial::subtract(Polynomial b) const{
    Polynomial ans;
    int end = (greatestPower > b.greatestPower) ? greatestPower : b.greatestPower;
    for (int i = 0; i <= end; i++) {
        ans.coefficients[i] = coefficients[i] - b.coefficients[i];
    }
    for (end; end > 0 && ans.coefficients[end] == 0; end--);
    ans.greatestPower = end;
    return ans;
}
Polynomial Polynomial::multiplication(Polynomial b) const{
    Polynomial ans;
    for (int i = 0; i <= greatestPower; i++) {
        for (int j = 0; j <= b.greatestPower; j++) {
            ans.coefficients[i + j] += coefficients[i] * b.coefficients[j];
        }
    }
    int end = greatestPower + b.greatestPower;
    for (end; end > 0 && ans.coefficients[end] == 0; end--);
    ans.greatestPower = end;
    return ans;
}
void Polynomial::output() const{
    for (int i = greatestPower; i >= 0; i--) (i != 0) ? cout << coefficients[i] << ' ' : cout << coefficients[i];
    //cout << coefficients[0]; 
}
#endif

