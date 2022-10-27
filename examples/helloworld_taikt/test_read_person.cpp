#include <iostream>
#include <fstream>
#include <string>
#include "person.pb.h"
using namespace std;

// g++ -std=c++11 test_read_person.cpp -o read_person person.pb.cc -L/usr/local/lib -lprotobuf -pthread
int main() {

    // read data from file
    PERSON::Person per2;
    fstream input("person.data", ios::in | ios::binary);
    if (!per2.ParseFromIstream(&input)) {
      cerr << "Failed to parse person data." << endl;
      return -1;
    }

    if (per2.has_name())
        cout<<" [read] name: "<<*per2.mutable_name()<<"\n";
    else cout<<"[read] name not defined\n";

    if (per2.has_email())
        cout<<" [read] email: "<<*per2.mutable_email()<<"\n";
    else cout<<"[read] email not defined\n";

    if (per2.has_id())
        cout<<" [read] id: "<<per2.id()<<"\n";

    return 0;
}