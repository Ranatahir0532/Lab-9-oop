#include<iostream>
#include<string>
using namespace std;
class transaction{
protected:
   int account_number;
   double amount;
  public:
  transaction(int acc,double am):account_number(acc),amount(am){
  }	
  virtual void process_transaction()=0;
};
class deposit:public transaction{
protected:
  	double Deposit_amount;
  	public:
  	deposit(int acc,double am,double da):transaction(acc,am),Deposit_amount(da){
  		
	  }	
	void process_transaction() override{
	amount+=Deposit_amount;
	cout<<"account number: "<<account_number<<endl;
	cout<<"Amount:"<<Deposit_amount<<" deposited sucessfully"<<endl;
	cout<<"total new amount is : "<<amount<<endl;
	}
};  
class Withdrawal:public transaction{
protected:
	double withdrawal_amount;
	public:
		Withdrawal(int acc,double am,double wa):transaction(acc,am),withdrawal_amount(wa){
  		
	  }	
	void process_transaction() override{
	if(withdrawal_amount>amount){
		cout<<"insuficient amount to withdrawal....."<<endl;
		return;
	}
	amount-=withdrawal_amount;
	cout<<"account number: "<<account_number<<endl;
	cout<<"Amount:"<<withdrawal_amount<<" withdrawal sucessfully"<<endl;
	cout<<"total new amount is : "<<amount<<endl;
	}
		

};
class Transfer:public transaction{
protected:
 int transfer_accnum;
 double transfer_amount;
 public:
    Transfer(int acc,double am,int tan,double ta):transaction(acc,am),transfer_accnum(tan){
  	transfer_amount=ta;
	  }	
	void process_transaction() override{
		if(transfer_amount>amount){
		cout<<"insuficient amount to transfer....."<<endl;
		return;
	}
	amount-=transfer_amount;
	cout<<"account number: "<<account_number<<endl;
	cout<<"Amount:"<<transfer_amount<<" transfered sucessfully to :"<<transfer_accnum<<endl;
	cout<<"total new amount is : "<<amount<<endl;
	}
 	
};
int main(){
  transaction *t1,*t2,*t3;
  t1=new deposit(1001,50000,4000);
  t2=new Withdrawal(1002,10000,3000);
  t3=new Transfer(1003,100000,1070,30000);
  cout<<"-----Deposit transaction----"<<endl;
  t1->process_transaction();
    cout<<"-----Withdrawal transaction----"<<endl;
  t2->process_transaction();
    cout<<"-----Transfer transaction----"<<endl;
  t3->process_transaction();
}
