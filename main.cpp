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
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Limb
    {
        void stepForward();
        int stepSize();
    };

    Limb leftFoot;
    Limb rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Limb::stepForward()
    {
        std::cout << "Move Foot Foward!" << std::endl;
    }

int Person::Limb::stepSize()
    {
        return 2;
    }

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize() + howFast;
}

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

// --------------------------------------------------------------------------
struct ElectricGuitar
{
    std::string brandName = "Gibson";
    std::string model = "Les Paul";
    int numberOfStringsOnGuitar = 6;
    int numberOfPickups = 2;
    int numberOfControls = 4;
    float volume = 0;
    int currentPickup = 0;
    void controlVolume(float newVolume);
    void makeSoundWithStrings(int fretPosition, int numberOfStringsToPlay);
    int switchPickup(int switchPosition = 0);
};

void ElectricGuitar::controlVolume(float newVolume)
{
    volume = newVolume;
}

void ElectricGuitar::makeSoundWithStrings(int fretPosition, int numberOfStringsToPlay)
{
    numberOfStringsOnGuitar -= numberOfStringsToPlay * fretPosition;
}

int ElectricGuitar::switchPickup(int switchPosition)
{
    return switchPosition - currentPickup;
}

// --------------------------------------------------------------------------
struct IPhone
{
    float version = 1.0f;
    float amountOfHardDriveSpace = 500.0f;
    std::string phoneCarrier = "Verizon";
    std::string cameraModel = "SuperGoodCamera";
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
    void takePhotos(int numberOfPhotos, std::string typeOfPhoto, Camera theCamera);
    void makePhoneCall(int phoneNumber, std::string nameOfcontact);
    void connectToInternet(int ipAddress);
};

void IPhone::takePhotos(int numberOfPhotos, std::string typeOfPhoto, IPhone::Camera theCamera)
{
    for(int i = 0; i < numberOfPhotos; i++)
        {
            std::cout << typeOfPhoto << " " << theCamera.manufactuer;   
        }
}

void IPhone::makePhoneCall(int phoneNumber, std::string nameOfContact)
{
    std::cout << "Call " << nameOfContact << " at " << phoneNumber << std::endl;
}

void IPhone::connectToInternet(int ipAddress)
{
    std::cout << "Connecting to " << ipAddress << std::endl;
}

// --------------------------------------------------------------------------
struct MyRefrigerator
{
    int numberOfEggs = 12;
    int numberOfVegetables = 5;
    float tempOfFridge = 40.0f;
    float percentageFull = 45.5f;
    float tempOfFreezer = 30.0f;
    void changeFridgeTemperature(float newTemperature);
    void changeFreezeTemperature(float newTemperature);
    int numberOfItemsInFridge();
};

void MyRefrigerator::changeFridgeTemperature(float newTemperature)
{
    tempOfFridge = newTemperature;
}

void MyRefrigerator::changeFreezeTemperature(float newTemperature)
{
    tempOfFreezer = newTemperature;
}

int MyRefrigerator::numberOfItemsInFridge()
{
    return numberOfEggs + numberOfVegetables;
}

// --------------------------------------------------------------------------
struct TapeMachine
{
    int numberOfTracks = 24;
    float currentSpeedInIPS = 30.0f;
    double currentTimecode = 0.00;
    std::string playStatus = "stopped";
    std::string model = "Studer";
    void play(float speedInIPS, double fromTime);
    double showTimeCode(double currentTime);
    void changeSpeedInIPS(float newSpeed);
};

void TapeMachine::play(float speedInIPS, double fromTime)
{
    std::cout << "Playing tape from " << fromTime << " at " << speedInIPS << " inches per second."<< std::endl;
}

double TapeMachine::showTimeCode(double currentTime)
{
    currentTimecode = currentTime;
    return currentTimecode;
}

void TapeMachine::changeSpeedInIPS(float newSpeed)
{
    currentSpeedInIPS = newSpeed;
}

// --------------------------------------------------------------------------
struct Display
{
    int numberOfPixels = 1080;
    float brightnessLevel = 75.0f;
    float width = 3.5f;
    float height = 3.0f;
    float energyConsumed = 50.0f;
    void showVisuals(int pixelsToChange);
    void changeBrightness(float newBrightnessLevel);
    void consumeEnergy (float amountOfEnergyToConsume = 0);
};

void Display::showVisuals(int pixelsToChange)
{
    for(int i = 0; i < pixelsToChange; i++)
        {
            std::cout << "Changed Pixel!" << std::endl;
        }
}

void Display::changeBrightness(float newBrightnessLevel)
{
    brightnessLevel = newBrightnessLevel;
}

void Display::consumeEnergy(float amountOfEnergyToConsume)
{
    energyConsumed -= amountOfEnergyToConsume;
}

// --------------------------------------------------------------------------
struct Controls
{
    int numberOfStartButtons = 1;
    int numberOfSelectButtons = 1;
    int numberOfDpads = 1;
    int numberOfOtherButtons = 2;
    float energyConsumed = 50.0f;
    void takeUserInput(int numberOfButtonsPressed, int dpadDirection);
    void pauseGame(std::string gameName);
    void startGame(std::string gameName);
};

void Controls::takeUserInput(int numberOfButtonsPressed, int dpadDirection)
{
    std::cout << numberOfButtonsPressed << " buttons pressed. D-Pad direction is " << dpadDirection << std::endl;
}

void Controls::pauseGame(std::string gameName)
{
    std::cout << gameName << " is paused!" << std::endl;
}

void Controls::startGame(std::string gameName)
{
    std::cout << gameName << " has started!" << std::endl;
}

// --------------------------------------------------------------------------
struct LogicBoard
{
    int amountOfRam = 4;
    float speedOfCPU = 1.3f;
    int numberOfConnections = 3;
    float energyConsumed = 50.0f;
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
        float returnTempFromCore (int cpuCore);
    };
    void processData(int inputData1, int inputData2, CPU cpu);
    void showVideoOutput(int inputData1, int pixelsUsed, Display targetDisplay, CPU cpu);
    void takeInputFromConnection(int connectionIndex, float inputData1);
};

void LogicBoard::processData(int inputData1, int inputData2, LogicBoard::CPU cpu)
{
    std::cout << cpu.nameOfCPU << " has processed " << inputData1 + inputData2 << std::endl;
}

void LogicBoard::showVideoOutput(int inputData1, int pixelsUsed, Display targetDisplay, LogicBoard::CPU theCPU)
{
   std::cout << (targetDisplay.numberOfPixels - pixelsUsed) * inputData1 << ": Pixel Data on CPU " << theCPU.nameOfCPU << std::endl;
}

void LogicBoard::takeInputFromConnection(int connectionIndex, float inputData1)
{
    std::cout << "Taking input: " << inputData1 << " at connection: " << connectionIndex << std::endl;
}

// --------------------------------------------------------------------------
struct Game
{
    float storageUsed = 30.4f; //IDE's need spellcheck
    std::string nameOfGame = "Donkey Kong";
    float amountOfMemoryNeeded = 0.4f;
    std::string nameOfDeveloper = "Nintendo";
    float priceOfGame = 19.99f;
    void loadLevels(int levelNumber, float gameStatus);
    void takeControlInput(Controls currentInput);
    float outputVideoSignal(float gameStatus, int numberOfPixelsUsed, Display targetDisplay);
};

void Game::loadLevels(int levelNumber, float gameStatus)
{
    std::cout << "Loading level " << levelNumber << ". Game status is " << gameStatus << std::endl;
}

void Game::takeControlInput(Controls currentInput)
{
    std::cout << "Currently using " << currentInput.numberOfOtherButtons << " buttons." << std::endl;
}

float Game::outputVideoSignal(float gameStatus, int numberOfPixelsUsed, Display targetDisplay)
{
    return (gameStatus * targetDisplay.numberOfPixels) - numberOfPixelsUsed;
}

// --------------------------------------------------------------------------
struct OutsideCase
{
    std::string color = "grey";
    float width = 6.0f;
    float height  = 12.2f;
    float depth = 1.0f;
    int totalNumberOfLEDs = 2;
    void protectInsides(int numberOfComponents, LogicBoard theLogicBoard, Display currentDisplay, Controls theControls);
    void displayCoolColor(std::string newColor, int numberOfLEDs);
    void lightUpLEDs(int numberOfLEDs);
};

void OutsideCase::protectInsides(int numberOfComponents, LogicBoard theLogicBoard, Display currentDisplay, Controls theControls)
{
    std::cout<< "Currently Protecting " << numberOfComponents << " components. Also protecting " << theLogicBoard.speedOfCPU << " and " << currentDisplay.numberOfPixels << " and " << theControls.numberOfOtherButtons << std::endl; 
}

void OutsideCase::displayCoolColor(std::string newColor, int numberOfLEDs)
{
    std::cout << "Change " << numberOfLEDs << " LEDs to color: " << newColor << std::endl;
}

void OutsideCase::lightUpLEDs(int numberOfLEDs)
{
    for(int i = 0; i < numberOfLEDs; i++)
        {
            std::cout << "Shine on your crazy LED." << std::endl;
        }
}

// --------------------------------------------------------------------------
struct Gameboy
{
    Display display;
    Controls controls;
    LogicBoard logicBoard;
    Game currentGame;
    OutsideCase outsideCase;
    void showVisuals(Display currentDisplay, LogicBoard theLogicBoard);
    void playSounds(int numberOfSoundsToPlay, float volume, LogicBoard theLogicBoard);
    void getInputFromUser(Controls playerControls);
};

void Gameboy::showVisuals(Display currentDisplay, LogicBoard theLogicBoard)
{
    std::cout << "GPU at speed: " << theLogicBoard.speedOfGPU << " sending to Display with " << currentDisplay.numberOfPixels << " pixels." << std::endl;
}

void Gameboy::playSounds(int numberOfSoundsToPlay, float volume, LogicBoard theLogicBoard)
{
    std::cout << "Using " << theLogicBoard.numberOfConnections << " connections to play " << numberOfSoundsToPlay << " sounds at " << volume << " volume level." << std::endl;
}

void Gameboy::getInputFromUser(Controls playerControls)
{
    std::cout << "Using " << playerControls.numberOfStartButtons + playerControls.numberOfSelectButtons + playerControls.numberOfOtherButtons << " buttons." << std::endl;
}



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
