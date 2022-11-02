#include <iostream>
#include <string>

using namespace std;

//dynamic array implementation (with pointers)
//Note: it's possible to do this without placeholder flowers using pointers to flowers in each array element
namespace FlowerClass{
    enum color {None, Red, Blue, Yellow, Purple, White};

    class Flower{
    private:
        bool placeholder;
        string Name;
        int PedalCount = 0;
        float Price = 0.0;
        color Color = None;
    public:
        Flower();
        Flower(const string& Name, int PedalCount, float Price, color Color);
        Flower(const Flower& flower);
        string getFlowerColor() const;
        string getName() const;
        void print();
        bool isPlaceholderFlower() const;
    };

    bool Flower::isPlaceholderFlower() const
    {
        return this->placeholder;
    }

    Flower::Flower() {
        this->placeholder = true;
        this->Name = "";
        this->PedalCount = 0;
        this->Price = 0.0;
        this->Color = None;
    }

    Flower::Flower(const string &Name, int PedalCount, float Price, color Color) {
        this->placeholder = false;
        this->Name = Name;
        this->PedalCount = PedalCount;
        this->Price = Price;
        this->Color = Color;
    }

    Flower::Flower(const Flower& flower) {
        this->placeholder = flower.placeholder;
        this->Name = flower.Name;
        this->PedalCount = flower.PedalCount;
        this->Price = flower.Price;
        this->Color = flower.Color;
    }

    string Flower::getFlowerColor() const
    {
        switch (this->Color) {
            case None:
                return "";
            case Red:
                return "Red";
            case Blue:
                return "Blue";
            case Yellow:
                return "Yellow";
            case Purple:
                return "Purple";
            case White:
                return "White";
            default:
                return "";
        }
    }

    string Flower::getName() const {
        return this->Name;
    }

    void Flower::print() {
        cout << this->getFlowerColor() << " " << this->Name << " with " << this->PedalCount
             << " petal(s) and cost of $" << this->Price << "\n";
    }

    class Bouquet{
    private:
        Flower *bouquet;
        int count;
    public:
        Bouquet();
        ~Bouquet();
        int getFlowerCount() const;
        void print();
        void addFlower(const Flower& newFlower);
        void removeFlower(const string& flowerName);
    };

    Bouquet::Bouquet() {
        bouquet = new Flower[1];
        count = 1;
    }

    Bouquet::~Bouquet() {
        delete[] bouquet;
    }

    int Bouquet::getFlowerCount() const {
        int flowerCount = 0;
        for(int i = 0; i < count; i++)
        {
            if (!bouquet[i].isPlaceholderFlower()) {
                flowerCount++;
            }
        }
        return flowerCount;
    }

    void Bouquet::print() {
        cout << this->getFlowerCount() << " flower(s)\n";
        for(int i = 0; i < this->count; i++)
        {
            if (!bouquet[i].isPlaceholderFlower())
                bouquet[i].print();
        }
    }

    void Bouquet::addFlower(const Flower& newFlower)
    {
        //Look for a placeholder to put the flower
        for(int i = 0; i < count; i++)
        {
            if (bouquet[i].isPlaceholderFlower()) {
                bouquet[i] = newFlower;
                return;
            }
        }
        //No placeholders found so expand array
        Flower *temp;
        temp = new Flower[this->count + 1];
        for (int i = 0; i < this->count; i++) {
            temp[i] = bouquet[i];
        }
        delete[] bouquet;
        bouquet = temp;
        bouquet[this->count] = newFlower;
        this->count = this->count + 1;
    }

    void Bouquet::removeFlower(const string& flowerName)
    {
        for(int i = 0; i < count; i++)
        {
            if (bouquet[i].getName() == flowerName) {
                Flower f;
                bouquet[i] = f;
            }
        }
        //code could be added here to shrink the array
    }

    class BouquetApp{
    private:
        Bouquet *bouquet;
    public:
        BouquetApp();
        ~BouquetApp();
        void addFlower();
        void removeFlower();
        void printFlowers();
        static color getFlowerColor(char c);
        static void printOptions();
        static void printInvalidOption(char option);
    };

    BouquetApp::BouquetApp() {
        bouquet = new Bouquet();
    }

    BouquetApp::~BouquetApp() {
        delete bouquet;
    }

    color BouquetApp::getFlowerColor(char c)
    {
        switch (c) {
            case 'r':
                return Red;
            case 'b':
                return Blue;
            case 'y':
                return Yellow;
            case 'p':
                return Purple;
            case 'w':
                return White;
            default:
                return None;
        }
    }

    void BouquetApp::addFlower()
    {
        string Name;
        int PedalCount;
        float Price;
        char c;
        cout << "Enter flower name:\n";
        cin >> Name;
        cout << "Enter flower pedal count:\n";
        cin >> PedalCount;
        cout << "Enter flower price:\n";
        cin >> Price;
        cout << "Enter flower color: (r)ed, (b)lue, (y)ellow, (p)urple, (w)hite\n";
        cin >> c;
        Flower flower(Name, PedalCount, Price, BouquetApp::getFlowerColor(c));
        this->bouquet->addFlower(flower);
    }

    void BouquetApp::removeFlower()
    {
        string flowerName;
        cout << "Enter a flower name:\n";
        cin >> flowerName;
        this->bouquet->removeFlower(flowerName);
    }

    void BouquetApp::printFlowers() {
        bouquet->print();
    }

    void BouquetApp::printOptions() {
        cout << "Enter option: (a)dd flower, (r)emove flower, (p)rint flowers, (e)xit\n";
    }

    void BouquetApp::printInvalidOption(char option){
        cout << option << " is not a valid option.\n";
    }
}

using namespace FlowerClass;

int main() {
    BouquetApp bouquetApp;
    char option;
    do{
        BouquetApp::printOptions();
        cin >> option;
        switch (option) {
            case 'a':
                bouquetApp.addFlower();
                break;
            case 'r':
                bouquetApp.removeFlower();
                break;
            case 'p':
                bouquetApp.printFlowers();
                break;
            case 'e':
                break;
            default:
                BouquetApp::printInvalidOption(option);
                break;
        }
    }while (option != 'e');
    return 0;
}