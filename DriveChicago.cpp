#include "iostream"
#include "string"
using namespace std;

class User {
    protected :
    string UserName; string UserEmail;
    bool isLoggedIn;

    public :
    User () : UserName("Unkown"),UserEmail("Unknownn"), isLoggedIn(false) {}
    User (const string& name, string e_mail) : UserName(name),UserEmail(e_mail), isLoggedIn(false) {}
    
    virtual void viewDashboard () = 0;

    void login () {isLoggedIn =true;}
    void logout () { isLoggedIn = false; }
}; 

class Engine {
    private :
    string EngineType;
    int horsepower;
    int NumberOfCylinders;
    string fuelType;
    bool isTurbo;
    int oilHealth;

    public :
    Engine() : EngineType("Unknown"), horsepower(0), oilHealth(100) {}
    Engine(const string& type,int power,int NOC,const string& fuel,bool charged,int level) : EngineType(type), horsepower(power), NumberOfCylinders(NOC), fuelType(fuel), isTurbo(charged), oilHealth(level)  {}

    void startEngine () {
        cout << "2024 F-150 ignition on. Engine running." << endl;
    }
    void stopEngine () {
        cout  << "thunk" << endl;
    }
    void checkOil() const {
        if (oilHealth >= 75)
        cout << "Mint condition - Oil. (" << oilHealth << "%)\n";
        else if (oilHealth >= 40)
        cout << "Mera mashwara oil change karwalo engine health achi rahegi. (" << oilHealth << "%)\n";
        else
        cout << "Jawwad dasti oil change karrrrrrrrrr. Murga mil gaya . (" << oilHealth << "%)\n";
    }

    string getSpecs () const {
        string specs = "400hp | 6-cyl | TurboCharged | Gas";
        return specs;
    }
    string getEngineType () { return EngineType; }
    int  getHorsepower () { return horsepower; }
    int  getNumberOfClyinders () { return NumberOfCylinders; }
    string getFuelType () { return fuelType; }
    bool getIsTurboCharged () { return isTurbo; }
    int  getOilHealth () { return oilHealth; }
};

class Transmission {
    private :
    string serialNo;
    string TransmissionType;
    int NumberOfGears;
    bool isWorking;
    int fluidLevel; 
    int currentGear;

    public : 
    Transmission () : serialNo("N/A"), TransmissionType("Auto"), NumberOfGears(6), fluidLevel(100) {}
    Transmission (const string& number,const string& type,int NOG) : serialNo(number), TransmissionType(type), NumberOfGears(NOG)  {
        isWorking = true; fluidLevel = 100; currentGear = 1;
    }

    void shiftUp() {
        if (currentGear < NumberOfGears) {
        currentGear++;
        cout << "Shifted up to gear " << currentGear << " of " << NumberOfGears << ".\n";
        } else {
        cout << "Already in top gear (" << NumberOfGears << "). Can't shift higher.\n";
        }
    }
    void shiftDown() {
        if (currentGear > 1) {
        currentGear--;
        cout << "Shifted down to gear " << currentGear << ".\n";
        } else {
        cout << "Already in gear 1. Can't shift lower.\n";
        }
    }
    void checkFluid () const { cout << "Fluid Percentage - " << fluidLevel << endl; }
    void diagnoseFault () { 
        if(!isWorking) { cout << "Warning : There's a fault in transmission. You are suggest not to drive." << endl; }
    }
};

class Vehicle {
    private : 
    const string VehcileIdentificationNumber; 
    string VehicleMake;
    string VehicleModel;
    int Year;
    int OdometerReading;
    string Color;
    string bodyStyle;
    Engine engine;
    Transmission transmission;

    protected:
    void printBaseInfo() const { cout << Year << " " << VehicleMake << " " << VehicleModel<< " | " << Color << " | " << bodyStyle << " | " << OdometerReading << " miles\n"<< endl;}

    public :
    Vehicle () : VehcileIdentificationNumber("Unknown") {}
    Vehicle (const string& VIN,const string& make,const string& model,int year,int mileage,const string& color,const string& style,Engine heart,Transmission brain) : VehcileIdentificationNumber(VIN), VehicleMake(make), VehicleModel(model), Year(year), OdometerReading(mileage), Color(color), bodyStyle(style) {
        engine = heart; transmission = brain;
    }
    Vehicle(const Vehicle& wheel,string newVIN) : VehcileIdentificationNumber(newVIN) {
        VehicleMake = wheel.VehicleMake;
        VehicleModel = wheel.VehicleModel;
        Year = wheel.Year;
        OdometerReading = wheel.OdometerReading;
        Color = wheel.Color;
        bodyStyle = wheel.bodyStyle;
        engine = wheel.engine;
        transmission = wheel.transmission;
    }

    void startCar() { engine.startEngine(); }
    void drive(int miles) { 
        int previousReading = OdometerReading;
        OdometerReading += miles; 
        cout << "Odometer : " << previousReading << " -> " << OdometerReading << "miles." << endl; 
    }
    void serviceCar() { engine.checkOil(); transmission.checkFluid(); }
    virtual void displayVehicleInfo() const =0 ;

    string getVehicleMake () const { return VehicleMake; }
    int getOdometerReading () const { return OdometerReading; }
    string getBodyStyle() const { return bodyStyle; }

    bool operator==(const Vehicle& other) const { return (VehicleMake == other.VehicleMake && VehicleModel == other.VehicleModel && Year == other.Year); }
};

class Listing;

class Dealership {
    private :
    string DealerShipName;
    string DearlerShipLocation;
    int DealerShipPhoneNumber;
    double rating;
    bool isVerfiedPartner;
    string DealerShipTagline;
    static int totalDealerShips;

    public : 
    Dealership () : rating(0.0) { isVerfiedPartner = false; totalDealerShips++; } 
    Dealership (const string& name,const string& location,int phone,const string& tagline) : DealerShipName(name), DealerShipPhoneNumber(phone), DearlerShipLocation(location), DealerShipTagline(tagline)  {
        rating = 5.0; isVerfiedPartner = true; totalDealerShips++;
    }

    void pitchDeal () { cout << "Sponsored by : " << DealerShipName << "|" << DealerShipTagline << endl; cout << "Address : " << DearlerShipLocation << "| For contact call us at - " << DealerShipPhoneNumber << endl; }
    void receiveReview (float review) {
        if(review < 1.0 || review > 5.0) {cout << "Rating range (1.0 - 5.0)" << endl; return; }
        rating = review; cout << DealerShipName << " rated - " << rating << "*(s)\n" << endl;
    }
    void displayProfile () const {
        cout << "Dealer : " << DealerShipName << "\n" << "Located : " << DearlerShipLocation << "\n" << "Contact : " << DealerShipPhoneNumber << "\n" << "Rating (stars) : " << rating << "\n" << "Status : " << (isVerfiedPartner ? "Verified Partner" : "Not Verified") << "\n" << "DealerShip Tagline : " << DealerShipTagline << "\n" << endl;
    }
    static int getTotalDealerShips () { return totalDealerShips; }
    string getDealerShipName() { return DealerShipName; }
    friend void generateDealReport(Dealership& d, Listing& l);

    void setVerified(bool status) { isVerfiedPartner = status; }
};
int Dealership::totalDealerShips = 0;

class Listing {
    private : 
    const int listingID;
    Vehicle* car;
    Dealership* carOwner;
    double carPrice;
    bool isApproved;
    bool isFeatured;
    string sideBarTrim;
    string  condition;
    static int totalListings;

    public :
    Listing () : listingID(0), carOwner(nullptr), carPrice(0), isApproved(false), isFeatured(false) {}
    Listing (int id,Vehicle* transport,Dealership* build,double price,const string& trim,const string& status) : condition(status), listingID(id), carPrice(price), sideBarTrim(trim), car(transport) {
        carOwner = build; isFeatured = false;
        isApproved = false; totalListings++;
    }

    void displayCard() const {
        if (isApproved) {
        cout << "Listing ID : " << listingID << "$" << carPrice << "\n" << endl;
        car->displayVehicleInfo();
        cout << "   Trim    : " << sideBarTrim << "\n" << "Sold by : " << carOwner->getDealerShipName() << "\n" << (isFeatured ? " >> Featured Lisitng <<\n" : "") << endl;
        } else {
        cout << "Listing ID : " << listingID << " Listing pending due to admin approval.\n" << endl;
        }
    }
    void updatePrice(int newCarPrice) {
        if(newCarPrice <= 0) { cout <<"Negative amount is not possible." << endl; return;}
        int previousPrice = carPrice;
        carPrice = newCarPrice; cout << "Updated Price : $ " << previousPrice << " To $ " << carPrice << "\n" << endl;
    } 
    void markAsFeatured() { isFeatured = true; cout << "Listing ID : " << listingID << "|" << carOwner->getDealerShipName() << "Is now live on our website Drive Chicago\n" << endl; }
    void comparePrice (const Listing* const other)  const {
        if(carPrice < other->carPrice) {cout << "Listing ID : " << listingID << "at price : $ " << carPrice << "is the better option for you than" << other->listingID << "at price : $ " << other->carPrice << "\n" << endl; } 
        else if (carPrice > other->carPrice) {cout << "Listing ID : " << other->listingID << "at price : $ " << other->carPrice << "is the better option for you than" << listingID << "at price : $ " << carPrice << "\n" << endl;} 
        else { cout << "Both cars are pricely same , you can go with either of them.\n" << endl; }
    }
    static int getTotalListings() {return totalListings;}

    int getPrice() const { return carPrice; }
    Vehicle* getVehicle() const { return car; }
    string getCondition () const { return condition; }
    bool getStatus() const { return isApproved; }
    int getListingID () const {return listingID; }
    Dealership* getCarOwner() const { return carOwner; }

    void setApproval (bool status) {isApproved = status;}

    friend void comparePrices(Listing& a, Listing& b);
    friend void verifyBuyerDeal(Client& c, Listing& l);
    bool operator<(const Listing& other) const { return carPrice < other.carPrice; }
};
int Listing::totalListings = 0;

class SearchFilter {
    private :
    int maxPrice;
    string makeFilter;
    int minPrice;
    int maxOdometerReading;
    string filterBodyStyle;
    string filterCondition;

    public :
    SearchFilter () : filterBodyStyle("Any"), filterCondition("Any"), makeFilter("Any") {}

    void setPriceRange (int minimum,int maximum) { maxPrice = maximum; minPrice = minimum; }
    void setMake (string make) { makeFilter = make; }
    void setCondition (string condition) { filterCondition = condition; }
    void setBodyStyle (string style) { filterBodyStyle = style; }
    void resetFilters () {filterBodyStyle = "Any"; filterCondition = "Any"; makeFilter = "Any"; }
    bool evaluateListingMatch(Listing list) {
        Vehicle* wheel = list.getVehicle();
        if(list.getPrice() < minPrice || list.getPrice() > maxPrice) {return false;}
        if(wheel->getOdometerReading() > maxOdometerReading) {return false; }
        if(makeFilter != "Any" && wheel->getVehicleMake() != makeFilter) {return false; }
        if(filterBodyStyle != "Any" && list.getCondition() != filterCondition) { return false; }
        if(filterCondition != "Any" && list.getCondition() != filterCondition) {return false; }
        return true;
    }
    bool evaluateListingMatch(Listing list, int zip) {
        cout << "Searching near ZIP: " << zip << "\n" <<endl;
        return evaluateListingMatch(list); 
    }
};

class DriveChicagoPlatform {
    private :
    string platformName;
    Listing* Register[100];
    int registerCount;
    double dealerFee;
    string featuredBanner;

    public :
    DriveChicagoPlatform(const string& name) {
        platformName = name; registerCount= 0; dealerFee = 299.99; featuredBanner = "";
    }

    void compiledRegistry(Listing* list) {
        if(registerCount < 100) {Register[registerCount++] = list; cout << "Platform Listing ID : " << list->getListingID() << "added to Drive Chicago Rolls" << endl; }
        else { cout << "Register Roll is full at this moment." << endl; }
    }
    void pullListing (int position){
        if(position >= 0 && position < registerCount) {Register[position]->setApproval(false); cout << "Platform - register pullled from Drive Chicago \n" << endl;}
        else {cout << "Platform - unidentified position \n" << endl; }
    }
    Listing* serveResults(SearchFilter sf) {
        cout << "\n Drive Chicago ENgine : Scanning " << registerCount<< "register(s) \n" << endl;
        for(int i=0;i<registerCount;++i) {
            if(Register[i]->getStatus() && sf.evaluateListingMatch(*Register[i])) { cout << "Matched foind "<< endl; return Register[i];}
        }
        cout << "Tera match bhi nahi mila . Bachelor hi marega ehhehehe\n" << endl; 
        return nullptr;
    }
    void showFrontPage () {
        cout << "Drive Chicago\nAvailable Cars : " << registerCount<< endl;
        if(featuredBanner != "" ) {cout << featuredBanner << "\n" << endl;}
        for(int i=0;i< registerCount; ++i) { if (Register[i]->getStatus() ) Register[i]->displayCard();
        }
    }
    void runSponsorBanner(string banner) {featuredBanner = banner; cout << "Platform - the banner is updated :"<< banner << "\n"<< endl; }
};

class CruiseNight {
    private : 
    string eventName;
    string cityName;
    string venue;
    string timeSlotForEvent;
    string eventDetails;
    string dayOfEveent;

    public :
    CruiseNight () : eventName("TBA"), cityName("chicago, IL"), venue("TBA"), timeSlotForEvent("TBA"), eventDetails("TBA"), dayOfEveent("TBA") {}
    CruiseNight(const string& name,const string& city,const string& destination,const string& time,const string& detail,const string& day) : eventName(name),cityName(city),venue(destination), timeSlotForEvent(time), eventDetails(detail), dayOfEveent(day) {}

    void displayEvent() const {
        cout << "Day : " << dayOfEveent << "City : " << cityName << "\n" << endl;
        cout << "EVent : " << eventName << "\nLocation : " << venue << "\nTime : " << timeSlotForEvent << "\nDetails : " << eventDetails << endl;
    }
    void submitEvent() {cout << "Community - " << eventName<< "\nin" << cityName <<" submitted for review\n" << endl; 
    cout << "Wait for the Driva Chicago Team verification. This process takes time so your co operation meant to us.\n" << endl;
    }
    void registerCar(string ownerCredential, string carCrdential) {
        cout << "Register + " << ownerCredential << "registered his/her " << carCrdential << "for " << eventName <<"\n" <<endl;
        cout << "Register - Your confirmation for the " << venue << "is sent tot the host\n"<< endl;
     }
    void announceWinner(string winnerCredential, string winnerCAr) {
        cout << "Show stopper : " <<winnerCredential << " Car : " << winnerCAr <<endl;
    }
};

class Message {
    private :
    const int messageID;
    string buyerName;
    string dealershipName;
    string textMessage;
    bool isRead;

    public :
    Message () : buyerName("Unkown"), dealershipName("Unknown" ), textMessage("Empty"), isRead(false), messageID(0)   { }
    Message (int id,const string& sender,const string& receiver,const string& text) : messageID(id), buyerName(sender), dealershipName(receiver), textMessage(text), isRead(false) {}
 
    void send() const { cout << "DM : " << buyerName << "->" <<dealershipName << "\n" << textMessage <<endl; }
    void markAsRead() { isRead = true; cout << dealershipName << " opened your message .\n" <<endl; }
    void deleteMessage () { textMessage = "Delted "; cout << textMessage << "\n" << endl; }
    void editMessage (string content) { textMessage = content ;} 

    string getBuyerName() {return buyerName; }
    string getDealershipName () { return dealershipName;}
    string getMessage() { return textMessage; }
}; 

class Client : public User {
    private :
    string clientName;
    string clientMail;
    double budget;
    int zipCode;
    int searchRadiusMiles;
    Listing* selections[10];
    int selectCount;

    public :
    Client() : clientName("Unknwn" ), clientMail("Unnknown"), budget(0.0), zipCode(0) , searchRadiusMiles(0), selectCount(0) {}
    Client(const string& name, const string& mail, double cash, int code, int miles) : User(name, mail),budget(cash), zipCode(code), searchRadiusMiles(miles), selectCount(0) {}

    void browseNew() const { cout << clientName << " is browsing NEW cars within " << searchRadiusMiles << " miles of ZIP " << zipCode << "\n" << endl;}
    void browseUsed() const { cout << clientName << " is browsing USED cars within " << searchRadiusMiles << " miles of ZIP " << zipCode << "\n" << endl;}
    
    void saveSelection(Listing* list) {
        if(selectCount < 10) {selections[selectCount++] = list; cout << "Listing ID : " << list->getListingID() << " saved by " << clientName <<endl;}
        else {cout << "Cap limit reached.. \n" <<endl; }
    }
    void sendDM(Listing* list, string message) {Message dm(0776,clientName,list->getCarOwner()->getDealerShipName(),message);
    dm.send(); }
    void viewSelections() const {
        cout << "\n " << clientName<< "\n" << endl;
        for(int i= 0; i<selectCount ;++i) selections[i]->displayCard();
    }
    void viewDashboard() override { cout << "Client: " << UserName << " | Budget: $" << budget << "\n" <<endl; }
    friend void verifyBuyerDeal(Client& c, Listing& l);
};

class Affan : public User{
private:
    string adminName;
    const int accessLevel;
    string department;
    string shift;
    bool isActive;

public:
    Affan(const string& name,const string& email, int level): User(name, email), accessLevel(level), department("Moderation"), shift("Day"), isActive(true) {}

    void approveListing(Listing& list) { list.setApproval(true); cout << "Listing approved and is now live.\n"<< endl; }
    void pullListing(Listing& list) { list.setApproval(false); cout << "Listing has been removed.\n"<< endl; }
     void verifyDealer(Dealership& dealer) { dealer.setVerified(true);
        cout << dealer.getDealerShipName() << " is now a verified partner.\n";
    }
    void viewSystemStats() const {
        cout << "Partner Dealers : " << Dealership::getTotalDealerShips () << "\n";
        cout << "Total Registers  : " << Listing::getTotalListings() << "\n";
    }
    void viewDashboard() override { cout << "Admin: " << UserName << " | Level: " << accessLevel << "\n"<< endl; viewSystemStats(); }
};

class CAR : public Vehicle{
    public :
    CAR (const string& VIN,const string& make,const string& model,int year,int mileage,const string& color,const string& style,Engine heart,Transmission brain) : Vehicle(VIN,make,model,year,mileage,color,style,heart,brain) {}

    void displayVehicleInfo() const override { cout << "Hey ! it's a CaRooooooo" <<endl;
        printBaseInfo() ;
    }
};

class TRuck : public Vehicle {
    public: 
    TRuck (const string& VIN,const string& make,const string& model,int year,int mileage,const string& color,const string& style,Engine heart,Transmission brain): Vehicle(VIN,make,model,year,mileage,color,style,heart,brain) {}

    void displayVehicleInfo() const override { cout << "OMG! truckuuuururur" << endl; 
    printBaseInfo ();
    }
};

void comparePrices(Listing& he, Listing& she) {
    if (he.carPrice < she.carPrice)
        cout << "Listing #" << he.listingID << " is cheaper.\n"<< endl;
    else
        cout << "Listing #" << she.listingID << " is cheaper.\n" << endl;
}

int main() {
    Engine gen("V8", 400, 8, "Petrol", true, 80); Transmission gear("TX1", "Auto", 6);
    CAR civic("VIN786", "Honda", "Civic", 2022, 15000, "Kala", "Sedan", gen, gear);
    Dealership tariqAutos("Tariq Motors", "Tariq Road Karachi", 3001234, "Sasta aur Tikao!");
    Listing l1(101, &civic, &tariqAutos, 4500000, "Oriel", "Used"), l2(102, &civic, &tariqAutos, 4800000, "RS", "New");
    Affan admin("Affan", "affan@drivechicago.com", 1); admin.approveListing(l1);
    Client hamza("Hamza", "hamza@gmail.com", 5000000, 75300, 10);
    hamza.viewDashboard(); hamza.saveSelection(&l1);
    comparePrices(l1, l2);
    civic.startCar(); civic.displayVehicleInfo();
    hamza.sendDM(&l1, "Bhai final price kya hogi? Thoda discount kardo murshid.");
    return 0;
}
