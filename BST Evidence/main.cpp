// Francisco Rocha Juárez - A01730560
// Iker Guerrero González - A00830026
// Aldo Maurico Cruz Lozada - A01732372

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//Creamos la clase para fecha
class Date{
  private:
    string month;
    int day, hour, minute, second;

  public:
    Date(){
      month = "none";
      day = 0;
      hour = 0;
      minute = 0;
      second = 0;
    }

    Date(string m, int day_aux, int hour_aux, int minute_aux, int second_aux){
     month = m;
     day = day_aux;
     hour = hour_aux;
     minute = minute_aux;
     second = second_aux;
    }
    string getMonth() const{
      return month;
    }
    int getDay() const{
      return day;
    }
    int getHour() const{
      return hour;
    }
    int getMinute() const{
      return minute;
    }
    int getSecond() const{
      return second;
  }


  void setMonth(int month1){
    month = month1;
  }
  void setDay(int day1){
    day = day1;
  }
  void setHour(int hour1){
    hour = hour1;
  }
  void setMinute(int minute1){
    minute = minute1;
  }
  void setSecond(int second1){
    second = second1;
  }

  void printDate(){
    string day_aux = to_string(day);
    string hour_aux = to_string(hour);
    string minute_aux = to_string(minute);
    string second_aux = to_string(second);
    if(day < 10){
      day_aux = "0" + day_aux;
    }
    if(hour < 10){
      hour_aux = "0" + hour_aux;
    }
    if(minute < 10){
      minute_aux = "0" + minute_aux;
    }
    if(second < 10){
      second_aux = "0" + second_aux;
    }
    cout << month << " " << day_aux << " " << hour_aux << ":" << minute_aux << ":" << second_aux << " ";
  }


  //Convierte la string de meses a un entero
  int monthToNumber(){
      if(month == "Jan"){
        return 1;
      } else if(month == "Feb"){
        return 2;
      } else if(month == "Mar"){
        return 3;
      } else if(month == "Apr"){
        return 4;
      } else if(month == "May"){
        return 5;
      } else if(month == "Jun"){
        return 6;
      } else if(month == "Jul"){
        return 7;
      } else if(month == "Aug"){
        return 8;
      } else if(month == "Sep"){
        return 9;
      } else if(month == "Oct"){
        return 10;
      } else if(month == "Nov"){
        return 11;
      } else if(month == "Dec"){
        return 12;
      }
      return 0;
  }
};

class ip_Address{
  private:
        int firstPart;
        int secondPart;
        int thirdPart;
        int fourthPart;
        int ip_Port;
  public:
    ip_Address(){
      firstPart=0;
      secondPart=0;
      thirdPart=0;
      fourthPart=0;
      ip_Port=0;
    }

    ip_Address(int firstPart, int secondPart, int thirdPart, int fourthPart, int ip_Port){
      this -> firstPart = firstPart;
      this -> secondPart = secondPart;
      this -> thirdPart = thirdPart;
      this -> fourthPart = fourthPart;
      this -> ip_Port = ip_Port;
    }
    void setNumOne(){
    this -> firstPart = firstPart;
    }
    int getNumOne(){
      return firstPart;
    }
    void setNumTwo(){
      this -> secondPart = secondPart;
    }
    int getNumTwo(){
      return secondPart;
    }
    void setNumThree(){
      this -> thirdPart = thirdPart;
    }
    int getNumThree(){
      return thirdPart;
    }
    void setNumFour(){
      this -> fourthPart = fourthPart;
    }
    int getNumFour(){
      return fourthPart;
    }
    void setPort(int ip_Port){
      this->ip_Port=ip_Port;
    }
    int getPort(){
      return ip_Port;
    }
    void printIp(){
      cout<<firstPart<<"."<<secondPart<<"."<<thirdPart<<"."<<fourthPart<<":"<<ip_Port;
    }
};

class Register{

private:
  Date date;
  ip_Address ip;
  string message;

public:
  Register(Date &date1, ip_Address &ip1, string message1){
    date=date1;
    ip=ip1;
    message= message1;
  }
  Register(){
    Date date1("",1,1,1,1);
    date = date1;
    ip_Address dir1(1,1,1,1,1);
    ip = dir1;
    message="";
  }
  Date getDate(){
    return date;
  }

  ip_Address getIp(){
    return ip;
  }

  string getMessage(){
    return message;
  }
  void printRegister(){
    date.printDate();
    ip.printIp();
    cout<<" "<<message<<endl;
  }


};


struct Node {
    Register data;
    Node* left;
    Node* right;
};


//Orden O(1)
Node* creaNodo(Register &registro1) {
  Node* new_tree_segment = new Node();
  new_tree_segment -> data = registro1;
  new_tree_segment -> left = NULL;
  new_tree_segment -> right = NULL;
  return new_tree_segment;
}

//Se crea la función para verificar las fechas
//O(1)
int compDates(Register &data1, Register &data2) {
  Date fecha1 = data1.getDate();
  Date fecha2 = data2.getDate();
  int m1, m2, d1, d2, h1, h2, min1, min2, s1, s2;
  m1 = fecha1.monthToNumber();
  d1 = fecha1.getDay();
  h1 = fecha1.getHour();
  min1 = fecha1.getMinute();
  s1 = fecha1.getSecond();
  m2 = fecha2.monthToNumber();
  d2 = fecha2.getDay();
  h2 = fecha2.getHour();
  min2 = fecha2.getMinute();
  s2 = fecha2.getSecond();
  if(m1<m2){ //Mes
    return -1;
  }else if(m1>m2){
    return 1;
  }else{
    if(d1<d2){ //Dia
      return -1;
    }else if(d1>d2){
      return 1;
    }else{
      if(h1<h2){ //Hora
        return -1;
      }else if(h1>h2){
        return 1;
      }else{
        if(min1<min2){ //Minuto
          return -1;
        }else if(min1>min2){
          return 1;
        }else{
          if(s1<s2){ //Segundo
            return -1;
          }else if(s1>s2){
            return 1;
          }else{
            return 0;
          }
        }
      }
    }
  }
}

//Verificar IP'second_aux
//Orden O(1)
int compIp(Register &data1, Register &data2) {
  ip_Address ip1 = data1.getIp();
  ip_Address ip2 = data2.getIp();
  int numOne1, numOne2, numTwo1, numTwo2, numThree1, numThree2, numFour1, numFour2, port1, port2;
  numOne1 = ip1.getNumOne();
  numTwo1 = ip1.getNumTwo();
  numThree1 = ip1.getNumThree();
  numFour1 = ip1.getNumFour();
  port1 = ip1.getPort();
  numOne2 = ip2.getNumOne();
  numTwo2 = ip2.getNumTwo();
  numThree2 = ip2.getNumThree();
  numFour2 = ip2.getNumFour();
  port2 = ip2.getPort();


  if(numOne1<numOne2){
    return -1;
  }else if(numOne1>numOne2){
    return 1;
  }else{
    if(numTwo1<numTwo2){
      return -1;
    }else if(numTwo1>numTwo2){
      return 1;
    }else{
      if(numThree1<numThree2){
        return -1;
      }else if(numThree1>numThree2){
        return 1;
      }else{
        if(numFour1<numFour2){
          return -1;
        }else if(numFour1>numFour2){
          return 1;
        }else{
          if(port1<port2){
           return -1;
         }else if(port1>port2){
           return 1;
         }else{
           return 0;
          }
        }
      }
    }
  }
}

//Se crea un método para verificar los error_Texts
//Orden O(1)
int comp_Error_Text(Register &data1, Register &data2) {
  string error_Text1 = data1.getMessage();
  string error_Text2 = data2.getMessage();

  if(error_Text1 > error_Text2){
    return -1;
  } else if(error_Text1 < error_Text2) {
    return 1;
  } else {
    return 0;
  }
}

//Se crea un método para verificar los registros
//Orden O(1)
int compRegisters(Node *reg1, Node *reg2){
  if(reg1 == NULL) {
    return 1;
  } else {
    Register data1 = reg1 -> data;
    Register data2 = reg2 -> data;
    int resultIp = compIp(data1, data2);
    if(resultIp == 0) {
      int resultFecha = compDates(data1, data2);
      if(resultFecha != 0){
        return resultFecha;
      } else {
        int resultMessage = comp_Error_Text(data1, data2);
        return resultMessage;
      }
    }
    return resultIp;
  }
}

//Las IP se separan
//Orden O(n)
vector<int> separate_IP(string ipIn){
  vector<int> ipNum;
  string separator = ".";
  string separator1 = ":";
  int position = 0;
  string aux;

  vector<string> vector_ips;

  while ((position = ipIn.find(separator)) != string::npos) {
    aux = ipIn.substr(0, position);
    ipIn.erase(0, position + separator.length());
    vector_ips.push_back(aux);
  }

  position = 0;

  while ((position = ipIn.find(separator1)) != string::npos) {
    aux = ipIn.substr(0, position);
    ipIn.erase(0, position + separator1.length());
    vector_ips.push_back(aux);
  }

  vector_ips.push_back(ipIn);

  for(int i = 0; i < vector_ips.size(); i++){
    int terminoIp = stoi(vector_ips[i]);
    ipNum.push_back(terminoIp);
  }
  return ipNum;
}

//Función para imprimir las IP másecond_aux altos de acuerdo a un int que indica el usuario
//Orden O(n)
void print_big_IP(Node* node, int n) {
    static int count = 0;
    if (node == NULL) return;
    if (count <= n) {
        print_big_IP(node -> right, n);
        count++;
        if(count <= n) {
          Register new_registro = node -> data;
          new_registro.printRegister();
        }
        print_big_IP(node -> left, n);
    }
}

//Inserta los registros en el orden
//Orden O(n)
void insertRegister(Node* &root, Node* registro){
  Node* temp = root;
  Node* prev;
  bool direction;
  if(root == NULL) {
    root = registro;
  } else {
    while(temp != NULL) {
      prev = temp;
      int result = compRegisters(registro,temp);
      if(result == -1) {
        temp = temp -> left;
        direction = 0;
      } else if(result == 1) {
        temp = temp -> right;
        direction = 1;
      } else return;
    }
    if(direction == 0) {
      prev -> left = registro;
    } else if(direction == 1) {
      prev -> right = registro;
    }
  }
}


int main() {
  int index = 0, day_aux, hour_aux, m, second_aux, d1Input, m1Input, d2Input, m2Input;
  vector<string> vector_dates;
  vector<int> ipAct;
  string month_in, day_in, hour_in, ip_in, message_in;
  Node* root = NULL;
  ifstream input("bitacora.txt");

  //Mientras el archivo no termine se leen las líneas
  while(!input.eof()) {
    getline(input,month_in,' ');
    getline(input,day_in,' ');
    getline(input,hour_in,' ');
    getline(input,ip_in,' ');
    getline(input,message_in);
    string separation = ":";
    int position = 0;
    string aux;

    while ((position = hour_in.find(separation)) != string::npos) {
      aux = hour_in.substr(0, position);
      hour_in.erase(0, position + separation.length());
      vector_dates.push_back(aux);
    }

    vector_dates.push_back(hour_in);
    hour_aux = stoi(vector_dates[index]);
    index++;
    m = stoi(vector_dates[index]);
    index++;
    second_aux = stoi(vector_dates[index]);
    index++;
    day_aux = stoi(day_in);
    Date new_date(month_in, day_aux, hour_aux, m, second_aux);
    ipAct = separate_IP(ip_in);
    ip_Address new_ip(ipAct[0], ipAct[1], ipAct[2], ipAct[3], ipAct[4]);
    Register new_data(new_date, new_ip, message_in);

    Node* new_tree_segment=creaNodo(new_data);
    insertRegister(root,new_tree_segment);
  }

  // cout << "Write the number of IP'second_aux to print, only the biggest will be printed" << '\n';
  // cin >> n;
  // print_big_IP(root,n);

  //En este caso solamente se imprimen 5, porque es lo que indica la tarea
  print_big_IP(root, 5);

  return 0;
}
