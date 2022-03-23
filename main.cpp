/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




// --------------------------------------------------------------------------
struct ElectricGuitar
{
    ElectricGuitar();
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

ElectricGuitar::ElectricGuitar()
{
    std::cout << "ElectricGuitar being constructed!" << std::endl;
}

void ElectricGuitar::controlVolume(float newVolume)
{
    volume = newVolume;
    std::cout << "Changed volume to " << volume << std::endl;
}

void ElectricGuitar::makeSoundWithStrings(int fretPosition, int numberOfStringsToPlay)
{
    numberOfStringsOnGuitar -= numberOfStringsToPlay * fretPosition;
    std::cout << "Make some sound with strings!" << std::endl;
}

int ElectricGuitar::switchPickup(int switchPosition)
{
    std::cout << "Switch Pickup!" << std::endl;
    return switchPosition - currentPickup;
}

// --------------------------------------------------------------------------
struct IPhone
{
    IPhone();
    float version = 1.0f;
    float amountOfHardDriveSpace = 500.0f;
    std::string phoneCarrier = "Verizon";
    std::string cameraModel = "SuperGoodCamera";
    int numberOfAccessories = 9;

    struct Camera
    {
        Camera();
        int megapixels = 40;
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
    void connectToInternet(long ipAddress);
};

IPhone::Camera::Camera()
{
    std::cout << "iPhone Camera being constructed!" << std::endl;
}

void IPhone::Camera::changeShutterSpeed(float newShutterSpeed)
{
    std::cout<< "Changing Camera shutter speed to " << newShutterSpeed << std::endl;    
}

void IPhone::Camera::changeISO(float newISOValue)
{
    std::cout << "Changing ISO to " << newISOValue << std::endl; 
}

void IPhone::Camera::captureImage(int numberOfImages)
{
    std::cout << "Took " << numberOfImages << " images." << std::endl;
}

IPhone::IPhone()
{
    std::cout << "iPhone being constructed!" << std::endl;
}

void IPhone::takePhotos(int numberOfPhotos, std::string typeOfPhoto, IPhone::Camera theCamera)
{
    std::cout << "Take " << numberOfPhotos << " " << typeOfPhoto << " photos from the " << theCamera.manufactuer << std::endl;
}

void IPhone::makePhoneCall(int phoneNumber, std::string nameOfContact)
{
    std::cout << "Call " << nameOfContact << " at " << phoneNumber << std::endl;
}

void IPhone::connectToInternet(long ipAddress)
{
    std::cout << "Connecting to " << ipAddress << std::endl;
}

// --------------------------------------------------------------------------
struct MyRefrigerator
{
    MyRefrigerator();
    int numberOfEggs = 12;
    int numberOfVegetables = 5;
    float tempOfFridge = 40.0f;
    float percentageFull = 45.5f;
    float tempOfFreezer = 30.0f;
    void changeFridgeTemperature(float newTemperature);
    void changeFreezeTemperature(float newTemperature);
    int numberOfItemsInFridge();
};

MyRefrigerator::MyRefrigerator()
{
    std::cout << "MyRefrigerator being constructed!" << std::endl;
}

void MyRefrigerator::changeFridgeTemperature(float newTemperature)
{
    tempOfFridge = newTemperature;
    std::cout << "Changed Fridge Temperature to " << tempOfFridge << "F" << std::endl;
}

void MyRefrigerator::changeFreezeTemperature(float newTemperature)
{
    tempOfFreezer = newTemperature;
    std::cout << "Changed Freezer Temperature to " << tempOfFreezer << "F" << std::endl;
}

int MyRefrigerator::numberOfItemsInFridge()
{
    std::cout << "Counting items in fridge!" << std::endl;
    return numberOfEggs + numberOfVegetables;
}

// --------------------------------------------------------------------------
struct TapeMachine
{
    TapeMachine();
    int numberOfTracks = 24;
    float currentSpeedInIPS = 30.0f;
    double currentTimecode = 0.00;
    std::string playStatus = "stopped";
    std::string model = "Studer";
    void play(float speedInIPS, double fromTime);
    double showTimeCode(double currentTime);
    void changeSpeedInIPS(float newSpeed);
};

TapeMachine::TapeMachine()
{
    std::cout << "TapeMachine being constructed!" << std::endl;
}

void TapeMachine::play(float speedInIPS, double fromTime)
{
    std::cout << "Playing tape from --[" << fromTime << "]-- at " << speedInIPS << " inches per second."<< std::endl;
}

double TapeMachine::showTimeCode(double currentTime)
{
    currentTimecode = currentTime;
    std::cout << "Timecode: --[" << currentTimecode << "]--" << std::endl;
    return currentTimecode;
}

void TapeMachine::changeSpeedInIPS(float newSpeed)
{
    std::cout << "Changing speed of tape machine to " << newSpeed << " inches per second." << std::endl;
    currentSpeedInIPS = newSpeed;
}

// --------------------------------------------------------------------------
struct Display
{
    Display();
    int numberOfPixels = 1080;
    float brightnessLevel = 75.0f;
    float width = 3.5f;
    float height = 3.0f;
    float energyConsumed = 50.0f;
    void showVisuals(int pixelsToChange);
    void changeBrightness(float newBrightnessLevel);
    void consumeEnergy (float amountOfEnergyToConsume = 0);
};

Display::Display()
{
    std::cout << "Display being constructed!" << std::endl;
}

void Display::showVisuals(int pixelsToChange)
{
    std::cout << "Changed " << pixelsToChange << " pixels on Display!" << std::endl;
}

void Display::changeBrightness(float newBrightnessLevel)
{
    brightnessLevel = newBrightnessLevel;
    std::cout << "Changed Display brightness to " << brightnessLevel << std::endl;
}

void Display::consumeEnergy(float amountOfEnergyToConsume)
{
    energyConsumed -= amountOfEnergyToConsume;
    std::cout << "Display has consumed " << amountOfEnergyToConsume << " energy." << std::endl;
}

// --------------------------------------------------------------------------
struct Controls
{
    Controls();
    int numberOfStartButtons = 1;
    int numberOfSelectButtons = 1;
    int numberOfDpads = 1;
    int numberOfOtherButtons = 2;
    float energyConsumed = 50.0f;
    void takeUserInput(int numberOfButtonsPressed, int dpadDirection);
    void pauseGame(std::string gameName);
    void startGame(std::string gameName);
};

Controls::Controls()
{
   std::cout << "Controls being constructed!" << std::endl; 
}

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
    LogicBoard();
    int amountOfRam = 4;
    float speedOfCPU = 1.3f;
    int numberOfConnections = 3;
    float energyConsumed = 50.0f;
    float speedOfGPU = 1.2f;

    struct CPU
    {
        CPU();
        int numberOfCores = 4;
        std::string nameOfCPU = "Ryzen";
        std::string manufactuer = "AMD";
        float overclockedSpeed = 2.0f;
        float currentTemperature = 80.4f;
        void performComputation(int binaryValue1, int binaryValue2);
        void overclock(float newOverclockSpeed = 2.0f);
        float returnTempFromCore (int cpuCore);
    };
    void processData(int inputData1, int inputData2, CPU cpu);
    void showVideoOutput(int inputData1, int pixelsUsed, Display targetDisplay, CPU cpu);
    void takeInputFromConnection(int connectionIndex, float inputData1);
};

LogicBoard::CPU::CPU()
{
    std::cout << "CPU on LogicBoard being constructed!" << std::endl;
}

void LogicBoard::CPU::performComputation(int binaryValue1, int binaryValue2)
{
    std::cout << "Performing Computation with " << binaryValue1 << " and " << binaryValue2 << std::endl;
}

void LogicBoard::CPU::overclock(float newOverclockSpeed)
{
    overclockedSpeed = newOverclockSpeed;
    std::cout << "Changed overclock speed on CPU to " << overclockedSpeed  << " GHz."<< std::endl;
}

float LogicBoard::CPU::returnTempFromCore(int cpuCore)
{
    return cpuCore;
}

LogicBoard::LogicBoard()
{
    std::cout << "LogicBoard being constructed!" << std::endl;
}

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
    Game();
    float storageUsed = 30.4f;
    std::string nameOfGame = "Donkey Kong";
    float amountOfMemoryNeeded = 0.4f;
    std::string nameOfDeveloper = "Nintendo";
    float priceOfGame = 19.99f;
    void loadLevels(int levelNumber, float gameStatus);
    void takeControlInput(Controls currentInput);
    float outputVideoSignal(float gameStatus, int numberOfPixelsUsed, Display targetDisplay);
};

Game::Game()
{
    std::cout << "Game being constructed!" << std::endl;
}

void Game::loadLevels(int levelNumber, float gameStatus)
{
    std::cout << "Loading level " << levelNumber << ". Game status is " << gameStatus << "%" << std::endl;
}

void Game::takeControlInput(Controls currentInput)
{
    std::cout << "Currently using " << currentInput.numberOfOtherButtons << " buttons." << std::endl;
}

float Game::outputVideoSignal(float gameStatus, int numberOfPixelsUsed, Display targetDisplay)
{
    std::cout << "Outputing video signal to " << targetDisplay.numberOfPixels << " pixels." << std::endl;
    return (gameStatus * targetDisplay.numberOfPixels) - numberOfPixelsUsed;
}

// --------------------------------------------------------------------------
struct OutsideCase
{
    OutsideCase();
    std::string color = "grey";
    float width = 6.0f;
    float height  = 12.2f;
    float depth = 1.0f;
    int totalNumberOfLEDs = 2;
    void protectInsides(int numberOfComponents, LogicBoard theLogicBoard, Display currentDisplay, Controls theControls);
    void displayCoolColor(std::string newColor, int numberOfLEDs);
    void lightUpLEDs(int numberOfLEDs);
};

OutsideCase::OutsideCase()
{
    std::cout << "OutsideCase being constructed!" << std::endl;
}

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
    std::cout <<  numberOfLEDs << " crazy LEDs are shining on." << std::endl;
}

// --------------------------------------------------------------------------
struct Gameboy
{
    Gameboy();
    Display display;
    Controls controls;
    LogicBoard logicBoard;
    Game currentGame;
    OutsideCase outsideCase;
    void showVisuals(Display currentDisplay, LogicBoard theLogicBoard);
    void playSounds(int numberOfSoundsToPlay, float volume, LogicBoard theLogicBoard);
    void getInputFromUser(Controls playerControls);
};

Gameboy::Gameboy()
{
    std::cout << "Gameboy being constructed!" << std::endl;
}

void Gameboy::showVisuals(Display currentDisplay, LogicBoard theLogicBoard)
{
    std::cout << "GPU at speed: " << theLogicBoard.speedOfGPU << " GHz sending to display with " << currentDisplay.numberOfPixels << " pixels." << std::endl;
}

void Gameboy::playSounds(int numberOfSoundsToPlay, float volume, LogicBoard theLogicBoard)
{
    std::cout << "Using " << theLogicBoard.numberOfConnections << " connections to play " << numberOfSoundsToPlay << " sounds at " << volume << " volume level." << std::endl;
}

void Gameboy::getInputFromUser(Controls playerControls)
{
    std::cout << "Using " << playerControls.numberOfStartButtons + playerControls.numberOfSelectButtons + playerControls.numberOfOtherButtons << " total buttons." << std::endl;
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
    Example::main();

    // ElectricGuitar
    std::cout << "\n-------------ElectricGuitar-------------" << std::endl;
    ElectricGuitar gibsonLesPaul;
    ElectricGuitar fenderStrat;
    gibsonLesPaul.controlVolume(0.95f);
    fenderStrat.makeSoundWithStrings(8, 4);
    gibsonLesPaul.switchPickup(2);
    std::cout << "This guitar has " << gibsonLesPaul.numberOfStringsOnGuitar << " strings." << std::endl;
    
    // IPhone Camera
    std::cout << "\n-------------IPhone Camera-------------" << std::endl;
    IPhone::Camera canonCamera;
    canonCamera.changeShutterSpeed(60.0f);
    canonCamera.changeISO(800.0f);
    canonCamera.captureImage(5);
    std::cout << "This camera has " << canonCamera.megapixels << " megapixels." << std::endl;

    // IPhone
    std::cout << "\n-------------IPhone-------------" << std::endl;
    IPhone iphone12;
    IPhone iphone4;
    iphone12.takePhotos(5, "normal", canonCamera);
    iphone4.makePhoneCall(1234567890, "Mom");
    iphone12.connectToInternet(192168000000);
    std::cout << "The phone carrier is " << iphone12.phoneCarrier << std::endl;
    
    // MyRefrigerator
    std::cout << "\n-------------MyRefrigerator-------------" << std::endl;
    MyRefrigerator kitchenFridge;
    kitchenFridge.changeFridgeTemperature(35.0f);
    kitchenFridge.changeFreezeTemperature(20.0f);
    std::cout << kitchenFridge.numberOfItemsInFridge() << " items in fridge." << std::endl;
    std::cout << "This fridge is currently " << kitchenFridge.percentageFull << "% full." << std::endl;

    // TapeMachine
    std::cout << "\n-------------TapeMachine-------------" << std::endl;
    TapeMachine studer;
    studer.play(30.0f, 0.00);
    studer.showTimeCode(32.44);
    studer.changeSpeedInIPS(15.0f);
    std::cout << "This tape machine has " << studer.numberOfTracks << " tracks." << std::endl;

    // Display
    std::cout << "\n-------------Display-------------" << std::endl;
    Display gameboyDisplay;
    Display gameboyHDDisplay;
    gameboyDisplay.showVisuals(80);
    gameboyHDDisplay.changeBrightness(0.75f);
    gameboyDisplay.consumeEnergy(0.10f);
    std::cout << "The dimensions of this display are " << gameboyDisplay.width << " inches by " << gameboyDisplay.height << " inches." << std::endl;
    
    // Controls
    std::cout << "\n-------------Controls-------------" << std::endl;
    Controls gameboyControls;
    gameboyControls.takeUserInput(2, 3);
    gameboyControls.pauseGame("Donkey Kong");
    gameboyControls.startGame("Donkey Kong");
    std::cout << "There is a total of " << gameboyControls.numberOfDpads << " D-Pads." << std::endl;
    
    // LogicBoard CPU
    std::cout << "\n-------------LogicBoard CPU-------------" << std::endl;
    LogicBoard::CPU amdCPU;
    LogicBoard::CPU intelCPU;
    amdCPU.performComputation(101, 011);
    intelCPU.overclock(30.5f);
    std::cout << "Current CPU temp is " << amdCPU.returnTempFromCore(99) << "F" << std::endl;
    std::cout << "This CPU has " << amdCPU.numberOfCores << " cores." << std::endl;
    
    // LogicBoard
    std::cout << "\n-------------LogicBoard-------------" << std::endl;
    LogicBoard gameboyLogicBoard;
    gameboyLogicBoard.processData(324, 22, amdCPU);
    gameboyLogicBoard.showVideoOutput(111,5234, gameboyDisplay, amdCPU);
    gameboyLogicBoard.takeInputFromConnection(2, 40.56f);
    std::cout << "This Logic Board has " << gameboyLogicBoard.amountOfRam << "GB of Ram." << std::endl;

    // Game
    std::cout << "\n-------------Game-------------" << std::endl;
    Game donkeyKong;
    donkeyKong.loadLevels(2, 0.25f);
    donkeyKong.takeControlInput(gameboyControls);
    donkeyKong.outputVideoSignal(0.25f, 80, gameboyHDDisplay);
    std::cout << "This game uses " << donkeyKong.storageUsed << "MB of storage." << std::endl;

    // OutsideCase
    std::cout << "\n-------------OutsideCase-------------" << std::endl;
    OutsideCase gameboyCase;
    gameboyCase.protectInsides(4, gameboyLogicBoard, gameboyDisplay, gameboyControls);
    gameboyCase.displayCoolColor("red", 10);
    gameboyCase.lightUpLEDs(50);
    std::cout << "The color of this case is " << gameboyCase.color << std::endl;

    // Gameboy
    std::cout << "\n-------------Gameboy-------------" << std::endl;
    Gameboy theGameboy;
    theGameboy.showVisuals(gameboyDisplay, gameboyLogicBoard);
    theGameboy.playSounds(4, 0.75f, gameboyLogicBoard);
    theGameboy.getInputFromUser(gameboyControls);
    std::cout << "The Current Game is " << theGameboy.currentGame.nameOfGame << std::endl;

    std::cout << "good to go!" << std::endl;
}
