#include <iostream>
#include <fstream>
#include <string>
#include "person.pb.h"
using namespace std;

// g++ -std=c++11 test_write_person.cpp -o write_person person.pb.cc -L/usr/local/lib -lprotobuf -pthread

int main() {

    PERSON::Person per;
    const string name = "tai";
    const string email = "tai2.tran@lge.com";

    per.set_name(name);
    per.set_id(10);
    per.set_email(email);

    if (per.has_name())
        cout<<" name: "<<*per.mutable_name()<<"\n";
    else cout<<"name not defined\n";

    if (per.has_email())
        cout<<" email: "<<*per.mutable_email()<<"\n";
    else cout<<"name not defined\n";

    if (per.has_id())
        cout<<" id: "<<per.id()<<"\n";

    //cout << per.DebugString()<<"\n";

    // write data to file
    fstream output("person.data", ios::out | ios::trunc | ios::binary);
    if (!per.SerializeToOstream(&output)) {
      cerr << "Failed to write person infor." << endl;
      return -1;
    } else cout<<"write data successfully\n";

    return 0;
}