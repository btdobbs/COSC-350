#include <iostream>
#include <string>

using namespace std;

//Fixed array implementation (no pointers)
namespace FlowerStructure{

    enum color {None, Red, Blue, Yellow, Purple, White};

    struct Flower{
        string Name;
        int PedalCount = 0;
        float Price = 0.0;
        color Color = None;
    };

    Flower createFlower(const string& Name, int PedalCount, float Price, color Color)
    {
        Flower f = {Name, PedalCount, Price, Color};
        return f;
    }

    bool isPlaceholderFlower(const Flower& f)
    {
        return f.Name.empty() && (f.Price == 0.0) && (f.PedalCount == 0) && (f.Color == None);
    }

    void addFlower(Flower bouquet[], int bouquetSize, const Flower& newFlower)
    {
        for(int i = 0; i < bouquetSize; i++)
        {
            if (isPlaceholderFlower(bouquet[i])) {
                bouquet[i] = newFlower;
                return;
            }
        }
        cout << "Failed to add flower to bouquet because the bouquet is full.\n";
    }

    void removeFlower(Flower bouquet[], int bouquetSize, const string& flowerName)
    {
        for(int i = 0; i < bouquetSize; i++)
        {
            if (bouquet[i].Name == flowerName) {
                Flower f;
                bouquet[i] = f;
            }
        }
    }

    int getFlowerCount(const Flower bouquet[], int bouquetSize)
    {
        int flowerCount = 0;
        for(int i = 0; i < bouquetSize; i++)
        {
            if (!isPlaceholderFlower(bouquet[i])) {
                flowerCount++;
            }
        }
        return flowerCount;
    }

    string getFlowerColorName(color c)
    {
        switch (c) {
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

    color getFlowerColorEnum(char c)
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

    void printFlower(const Flower& f)
    {
        cout << getFlowerColorName(f.Color) << " " << f.Name << " with " << f.PedalCount
        << " petal(s) and cost of $" << f.Price << "\n";
    }

    void printBouquet(const Flower bouquet[], int bouquetSize)
    {
        cout << getFlowerCount(bouquet, bouquetSize) << " flower(s)\n";
        for(int i = 0; i < bouquetSize; i++)
        {
            if (!isPlaceholderFlower(bouquet[i]))
                printFlower(bouquet[i]);
        }
    }
}

using namespace FlowerStructure;

void addFlowerFunction(Flower bouquet[], int maxBouquetSize)
{
    Flower f;
    char c;
    cout << "Enter flower name:\n";
    cin >> f.Name;
    cout << "Enter flower pedal count:\n";
    cin >> f.PedalCount;
    cout << "Enter flower price:\n";
    cin >> f.Price;
    cout << "Enter flower color: (r)ed, (b)lue, (y)ellow, (p)urple, (w)hite\n";
    cin >> c;
    f.Color = getFlowerColorEnum(c);
    addFlower(bouquet, maxBouquetSize, f);
}

void removeFlowerFunction(Flower bouquet[], int maxBouquetSize)
{
    string flowerName;
    cout << "Enter a flower name:\n";
    cin >> flowerName;
    removeFlower(bouquet, maxBouquetSize, flowerName);
}

int main() {
    int maxBouquetSize = 5;
    Flower bouquet[maxBouquetSize];
    char option;
    do{
        cout << "Enter option: (a)dd flower, (r)emove flower, (p)rint flowers, (e)xit\n";
        cin >> option;
        switch (option) {
            case 'a':
                addFlowerFunction(bouquet, maxBouquetSize);
                break;
            case 'r':
                removeFlowerFunction(bouquet, maxBouquetSize);
                break;
            case 'p':
                printBouquet(bouquet, maxBouquetSize);
                break;
            case 'e':
                break;
            default:
                cout << option << " is not a valid option.\n";
                break;
        }
    }while (option != 'e');
    return 0;
}
