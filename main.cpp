
#include<bits//stdc++.h>
using namespace std;

class Restaurant 
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    double total_tax;
    int tax(){
        total_tax=0;
        return total_tax;
     }
};

int main(){
    Restaurant *myResturant=new Restaurant;
    int n;
    cout<<"Enter how many products you add: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter you product code: ";
        cin>>myResturant->food_item_codes[i];
        cin.ignore();
        cout<<"Enter your product name: ";
        getline(cin,myResturant->food_item_names[i]);
        cout<<"Enter your product price: ";
        cin>>myResturant->food_item_prices[i];
    }
    double netBill;
    while(true){
        myResturant->tax();
        netBill=0;
        cout<<"\t\t\t\t\tMAKE BILL"<<endl;
        cout<<"\t\t\t\t_______________________"<<endl;
        cout<<"Item Code\t\t\tItem Name\t\t\t\tItem Price"<<endl;
        for(int i=0;i<n;i++){
            cout<<myResturant->food_item_codes[i]<<"\t\t\t\t"<<myResturant->food_item_names[i]<<"\t\t\t"<<myResturant->food_item_prices[i]<<endl;
        }
        int table,item;
        cout<<"Enter Table no : ";
        cin>>table;
        cout<<"Enter Number of Item : ";
        cin>>item;
        int code[item],quantity[item];
        for(int i=0,k=1;i<item;i++,k++){
        
            cout<<"Enter Item "<<k<<" code : ";
            flag:
            bool check=false;
            cin>>code[i];
            for(int j=0;j<n;j++){
                if(code[i]==myResturant->food_item_codes[j]){
                    check=true;
                }
               

            }
            if(check==false){
                cout<<"Code isn't Valid, Enter again : ";
                goto flag;
            }

            cout<<"Enter Item "<<k<<" Quantity : ";
            cin>>quantity[i];
           
        }
        
        for(int i=0;i<item;i++){
            for(int j=0;j<n;j++){
                if(myResturant->food_item_codes[j]==code[i]){
                    netBill+=(myResturant->food_item_prices[j]*quantity[i]);
                }
            }
        }
    myResturant->total_tax += ((netBill*5)/100);
    netBill +=myResturant->total_tax;
    // cout<<fixed<<setprecision(2)<<myResturant->total_tax<<endl;
    //  cout<<totalBill<<endl;
    cout<<"\t\t\t\t\tBILL SUMMARY"<<endl;
    cout<<"\t\t\t\t__________________________"<<endl;
    cout<<"Table No : "<<table<<endl;
     cout<<"Item Code\t\tItem Name\t\tItem Price\t\tItem Quantity\t\tTotal Price"<<endl;
     for(int i=0;i<item;i++){
        for(int j=0;j<n;j++){
                if(myResturant->food_item_codes[j]==code[i]){
                    cout<<myResturant->food_item_codes[j]<<"\t\t\t"<<myResturant->food_item_names[j]<<"\t"<<myResturant->food_item_prices[j]<<"\t\t\t"<<quantity[i]<<"\t\t\t"<<myResturant->food_item_prices[j]*quantity[i]<<endl;
                }
            }
     }
     cout<<"Tax\t\t\t\t\t\t\t\t\t\t\t\t"<<fixed<<setprecision(2)<<myResturant->total_tax<<endl;
     cout<<"____________________________________________________________________________________________________________"<<endl;
     cout<<"NET TOTAL\t\t\t\t\t\t\t\t\t\t\t"<<fixed<<setprecision(2)<<netBill<<" Taka"<<endl;

    }

}


