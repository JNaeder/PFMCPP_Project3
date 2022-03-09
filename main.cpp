/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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

struct iPhone
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
    float stoargeUsed = 30.4f;
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
