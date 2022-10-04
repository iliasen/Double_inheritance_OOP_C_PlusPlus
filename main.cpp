#include <iostream>
#include <string>
using namespace std;

class Codec
{
public:
  Codec()
  {
    cout << "Конструктор класса Codec вызван" << endl;
  }
  void AddGData()
  { cout<<"Введите имя группы кодеков:";
    cin>>groupname;
    cout<<"Введите примерное время выполнения группы кодеков";
    cin>>grouptime;
  }
  void OutGData(){
    cout<<"Имя группы кодеков:"<<groupname<<"Примерное время выполнения кодеков данной группы:"<<grouptime<<endl;
  }
  ~Codec()
  {
    cout << "Диструктор класса Codec вызван" << endl;
  }
private:
string groupname;
int grouptime;
};

class JSONcodec: public virtual Codec
{
public:
  JSONcodec()
  {
    cout << "Конструктор класса JSONcodec вызван" << endl;
  }
  void AddJData()
  {
    cout<<"Введите имя данного кодека: ";
    cin>>jname;
    cout<<"Введите время выполнения данного кодека: ";
    cin>>jtime;
  }
  void OutJData(){
    cout<<"Имя кодека:"<<jname<<"Bремя выполнения кодекa:"<<jtime<<endl;
  }
  ~JSONcodec()
  {
    cout << "Диструктор класса JSONcodec вызван" << endl;
  }
private:
  string jname;
  int jtime;
};

class XMLcodec: public virtual Codec
{
public:
  XMLcodec()
  {
    cout << "Конструктор класса XMLcodec вызван" << endl;
  }
  void AddXData()
  {
    cout<<"Введите имя данного кодека: ";
    cin>>xname;
    cout<<"Введите время выполнения данного кодека: ";
    cin>>xtime;
  }
  void OutXData(){
    cout<<"Имя кодека:"<<xname<<"Bремя выполнения кодекa:"<<xtime<<endl;
  }
  ~XMLcodec()
  {
    cout << "Диструктор класса XMLcodec вызван" << endl;
  }
private:
  string xname;
  int xtime;
};

class Protobufcodec: public virtual Codec
{
public:
  Protobufcodec()
  {
    cout << "Конструктор класса Protobucodec вызван" << endl;
  }
  void AddPData()
  {
    cout<<"Введите имя данного кодека: ";
    cin>>pname;
    cout<<"Введите время выполнения данного кодека: ";
    cin>>ptime;
  }
  void OutPData(){
    cout<<"Имя кодека:"<<pname<<"Bремя выполнения кодекa:"<<ptime<<endl;
  }
  ~Protobufcodec()
  {
    cout << "Диструктор класса Protobucodec вызван" << endl;
  }
private:
  string pname;
  int ptime;
};

class Instructions: public JSONcodec, public XMLcodec, public Protobufcodec
{public:
  Instructions(){}
  void AddIData()
  {
    cout<<"Введите инструкцию выполнения: ";
    cin>>settings;
    cout<<"Введите тип выполнений: ";
    cin>>type_of_instructions;
  }
  void OutIData(){
    cout<<"Имя кодека:"<<settings<<"Bремя выполнения кодекa:"<<type_of_instructions<<endl;
  }
  ~Instructions(){}
private:
string settings,type_of_instructions;
};

int main()
{
  setlocale(LC_ALL, "rus");
  Instructions i;
  cout<<"Выберите:"<<endl<<"\n1. Ввод элементов"<<"\n2. Вывод элементов"<<"\n3. Выход"<<endl<<"\nВаш выбор:"<<endl;
  int key;
  cin>>k;
  while(1){
  switch (key)
  {
  case 1: i.AddGData();
 cout<<"Выберите:"<<endl<<"\n1. Ввод кодеков json "<<"\n2. Ввод xml кодеков"<<"\n3. Ввод Production кодек"<<endl<<"\nВаш выбор:"<<endl;
  int choise;
  cin>>choise;
  switch(choise)
  {
    case 1:
      i.AddJData();
      break;
    case 2:
      i.AddXData();
      break;
    case 3:
    i.AddPData();
    break;
  }
   i.AddIData();
    break;
  case 2:cout<<"Выберите:"<<endl<<"\n1. Вывод кодеков json "<<"\n2. Вывод xml кодеков"<<"\n3. Вывод Production кодек"<<endl<<"\nВаш выбор:"<<endl;
  int choise;
  cin>>choise;
  switch(choise)
  {
    case 1:
      i.OutJData();
      break;
    case 2:
      i.OutXData();
      break;
    case 3:
    i.OutPData();
    break;
  }
  i.OutPData();
  break;
  default:
  return 0;
    break;
  }
  }
  return 0;
}