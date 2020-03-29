//
//  Customer.h
//  Heap Assignment Mac Version
//
//  Created by hcheng on 28/6/18.
//  Copyright © 2018 NUS. All rights reserved.
//


#ifndef Customer_h
#define Customer_h

class Customer {
private:
    int arrival_time; // time of arrival after the shop opened in min
    int processing_time; // amount of time need to be processed with the customer serivce in min
public:
    Customer () {arrival_time = 0; processing_time = 0;};
    void setAT(int t) {arrival_time = t;};
    void setPT(int t) {processing_time = t;};
    int AT() {return arrival_time;};
    int PT() {return processing_time;};
	bool operator>(const Customer& c); // a customer is "greater" if his time is shorter
        
};

void customerQueueTest(int);

#endif /* Customer_h */
