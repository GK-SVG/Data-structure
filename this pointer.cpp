#include<iostream>
using namespace std;
class person
{
 private:
 int id;
 int roll;
 float salary;
 public:
 void getdata(int id, int roll, float salary)
 {
   this->id=id; this->roll= roll; this->salary=salary;
 }

 void showdata()
 {
   cout<<"\n id="<<id<<"\n roll="<<roll<<"\n salary="<<salary;
 }
};



int main()
{
  person p1;
  p1.getdata();
  p1.showdata();
  return 0;
}
