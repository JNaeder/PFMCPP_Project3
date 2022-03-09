 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */


/*
Thing 1) Electric Guitar
5 properties:
    1) Brand (std::string)
    2) Model (std::string)
    3) Number of srings (int)
    4) Number of pickups (int)
    5) Number of controls (int)
3 things it can do:
    1) Control volume
    2) Make sound from strings
    3) Change pickups
 */

struct ElectricGuitar
{
//     1) Brand (std::string)
    std::string brandName = "Gibson";
//     2) Model (std::string)
    std::string model = "Les Paul";    
//     3) Number of srings (int)
    int numberOfString = 6;
//     4) Number of pickups (int)
    int numberOfPickups = 2;
//     5) Number of controls (int)
    int numberOfControls = 4;
//     1) Control volume
    void controlVolume(float newVolume);
//     2) Make sound from strings
    void makeSoundWithStrings(int fretPosition, int numberOfStrings);
//     3) Change pickups
    int switchPickup(int switchPosition = 0); // returns the new pickup number
};


/*
Thing 2) iPhone
5 properties:
    1) Version of iPhone (float)
    2) Amount of space (float)
    3) Phone carrier (std::string)
    4) Camera model (std::string)
    5) Number of accessories (int)
3 things it can do:
    1) Take photos
    2) Make phone calls
    3) Go on internet
 */

struct iPhone FIXME: type names need to begin with a capital letter
{
//     1) Version of iPhone (float)
    float version = 1.0f;
//     2) Amount of space (float)
    float amountOfHardDriveSpace = 500.0f;
//     3) Phone carrier (std::string)
    std::string phoneCarrier = "Verizon";
//     4) Camera model (std::string)
    std::string cameraModel = "SuperGoodCamera";
//     5) Number of accessories (int)
    int numberOfAccessories = 9;

    struct Camera
    {
        int megapixles = 40;
        float energyConsumed = 23.4f;
        std::string manufactuer = "Canon";
        float iso = 200.0f;
        float shutterSpeed = 60.0f;

        void changeShutterSpeed(float newShutterSpeed);
        void changeISO(float newISOValue);
        void captureImage(int numberOfImages);
    };

//     1) Take photos
    void takePhotos(int numberOfPhotos, std::string typeOfPhoto, Camera theCamera);
//     2) Make phone calls
    void makePhoneCall(int phoneNumber, std::string nameOfcontact);
//     3) Go on internet
    void connectToInternet(int IPAddress);
};

/*
Thing 3) My Refrigerator
    1) Number of eggs (int)
    2) Number of vegetables (int)
    3) Current temperature of fridge (float)
    4) Percentage full (float)
    5) Current temperature of freezer (float)
    1) Change the temperature of fridge
    2) Change the temperature of freezer
    3) Return number food items in fridge
 */

struct MyRefrigerator
{
//     1) Number of eggs (int)
    int numberOfEggs = 12;
//     2) Number of vegetables (int)
    int numberOfVegetables = 5;
//     3) Current temperature of fridge (float)
    float tempOfFridge = 40.0f;
//     4) Percentage full (float)
    float percentageFull = 45.5f;
//     5) Current temperature of freezer (float)
    float tempOfFreezer = 30.0f;
//     1) Change the temperature of fridge
    void changeFridgeTemperature(float newTemperature);
//     2) Change the temperature of freezer
    void changeFreezeTemperature(float newTemperature);
//     3) Return number food items in fridge
    int numberOfItemsInFridge(); //returns items 
};

/*
Thing 4) Tape machine
    1) Number of tracks (int)
    2) Current speed in IPS (int)
    3) Current timecode (double)
    4) Current play status (std::string)
    5) Model of Machine (std::string)
    1) Play tape
    2) Show timecode
    3) Change speed in IPS
 */

struct TapeMachine
{
//     1) Number of tracks (int)
    int numberOfTracks = 24;
//     2) Current speed in IPS (float)
    float speedInIPS = 30.0f;
//     3) Current timecode (double)
    double currentTime = 0.00;
//     4) Current play status (std::string)
    std::string playStatus = "stopped";
//     5) Model of Machine (std::string)
    std::string model = "Studer";
//     1) Play tape
    void play(float speedInIPS, double fromTime);
//     2) Show timecode
    double showTimeCode(double currentTime); // returns the current timecode
//     3) Change speed in IPS
    void changeSpeedInIPS(float newSpeed);
};

/*
Thing 5) Display
    1) Number of pixels (int)
    2) Brightness level (float)
    3) Width (float)
    4) Height (float)
    5) Energy consumed (float)
    1) Show visuals
    2) Change brightness
    3) Consume energy
 */

struct Display
{
//     1) Number of pixels (int)
    int numberOfPixels = 1080;
//     2) Brightness level (float)
    float brightnessLevel = 75.0f;
//     3) Width (float)
    float width = 3.5f;
//     4) Height (float)
    float height = 3.0f;
//     5) Energy consumed (float)
    float energyConsumed = 50.0f;
//     1) Show visuals
    void showVisuals(int pixelsToChange);
//     2) Change brightness
    void changeBrightness(float newBrightnessLevel);
//     3) Consume energy
    void consumeEnergy (float amountOfEnergyToConsume = 0);
};

/*
Thing 6) Controls
    1) Number of Start Buttons (int)
    2) Number of Select Buttons (int)
    3) Number of D pads (int)
    4) Number of other buttons (int)
    5) Energy consumed (float)
    1) Take input from user
    2) Pause game
    3) Start Game
 */

struct Controls
{
//     1) Number of Start Buttons (int)
    int numberOfStartButtons = 1;
//     2) Number of Select Buttons (int)
    int numberOfSelectButtons = 1;
//     3) Number of D pads (int)
    int numberOfDpads = 1;
//     4) Number of other buttons (int)
    int numberOfOtherButtons = 2;
//     5) Energy consumed (float)
    float energyConsumed = 50.0f;
//     1) Take input from user
    void takeUserInput(int numberOfButtonsPressed, int dpadDirection);
//     2) Pause game
    void pauseGame(std::string gameName);
//     3) Start Game
    void startGame(std::string gameName);
};

/*
Thing 7) Logic Board
    1) Amount of RAM (int)
    2) Speed of CPU (float)
    3) Number of connections (int)
    4) Energy consumer (float)
    5) Speed of GPU (float)
    1) Process data
    2) Show video output
    3) Interfact with connections
 */

struct LogicBoard
{
//     1) Amount of RAM (int)
    int amountOfRam = 4;
//     2) Speed of CPU (float)
    float speedOfCPU = 1.3f;
//     3) Number of connections (int)
    int numberOfConnections = 3;
//     4) Energy consumer (float)
    float energyConsumed = 50.0f;
//     5) Speed of GPU (float)
    float speedOfGPU = 1.2f;

    struct CPU
    {
        int numberOfCores = 4;
        std::string nameOfCPU = "Ryzen";
        std::string manufactuer = "AMD";
        float overclockedSpeed = 2.0f;
        float currentTemperature = 80.4f;

        void performComputation(int binaryValue1, int binaryValue2);
        void overclock(float newOverclockSPeed = 2.0f);
        float returnTempFromCore (int cpuCore); //returns temp of one of the cores
    };

//     1) Process data
    void processData(float inputData1, int inputData2, CPU cpu);
//     2) Show video output
    void showVideoOutput(float inputData1, int pixelsUsed, Display targetDisplay, CPU cpu);
//     3) Interfact with connections
    void takeInputFromConnection(int connectionIndex, float inputData1);
};

/*
Thing 8) Game
    1) Amount of stoage used (float)
    2) Name of game (std::string)
    3) Amount of memory needed (float)
    4) Name of Developer (std::string)
    5) Price of game (float)
    1) Load levels
    2) Take input from controls
    3) Output video signals
 */

struct Game
{
//     1) Amount of stoage used (float)
    float stoargeUsed = 30.4f; FIXME spelling
//     2) Name of game (std::string)
    std::string nameOfGame = "Donkey Kong";
//     3) Amount of memory needed (float)
    float amountOfMemoryNeeded = 0.4f;
//     4) Name of Developer (std::string)
    std::string nameOfDeveloper = "Nintendo";
//     5) Price of game (float)
    float priceOfGame = 19.99f;
//     1) Load levels
    void loadLevels(int levelNumber, float gameStatus);
//     2) Take input from controls
    void takeControlInput(Controls currentInput);
//     3) Output video signals
    float outputVideoSignal(float gameStatus, int numberOfPixelsUsed, Display targetDisplay); // outputs magical float signal that the logic board could use.
};

/*
Thing 9) Outside Case
    1) Color (std::string)
    2) Width (float)
    3) Height (float)
    4) Depth (float)
    5) Number of LED lights (int)
    1) Protect insides
    2) Display cool color
    3) Light up
 */

struct OutsideCase
{
//     1) Color (std::string)
    std::string color = "grey";
//     2) Width (float)
    float width = 6.0f;
//     3) Height (float)
    float height  = 12.2f;
//     4) Depth (float)
    float depth = 1.0f;
//     5) Number of LED lights (int)
    int numberOfLEDs = 2;
//     1) Protect insides
    void protectInsides(int numberOfComponents, LogicBoard theLogicBoard, Display currentDisplay, Controls theControls);
//     2) Display cool color
    void displayCoolColor(std::string newColor, int numberOfLEDs);
//     3) Light up
    void lightUpLEDs(int numberOfLEDs);
};

/*
Thing 10) Gameboy
    1) Display
    2) Controls
    3) Logic Board
    4) Game
    5) Outside Case
    1) Show visuals
    2) Play sounds
    3) Get input from user
 */

struct Gameboy
{
//     1) Display
    Display display;
//     2) Controls
    Controls controls;
//     3) Logic Board
    LogicBoard logicBoard;
//     4) Game
    Game currentGame;
//     5) Outside Case
    OutsideCase outsideCase;
//     1) Show visuals
    void showVisuals(Display currentDisplay, LogicBoard logicBoard);
//     2) Play sounds
    void playSounds(int numberOfSoundsToPlay, float volume, LogicBoard logicBoard);
//     3) Get input from user
    void getInputFromUser(Controls playerControls);
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
