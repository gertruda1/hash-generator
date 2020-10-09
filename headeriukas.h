#include <iostream>
#include <string>
#include <cstring>
#include <fstream>


std::string hash_function(std::string str)
{
    int hash_length = 64;
    std::string result;
    std::string default_str = "O Fortuna velut luna statu variabilis, semper crescis aut dec...";
    std::string copy = default_str;
    

    if(str.empty())
    {
        for(int i = 0; i < hash_length; i++)
        {
            int a = 0;
                do
                {
                    a++;
                    copy[i] = (((copy[i] + a*i + a) ^ ((default_str[i] ^ i) + a)) & (default_str[(i * a - 1 * ~(i*a))%hash_length] + ~a)) % 128;
                } while ((copy[i] < '0' || copy[i] > '9') && (copy[i] < 'a' || copy[i] > 'f'));
        }
    }
    else
    {
        
        for(int i = 0; i < str.length(); i++)
        {
            for(int j = 0; j < hash_length; j++)
            {
                int a = 0;
                do
                {
                    a++;
                    copy[j] = (str[i] * copy[j] + a + i * j * a + (copy[a * i % hash_length] * default_str[j]) ^ (str[a % str.length()] * copy[3])) % 128;
                } while ((copy[j] < '0' || copy[j] > '9') && (copy[j] < 'a' || copy[j] > 'f'));
            }
        }
    }
    
    
    return copy;
    
}
void read_file()
{
    std::string file;
    std::cout << "Iveskite failo, is kurio skaitysime, pavadinima: ";
    std::cin >> file;
    std::cout << std::endl;
    std::ifstream in (file.c_str());

        try
        {
            std::string exc = "Skaitymo failas neegzistuoja";
            if(in) std::cout << "skaitymo failas egzistuoja" << std::endl;
            else throw(exc);
        }
        catch(std::string exc)
        {
            std::cout << exc << std::endl;
            return;
        }

    std::string ojojoj;
    std::string input;
    while(!in.eof())
    {
        std::getline(in, ojojoj);
        input += ojojoj;
    }
    
    std::cout << hash_function(input);    
}

void interface ()
{
    std::cout << "Inputa skaitysim is failo (f) ar irasysim ranka (r)?";
    char kaip;
    std::cin >> kaip;
    while(!std::cin || kaip!='f' && kaip!='r' )
    {
        std::cout<<"Ivestas netinkamas dydis, pasirinkite f ar r: ";
        std::cin>>kaip;

        if(kaip=='f' || kaip=='r' )
        {
            break;
        }
    }

    if (kaip == 'r')
    {
        std::cout << "Input: ";
        std::string input;
        std::getline(std::cin, input);
        
        std::cout << hash_function(input);
    }

    else read_file();

    
}

